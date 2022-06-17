def golf():
    numOfPlayers = int(input("Enter the numbers of players in the tournament: "))
    i = 0
    scores = {}
    while(i < numOfPlayers):
        tempName = input("Enter the name of the player: ")
        tempScore = input("Enter the golf score: ")
        scores[tempName] = tempScore
        i+=1
    return scores

def printToFile(scores):
    f = open("golf.txt","w")
    for k,v in scores.items():
        f.write(k+"\n"+v+"\n")
        
    f.close()

def readFromFile():
    f = open("golf.txt","r")
    scores = []
    tempName = f.readline()
    tempScore = f.readline()
    print()
    while(tempScore != ""):
        print("Name: "+tempName,end='')
        print("Golf Score: "+tempScore,end='')
        scores.append(int(tempScore))
        tempName = f.readline()
        tempScore = f.readline()
    print()    
    print("Min Score = "+str(min(scores)))
    print("Max Score = "+str(max(scores)))

printToFile(golf())
readFromFile()
    
