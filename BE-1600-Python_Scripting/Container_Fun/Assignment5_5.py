tup1 = (1,2)
tup2 = (3,4)

def add_tuple(tup1, tup2):
    num = (tup1[0]*tup2[1])+(tup1[1]*tup2[0])
    den = tup1[1]*tup2[1]
    tup = (num,den)
    print(str(tup1)+" + "+str(tup2)+" = "+str(tup))

add_tuple(tup1,tup2)

def multiply_tuple(tup1, tup2):
    num = tup1[0]*tup2[0]
    den = tup1[1]*tup2[1]
    tup = (num,den)
    print(str(tup1)+" * "+str(tup2)+" = "+str(tup))

multiply_tuple(tup1, tup2)
