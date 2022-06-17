def frequency():
    letters = []

    statement = input("Enter a string: ")
    statement = removeSpace(statement.lower())

    letters.append([ord(statement[0]),0])
    
    for i in range(len(statement)):
        for l in range(len(letters)):
            if(ord(statement[i]) == letters[l][0]):
                letters[l][1]+=1
            elif(l == len(letters)-1):
                letters.append([ord(statement[i]),1])

    return letters

def findGreatest(letters):
    greatPos = []

    greatPos.append(0)

    for i in range(len(letters)):
        if(letters[i][1] > letters[greatPos[0]][1]):
            greatPos.clear()
            greatPos.append(i)
        elif(letters[i][1] == letters[greatPos[0]][1]):
            if(i == 0):
                greatPos.clear()
            greatPos.append(i)
    if(len(greatPos) == 1):        
        print("The character that appears most frequently in the string is "+
            chr(letters[greatPos[0]][0]).upper())
    else:
         print("The characters that appears most frequently in the string is "
               ,end='')
         for i in range(len(greatPos)):
            if(i != len(greatPos)-1):
                 print(chr(letters[greatPos[i]][0]).upper()+", ",end='')
            else:
                 print(chr(letters[greatPos[i]][0]).upper())                
    
def removeSpace(string): 
    return string.replace(" ", "")

findGreatest(frequency())
