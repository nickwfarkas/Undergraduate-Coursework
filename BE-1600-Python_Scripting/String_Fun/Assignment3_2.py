def repl(inital, rep):
    statement = ''
    print(inital+" -> ",end='')
    for i in range(rep):
        statement = statement+inital
    return statement

print(repl("hello",120))
