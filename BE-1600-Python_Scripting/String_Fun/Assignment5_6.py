def frequency():
    letters = {}

    statement = input("Enter a string: ")
    statement = removeSpace(statement.lower())

    for i in range(len(statement)):
        if isinstance(letters.get(statement[i]),int):
            letters.update({statement[i]:letters.get(statement[i])+1})
        else:
            letters[statement[i]] = 1
    return letters

def removeSpace(string): 
    return string.replace(" ", "")

def printHistogram(letters):
    for k,v in sorted(letters.items()):
        print(k.upper()+" ",end='')
        for i in range(v):
            print("* ",end='')
        print('')

printHistogram(frequency())
