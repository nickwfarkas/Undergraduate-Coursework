from cgitb import text
from copy import deepcopy
import json
import os
from pydoc import TextRepr
from datetime import date, datetime
import random
from tkinter import *
from uuid import uuid4
from PIL import ImageTk, Image

'''Global Data to be used across all functions and Windows'''
window = Tk(className = "- Drink Service -")
window.geometry("350x300")
window.columnconfigure(0, weight=1)
window.title("Agreement")


global_user = {}
images = {}
drink_data = []

def load_data():
    global drink_data
    global images
    f = open('drinks.json')
    drink_data = json.load(f)

    '''Converting images into a array'''
    for i in drink_data:
        if(i["file_name"] != ""):
            temp_path = "./Assets/"+i["file_name"]
        else:
            temp_path = "./Assets/drink.png"
        
        temp = Image.open(temp_path)
        temp = temp.resize((200,200))
        temp_image_tk = ImageTk.PhotoImage(temp)
        images[i["id"]] = temp_image_tk

'''Drink window where user chooses what drink to order'''   
def drink_window(t = None):
    load_data()
    
    if(t != None):
        t.destroy()
    top = Toplevel(window)
    top.geometry("800x800")
    top.title("- Drink Service -")
    top.columnconfigure(0, weight=1)
    top.columnconfigure(1, weight=1)
    top.columnconfigure(2, weight=1)
    welcome = Label(top,text="Welcome to the Drink Service")
    label = Label(
        top,
        text = "CopyRight 2022",
        foreground = "white",
        background = "blue"
    )
    create = Button(top, text="Create New Drink",command=lambda:create_drink(top))
    admin = Button(top, text="Admin Console",command=lambda:admin_startup())

    welcome.grid(column=1, row=1)
    label.grid(column=1, row=2)
    create.grid(column=0, row=3)
    admin.grid(column=2, row=3)
    
    button_list = []
    
    for i in range(1,len(images)+1):
        button_list.append(Button(top, image = images[str(i)], command=lambda id=i:take_action_on_drink(id,drink_data)))
    
    r = 4
    c = 0
    
    for i in range(len(button_list)):
        if(c >= 3):
            r += 2
            c = 0
        button_list[i].grid(column = c, row = r, padx = 5, pady = 5)
        Label(top,text = drink_data[i]["name"]).grid(column = c, row = r+1)
        c+=1
        
'''Allows user to Login, Display Drink Details, Sell a drink, or create a drink.'''
def take_action_on_drink(id, data):    
    top = Toplevel(window)
    top.geometry("230x100")
    top.title("Take Action")
    top.columnconfigure(0, weight=1)
    top.columnconfigure(1, weight=1)
    top.columnconfigure(2, weight=1)
    top.rowconfigure(0, weight=1)
    top.rowconfigure(1, weight=1)
    top.rowconfigure(2, weight=1)
    details = Button(top,text='Drink Details', font = 'Helvetica', foreground = 'Black', background = 'Grey', command =lambda:display_drink_details(data,id))
    details.grid(column=0,row=1)
    sale = Button(top,text='Drink Sale', font = 'Helvetica', foreground = 'Black', background = 'Grey', command =lambda:customer_detail(id))
    sale.grid(column=1,row=1)
    back = Button(top,text='Back', font = 'Helvetica', foreground = 'Black', background = 'Grey', command =lambda:top.destroy())
    back.grid(column=2,row=1)

def login():
    top = Toplevel(window)
    top.geometry("400x200")
    top.title("Login")
    top.columnconfigure(0, weight=2)
    Label(top, text= "User Name:", font=('Mistral 18 bold')).grid(column=0, row=0)
    user_name = Entry(top, width=20)
    user_name.grid(column=0, row=1)
    Label(top, text= "Password:", font=('Mistral 18 bold')).grid(column=0, row=2)
    password = Entry(top, width=20)
    password.grid(column=0, row=3)
    submit = Button(top,text="Submit",command=lambda:server_log_in(user_name.get(),password.get(),top))
    submit.grid(column=0, row=4)

'''Checks if user is logged in or not'''
def login_check():
    if(global_user == {}):
        top = Toplevel(window)
        top.columnconfigure(0, weight=1)
        top.columnconfigure(1, weight=1)
        top.columnconfigure(2, weight=1)
        top.geometry("300x100")
        top.title("Access Denied")
        l = Label(top, text = "You must login to use this feature")
        l.grid(column=1)
        e = Button(top,text="Okay",command=lambda:top.destroy())
        e.grid(column=1)
        return False
    else:
        return True

