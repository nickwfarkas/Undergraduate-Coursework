dct1 = {'Marty': 'Stepp', 'Stuart': 'Reges', 'Jessica': 'Wolk', 
 'Allison': 'Obourn', 'Hal': 'Perkins'}

dct2 = {'Kendrick': 'Perkins', 'Stuart': 'Reges', 'Jessica': 'Wolk', 
 'Bruce': 'Reges', 'Hal': 'Perkins'}

def is_unique(dct):
    dic_to_list = list(dct.values())
    for v in range(len(dic_to_list)):
        for i in range(len(dic_to_list)):
            if(i != v):
                if(dic_to_list[v] == dic_to_list[i]):
                    return False
    return True
print("dct1 = "+str(dct1))
print("dct1 - is_unique: "+str(is_unique(dct1))+"\n")
print("dct2 = "+str(dct2))
print("dct2 - is_unique: "+str(is_unique(dct2)))
