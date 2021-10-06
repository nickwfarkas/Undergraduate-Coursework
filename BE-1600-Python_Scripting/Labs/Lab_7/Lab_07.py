def main():
    correct = ['B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A']
    wrong = []
    f = open("student_solution.txt","r")
    temp = '0'
    i = 0
    isLine = True
    
    while(isLine):
        temp = f.readline().strip()
        if  temp == '':
            isLine = False
        elif correct[i] != temp:
            wrong.append(i+1)
        i+=1

    f.close()

    if len(wrong) > 5:
        print("Sorry, you did not pass the exam")
    else:
        print("Congradulations!! You passed the exam!")
        
    print("You answered "+str(20-len(wrong))+" and "+str(len(wrong))+" questions incorrectly")
    print("The questions you answered incorrectly are: ")
    for i in range(len(wrong)):
        print(str(wrong[i])+" ",end='')

main()

        