'''Logs into server returning user information'''
def server_log_in(user_name, password, t):
    file = open('employee.json')
    d = json.load(file)
    temp = {}
    global global_user
    top = Toplevel(window)
    top.columnconfigure(0, weight=1)
    top.columnconfigure(1, weight=1)
    top.columnconfigure(2, weight=1)
    top.geometry("200x100")
    if(len(global_user.keys()) == 0):
        for i in range(len(d)):
            if(d[i]["user_name"] == user_name):
                temp = d[i]
        if(len(temp.keys()) == 0):
            top.title("LOGIN FAILURE")
            l = Label(top, text = "Your user name is incorrect!")
            l.grid(column=1)
            e = Button(top,text="Okay",command=lambda:top.destroy())
            e.grid(column=1)
            log_event("User Name Failure",f"Username: {user_name} - Password: {password}")     
        elif(temp["password"] == password):
            global_user = temp
            log_event("Login Success","Username: "+user_name+" - Password: "+password)
            drink_window(t)
        else:
            top = Toplevel(window)
            top.columnconfigure(0, weight=1)
            top.columnconfigure(1, weight=1)
            top.columnconfigure(2, weight=1)
            top.geometry("200x100")
            top.title("LOGIN FAILURE")
            l = Label(top, text = "Your password is incorrect!")
            l.grid(column=1)
            e = Button(top,text="Okay",command=lambda:top.destroy())
            e.grid(column=1)
            log_event("Password Failure","Username: "+user_name+" - Password: "+password)
    

'''Logs multiple types of events around the application'''
def log_event(event: str = "General", details: str = "LOG", user:str = "None"):
    l = {}
    l["event"] = event
    l["details"] = details
    l["user"] = user
    l["date_time"] = str(datetime.now())
    file = open('logs.json')
    d = json.load(file)    
    d.append(l)
    
    with open('logs.json', 'w', encoding='utf-8') as json_file:
        json_file.write(json.dumps(d))
        
def log_sale(drink_id, age, user):
    l = {}
    l["transaction_id"] = str(uuid4())
    l["drink_id"] = drink_id
    l["user"] = user["name"]
    l["customer_age"] = age
    l["date_time"] = str(datetime.now())
    file = open('sales.json')
    d = json.load(file)    
    d.append(l)
    
    with open('sales.json', 'w', encoding='utf-8') as json_file:
        json_file.write(json.dumps(d))
    
def customer_detail(drink_id):
    top = Toplevel(window)
    top.geometry("400x200")
    top.title("Verification")
    top.columnconfigure(0, weight=2)
    Label(top, text= "Verify Customer Age", font=('Mistral 18 bold')).grid(column=0, row=0)
    age = Entry(top, width=20)
    age.grid(column=0, row=1)
    submit = Button(top,text="Submit",command=lambda:validate_customer(drink_id, top,age.get()))
    submit.grid(column=0, row=4)
    
def validate_customer(drink_id, t, age):
    global global_user
    t.destroy()
    if(age.isnumeric()):
        if(float(age) < 21):
            top = Toplevel(window)
            top.geometry("200x100")
            top.title("Alert")
            top.columnconfigure(0, weight=2)
            Label(top, text= "Do Not Serve!", font=('Mistral 18 bold')).grid(column=0, row=0)
            log_event("Underage", "Age: "+age, global_user)
        else:
            sell_drink(drink_id,age)
    else:
        top = Toplevel(window)
        top.geometry("200x100")
        top.title("Alert")
        top.columnconfigure(0, weight=2)
        Label(top, text= "Age must be numeric!", font=('Mistral 18 bold')).grid(column=0, row=0)

'''Displays drink details into a concise window'''
def display_drink_details(data, id):
    if(id!=0):
        top = Toplevel(window)
        top.columnconfigure(0, weight=1)
        top.columnconfigure(1, weight=1)
        top.columnconfigure(2, weight=1)

        top.geometry("500x250")
        top.title(data[int(id)-1]["name"])
        Label(top, image = images[str(id)]).grid(column=0)
        Label(top, text="Ingredient:",font=('Helvetica 18 bold')).grid(column=1, row=0)
        Label(top, text="Quantity:",font=('Helvetica 18 bold')).grid(column=2,row=0)
        row = 1
        for i in data[int(id)-1]["ingredients"]:
            row+=1
            Label(top, text=i["ingredient"]).grid(column=1, row=row)
            Label(top, text=i["oz"]).grid(column=2, row=row)

