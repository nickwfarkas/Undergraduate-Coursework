# 1. Original Data
arr =[
    1121, "Jackie Grainger", 22.22,
    1122, "Jignesh Thrakkar", 25.25,
    1127, "Dion Green", 28.75, False,
    24.32, 1132, "Jacob Gerber",
    "Sarah Sanderson", 23.45, 1137, True,
    "Brandon Heck", 1138, 25.84, True,
    1152, "David Toma", 22.65, 
    23.75, 1157, "Charles King", False,
    "Jackie Grainger", 1121, 22.22, False,
    22.65, 1152, "David Toma"]

temp_id=""
temp_name=""
temp_pay=""
temp_mystery=""
employees= []

def is_whole_number(s: str):
    if('.' in s):
        return False
    else:
        return True

def is_id(s: str):
    if(s[0:2] == "11" and is_whole_number(s)):
        return True
    else:
        return False        

def is_name(s: str):
    if(' ' in s):
        return True
    else:
        return False

def is_pay(s: str):
    if(not is_whole_number(s) and s[-1].isnumeric()):
        return True
    else:
        return False

# 3 Removes duplicate if there is already one in list but saves most current
def check_duplicates(id,name,pay,additional):
    inserted = False
    for i in range(len(employees)):
        if(employees[i]["id"] == id):
            inserted = True
            employees.pop(i)
            employees.append({"id":id,"name":name,"pay":pay,"additional_1":additional})
    if(not inserted):
        employees.append({"id":id,"name":name,"pay":pay,"additional_1":additional})

# 2 Goes through each item in list and assigns them and puts them in a object form

for i in range(len(arr)):
    temp = str(arr[i])
    
    if(is_pay(temp)):
        if(temp_pay == ""):
            temp_pay = arr[i]
        else:
            check_duplicates(temp_id,temp_name,temp_pay,temp_mystery)
            temp_id=""
            temp_name=""
            temp_pay=arr[i]
            temp_mystery="" 
    elif(is_name(temp)):
        if(temp_name == ""):
            temp_name = arr[i]
        else:
            check_duplicates(temp_id,temp_name,temp_pay,temp_mystery)
            temp_id=""
            temp_name=arr[i]
            temp_pay=""
            temp_mystery=""
    elif(is_id(temp)):
        if(temp_id == ""):
            temp_id = arr[i]
        else:
            check_duplicates(temp_id,temp_name,temp_pay,temp_mystery)
            temp_id=arr[i]
            temp_name=""
            temp_pay=""
            temp_mystery_1=""
    else:
        temp_mystery = arr[i]
        
check_duplicates(temp_id,temp_name,temp_pay,temp_mystery)

# 4 creates new key and put a 1.3x salary for each employee
for e in employees:
    e["total_hourly_rate"] = e["pay"]*1.3
    
# 5 adds employee to list if employee makes more than 28.15 and less than 30.65
underpaid_salaries = []
for e in employees:
    if(e["total_hourly_rate"] <= 30.65 and e["total_hourly_rate"] >= 28.15):
        underpaid_salaries.append(e)

# 6 Checks each employees wages to put them in a raise bracket
company_raises = []
for e in employees:
    if(e["pay"] <= 24 and e["pay"] >= 22):
        company_raises.append({"name":e["name"],"raise":e["pay"]*.05})
    elif(e["pay"] <= 26 and e["pay"] > 24):
        company_raises.append({"name":e["name"],"raise":e["pay"]*.04})
    elif(e["pay"] <= 28 and e["pay"] > 26):
        company_raises.append({"name":e["name"],"raise":e["pay"]*.03})
    else:
        company_raises.append({"name":e["name"],"raise":e["pay"]*.02})

# 7 Prints out all items in all lists one at a time
print("Employees: ")
for e in employees:        
    print(e)
print("\nUnderpaid Salaries: ")
for e in underpaid_salaries:
    print(e)
print("\nCompany Raises: ")
for e in company_raises:
    print(e)

