import random

def math_practice():
    sent = 1
    answer = 0
    i = 0
    c = 0
    while(int(sent) == 1):
        print("Welcome to Math Practice")
        print("Enter 1 for Addition")
        print("Enter 9 to exit the test")
        sent = input("Pick an item from the menu: ")
        if(int(sent) == 1):
            i+=1
            x = random.randrange(0, 10)
            y = random.randrange(0, 10)
            answer  = input("\nWhat is "+str(x)+" + "+str(y)+": ")

            if((x+y)==int(answer)):
                print("Your answer is correct\n")
                c+=1
            else:
                print("Your answer is incorrect\n")
    print("Number of questions "+str(i))
    print("Number of correct answers "+str(c))

math_practice()
