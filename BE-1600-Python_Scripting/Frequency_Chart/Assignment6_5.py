import string

def frequency():
    letters = {}
    fileName = getFile()
    f = open(fileName,"r")
    
    statement = str(f.read())
    statement = removeAll(statement.lower())

    for i in range(len(statement)):
        if isinstance(letters.get(statement[i]),int):
            letters.update({statement[i]:letters.get(statement[i])+1})
        else:
            letters[statement[i]] = 1
    return letters

def getFile():
    fileName = input("Enter the file's name: ")
    if ".txt" not in fileName:
        fileName += ".txt"
    return fileName

def removeAll(statement):
    for c in statement:
        if c in str(string.punctuation)+str(string.digits)+' '+'\n':
            statement = statement.replace(c, "")
    return statement

def printHistogram(letters):
    print("Letter Count")
    for k,v in sorted(letters.items()):
        print(k.upper()+": "+str(v))
        
printHistogram(frequency())
