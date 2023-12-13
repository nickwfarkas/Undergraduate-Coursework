Nicholas Farkas

Inventory Management System

Required Elements:
- Strings
    -Throughout my project I used many string and even cases where I had to use the string libarys functionalities.
    -Ex. In the AutoPart class I used the string char indexing feature to grab a letter from input.

- Classes and Constructors
    -I have 5 classes and used separate compilation to create these classes.
    -My in my Products class there is a non-default constructor, in my Employees class I have both a non-default and a default constructor, and the rest of my program I had non default constructers mainly because I felt the information inputted there is only one required attribute the ID.
    -Ex. my classes names are Product, Service, Employee, BulkLiquid, AutoPart.

- Vectors
    - I have one main vector in my class and that is my "products" vector where I store all the inventory of my auto shop.
    - I inserted, accessed, deleted, pushed with my one products vector.

- Inheritance / Polymorphism and Composition/Aggregation/Initialization Lists
    -Inheritance: my BulkLiquid, AutoPart, and Service classes are children of my products class and took advantage of protected access modifiers.
    -Polymorphism: to be able to store all my products in one vector I used polymorphism with the Data type inside the container which is products and used many virtual classes.
    -Aggregation: I used aggregation in my Service object. I used the Employee class to handle Employees who can do said serves.
    -Initialization Lists: Since I used inheritance and polymorphism all through my program most constructors have a initialization list.

- Files
    - This program is file driven so the only way to input a new product is with a .txt file with a certain formatting. There are options to mass create employess when using the correct naming scheme for yor files or you can indiviually input files by typing their name in.
    - I included test data that you can reference and use.

- Exception Handing
    - Since we are mass including employees there are exceptions that will be thrown making it impossible to use but I handled them with a try catch system.

- Templates
    - The template I used may not be the best used case but performs its task perfectly outputting the correct data when the program ends

- Iterators
    - I used a set container to hold my VINs for car parts.
    - since I used a set I have to iterate through them to print out the data to the user.

- STL's
    - Like stated above I used a set container to hold my VINs.
    - No two vins can be the same so a set of strings works perfect for containing the vins making them easer to search and insert into than a vector or array.

-Git/GitHub
    - Throughout this project I have used git and github both in the command line and using Xcode
    - https://github.com/NicholasFarkas/Inventory_Management_System.git
    - Feel free to make a pull request :)

- Instructions for Use

    Inserting Data: There are two ways with .txt files only

        1. By using option 2 local files within the project can be entered manually by selecting option two at main menu. Just type the file name with no need for the .txt

        2. By using option 3 if you keep your naming scheme to Object Name (AutoPart, BulkLiquid, or Service) followed by an integer starting with 1 for example AutoPart1, AutoPart2, AutoPart3, BulkLiquid1, BulkLiquid2, BulkLiquid3, Service1, Service2, Service3. The program will autmatically take them from the file and create objects.

    Making Sales:

        3. By using option 1 you can never change the inventory directly but you can make sales which will automatically re order the product once the product goes out of stock by using option 1.

    Accessing Information:

        4. You can print all the data held within one product object by using option 4 by inputting a valid product ID.

        5. You can print all the data held within multiple product objects by using option 5 by inputting a valid Product type.

        6. You can print all the data held within all products object by using option 6.

    Manipulating Individual Products:

        7. You can delete a product by its ID by using option 7.

    Exiting Program:

        8. Will exit the program and print out how many Products are in your inventory.
