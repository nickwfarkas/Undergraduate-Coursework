import datetime
import json
import os
from uuid import uuid4
import pygame
import sys
import time
import random

'''Sets up Pygame'''
pygame.init()

screen = pygame.display.set_mode((720,720))

pygame.display.set_caption("Twins")

'''For janky pyinstaller so it will read the json file'''

high_score = './High_Scores.json'

# determine if application is a script file or frozen exe
if getattr(sys, 'frozen', False):
    application_path = os.path.dirname(sys.executable)
elif __file__:
    application_path = os.path.dirname(__file__)

high_score_path = os.path.join(application_path, high_score)


'''Global Player and Game Stats'''
twins = []
t = 0
target_x = 0
target_y = 0
target_id = 0
lives = 0
win = False
lose = False
game_status = ""
score = ""
start: time
player_name = "Player"+str(uuid4())

'''Starts game by creating twins and chosing one by random'''
def generate_twins():
    global t
    global target_x
    global target_y
    global target_id
    global lives
    global win
    global lose
    global game_status
    global twins
    global score
    global start
    
    twins = []
    lives = 1
    t = random.randint(0,15)
    
    for i in range(1,17):
        temp_path = "./Twins/Trainer_"+str(i)+".png"
        temp = pygame.image.load(temp_path).convert_alpha()
        temp = pygame.transform.scale(temp, (50, 50))
        twins.append({"id":i,"twin":temp, "posx": random.randint(0,670), "posy": random.randint(0,670), "dirx": random.choice([-1,1]),"diry": random.choice([-1,1]), "speed": random.random()+.25, "is_target": False})
        
    for i in range(1,17):
        temp_path = "./Twins/Trainer_"+str(i)+".png"
        temp = pygame.image.load(temp_path).convert_alpha()
        temp = pygame.transform.scale(temp, (50, 50))
        twins.append({"id":i,"twin":temp, "posx": random.randint(0,670), "posy": random.randint(0,670), "dirx": random.choice([-1,1]),"diry": random.choice([-1,1]), "speed": random.random()+.25, "is_target": False})

    twins.pop(t+16)

    target_id = twins[t]["id"]

    print(target_id)
    win = False
    lose = False

    game_status = "start"
    start = time.time()

'''Enters user score into the High_Scores.json File'''
def enter_score(**args):
    d = []
    l = {}
    l["name"] = player_name
    l["score"] = args['s']
    l["date_time"] = str(datetime.datetime.now())
    file = open(high_score_path)
    d = json.load(file)    
    d.append(l)
    
    try:
        json_file = open(high_score_path, 'w', encoding='utf-8')
        json_file.write(json.dumps(d))
    except OSError:
        print("File doesnt exist!")

'''Gets user scores form the High_Scores.json File'''     
def get_scores():
    file = open(high_score_path)
    data = json.load(file)
    
    return sorted(data, key=lambda d: d['score'])    
    
'''Sets Fonts for the entire Project'''
title_font = pygame.font.Font('freesansbold.ttf', 128)
font = pygame.font.Font('freesansbold.ttf', 64)
font1 = pygame.font.Font('freesansbold.ttf', 32)

'''Initial Call to start Game'''
generate_twins()

