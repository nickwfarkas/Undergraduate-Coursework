dict = {'a':15 , 'c':35, 'b':10}

def print_all_keys(dict):
    print("Keys: ",end='')
    for k in dict:
        print(k,end=' ')
    print('')

print_all_keys(dict)

def print_all_values(dict):
    print("Values: ",end='')
    for v in dict.values():
        print(v,end=' ')
    print('')
    
print_all_values(dict)

def print_all_pairs(dict):
    print("Key-Value pairs: ")
    for k,v in dict.items():
        print(k, v)
    
print_all_pairs(dict)

def print_all_pairs_key(dict):
    print("\nKey-Value pairs- sorted by key ")
    for k,v in sorted(dict.items()):
        print(k,v)
    
print_all_pairs_key(dict)

def print_all_pairs_value(dict):
    print("\nKey-Value pairs- sorted by value ")
    for k,v in sorted(dict.items(),key=lambda p:p[1]):
        print(k,v)
    
print_all_pairs_value(dict)




