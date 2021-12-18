-- Assignment 4

--q1 

IF OBJECT_ID('[dbo].[NFCustomers]', 'U') IS NOT NULL
DROP TABLE [dbo].[NFCustomers]
GO

IF OBJECT_ID('[dbo].[NFOrders]', 'U') IS NOT NULL
DROP TABLE [dbo].[NFOrders]
GO

SELECT *
INTO NFCustomers
FROM Customers

SELECT *
INTO NFOrders
FROM Orders

--q2

INSERT INTO [dbo].[NFCustomers]
(
 [CustomerID], [CompanyName], [ContactName],
 [ContactTitle], [Address], [City],
 [Region], [PostalCode], [Country],
 [Phone], [Fax]
)
VALUES
(
 'HFCC', 'Henry Ford Community College', 'Nick Farkas',
 'Student', '5101 Evergreen Rd', 'Dearborn',
 'MI', '48124', 'USA', 
 '(313) 845-9637', Null
)
GO

--q3

SELECT *
INTO NFUSACustomers
FROM Customers
WHERE 1 = 2

INSERT INTO NFUSACustomers
SELECT *
FROM NFCustomers

--q4

UPDATE [dbo].[NFOrders]
SET
    [EmployeeID] = 6
WHERE EmployeeID = 4
GO

--q5

UPDATE [dbo].[NFCustomers]
SET
    [CompanyName] = 'All Four Cheeses',
    [ContactName] = 'Bill Jackson',
    [ContactTitle] = 'Owner',
    [Phone] = '(503) 555-7890',
    [Fax] = '(503) 555-2323'
WHERE CustomerID = 'THEBI'
GO

--q6

UPDATE [dbo].[NFOrders]
SET
    [ShippedDate] = DATEADD([DAY], 3, ShippedDate)
WHERE CustomerID IN
(
    SELECT CustomerID
    FROM Customers
    WHERE ShipCountry = 'Germany'
)
GO

--q7

-- Delete rows from table '[NFOrders]' in schema '[dbo]'
DELETE NFOrders
FROM [dbo].[NFOrders] 
JOIN Customers ON NFOrders.CustomerID = Customers.CustomerID
WHERE PostalCode = '12209'
GO

--q8

DELETE [dbo].[NFOrders] FROM 
NFOrders JOIN Shippers ON NFOrders.ShipVia = Shippers.ShipperID
WHERE 
(OrderDate BETWEEN '10/10/2016' and '10/25/2016') and
(CompanyName = 'United Package')
GO

--q9

DELETE NFCustomers
FROM [dbo].[NFCustomers]
JOIN Orders ON NFCustomers.CustomerID = Orders.CustomerID
WHERE EXISTS
(
    SELECT OrderID
)
GO

--q10

DELETE FROM [dbo].[NFUSACustomers]
WHERE 1 <> 2
GO