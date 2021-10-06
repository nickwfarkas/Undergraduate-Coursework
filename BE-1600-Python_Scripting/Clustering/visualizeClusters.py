import turtle
from createClusters import *

import csv
def readEarthquakeFile(filename):
    dataFile = open(filename, "r") 
    csvReader = csv.reader(dataFile) 
    titles = next(csvReader)        #read and skip titles
    dataDict = {}
    key = 0

    for aLine in csvReader:
        key = key + 1               #key is the line number
        lat = float(aLine[1])       #extract latitude
        long = float(aLine[2])
        depth = float(aLine[3])
        dataDict[key] = [long, lat, depth]

    return dataDict

def visualizeQuakes(dataFile):
    dataDict = readEarthquakeFile(dataFile)
    quakeCentroids = createCentroids(6, dataDict)
    clusters = createClusters(6, quakeCentroids, dataDict, 3)

    quakeT = turtle.Turtle()
    quakeWin = turtle.Screen()
    quakeWin.bgpic("worldmap.gif")
    quakeWin.screensize(445, 253)

    wFactor = (quakeWin.screensize()[0]/2)/180
    hFactor = (quakeWin.screensize()[1]/2)/90

    quakeT.hideturtle()
    quakeT.up()

    colorList = ["red","lawngreen","blue","orange","cyan","yellow"]

    for clusterIndex in range(6):
        quakeT.color(colorList[clusterIndex]) #choose cluster color
        for aKey in clusters[clusterIndex]:
            lon = dataDict[aKey][0]
            lat = dataDict[aKey][1]
            quakeT.goto(lon * wFactor, lat * hFactor)
            quakeT.dot()
    quakeWin.exitonclick() 

visualizeQuakes("earthquakes.csv")
