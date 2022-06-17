--q1
SELECT * 
FROM [Order Details]
WHERE [Order Details].[OrderID] In(10251, 10251, 10258, 10266, 10371)
Order BY UnitPrice DESC

--q2
SELECT SupplierID, CompanyName, ContactName, ContactTitle, Country, Fax
FROM Suppliers
WHERE Country = 'USA' AND Fax is null

--q3
SELECT 
FirstName, 
LastName, 
(LastName + ', ' + FirstName) as 'Full Name', Title, BirthDate
FROM Employees
WHERE 
Title = 'Sales Representative' and 
(BirthDate Between '1-1-1960' and '12-31-1969')

--q4
SELECT CustomerID, OrderDate, Freight, ShipName, ShipAddress
FROM Orders
WHERE (CustomerID Like 'k%') and (Freight >= 100)

--q5
SELECT 
CustomerID, 
OrderDate, 
ShippedDate, 
DATEDIFF([DAY], OrderDate, ShippedDate) as 'Days to Process Order'
FROM Orders
WHERE 
(OrderDate Between '4-1-2017' and '4-15-2017') and 
DATEDIFF([DAY], OrderDate, ShippedDate) <= 10

--q6
SELECT ContactName, ContactTitle, Country
FROM Customers
WHERE Country In('Brazil', 'France') and ContactTitle Like '%manager%'

--q7
SELECT 
ProductName, 
ProductID, 
UnitPrice, 
(UnitPrice * 1.02) as '2%', (UnitPrice  * 1.03) as '3%'
FROM Products
WHERE (UnitPrice Between 10 and 30) and (UnitsInStock Between 40 and 100) and (CategoryID > 2)

--q8
SELECT Top(15) with Ties 
ProductID, 
ProductName, 
SupplierID, 
UnitPrice, 
UnitsInStock
FROM Products
ORDER BY UnitPrice DESC

--q9
SELECT * , ((UnitPrice * Quantity) * (1 - Discount)) as 'ProductSale'
FROM [Order Details]
WHERE 
(Quantity BETWEEN 20 and 40) and (Discount > 0)