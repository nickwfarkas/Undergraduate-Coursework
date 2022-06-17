def inCircle(radius,x,y):
    if(x**2 + y**2 <= radius**2):
        print("Point({0},{1}) is in circle with radius {2}".format(x,y,radius))
    else:
        print("Point({0},{1}) is not in circle with radius {2}".format(x,y,radius))

inCircle(8,10,-10)
