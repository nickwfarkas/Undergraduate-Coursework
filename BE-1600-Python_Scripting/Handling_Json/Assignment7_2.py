import json
import urllib.request

def print_ten_quakes():
    handle = urllib.request.urlopen(
        "https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/4.5_month.geojson")

    placeList = []
    data = handle.read()
    eData = json.loads(data)

    full = eData.get('features')

    for i in range(len(full)):
        e = full[i]
        prop = e.get('properties')
        place = prop.get('place')
        placeList.append(place)
        if(i < 10):
            print(place)

print_ten_quakes()

