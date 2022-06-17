# Work Ticket 1

names = ['joe','tom','barb', 'sue', 'sally']
scores = [10,23,13,18,12]

def to_dict(names, scores):
    d ={}
    for i in range(len(names)):
        d[names[i]] = scores[i]
    return d

score_dict = to_dict(names,scores)

print(score_dict)

# Work Ticket 2

def retrive_score(score_dict):
    name = input("Enter the name you would like the score of: ")
    while(name != "q"): 
        try:
            print(score_dict[name])
        except KeyError:
            print("Student does not exist!")
        name = input("Enter the a name for their score or q to quit: ")

# Work Ticket 3

def insert(dict):
    t = ""
    while(t != "n"):
        name = input("Enter the name of the player: ")
        score = input(f"Enter {name}'s score: ")
        dict[name] = score
        t = input("Would you like to enter another players score (y or n): ")

# Work Ticket 4

s = list(score_dict.values())
s.sort()
print(s)

# Work Ticket 5

def delete(score_dict):
    name = input("Enter the name of the player to delete: ")
    try:
        score_dict.pop(name)
    except KeyError:
        print("Student does not exist!")

def control(score_dict):
    user_input = input("Please enter \n1: Add\n2: Delete\n3: Get\n4: Print All\n5: Quit\n")
    while(user_input != "5"):
        if(user_input == "1"):
            insert(score_dict)
        elif(user_input == "2"):
            delete(score_dict)
        elif(user_input == "3"):
            retrive_score(score_dict)
        elif(user_input == "4"):
            print(list(score_dict.values()))
        elif(user_input == "5"):
            pass
        else:
            print(f"{user_input} is not a valid please try again")
        user_input = input("Please enter \n1: Add\n2: Delete\n3: Get\n4: Print All\n5: Quit\n")
    print("You're final dictionary: ")
    print(score_dict)
        
control(score_dict)

