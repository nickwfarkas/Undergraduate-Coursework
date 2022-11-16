import json
import googleapiclient.discovery
import requests
from spotipy.oauth2 import SpotifyClientCredentials
import spotipy
import pprint
import pandas as pd

api_service_name = "youtube"
api_version = "v3"
DEVELOPER_KEY = ""


'''
Get playlist Id from YouTube API
'''
def get_playlist_id():

    youtube = googleapiclient.discovery.build(
        api_service_name, api_version, developerKey = DEVELOPER_KEY)

    request = youtube.playlists().list(
        part="snippet,contentDetails",
        channelId="UCt7fwAhXDy3oNFTAzF2o8Pw",
        maxResults=25
    )
    response = request.execute()

    all_playlists = response["items"]
    
    playlist_id = ""
    
    for playlist in all_playlists:
        if(playlist["snippet"]["title"] == "Weekly Track Roundup / Raw Reviews"):
            playlist_id = playlist["id"]
            print(playlist["snippet"]["title"]+" Added!")
            
    return playlist_id


'''
Get all video items in the playlist
'''
def get_playlist_items_YT(id):
    
    youtube = googleapiclient.discovery.build(
        api_service_name, api_version, developerKey = DEVELOPER_KEY)

    request = youtube.playlistItems().list(
        part="snippet",
        playlistId = id,
        maxResults=25
    )
    response = request.execute()

    playlist_items = response
    
    tracks = []
    
    count = 0
    
    while(True):
        try: 
            request = youtube.playlistItems().list(
                part="snippet",
                playlistId = id,
                pageToken = playlist_items["nextPageToken"],
                maxResults=25
            )
            response = request.execute()
            
            playlist_items = response
            
            count += len(playlist_items["items"])
        
            get_tracks_YT(playlist_items, tracks)
            
        except KeyError:
            print("done")
            break
        
    print(count)
        
    json_file = open("data.json", 'w', encoding='utf-8')
    json_file.write(json.dumps(tracks))
    json_file.close()


'''
Data scrape music ratings from video description
'''
def get_tracks_YT(playlist_items, tracks):
    for i in range(len(playlist_items["items"])):
        if("Weekly Track Roundup" in playlist_items["items"][i]["snippet"]["title"]):
            description = playlist_items["items"][i]["snippet"]["description"].split('\n')
        
            best = True
            meh = False
            for line in description:
                if('...meh...' in line):
                    best = False
                    meh = True
                if('!!!WORST TRACKS THIS WEEK!!!' in line):
                    meh = False
                    
                temp = validate_split(line)
                    
                if(best and len(temp) > 0):
                    tracks.append({"artist": temp[0], "title": temp[1], "score": 1})
                elif(meh and len(temp) > 0):
                    tracks.append({"artist": temp[0], "title": temp[1], "score": 0})
                elif(len(temp) > 0):
                    tracks.append({"artist": temp[0], "title": temp[1], "score": -1})

'''
Remove uneeded information from music titles. Isolate and split artist and song name
'''
def validate_split(line: str):
    if('-' in line and ':' not in line):
        temp = line.split('-')
        temp[0] = temp[0].strip()
        temp[1] = temp[1].strip()
    else:
        return []
    
    if(" x " in temp[0]):
        temp[0] = remove_x(temp[0])
    if("ft. " in temp[1]):
        temp[1] = remove_feature(temp[1])
    if("&" in temp[0]):
        temp[0] = remove_and(temp[0])
    return temp
                  
def remove_feature(s: str):
    arr = s.split('ft. ')
    return arr[0].strip()

def remove_and(s: str):
    arr = s.split('&')
    return arr[0].strip()

def remove_x(s: str):
    arr = s.split(' x ')
    return arr[0].strip()

'''
Search spotify API for tracking using track name and artist name.
Save music stats in data object. Handle errors for manual intervention.
''' 
def spotify_search(track_name: str, artist: str, rating: int, failed: list, tracks: list):
    temp = {}
    search_str = f'{track_name}+{artist}'
    sp = spotipy.Spotify(client_credentials_manager=SpotifyClientCredentials(client_id='', client_secret=''))
    try:
        result = sp.search(search_str)
        track = sp.track(result["tracks"]["items"][0]["id"])
        analysis = sp.audio_features(result["tracks"]["items"][0]["id"])
        temp["name"] = track_name
        temp["artist"] = artist
        temp["popularity"] = track["popularity"]
        temp["acousticness"] = analysis[0]["acousticness"]
        temp["danceability"] = analysis[0]["danceability"]
        temp["duration_ms"] = analysis[0]["duration_ms"]
        temp["energy"] = analysis[0]["energy"]
        temp["instrumentalness"] = analysis[0]["instrumentalness"]
        temp["key"] = analysis[0]["key"]
        temp["liveness"] = analysis[0]["liveness"]
        temp["loudness"] = analysis[0]["loudness"]
        temp["mode"] = analysis[0]["mode"]
        temp["speechiness"] = analysis[0]["speechiness"]
        temp["tempo"] = analysis[0]["tempo"]
        temp["valence"] = analysis[0]["valence"]
        temp["rating"] = rating
        tracks.append(temp)
    except KeyError:
        failed.append(f"{artist}~{track_name}~{rating}")
        print("Key Error")
    except IndexError:
        failed.append(f"{artist}~{track_name}~{rating}")
        print("Index Error")
        
'''
Join spotify data (music stats) with youtube data (rating and titles)
'''
def merge_data(input_file):
    yt_data_file = open(input_file, 'r', encoding='utf-8')
    yt = json.load(yt_data_file)
    yt_data_file.close()
    
    nd_data_file = open("NeedleDrop.json", 'r', encoding='utf-8')
    nd = json.load(nd_data_file)
    nd_data_file.close()
    
    f_data_file = open("Failed.json", 'r', encoding='utf-8')
    failed = json.load(f_data_file)
    f_data_file.close()
    
    count = 0
    for v in yt:
        print(count)
        spotify_search(v["title"],v["artist"],v["score"],failed,nd)
        count+=1
    json_file = open("NeedleDrop.json", 'w', encoding='utf-8')
    json_file.write(json.dumps(nd))
    json_file.close()
    print("Merge Complete")
    
    json_file = open("Failed.json", 'w', encoding='utf-8')
    json_file.write(json.dumps(failed))
    json_file.close()

'''
Driver function to export data
'''
if __name__ == "__main__":
    with open('NeedleDrop.json', encoding='utf-8') as inputfile:
        jn = pd.read_json(inputfile)
        
    jn.to_csv('NeedleDrop.csv', encoding='utf-8', index=False)