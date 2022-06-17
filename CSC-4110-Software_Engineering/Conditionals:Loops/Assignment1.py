## Problem ONE
def ticket_validation(response: str) -> bool:
    if "here" in response.lower():
        return True
    else:
        return False

def usher_desk():
    user_input = ""
    while(not ticket_validation(user_input)):
        user_input = input("Tickets, Please.\n")
        print()

## Problem TWO

def pyramid(peak_height: int):
    for i in range(1,peak_height+1):
        print("*"*i)
    for i in range(peak_height-1,0,-1):
        print("*"*i)

## Problem THREE (Copied from IDLE)

for i in range(1,11):
    print("*"*i)
    if(i == 10):
        for j in range(9,0,-1):
            print("*"*j)

## CONTROL
def main():
    user_input = input("Which program would you like to run\n1 - Usher Desk\n2 - Pyramid\n")
    if(user_input == "1"):
        usher_desk()
    elif(user_input == "2"):
        pyramid(10)
    else:
        print(f"\n{user_input} is an invalid input please enter 1 or 2\n")
        main()
main() 