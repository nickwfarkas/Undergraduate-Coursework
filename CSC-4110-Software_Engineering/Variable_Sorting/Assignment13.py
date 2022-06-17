class Integer(Exception):
    pass

class String(Exception):
    pass

class Float(Exception):
    pass

class VariableSort:
    string_values: list
    float_values: list
    integer_values: list
    
    def __init__(self) -> None:
        self.string_values = []
        self.float_values = []
        self.integer_values = []
                
    '''Raises data type exception according to type of parameter'''
    def insert(self, value):
        t = str(type(value))
        try:
            if(t == "<class 'int'>"):
                raise Integer
            elif(t == "<class 'str'>"):
                raise String
            elif(t == "<class 'float'>"):
                raise Float
            else:
                print("Not a valid value")
        except Integer:
            self.integer_values.append(value)
        except Float:
            self.float_values.append(value)
        except String:
                if(value.isalpha()):
                    self.string_values.append(value)
                else:
                    print("Value must only contain upper case and lower case letters")

def test():    
    vs = VariableSort()
    # Test 1 
    vs.insert(1)
    # Test 2 Raises Error 
    vs.insert("a1")
    # Test 3 
    vs.insert(1.0)
    # Test 4 Raises Error
    vs.insert([1,2,3])
    # Test 5 Raises Error
    vs.insert({"a":"b"})
    # Test 6
    vs.insert("a")

    print(vs.integer_values)
    print(vs.float_values)
    print(vs.string_values)
    
def main():
    vs = VariableSort()
    print('Enter "quit" to quit')
    s = input("Input a value: ")
    while(s.lower() != "quit"):
        if(s.isdigit()):
            vs.insert(int(s))
        elif('.' in s):
            vs.insert(float(s))
        else:
            vs.insert(s)
        s = input("Input a value: ")
        
    print(f"Integers: {vs.integer_values}")
    print(f"Float: {vs.float_values}")
    print(f"String: {vs.string_values}")
    
main()