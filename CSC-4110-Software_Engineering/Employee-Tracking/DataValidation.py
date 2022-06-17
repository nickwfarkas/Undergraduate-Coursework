from Employee import Employee
import pydoc

'''
Validates user entered data for creating new employee.
Puts all errors in a array and return it
'''
def validate_employee(e: Employee, d: dict) -> list:
    list_of_errors = []
    
    if(not e.first_name.isalpha()):
        list_of_errors.append("First name should only contain letters")
    if(not e.last_name.isalpha()):
        list_of_errors.append("Last name should only contain letters")
    if(not e.age.isdigit()):
        list_of_errors.append("Age must be numeric only ex. 18")
    if(('@' not in e.email) or ('.' not in e.email)):
        list_of_errors.append("Email must be in format ex. email@website.com")
    if(not e.address.isdigit()):
        list_of_errors.append("Address must be numeric only ex. 1234")
    if(not e.street.isalnum):
        list_of_errors.append("Street names should only contain numbers and letters")
    if(not e.city.isalpha()):
        list_of_errors.append("City must not contain numeric values ex. Detroit")
    if(not e.state.isalpha or len(e.state) <= 2):
        list_of_errors.append("Please enter full state name ex. Michigan")
    if(not e.zipcode.isdigit()):
        list_of_errors.append("Zip code should be only a number ex. 12345")
    if(not e.dept.isalpha()):
        list_of_errors.append("Department must not contain numeric values ex. IT")
    if(not e.ssn.isdigit or len(e.ssn) != 9):
        list_of_errors.append("SSN should be numeric only and be 9 digits long ex. 123456789")
    if(e.employee_id in d.keys()):
        list_of_errors.append("Employee ID already exists please use a new one")
        
    return list_of_errors
    

    
    
    
    
    
    
    