'''Checks if we have all ingredents to sell drinks and sells them if we do updating our inventory'''
def sell_drink(id, age, t = None):
    if(t != None):
        t.destroy()
    if(login_check() and id != 0):

        data = drink_data
        display_drink_details(data, id)
        
        ing = open('inventory.json')
        ingredients = json.load(ing)
        
        flag = False
        ingredient_owned = False
        for i in data[int(id)-1]["ingredients"]:
            for j in ingredients:
                if(i["ingredient"] == j["Ingredient"]):
                    ingredient_owned = True
                    q = float(j["OZ_Available"]) - float(i["oz"])
                    if(q >= 0):
                        j["OZ_Available"] = str(q)
                    else:
                        flag = True
                        top = Toplevel(window)
                        top.columnconfigure(0, weight=1)
                        top.columnconfigure(1, weight=1)
                        top.columnconfigure(2, weight=1)
                        top.geometry("400x100")
                        top.title("Quantities Exceeded")
                        l = Label(top, text = "There is not enough "+i["ingredient"]+" to make this drink!")
                        l.grid(column=1)
            if(not ingredient_owned):
                flag = True
                top = Toplevel(window)
                top.columnconfigure(0, weight=1)
                top.columnconfigure(1, weight=1)
                top.columnconfigure(2, weight=1)
                top.geometry("400x100")
                top.title("Quantities Exceeded")
                l = Label(top, text = "There is not enough "+i["ingredient"]+"to make this drink!")
                l.grid(column=1)
            else:
                ingredient_owned = False
        if(not flag):
            log_sale(id,age,global_user)
            with open('inventory.json', 'w', encoding='utf-8') as json_file:
                json_file.write(json.dumps(ingredients))

'''User Created Drinks that are validated'''    
def create_drink(t):
    if(login_check()):
        top = Toplevel(window)
        top.columnconfigure(0, weight=1)
        top.columnconfigure(1, weight=1)
        top.columnconfigure(2, weight=1)
        
        top.geometry("400x500")
        top.title("New Drink")
        Label(top, text= "Drink Creator", font=('Mistral 18 bold')).grid(column=1)
        Label(top, text= "No special Characters", font=('Mistral 12')).grid(column=1,pady=10)
        Label(top, text= "Name of Drink", font=('Mistral 18 bold')).grid(column=1)
        name = Entry(top, width=20)
        name.grid(column=1)
        Label(top, text= "Ingredients in a Comma Seperated List", font=('Mistral 18 bold')).grid(column=1)
        Label(top, text= "Comma Seperated List", font=('Mistral 12')).grid(column=1)
        ingredients = Entry(top, width=20)
        ingredients.grid(column=1)
        Label(top, text= "Ingredients measurements", font=('Mistral 18 bold')).grid(column=1)
        Label(top, text= "Comma Seperated List", font=('Mistral 12')).grid(column=1)
        measurements = Entry(top, width=20)
        measurements.grid(column=1)
        Label(top, text= "Instructions", font=('Mistral 18 bold')).grid(column=1)
        instructions = Entry(top, width=20)
        instructions.grid(column=1)
        Label(top, text= "Description", font=('Mistral 18 bold')).grid(column=1)
        description = Entry(top, width=20)
        description.grid(column=1)
        Label(top, text= "Exact File Path", font=('Mistral 18 bold')).grid(column=1)
        file = Entry(top, width=20)
        file.grid(column=1)
        
        submit = Button(top,text="Submit",command=lambda:validate(t, top,name.get(),ingredients.get(),measurements.get(),instructions.get(),description.get(),file.get()))
        submit.grid(column=1)
    
'''Validates user created drinks'''
def validate(main, t, name:str, ingredients, measurements, instructions, description, file):
    forbidden_symbols = "~`!@#$%^&*()-_=+][}{\|:;',<.>?/"+'"'
    numbers = "1234567890"
    errors = []
    for l in name:
        if(l in forbidden_symbols+numbers):
            errors.append("Name must be Alphabetic.")
    if(len(ingredients) == 0):
        errors.append("Double check ingredients and measurements.")
    if(len(file) > 0):
        try:
            open(file)
        except:
            errors.append("File doesnt exist.\nLeave blank for default.")
    if(len(errors) != 0):
        top = Toplevel(window)
        top.columnconfigure(0, weight=1)
        top.columnconfigure(1, weight=1)
        top.columnconfigure(2, weight=1)
        top.geometry("300x100")
        top.title("Errors in Drink Creation")
        for i in errors:
            Label(top, text = i).grid(column=1)
    else:
        send_drink(main, t, name, create_ingredient_list(ingredients,measurements), instructions, description, file)
       
