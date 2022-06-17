x = 'acegikmoqsuwy'

y = '+bdfhj lnprtvxz'
print(len(x))

z = ''
j = 0
for i in range(len(x)):
    print(i)
    z+=x[i]
    if(y[j].isalpha()):
        z+=y[j]
        j+=1
    else:
        j+=1
        z+=y[j]
        j+=1
print(z)

x = 'This is a test.'
print(x * 3)
