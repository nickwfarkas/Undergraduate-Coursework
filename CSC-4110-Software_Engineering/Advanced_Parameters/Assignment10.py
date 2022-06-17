import math

# Work Ticket 1

def area_of_shape(**args):
    return math.pi*(args['radius']**2)

print("Work Ticket 1:")
print(f"Area of Circle: {area_of_shape(radius=5)}cm^2\n")

# Work Ticket 2

def find_length(**args):
    return args['V']**(1. / 3)

print("Work Ticket 2:")
print(f"Length of Side: {find_length(V=729)}cm\n")

# Work Ticket 3

def find_hypotenuse(**args):
    return math.sqrt((args['a']**2)+(args['b']**2))

print("Work Ticket 3:")
print(f"Hypotenuse: {find_hypotenuse(a=10,b=18)}cm\n")

# Work Ticket 4

def work_ticket_4(*args):
    return math.sqrt(((((args[0]+args[1])**args[2])-args[3])/((args[4])+(args[5]-args[6])*((args[7]-args[8])**(args[9])))))

print("Work Ticket 4:\n"+str(work_ticket_4(4.172,9.131844,3,18,-3.5,11.2,4.6,7,2.91683,-0.4))+"\n")

# Work Ticket 5

print("Work Ticket 5:")

def f(a, b=4, c=5):
    print(a,b,c)

# A. Print 1 2 5

f(1,2)

def f(a,b,c=5):
    print(a,b,c)

# A. Print 1 2 3 

f(1,c=3,b=2)

# C. They printed as expected. When you call a function and put in the arguments it will overrite the default.