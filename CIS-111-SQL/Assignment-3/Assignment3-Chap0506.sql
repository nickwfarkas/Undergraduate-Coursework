--CIS  111 Assignment 3

--Chapter 5

--q1
SELECT 
ShipCountry, 
COUNT(OrderID) as numOrders, 
MIN(OrderDate) as minDate, 
MAX(OrderDate) as maxDate
FROM Orders
WHERE ShipCountry = 'USA' OR ShipCountry = 'Mexico'
GROUP BY ShipCountry
ORDER BY ShipCountry

--q2
SELECT 
AVG((UnitPrice*Quantity)*(1-Discount)) as avgProductSales,
AVG(UnitPrice) as avgUnitPrice,
AVG(Quantity) as avgQuantity
FROM [Order Details]

--q3
SELECT 
AVG(Quantity), 
MAX(Quantity),
SUM([Order Details].UnitPrice*Quantity*(1-Discount)) as ProductSales
FROM Products 
JOIN Categories on Products.CategoryID = Categories.CategoryID
JOIN [Order Details] on Products.ProductID = [Order Details].[ProductID]
WHERE CategoryName = 'Beverages'
GROUP BY ProductName

--q4
SELECT COUNT(OrderID)
FROM Orders 
JOIN Employees ON Orders.EmployeeID = Employees.EmployeeID
JOIN EmployeeTerritories ON Employees.EmployeeID = EmployeeTerritories.EmployeeID
JOIN Territories ON EmployeeTerritories.TerritoryID = Territories.TerritoryID
GROUP BY Territories.TerritoryDescription
HAVING COUNT(OrderID) > 100 

--Chapter 6

--q5
SELECT Customers.CustomerID, CompanyName, Country
FROM Customers 
WHERE CustomerID NOT IN 
(
    SELECT CustomerID FROM Orders
)

--q6
SELECT Orders.OrderID, OrderDate, ProductID, Quantity, UnitPrice, Discount
FROM Orders 
JOIN [Order Details] ON Orders.OrderID = [Order Details].[OrderID]
WHERE Quantity > ALL(SELECT Quantity FROM [Order Details] WHERE ProductID = 11)

--q7
SELECT OrderID, CustomerID, OrderDate, ShippedDate, Freight
FROM Orders
WHERE Freight > 
(
    SELECT AVG(Freight)
    FROM Orders
)

--q8
SELECT Orders.CustomerID, MIN(OrderDate), MAX(OrderDate), COUNT(OrderID)
FROM Orders JOIN
(
    SELECT TOP 5 COUNT(OrderID) as 'count', CustomerID
    FROM Orders
    GROUP BY CustomerID
    Order BY COUNT(OrderID) DESC
) AS OrderCount
ON Orders.CustomerID = OrderCount.CustomerID
GROUP BY Orders.CustomerID
ORDER BY COUNT(OrderID) DESC
