import json
import os
from random import *
from tkinter import *
import uuid

window = Tk(className = "- Book Tracker -")
window.geometry("400x150")

db = []

file = open("db.json")
db = json.load(file)

'''Main Control'''

def main():
    Button(window,text='Show all books', font = 'Helvetica', foreground = 'Black', background = 'Grey',command =lambda:show_all_books()).pack()
    Button(window,text='Add a book', font = 'Helvetica', foreground = 'Black', background = 'Grey',command =lambda:add_a_book()).pack()
    Button(window,text='Edit a book', font = 'Helvetica', foreground = 'Black', background = 'Grey',command =lambda:edit_a_book()).pack()
    Button(window,text='Remove a book', font = 'Helvetica', foreground = 'Black', background = 'Grey',command =lambda:remove_a_book()).pack()
    Button(window,text='Generate fake books', font = 'Helvetica', foreground = 'Black', background = 'Grey',command =lambda:generate_books()).pack()

'''Searching all db for book given ISBN'''

def search(ISBN: str):
    for i in range(len(db)):
        if(db[i]["ISBN"] == ISBN):
            return i
    return -1

'''Generate n number of fake books'''

def generate_books():
    amount_of_books = input("How many books would you like to generate: ")
    file = open("db.json")
    local_db = json.load(file)
    for i in range(int(amount_of_books)):
        local_db.append(
            {
                "ISBN": str(uuid.uuid4()),
                "Title": str(randint(9999,99999)), 
                "Author": str(randint(9999,99999))+" "+str(randint(9999,99999)), 
                "Purchased": randint(0,1000), 
                "Inventory": randint(0,100), 
                "Price": random()*20
            }
        )
    with open('db.json', 'w', encoding='utf-8') as json_file:
        json_file.write(json.dumps(local_db))
    print(f"{amount_of_books} books added!")

'''Print all books in db'''

def show_all_books():
    file = open("db.json")
    local_db = json.load(file)
    
    for book in local_db:
        print(f"Book Title: {book['Title']}")
        print(f"Author: {book['Author']}")
        print(f"ISBN: {book['ISBN']}")
        print(f"Number of copies purchased: {book['Purchased']}")
        print(f"Number of copies not checked out: {book['Inventory']}")
        print("Retail Price: %.2f\n"%book['Price'])

'''Add a new book to db'''
    
def add_a_book():
    global db
    flag = False
    title = input("Enter the Title: ")
    isbn = input("Enter ISBN: ")
    if(not isbn.isnumeric()):
        flag = True
        print("ISBM can only contain numbers")
    author = input("Enter the Author: ")
    if(not author.isalpha()):
        flag = True
        print("Author can only contain letters")
    numCopies = input("Enter the number of copies: ")
    if(not numCopies.isdigit()):
        print("Copies can only be a number")
        flag = True
    price = input("Enter the number of copies: ")
    if(not numCopies.isdecimal()):
        print("Price must include a decimal point")
        flag = True
    if(not flag):
        db.append(
            {
                "ISBN": isbn,
                "Title": title, 
                "Author": author, 
                "Purchased": 0, 
                "Inventory": int(numCopies), 
                "Price": float(price)
            }
        )
        with open('db.json', 'w', encoding='utf-8') as json_file:
            json_file.write(json.dumps(db))
        print("Book added!")
    
'''Edit existing book in db'''
def edit_a_book():
    isbn = input("Enter the ISBN to edit: ")
    index = search(isbn)
    if(index != -1):
        p = input("Would you like to change the 1. ISBN\n2. Title\n3. Author\n4. Update Sales\n5. Update Inventory\n6. Update Price")
        if(p == "1"):
            change = input("What would you like to change it to: ")
            if(not change.isnumeric()):
                flag = True
                print("ISBM can only contain numbers")
            if(not flag):
                db[index]["ISBN"] = change
        elif(p == "2"):
            change = input("What would you like to change it to: ")
            db[index]["Title"] = change
        elif(p == "3"):
            change = input("What would you like to change it to: ")
            if(not change.isalpha()):
                flag = True
                print("Author can only contain letters")
            if(not flag):
                db[index]["Author"] = change
        elif(p == "4"):
            change = input("What would you like to change it to: ")
            if(not change.isnumeric()):
                flag = True
                print("Purchase can only contain numbers")
            if(not flag):
                db[index]["Purchased"] = int(change)
        elif(p == "5"):
            change = input("What would you like to change it to: ")
            if(not change.isdigit()):
                flag = True
                print("Inventory can only contain numbers")
            if(not flag):
                db[index]["Inventory"] = int(change)
        elif(p == "6"):
            change = input("What would you like to change it to: ")
            if(not change.isdecimal()):
                flag = True
                print("Price can only contain numbers")
            if(not flag):
                db[index]["Price"] = float(change)
        else:
            print("Not a valid choice!")
        
        with open('db.json', 'w', encoding='utf-8') as json_file:
            json_file.write(json.dumps(db))
        print("Book edited!\n")
    else:
        print("Book doesn't exist!")
    
'''Remove Existing book from db'''
def remove_a_book():
    isbn = input("Enter the ISBN to delete: ")
    index = search(isbn)
    if(index != -1):
        db.pop(index)
        print("Book Deleted!")
        with open('db.json', 'w', encoding='utf-8') as json_file:
            json_file.write(json.dumps(db))
    else:
        print("Book doesn't exist!")
    
main()

window.mainloop()