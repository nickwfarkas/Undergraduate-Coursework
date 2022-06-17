from tkinter import *
import os, random, turtle

window = Tk()
window.geometry('300x550')
window.title('Mad Gen')

Label (window, text= 'Mad Libs & PolyGon Generator', font='Helvetica 20 bold').pack()
#MadLib One

madlib = {}

def draw_polygon(sides: int, length: int, red: int, blue: int, green: int):
    t = turtle.Turtle()
    turtle.colormode(255)
    t.pencolor(red,blue,green)
    for i in range(sides):
        t.forward(length)
        t.right(360/sides)

def user_polygon():
    n = int(input("Enter the number of the sides of the polygon: "))
    l = int(input("Enter the length of the sides of the polygon: "))
    r = int(input("Enter the number of red shift of the polygon: "))
    g = int(input("Enter the number of green shift of the polygon: "))
    b = int(input("Enter the length of blue shift of the polygon: "))
    draw_polygon(n,l,r,g,b)
    
def random_polygon():
    n = random.randint(3,100)
    l = random.randint(1,10)
    r = random.randint(0,255)
    g = random.randint(0,255)
    b = random.randint(0,255)
    print(f"{n} sides of length {l}")
    draw_polygon(n,l,r,g,b)
    
def validate(k: str):
    s = madlib[k]
    while(not s.isalpha()):
        s = input(f"\n{s} is not a valid response please try again\n")
    print()
    madlib[k] = s

def madlib1():
    madlib["animals"] = input('enter a animal name : ')
    validate("animals")
    madlib["profession"] = input('enter a profession name: ')
    validate("profession")
    madlib["cloth"] = input('enter a piece of cloth name: ')
    validate("cloth")
    madlib["things"] = input('enter a thing name: ')
    validate("things")
    madlib["name"] = input('enter a name: ')
    validate("name")
    madlib["place"] = input('enter a place name: ')
    validate("place")
    madlib["verb"] = input('enter a verb in "ing" form: ' )
    validate("verb")
    madlib["food"] = input('food name: ')
    validate("food")
    print(f'say {madlib["food"]}, the photographer said as the camera flashed! {madlib["name"]} and I had gone to {madlib["place"]} to get our photos taken on my birthday. The first photo we really wanted was a picture of us dressed as a {madlib["animals"]} pretending to be a {madlib["profession"]}. when we saw the second photo, it was exactly what I wanted. We both looked like {madlib["things"]} wearing {madlib["cloth"]} and {madlib["verb"]} --exactly what I had in mind')

def madlib2():
    madlib["adjective"] = input ('enter adjective: ')
    validate("adjective")
    madlib["color"] = input('enter a color: ')
    validate("color")
    madlib["thing"] = input('enter a thing name: ')
    validate("thing")
    madlib["place"] = input('enter a place: ')
    validate("place")
    madlib["person"] = input('enter a person name: ')
    validate("person")
    madlib["adjective1"] = input ('enter a adjective: ')
    validate("adjective1")
    madlib["insect"] = input('enter a insect name: ')
    validate("insect")
    madlib["food"] = input('food name: ')
    validate("food")
    madlib["verb"] = input('enter a verb in ing form: ' )
    validate("verb")
    print(f'Last night I dreamed I was a {madlib["adjective"]} butterfly with {madlib["color"]} splotches that looked like {madlib["thing"]}. I flew to {madlib["place"]} with my bestfriend and {madlib["person"]} who was a {madlib["adjective1"]} {madlib["insect"]}. We ate some {madlib["food"]} when we got there and then decided to {madlib["verb"]} and the dream ended when I said-- lets {madlib["verb"]}.')

def madlib3():
    
    madlib["person"] = input ('enter a person name : ')
    validate("person")
    madlib["color"] = input('enter a color: ')
    validate("color")
    madlib["foods"] = input('enter food name: ')
    validate("foods")
    madlib["adjective"] = input ('enter adjective: ')
    validate("adjective")
    madlib["thing"] = input('enter a thing name: ')
    validate("thing")
    madlib["place"] = input('enter a place name: ')
    validate("place")
    madlib["verb"] = input('enter a verb in ing form: ' )
    validate("verb")
    madlib["adverb"] = input('enter adverb: ' )
    validate("adverb")
    madlib["food"] = input('food name: ')
    validate("food")
    madlib["things"] = input('enter a thing name: ')
    validate("things")
    print(f'Today we picked apple from {madlib["person"]}\'s Orchard. I had no idea there were so many different varieties of apples. I ate {madlib["color"]} apples straight off the tree that tasted like {madlib["foods"]}. Then there was a {madlib["adjective"]} apple that looked like a {madlib["thing"]}. When our bag were full, we went on a free hay ride to {madlib["place"]} and back. It ended at a hay pile where we got to {madlib["verb"]}. I can hardly wait to get home and cook with the apples. We are going to make apple {madlib["adverb"]} and {madlib["food"]} pies!')

def quit_program():
    os._exit(0)

Label (window, text = "Madlibs: ", font = 'arial 15 bold').place(x=40, y=60)
Button(window, text= 'The Photographer', font ='arial 15', command= madlib1, bg = 'ghost white' ).place(x=60, y=120)
Button(window, text= 'The Butterfly', font ='arial 15', command= madlib2, bg = 'ghost white' ).place(x=80, y=240)
Button(window, text='apple and apple', font= 'arial 15', command = madlib3, bg = 'ghost white' ).place(x=70, y=180)
Label (window, text = "Polygon Generator:", font = 'arial 15 bold').place(x=40, y=300)
Button(window, text= 'Random Polygon', font ='arial 15', command= random_polygon, bg = 'ghost white' ).place(x=60, y=360)
Button(window, text= 'Custom Polygon', font ='arial 15', command= user_polygon, bg = 'ghost white' ).place(x=70, y=420)
Button(window, text='QUIT', font= ('Helvectica 13 bold'), foreground="Green", command = quit_program, background = 'Yellow' ).place(x=80, y=480)


window.mainloop()

