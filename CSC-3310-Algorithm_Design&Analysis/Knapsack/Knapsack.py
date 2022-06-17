import random

def bit(num, bit):
    temp = (1 << bit)
    temp = temp & num
    return 1 if temp else 0

def knapsack(items,rows,capacityValue):
    topSet = []
    topValue = -1
    for i in range(1, 2 ** rows):
        set = []
        for j in range(0, rows):
            if bit(i, j) == 1:
                set.append(items[j])
        v = getTotalValue(set,capacityValue)
        if(topValue < v):
            topSet = set
            topValue = v
    return topSet            
    
def getTotalValue(set,capacityValue):
    w = 0
    v = 0
    validity = "Invalid"
    for i in range(len(set)):
        w += set[i][0]
        v += set[i][1]
    if(w <= capacityValue):
        validity = "Valid" 
    else: 
        v = -1 
    print(f"{set} is {validity}")
    return v
    
def generateItems(rows):
    items = []
    for i in range(rows):
        items.append((random.randrange(1,11),random.randrange(1,7)))
    capacityValue = random.randrange(8,14)
    return [capacityValue,items]

rows = 4
items = generateItems(rows)
print(f"\nCapacity Value: {items[0]}\nItems: {items[1]}\n")
print(knapsack(items[1],rows,items[0]))
