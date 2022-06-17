import math
import csv
import json

# Work Ticket 1

def sphere_volume(r: float):
    return ((4/3)*(math.pi*(r**3)))

# Work Ticket 2

def print_range(start: int, end: int):
    print(start)
    if(start > end):
        print_range(start-1,end)
    elif(start < end):
        print_range(start+1,end)
        
        
# Work Ticket 3

def GCD(a: int,b: int):
    if(a > b):
        a-=b
    elif(a < b):
        b-=a
    else:
        return a

    return GCD(a,b)

# Work Ticket 4

def create_file(csv_file_name: str, json_file_name: str):
    sales_data = []
    temp = {}

    with open(csv_file_name, encoding='utf-8') as csv_file:
        r = csv.reader(csv_file)
    
        for row in r:
            temp["Transaction_date"] = row[0]
            temp["Product"] = row[1]
            temp["Price"] = row[2]
            temp["Payment_Type"] = row[3]
            temp["Name"] = row[4]
            temp["City"] = row[5]
            temp["State"] = row[6]
            temp["Country"] = row[7]
            
            sales_data.append(temp)
            temp = {}
            
        with open(json_file_name, 'w', encoding='utf-8') as json_file:
            json_file.write(json.dumps(sales_data))
            
            

def main():
    user_choice = input("Which Work Ticket would you like to test: ")
    if(user_choice == "1"):
        r = float(input("Please enter a radius: "))
        print(sphere_volume(r))
    elif(user_choice == "2"):
        s = int(input("What is the number you want to start at: "))
        e = int(input("What number would you like to end with: "))
        print_range(s,e)
    elif(user_choice == "3"):
        num_1 = int(input("Please enter a number: "))
        num_2 = int(input("Please enter another number: "))
        print(GCD(num_1,num_2))
    elif(user_choice == "4"):
        create_file("SalesJan2009.csv", "SalesJan2009.json")
    else:
        print("Not a valid option please try again!")
        
main()