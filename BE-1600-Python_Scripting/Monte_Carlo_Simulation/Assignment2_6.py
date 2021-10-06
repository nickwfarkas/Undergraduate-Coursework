import random
import math
import turtle

def showMontePi(numDarts, drawingT,wn):
    
    
    wn.setworldcoordinates(-2,-2,2,2)
    
    drawingT.up()
    drawingT.goto(-1,0)
    drawingT.down()
    drawingT.goto(1,0)
    
    drawingT.up()
    drawingT.goto(0,1)
    drawingT.down()
    drawingT.goto(0,-1)
    
    circle = 0
    drawingT.up()
    wn.tracer(0)
    for i in range(numDarts):
        x = random.uniform(-1.0,1.0)
        y = random.uniform(-1.0,1.0)

        d = math.sqrt(x**2 + y**2)

        drawingT.goto(x,y)
        
        if d <= 1:
            circle = circle + 1
            drawingT.color("blue")
        else:
            drawingT.color("red")
            
        drawingT.dot()
    
    pi = circle/numDarts * 4

    return pi

wn = turtle.Screen()
drawingT = turtle.Turtle()
print (showMontePi(2000, drawingT,wn))
wn.exitonclick()


