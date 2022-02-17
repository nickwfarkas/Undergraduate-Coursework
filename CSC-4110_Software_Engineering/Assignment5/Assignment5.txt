from datetime import date
from math import sqrt

# My full name Nicholas Farkas
first_name = "nicholas"
last_name = "FARKAS"

print(f"Hello, {first_name.upper()} {last_name.lower()}\n\n")

full_name = first_name+" "+last_name;

print(full_name[(len(first_name)+1):])

full_name = full_name[:len(first_name)+1] + last_name + ", Walsh College Student"

print(full_name)

print('"Start by doing what\'s necessary; then do what\'s possible; and suddenly you are doing the impossible - Francis of Assisi"')

# num1 = approx. PI and num2 = approx. e
num1: float = 3.14;
num2: float = 2.72;

addition = num1+num2
subtraction = num1-num2
multiplication = num1*num2
division = num1/num2

print("%s plus %s equals %s"%(str(num1),str(num2),str(addition)))

print("{0} minus {1} equals {2}".format(num1,num2,subtraction))

print(str(num1)+" times "+str(num2)+" equals "+str(multiplication))

print(f"{num1} divided by {num2} equals {division}")

sq_root = round(sqrt(multiplication),2)

print(f"The square root of {multiplication} equals {sq_root}")

month = date.today().strftime("%B")
day: int = date.today().day

print("\n\t\tToday is day {1} of the month of {0}.".format(month,day))