def swap_pairs(string):
    newString = ''
    for i in range(1,len(string),2):
        newString += string[i]+string[i-1]
    if(len(string)%2 != 0):
        newString+=string[len(string)-1]
    return newString

print(swap_pairs("The duck went over the 0"))
