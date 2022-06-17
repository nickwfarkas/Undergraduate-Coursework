import random
def calcShipping(weight):
    if(weight > 0 and weight <= 2):
        print("Package weight: {0}\nShipping rate: ${1}\nShipping charge: ${2}".format(
              weight,"1.10",format(weight*1.1, '.2f')))
    elif(weight > 2 and weight <= 6):
        print("Package weight: {0}\nShipping rate: ${1}\nShipping charge: ${2}".format(
              weight,"2.20",format(weight*2.2, '.2f')))
    elif(weight > 6 and weight <= 10):
        print("Package weight: {0}\nShipping rate: ${1}\nShipping charge: ${2}".format(
              weight,"3.70",format(weight*3.7, '.2f')))
    elif(weight > 10 and weight <= 20):
        print("Package weight: {0}\nShipping rate: ${1}\nShipping charge: ${2}".format(
              weight,"4.50",format(weight*4.5, '.2f')))
    elif(weight > 20):
        print("Package weight: {0}\nThis package is over 20 pounds and cannot be shipped".format(weight))
    else:
        print("{0} is an invalid entry  please try again!".format(weight))

calcShipping(random.randrange(0,51))
