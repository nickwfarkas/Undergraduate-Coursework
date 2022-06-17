import os
from random import *
from tkinter import *
import pickle
from Employee import Employee
from DataGeneration import *
from DataValidation import *

window = Tk(className = "Employee Tracker")
window.geometry("400x150")

'''Returns Current Dictionary acting as Db'''
def getData(fileName: str) -> dict:
    file = open(fileName, 'rb')
    localdata: dict = {}
    try:
        localdata = pickle.load(file)
    except EOFError:
        print("Empty")
        file.close()
        return {}
    file.close()
    return localdata

'''Displays the whole Db for internal testing usage'''
def displayDB() -> None:
    db: dict = getData("SampleData")
    print(db)
    for item in db.values():
        print(f"Name: {item.first_name}")
        print(f"Age: {item.age}")
        print(f"Email: {item.email}")
        print(f"Address: {item.address}")
        print(f"Street: {item.street}")
        print(f"City: {item.city}")
        print(f"State: {item.state}")
        print(f"Zipcode: {item.zipcode}")
        print(f"Department: {item.dept}")
        print(f"SSN: {item.ssn}")
        print(f"Employee ID: {item.employee_id}\n")

'''Opens window and prompts user for a Employee ID'''
def get_record(db: dict):
    top = Toplevel(window)
    top.geometry("400x100")
    top.title("Search Employee Database")
    Label(top, text= "Employee ID", font=('Mistral 18 bold')).pack()
    id = Entry(top, width=20)
    id.pack()
    
    Button(top,text='Submit', font = 'Helvetica', foreground = 'Black', background = 'Grey',command =lambda:record_helper(db,id)).pack()
    
'''
Opens window 
If id doesnt exist it prints that
If id does exist it prints all the information of the employee
'''
def record_helper(db: dict, id: Entry):
    top = Toplevel(window)
    top.geometry("400x300")
    top.title("Employee: "+id.get())
    record: Employee
    isEmployee = True
    try:
        record = db[id.get()]
    except KeyError:
        Label(top, text= "Employee "+id.get()+" does not exist.", font=('Mistral 18 bold')).pack()
        isEmployee = False

    if(isEmployee):
        Label(top, text= "Employee: "+id.get(), font=('Mistral 18 bold')).pack()
        Label(top, text= "Name: "+record.first_name+" "+record.last_name, font=('Mistral 12')).pack()
        Label(top, text= "Age: "+record.age, font=('Mistral 12')).pack()
        Label(top, text= "Email: "+record.email, font=('Mistral 12')).pack()
        Label(top, text= "Address: "+record.address, font=('Mistral 12')).pack()
        Label(top, text= "Street: "+record.street, font=('Mistral 12')).pack()
        Label(top, text= "City: "+record.city, font=('Mistral 12')).pack()
        Label(top, text= "Zip Code: "+record.zipcode, font=('Mistral 12')).pack()
        Label(top, text= "State: "+record.state, font=('Mistral 12')).pack()
        Label(top, text= "Department: "+record.dept[0:2]+"-"+record.dept[3:5]+"-"+record.dept[6:8], font=('Mistral 12')).pack()
        Label(top, text= "Social Security Number: "+record.ssn, font=('Mistral 12')).pack()
        
                
'''Adds employee to Db'''

def LocalAddEmployeeData(employee: Employee) -> None:
    local_data: dict
    local_data = getData("SampleData")
    
    file = open('SampleData', 'wb')

    local_data[employee.employee_id] = employee
    pickle.dump(local_data, file)
    
    print("Employee Added!")
    file.close()
    
