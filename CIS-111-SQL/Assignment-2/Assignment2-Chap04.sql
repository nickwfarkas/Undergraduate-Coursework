--q1
SELECT CompanyName, ContactName, ContactTitle, OrderID
FROM Customers LEFT JOIN Orders ON Customers.CustomerID = Orders.CustomerID
WHERE OrderID is null
Order by OrderID 

--q2
SELECT 
Employees.FirstName, 
Employees.LastName,
Employees.ReportsTo, 
Employees_1.FirstName + ' ' + Employees_1.LastName as 'Supervisor'
FROM Employees JOIN Employees as Employees_1 ON Employees.ReportsTo = Employees_1.EmployeeID

--q3
SELECT 
Customers.CustomerID, 
Customers.CompanyName, 
Employees.LastName, 
Orders.OrderDate, 
Products.ProductName, 
[Order Details].Quantity, 
Suppliers.CompanyName
FROM Customers JOIN Orders ON Customers.CustomerID = Orders.CustomerID
JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
JOIN [Order Details] ON Orders.OrderID = [Order Details].[OrderID]
JOIN Products ON [Order Details].[ProductID] = Products.ProductID
JOIN Suppliers ON Products.SupplierID = Suppliers.SupplierID
WHERE Employees.LastName = 'Buchanan' and Customers.CustomerID = 'SAVEA' and 
MONTH(Orders.OrderDate) = 07

--q4
SELECT ProductName, CompanyName,  CategoryName
FROM Orders JOIN [Order Details] ON Orders.OrderID = [Order Details].OrderID
JOIN Products ON Products.ProductID  = [Order Details].ProductID
JOIN Suppliers ON Suppliers.SupplierID = Products.SupplierID
JOIN Categories ON Categories.CategoryID = Products.CategoryID
WHERE Quantity >= 100 and 
(CategoryName = 'Beverages' or CategoryName = 'Meat/Poultry' or CategoryName = 'Dairy Products' or CategoryName = 'Seafood')
ORDER BY ProductName

--q5
SELECT 
(Products.UnitPrice  *  Quantity) * (1 - Discount) as ProductSale, 
'Discounted', 
[Order Details].ProductID, 
ProductName, 
[Order Details].UnitPrice,
Quantity
FROM [Order Details] JOIN Products ON Products.ProductID = [Order Details].[ProductID]
WHERE [Order Details].[Discount] > 0 and Quantity >= 100
UNION
SELECT 
(Products.UnitPrice * Quantity) as ProductSale, 
'No Discount', 
[Order Details].ProductID, 
ProductName, 
[Order Details].UnitPrice,
Quantity
FROM [Order Details] JOIN Products ON Products.ProductID = [Order Details].[ProductID]
WHERE Discount = 0 and Quantity >= 100

--q6
SELECT Distinct FirstName, LastName
FROM Employees JOIN Orders ON Employees.EmployeeID = Orders.EmployeeID
JOIN [Order Details] ON [Order Details].[OrderID] = Orders.OrderID
JOIN Products ON Products.ProductID = [Order Details].[ProductID]
WHERE ProductName = 'Boston Crab Meat' or ProductName = 'Chai' or ProductName = 'Sir Rodney''s scones'
ORDER BY LastName, FirstName

--q7
SELECT City FROM Employees
INTERSECT
SELECT City FROM Customers

--q8
SELECT LastName, FirstName, TerritoryDescription, [Order Details].UnitPrice, Quantity, ProductName, RegionDescription
FROM Employees
JOIN EmployeeTerritories ON Employees.EmployeeID = EmployeeTerritories.EmployeeID
JOIN Territories ON Territories.TerritoryID = EmployeeTerritories.TerritoryID
JOIN Orders ON Employees.EmployeeID = Orders.EmployeeID
JOIN [Order Details] ON Orders.OrderID = [Order Details].[OrderID]
JOIN Products ON [Order Details].[ProductID] = Products.ProductID
JOIN Region ON Territories.RegionID = Region.RegionID
WHERE TerritoryDescription = 'Atlanta' AND RegionDescription = 'Southern' AND [Order Details].UnitPrice <= 10 AND ProductName = 'Filo Mix' AND (Quantity BETWEEN 10 and 25)
