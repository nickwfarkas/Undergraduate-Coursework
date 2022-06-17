# Work Ticket 1
# Need system to change command Line
import sys
def work_ticket_1():
    # Set inital color to white (since I am in dark mode)
    sys.stdout.write("\033[0;0m")
    print("Please enter a string: ")
    # Set Color to Red
    sys.stdout.write("\033[1;31m")
    s = input()
    # Set Color to white
    sys.stdout.write("\033[0;0m")
    print(f"You entered {s} and it's type is {type(s)}")
    print("Please enter an integer")
    # Set Color to Red
    sys.stdout.write("\033[1;31m")
    s = input()
    sys.stdout.write("\033[0;0m")
    # Set Color to white
    print(f"You entered {s} and its type is {type(s)}")

# Work Ticket 2
def work_ticket_2():
    print("Twinkle, twinkle, little star,")
    print("\tHow I wonder what you are!")
    print("\t\tUp above the world so high,\n")
    print("\t\tLike a diamond in the sky.")
    print("Twinkle, twinkle, little star,")
    print("\tHow I wonder what you are")

# Work Ticket 3
# Area of circle equation is Pi*Radius^2
import math
def work_ticket_3():
    r = input("Enter radius of a circle: ")

    print(f"\nr = {r}")
    print(f"Area = {(float(r)**2)*math.pi}")

# Work Ticket 4
def work_ticket_4():
    l = input("Enter a letter to check if vowel: ")
    # All Vowels
    vowels = ['a','e','i','o','u']
    if(l.lower() in vowels):
        print(f"{l} is a Vowel")
    else:
        print(f"{l} is not a Vowel")

# Work Ticket 5
def work_ticket_5():
    print([i**4 for i in range(0,19)])

# Work Ticket 6
# Bet object to store number, color and bet amount
class UserBet:
    bet_amount: float
    number: str
    color: str
    
    def __init__(self, bet_amount, number):
        self.bet_amount = bet_amount
        self.number = number
        if(number == '0' or number == "00"):
            self.color = "green"
        else:
            self.color = 'black' if (int(number)%2 == 0) else 'red'
        
    def __eq__(self, other):
        return (self.number == other.number) and (self.color == other.color)

    def __ne__(self, other):
        return not (self == other)

import random as r

# Creates a 2D lisr of number values and color values
list_of_options = [[str(i),'black' if (i%2 == 0) else 'red'] for i in range(1,37) ]
list_of_options.append(["0","green"])
list_of_options.append(["00","green"])

LOG = []

# Two Types of Bets Inside or Number Betting and Outside or Color Betting
def bet_type():
    user_option = input("Would you like to bet on the 1.Inside or 2.Outside: ")
    if(user_option == '1'):
        inside_bet()
    elif(user_option == '2'):
        outside_bet()

# Gets bet with validation
def outside_bet():
    user_option = input('Would you like to bet on? Enter Red or Black: ')
    user_bet = input(f"How much would you like to put on {user_option} $")
    while(user_option.lower() != 'black' and user_option.lower() != 'red'):
        print(f"{user_option} is not a valid option!")
        user_option = input('Would you like to bet on? Enter Red or Black: ')
        user_bet = input(f"How much would you like to put on {user_option} $")
        
    if(user_option.lower() == "red"):
        LOG.append(UserBet(user_bet,"1"))
    else:
        LOG.append(UserBet(user_bet,"2"))
    spin("Outside")
       
# Gets bet with validation
def inside_bet():
    raw_user_option = input('What slot would you like? Type "done" to spin: ')
    user_bet = input(f"How much would you like to put on {raw_user_option} $")
    
    while(raw_user_option != "done"):
        user = UserBet(user_bet,raw_user_option)
        LOG.append(user)
        print(f"{raw_user_option} Added!")
        raw_user_option = input('What slot would you like? Type "done" to spin: ')
        if(raw_user_option != "done"):
            user_bet = input(f"How much would you like to put on {raw_user_option} $")
    spin("Inside")

# Spins the wheel and compares the bets to what the wheel lands on
def spin(bet_type: str):
    win = False
    s = r.choice(list_of_options)
    print(f"Wheel lands on {s[1].upper()} {s[0]}")
    
    if(bet_type == "Outside"):
        if(LOG[0].color == s[1]):
            print("You win!")
            print("Cash out of ${:.2f}".format(float(LOG[0].bet_amount)*2))
            win = True
        else:
            print("Better Luck Next Time!")
    elif(bet_type == "Inside"):
        sub = UserBet(0,s[0])
        for i in range(len(LOG)):
            if(sub == LOG[i]):
                print("You win!")
                print("Cash out of ${:.2f}".format(float(LOG[0].bet_amount)*36))
                win = True
        if(win == False):
            print("Better Luck Next Time!")
                    
def work_ticket_6():
    bet_type()
                
# Work Ticket 7
guest_list = []
date_list = []

# Fills lists with user input
def compile_lists():
    guest = input("What guest would you like to add in format of FirstName_LastName or done when done\n")
    if(guest != "done"):
        date = input("What date were you invited MM/DD/YYYY: ")
        guest_list.append(guest)
        date_list.append(date)

    while(guest.lower() != "done"):
        guest = input("What guest would you like to add in format of FirstName_LastName or done when done\n")
        if(guest != "done"):
            date = input("What date were you invited MM/DD/YYYY: ")
            guest_list.append(guest)
            date_list.append(date)

# Merge sort for sorting lengths of guest names
def merge_sort(guest, date):
    if len(guest) > 1:
        mid = len(guest)//2
        
        L = guest[:mid]
        L2 = date[:mid]

        R = guest[mid:]
        R2 = date[mid:]

        merge_sort(L,L2)

        merge_sort(R,R2)
  
        i = j = k = 0

        while i < len(L) and j < len(R):
            if len(L[i]) < len(R[j]):
                guest[k] = L[i]
                date[k] = L2[i]
                i += 1
            else:
                guest[k] = R[j]
                date[k] = R2[j]
                j += 1
            k += 1

        while i < len(L):
            guest[k] = L[i]
            date[k] = L2[i]
            i += 1
            k += 1
  
        while j < len(R):
            guest[k] = R[j]
            date[k] = R2[j]
            j += 1
            k += 1

# Invitation + Date printing
def print_list(g,d):
    for i in range(len(g)):
        for j in range(len(g[i])):
            if((i+1)%2 == 0):
                print(f"{g[i][j]}'s invitation date was {d[i][j]} - Large Tag")
            else:
                print(f"{g[i][j]}'s invitation date was {d[i][j]} - Small Tag")

def work_ticket_7():
    compile_lists()
    merge_sort(guest_list,date_list)
    g = [guest_list[:int(len(guest_list)/2)],guest_list[int(len(guest_list)/2):]]
    d = [date_list[:int(len(date_list)/2)],date_list[int(len(date_list)/2):]]
    print_list(g,d)

# Program Starts Here 
def flow_control():
    user = input("Which program would you like to run (1-7): ")
    print()
    if(user == '1'):
        work_ticket_1()
    elif(user == '2'):
        work_ticket_2()
    elif(user == '3'):
        work_ticket_3()
    elif(user == '4'):
        work_ticket_4()
    elif(user == '5'):
        work_ticket_5()
    elif(user == '6'):
        work_ticket_6()
    elif(user == '7'):
        work_ticket_7()
    else:
        print("Not a valid input")
        flow_control()
        
flow_control()
    
                