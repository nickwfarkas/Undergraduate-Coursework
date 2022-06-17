def double_list(originalList):
    newList = []
    for i in range(len(originalList)):
        for j in range(2):
            newList.append(originalList[i])
    return newList
originalList = ['how', 'are', 'you']
print("original list: "+str(originalList))
print("double list: "+str(double_list(originalList)))
