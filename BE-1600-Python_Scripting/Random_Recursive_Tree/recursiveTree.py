import turtle
import random

def tree(t, trunkLength):
    if trunkLength < 5:
        t.dot("green")
        return
    else:
        a = random.randint(15, 46)
        l = random.randint(5, 26)
        if(trunkLength < 10):
            t.color("green")
        else:
            t.color("brown")
        t.forward(trunkLength)
        t.right(a)
        tree(t, trunkLength - l)
        t.left(a*2)
        tree(t, trunkLength - l)
        t.right(a)
        t.penup()
        t.backward(trunkLength)
        t.pendown()

t = turtle.Turtle()
t.penup()
t.goto(0,-100)
t.pendown()
t.left(90)
trunkLength = 100
tree(t, trunkLength)
