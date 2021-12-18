def russianPeasant(n: int, m: int): 
    result = 0
    while (m > 0):
        if (m & 1):
            result = result + n
        n = n << 1
        m = m >> 1
        print(f"N: {n} M: {m}")    
    return result

def main():
    n: int = int(input("Enter number a number: "))
    m: int = int(input(f"Enter a number to be multiplied by {n}: "))
    finalResult: int = russianPeasant(n, m)
    
    print(f"Final Result: {finalResult}")
    
main()