while True:
    ''' 
    When in game mode this moves the sprites and listens for actions
    like user click and user quit. Also contains logic for winning
    and losing.
    '''
    
    if(game_status == "play"):
        j = 0
        for twin in twins:
            twin["posx"] += twin["dirx"]*twin["speed"]
            twin["posy"] += twin["diry"]*twin["speed"]
            if(twin["posx"] >= 670 or twin["posx"] <= 0):
                twin["posx"] = 0
                twin["posy"] = random.randint(0,650)
                twin["dirx"] = 1
                twin["diry"] = random.choice([-1,1])
            if(twin["posy"] >= 670 or twin["posy"] <= 0):
                twin["posy"] = 0
                twin["posx"] = random.randint(0,650)
                twin["dirx"] = random.choice([-1,1])
                twin["diry"] = 1
            if(j == t):
                target_x = twin["posx"]
                target_y = twin["posy"]
            j+=1
        screen.fill("white")
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()
                sys.exit()
            if(event.type == pygame.MOUSEBUTTONDOWN):
                cx,cy = pygame.mouse.get_pos()
                if(int(cx) in range(int(target_x-25),int(target_x+75)) and int(cy) in range(int(target_y-25),int(target_y+75))):
                    end = time.time()
                    win = True
                    game_status = "end"
                    for twin in twins:
                        twin["speed"] = 0
                    score = end-start
                    enter_score(s = score)
                else:
                    lives-=1
                    if(lives == 0):
                        end = time.time()
                        lose = True
                        score = end-start
                        twin["speed"] = 0
                        game_status = "end"
                    else:
                        print(str(lives)+" lives left!")
        for twin in twins:
            twins[t]["twin"] = pygame.transform.scale(twins[t]["twin"], (50, 50))
            screen.blit(twin["twin"],(twin["posx"],twin["posy"]))
    elif(game_status == "start"):
        '''Where the game begins. Where you can choose to change name or start game'''
        desc = [
            "Every year a convention of twins",
            "gather but of course non-twins",
            "want to infiltrate. As the over-",
            "seer of the event. It is your job",
            "to find the non-twin."
        ]
        screen.fill("white")
        text = title_font.render('Twins', True, (255, 255, 255), (0,0,0))
        screen.blit(text, (190,75))
        text = font.render('Start', True, (255, 255, 255), (0,255,0))
        screen.blit(text, (300,260))
        for i in range(len(desc)):
            text = font1.render(desc[i], True, (99,102,106), (255, 255, 255))
            screen.blit(text, (100,350+(i*40)))    
        text = font.render('Set Player Name', True, (255, 255, 255), (0,0,255))
        screen.blit(text, (100,575))
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()
                sys.exit()
            if(event.type == pygame.MOUSEBUTTONDOWN):
                cx,cy = pygame.mouse.get_pos()
                if(cx in range(300,450) and cy in range(260,320)):
                    game_status = "play"
                    start = time.time()
                if(cx in range(100,650) and cy in range(575,700)):
                    player_name = ""
                    game_status = "name"
    elif(game_status == "end"):
        '''
        Displays end stats when game is over including scoreboard,
        target sprite, user score and name. Also listens for quit and
        play again.
        '''
        s = get_scores()
        if(win):
            text = font.render('You Won in '+str(round(score,2))+'s', True, (255, 255, 255), (0,0,0))
            screen.blit(text, (100,25))
        else:
            text = font.render('You Lost in '+str(round(score,2))+'s', True, (255, 255, 255), (0,0,0))
            screen.blit(text, (100,25))
        end_character = pygame.transform.scale(twins[t]["twin"], (200, 200))
        screen.blit(end_character,(260,110))
        
        if(len(s) < 5):
            stop = len(s)
        else:
            stop = 5
        
        for i in range(stop):
            if(len(s[i]["name"]) > 15):
                temp_name = s[i]["name"][:15]+"..."
            else:
                temp_name = s[i]["name"]
            text = font1.render(str(i+1)+". ", True, (255, 255, 255), (0,0,0))
            screen.blit(text, (130,350+(i*40)))
            text = font1.render(temp_name, True, (255, 255, 255), (0,0,0))
            screen.blit(text, (200,350+(i*40)))
            text = font1.render(str(round(s[i]["score"],2)), True, (255, 255, 255), (0,0,0))
            screen.blit(text, (520,350+(i*40)))
        
        text = font.render('Restart', True, (255, 255, 255), (0,0,200))
        screen.blit(text, (100,600))
        text = font.render('Quit', True, (255, 255, 255), (200,0,0))
        screen.blit(text, (430,600))
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()
                sys.exit()
            if(event.type == pygame.MOUSEBUTTONDOWN):
                cx,cy = pygame.mouse.get_pos()
                if(cx in range(430,560) and cy in range(600,650)):
                    pygame.quit()
                    sys.exit()
                if(cx in range(100,330) and cy in range(600,650)):
                    generate_twins()
    elif(game_status == "name"):
        '''
        Listens to users keyboard for username input.
        Also validates that the username is valid.
        '''
        screen.fill("white")
        text = font1.render("Enter Player Name (Must be Alpha Numeric):", True, (0, 0, 0), (255,255,255))
        screen.blit(text, (10,20))
        text = font1.render(player_name, True, (0, 0, 0), (255,255,255))
        screen.blit(text, (20,100))
        if(player_name.isalnum()):
            text = font.render('Submit', True, (255, 255, 255), (0,255,0))
            screen.blit(text, (230,260))
        else:
            text = font.render('Submit', True, (255, 255, 255), (99,102,106))
            screen.blit(text, (230,260))
        for event in pygame.event.get():
            if(event.type == pygame.QUIT):
                pygame.quit()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_BACKSPACE:
                    player_name = player_name[:-1]
                else:
                    player_name += event.unicode
            if(player_name.isalnum()):
                if(event.type == pygame.MOUSEBUTTONDOWN):
                    cx,cy = pygame.mouse.get_pos()
                    if(cx in range(230,460) and cy in range(260,350)):
                        game_status = "start"
                
    pygame.display.update()
 
    
    

        
    
    
