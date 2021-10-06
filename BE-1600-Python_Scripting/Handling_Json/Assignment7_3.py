import json
import urllib.request
import turtle

def franklin():
    screen = turtle.Screen()
    frank = turtle.Turtle()
    frank.speed(0)

    screen.setworldcoordinates(-400,-400,400,400)
        
    frank.up()
    frank.goto(-200,0)
    frank.down()
    frank.goto(200,0)

    frank.up()
    frank.goto(0,200)
    frank.down()
    frank.goto(0,-200)

    handle = urllib.request.urlopen(
            "https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/4.5_month.geojson")

    cordList = []
    data = handle.read()
    eData = json.loads(data)

    full = eData.get('features')

    for i in range(len(full)):
        frank.up()
        e = full[i]
        geo = e.get('geometry')
        x = geo.get('coordinates')[0]
        y = geo.get('coordinates')[1]
        frank.goto(x,y)
        frank.dot()
        if(i < 10):
            print("("+str(x)+","+str(y)+")")
        
    screen.exitonclick()

franklin()
