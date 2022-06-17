import math

def  kilometerToMile(kilometers):
    return float(kilometers)  * 0.62137

def printMiles(kilometers, miles):
    print(str(kilometers) + " kilometers =  " + str(miles) + " miles")

def circle(r):
    print("A circle with radius = " + str(round(r, 2)) + " has:\n")
    print("Diameter of a Circle = " + str(round(2 * r, 2)) + "\n")
    print("Circumference of a Circle = " + str(round(2 * math.pi * r, 2)) + "\n")
    print("Area of a Circle = " + str(round(math.pi * r**2, 2)) + "\n")


kilometers = 300

radius = 4

printMiles(kilometers, kilometerToMile(kilometers))

print("\n")

circle(radius)
