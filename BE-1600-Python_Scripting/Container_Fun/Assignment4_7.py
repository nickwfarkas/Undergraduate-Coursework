def remove_duplicates(original):
    i =  0
    j = len(original)-1
    while i < j:
        if(original[i] == original[i+1]):
            original.pop(i+1)
            j-=1
        else:
            i+=1
        
    return original

original = ['be', 'be', 'is', 'not', 'or', 'question', 'question', 'that', 'the', 'to', 'to', 'to', 'to']
print("original list: "+str(original))
print("list after removing duplicates: "+str(remove_duplicates(original)))
