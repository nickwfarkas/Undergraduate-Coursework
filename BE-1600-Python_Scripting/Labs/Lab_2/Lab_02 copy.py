def funcOne(firstNum, secondNum):
    print("print Numbers:")
    for i in range(firstNum, secondNum, 1):
        print(str(i)+" ", end='')
    print('\n')
    
def funcTwo(firstNum, secondNum):
    if((firstNum%2) == 0):
        firstNum+=1
    print("print odd Numbers:")
    for i in range(firstNum, secondNum, 2):
        print(str(i)+" ", end='')
    print('\n')

def funcThree(firstNum, secondNum):
    if((firstNum%2) == 0):
        firstNum+=1
    print("print sum of the odd Numbers:")
    sumOfOdd=0
    for i in range(firstNum, secondNum+1, 2):
        sumOfOdd+=i
    print(sumOfOdd, end='\n\n')

def funcFour(firstNum, secondNum):
    if((firstNum%2) == 0):
        firstNum+=1
    sumOfOdd=0
    print("print sum of the square of the odd Numbers:")
    for i in range(firstNum, secondNum+1, 2):
        sumOfOdd+=(i**2.0)

    print(sumOfOdd,end='\n\n')

def funcFive():
    print("print numbers and their squares:")
    for i in range(1,11):
        print(str(i)+" "+str(i**2))

funcOne(3,12)
funcTwo(3,12)
funcThree(3,12)
funcFour(3,12)
funcFive()
