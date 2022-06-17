import random
def main():
    rand = random.randrange(2, 10)
    print("Enter "+str(rand)+" values:")
    old_list =  []
    for i in range(0,rand):
        value = input("Enter value "+str(i+1)+": ")
        old_list.append(int(value))
    print("Old List: "+str(old_list))
    print("Collapse List: "+str(collapse(old_list)))
    
def collapse(old_list):
    new_list = []
    isOdd = False;
    if(len(old_list)%2 != 0):
        upper = len(old_list)-1
        isOdd = True
    else:
        upper = len(old_list)
    for i in range(0,upper,2):
        new_list.append(old_list[i]+old_list[i+1])
    if(isOdd):
        new_list.append(old_list[len(old_list)-1])
    return new_list

main()
