## Work Ticket 1

def work_ticket_1():
    ## Part 1
    print('He said "I was hungry", and I responed "Me too!".')

    ## Part 2
    print("I've had this cold's symptoms for 3 days.")

    ## Part 3
    print("Line One\nLine Two\nLine Three")

    ## Part 4
    print("This is from this print statement, ",end='')
    print("This is from another")

## Work Ticket 2

def work_ticket_2():
    ## Part 1
    s = "string"
    print(len(s))

    ## Part 2
    c = "concatenation"
    print(s+c)

    ## Part 3
    print(f"{s} {c}")

    ## Part 4
    z = "bazinga"
    print(z[2:6])

## Work Ticket 3

def to_lower(s):
    for string in s:
        print(string.lower())

def to_upper(s):     
    for string in s:
        print(string.upper()) 

def remove_white_space(s: str) -> str:
    i = 0
    j = len(s)-1
    while(s[i].isspace() and (i < len(s))):
        i+=1
    while(s[j].isspace() and j >= 0):
        j-=1
    return s[i:j+1]    

def work_ticket_3():
    collection = ["Animals", "Badger", "Honey Bee", "Honey Badger"]

    ## Part 1      
    to_lower(collection)

    ## Part 2
    to_upper(collection)    

    string1 = " Filet Mignon"
    string2 = "Brisket "
    string3 = " Cheeseburger "

    ## Part 3
    print(remove_white_space(string1))
    print(remove_white_space(string2))
    print(remove_white_space(string3))

    string1 = "Becomes"
    string2 = "becomes"
    string3 = "BEAR"
    string4 = " bEautiful"

    ## Part 4
    print(string1.startswith("be"))
    print(string2.startswith("be"))
    print(string3.startswith("be"))
    print(string4.startswith("be"))

## Work Ticket 4

def work_ticket_4():
    ## Part 1
    s = "259"
    int_s = int(s)
    print(f"The product of 2 and {int_s} is {2*int_s}")

    ## Part 2
    float_s = float(s)
    print(f"The product of 2 and {float_s} is {2*float_s}")

    ## Part 3
    s = "259"
    i = 259
    print(str(259)+s)

    ## Part 4
    user_input1 = input("Enter a number: ")
    user_input2 = input("Enter another number: ")
    print(f"The product of {user_input1} and {user_input2} is {float(user_input1)*float(user_input2)}.")

    ## Part 5
    find_string = "NasfhuiwdfieifuhdasIHUDLfukIKUHFVBKVKBNickKJHDjkhSDjkhdsKJHDvskd"
    search_string = "Nick"
    print(f"{search_string} starts at index: {find_string.find(search_string)}")

def control_flow():
    user_input = input("Which work ticket would you like to run: ")
    if(user_input == "1"):
        work_ticket_1()
    elif(user_input == "2"):
        work_ticket_2()
    elif(user_input == "3"):
        work_ticket_3()
    elif(user_input == "4"):
        work_ticket_4()
        
control_flow()