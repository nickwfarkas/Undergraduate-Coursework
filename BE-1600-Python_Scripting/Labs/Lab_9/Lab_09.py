def locations():
    f = open("fruit.txt","r")
    fruit = {}
    j = 1
    temp = " "
    while(temp != ""):
        temp = f.readline()
        if(temp != ""):
            lineList = temp.split()
            for i in range(len(lineList)):
                if(lineList[i] in fruit.keys()):
                    fruit[lineList[i]].append(j)
                else:
                    fruit[lineList[i]] = [j]
            j+=1
    return fruit
    
def concordance(fruit):
    for k,v in fruit.items():
        print(str(k)+" appears in line(s) ",end='')
        for i in range(len(v)):
            print(str(v[i])+" ",end='')
        print()

concordance(locations())
            
    
    
    
