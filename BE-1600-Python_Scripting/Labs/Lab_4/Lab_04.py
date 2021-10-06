def replaceConst(s):
    newString = ''
    count = 0
    print("Old String: "+s)
    s = s[1:len(s)-1]
    s = s.upper()
    for c in s:
        if(c != 'A' and c != 'E' and c != 'I' and c != 'O' and c != 'U' and c != ' '):
            count+=1
            newString += '*'
        else:
            newString+=c
            
    print("New String: "+str(newString))
    print("Number of constant characters: "+str(count))

userInput = input("Enter a string: ")

replaceConst(userInput)