'''Window prompts user for employee information'''
def createNewEmployee(d: dict) -> None:
    top = Toplevel(window)
    top.geometry("400x1000")
    top.title("New Employee")
    Label(top, text= "First Name", font=('Mistral 18 bold')).pack()
    first_name = Entry(top, width=20)
    first_name.pack()
    Label(top, text= "Last Name", font=('Mistral 18 bold')).pack()
    last_name = Entry(top, width=20)
    last_name.pack()
    Label(top, text= "Age", font=('Mistral 18 bold')).pack()
    age = Entry(top, width=20)
    age.pack()
    Label(top, text= "Email", font=('Mistral 18 bold')).pack()
    email = Entry(top, width=20)
    email.pack()
    Label(top, text= "Address", font=('Mistral 18 bold')).pack()
    address = Entry(top, width=20)
    address.pack()
    Label(top, text= "Street", font=('Mistral 18 bold')).pack()
    street = Entry(top, width=20)
    street.pack()
    Label(top, text= "City", font=('Mistral 18 bold')).pack()
    city = Entry(top, width=20)
    city.pack()
    Label(top, text= "State", font=('Mistral 18 bold')).pack()
    state = Entry(top, width=20)
    state.pack()
    Label(top, text= "Zip Code", font=('Mistral 18 bold')).pack()
    zipcode = Entry(top, width=20)
    zipcode.pack()
    Label(top, text= "Department", font=('Mistral 18 bold')).pack()
    dept = Entry(top, width=20)
    dept.pack()
    Label(top, text= "Social Secuirity Number", font=('Mistral 18 bold')).pack()
    ssn = Entry(top, width=20)
    ssn.pack()
    Label(top, text= "Employee ID", font=('Mistral 18 bold')).pack()
    employee_id = Entry(top, width=20)
    employee_id.pack()

    Button(top,text='Submit', font = 'Helvetica', foreground = 'Black', background = 'Grey', 
                    command =lambda:create_helper(
                        top, first_name, last_name, age, email, address,
                            street, city, state, zipcode, dept,
                            ssn, employee_id, d
                        )).pack()

'''
checks inputted information for errors and opens a new window with those errors
or sends imported data to Db
'''
def create_helper(
    top: Toplevel, first_name: Entry, last_name: Entry, age: Entry, email: Entry, address: Entry,
    street: Entry, city: Entry, state: Entry, zipcode: Entry, dept: Entry,
    ssn: Entry, employee_id: Entry, d: dict
    ):
    
    e = Employee(
        first_name.get().upper(), last_name.get().upper(), age.get(),
        email.get(), address.get(), street.get().upper(), city.get().upper(),
        state.get().upper(), zipcode.get(), dept.get().upper(), ssn.get(), employee_id.get()
        )
    
    errors = validate_employee(e,d)
    if(len(errors) == 0):
        LocalAddEmployeeData(e)
        top.destroy()
    else:
        top = Toplevel(window)
        top.geometry("400x300")
        top.title("New Employee")
        for e in errors:
            Label(top, text= e, font=('Mistral 12')).pack()

'''Initial popup agreeing to terms'''
def open_popup():
    top = Toplevel(window)
    top.geometry("400x400")
    top.title("Agreement")
    Label(top, text= 
          "If you press agree, you give consent\n" 
          "to the use of data you provide to be\n"+
          "used in any way the company sees fit.\n"+
          "If you have any questions are conecerns\n"+
          "please contact HR. Any data that is given\n"+
          "is at will and we are not responsible for\n"+
          "security breaches. user may not sell or\n"+
          "distribute data without the express consent\n"+
          "of umbrella company. This program goes through\n"+
          "routine data penetration tests but unaitherized\n"+
          "tests or uses is prohibited. These requirements\n"+
          "are elastic and may change over time as needed.",
          font=('Mistral 14')).place(x=30,y=10)
    Button(top, text='Agree', font = 'Helvetica', foreground = 'Black', background = 'green', command = lambda:main_window(top)).place(x=150,y=300)
    Button(top, text = "Deny", font = 'Helvetica', foreground= 'Black', background = 'red', command = quit_program).place(x=200,y=300)

'''Main window where user chooses what to do'''   
def main_window(t: Toplevel):
    t.destroy()
    welcome = Label(text="Welcome to the Employee Database")
    label = Label(
        text = "CopyRight 2022",
        foreground = "white",
        background = "blue"
    )
    Display_Button = Button(text='Get Record', font = 'Helvetica', foreground = 'Black', background = 'Grey', command =lambda:get_record(getData("SampleData")))
    Add_Button = Button(text = "Add Record", font = 'Helvetica', foreground= 'Black', background = 'Grey', command = lambda:createNewEmployee(getData("SampleData")))
    Test_Data_Button = Button(text = "Admin", font = 'Helvectia', foreground = 'Black', background = 'blue', command= lambda:test_data_generator("SampleData"))
    welcome.pack();label.pack();Display_Button.pack();Add_Button.pack();Test_Data_Button.pack()

'''Closes and quits program'''
def quit_program():
    os._exit(0)

open_popup()

window.mainloop()