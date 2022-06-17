class Employee:
    first_name: str
    last_name: str
    age: str
    email: str
    address: str
    street: str
    city: str
    state: str
    zipcode: str
    dept: str
    ssn: str
    employee_id: str
    
    def __init__(self, first_name, last_name, age, email, address, street, 
                 city, state, zipcode, dept, ssn, employee_id):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.email = email
        self.address = address
        self.street = street
        self.city = city
        self.state = state
        self.zipcode = zipcode
        self.dept = dept
        self.ssn = ssn
        self.employee_id = employee_id