'''Once drink is validated this sends it to the server''' 
def send_drink(main, t, name, ingredients, instructions, description, file):
    global drink_data
    drink = {}
    drink["id"] = str(len(drink_data)+1)
    drink["name"] = name
    drink["ingredients"] = ingredients
    drink["instructions"] = instructions
    drink["description"] = description
    if(len(file) > 0): 
        drink["file_name"] = file
    else:
        drink["file_name"] = "drink.png"
    
    drink_data.append(drink)
    with open('drinks.json', 'w', encoding='utf-8') as json_file:
        json_file.write(json.dumps(drink_data))
    top = Toplevel(window)
    top.columnconfigure(0, weight=1)
    top.columnconfigure(1, weight=1)
    top.columnconfigure(2, weight=1)
    top.geometry("300x100")
    top.title("Drink Created")
    Label(top, text = name+" was successfully created!").grid(column=1)
    t.destroy()
    main.destroy()
    drink_window()
    
'''Updates current windows'''
def restart(t):
    global window
    top = Toplevel(window)
    top.columnconfigure(0, weight=1)
    top.columnconfigure(1, weight=1)
    top.columnconfigure(2, weight=1)
    top.columnconfigure(3, weight=1)
    top.geometry("300x100")
    top.title("Changes Successful")
    Label(top, text="Please restart to see changes").grid(column=0,row=0)
    e = Button(top,text="Quit Program",command=lambda:quit_program())
    e.grid(column=1,row=1)
    e2 = Button(top,text="Okay",command=lambda:(t.destroy(),top.destroy()))
    e2.grid(column=2,row=1)

'''Creates ingredient object from two arrays'''
def create_ingredient_list(ingredients,measurements):
    i_list = ingredients.split(",")
    m_list = measurements.split(",")
    l = []
    
    if(len(i_list) == len(m_list)):
        for i in range(len(i_list)):
            if(m_list[i].isnumeric()):
                l.append({"oz": m_list[i], "ingredient": i_list[i]})
    return l

def mock_sales():
    num = input("Number of test sales records: ")
    for i in range(int(num)):
        log_sale(random.randint(1,len(drink_data)-1),random.randint(10,90),{ "name": "Test Data", "user_name": "test", "password": "test", "status": "test", "isAdmin": "0" })
        
def admin_startup():
    admin_choice = ""
    if(global_user["isAdmin"] == "1"):
        while(admin_choice != "4"):
            print("Welcome "+global_user["name"])
        
            admin_choice = input("\nWhat action would you like to take:\n1. Mock Sales Data\n2. Add Employee\n3. Update Inventory\n4. Quit Admin console\n")
        
            if(admin_choice == "1"):
                mock_sales()
            elif(admin_choice == "2"):
                add_employee()
            elif(admin_choice == "3"):
                update_inventory()
            elif(admin_choice != "4"):
                print(admin_choice+"is not a valid choice please try again!\n")  
    else:
        print("You do not have admin privileges. Please contact your leader.")
        
def add_employee():
    employee = {}
    employee["name"] = input("Please enter employee name: ")
    employee["user_name"] = input("Please enter employee username: ")
    employee["password"] = input("Please enter employee password: ")
    employee["status"] = "active"
    employee["isAdmin"] = input("Do they have admin privileges\n0: Yes 1: No\n")
    
    file = open("employee.json")
    d = json.load(file)
    
    d.append(employee)
    with open('employee.json', 'w', encoding='utf-8') as json_file:
        json_file.write(json.dumps(d))
        
def update_inventory():
    inv = {}
    inv["Ingredient"] = input("The Ingredient name: ")
    inv["OZ_Available"] = input("The quantity in oz: ")
    
    file = open("inventory.json")
    d = json.load(file)
    flag = False
    for i in range(len(d)):
        if(d[i]["Ingredient"].lower() == inv["Ingredient"].lower()):
            d[i]["OZ_Available"] = inv["OZ_Available"]
            flag = True
    
    if(not flag):
        d.append(inv)
            
    
    with open('inventory.json', 'w', encoding='utf-8') as json_file:
        json_file.write(json.dumps(d))


'''Closes and quits program'''
def quit_program():
    os._exit(0)

def open_popup():
    Label(window, text= 
          "If you press agree, you give consent to the\n"+ 
          "use of data you provide to be used in any\n"+
          "way the company sees fit. If you have any\n"+
          "questions are conecerns please contact HR.\n"+
          "Any data that is given is at will and we\n"+
          "are not responsible for security breaches.\n"+
          "User may not sell or distribute data without\n"+
          " the express consent of the contracting\n"+
          "company. The application goes through routine\n"+
          "data penetration tests but unaitherized tests\n"+
          "or uses is prohibited. These requirements are\n"+
          "elastic and may change over time as needed.",
          font=('Mistral 14'), justify=LEFT).grid(row=0)
    Button(window, text='Agree', font = 'Helvetica', foreground = 'Black', background = 'green', command = lambda:login()).grid(row=2)
    Button(window, text = "Deny", font = 'Helvetica', foreground= 'Black', background = 'red', command = quit_program).grid(row=3)
    
open_popup()

window.mainloop()
    
