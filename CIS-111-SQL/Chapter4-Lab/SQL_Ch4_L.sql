--q1

SELECT CategoryName, ProductName, ListPrice
FROM Categories JOIN Products ON Categories.CategoryID = Products.CategoryID

--q2

SELECT FirstName, LastName, Line1, City, State, ZipCode
FROM Customers JOIN Addresses ON Customers.CustomerID =  Addresses.CustomerID
WHERE EmailAddress =  'allan.sherwood@yahoo.com'

--q3

SELECT FirstName, LastName, Line1, City, State, ZipCode
FROM Customers JOIN Addresses ON Customers.CustomerID = Addresses.CustomerID
WHERE ShippingAddressID = AddressID

--q4

SELECT LastName, FirstName, OrderDate, ProductName, ItemPrice, DiscountAmount,Quantity
FROM Customers as C
JOIN Orders as O on C.CustomerID = O.CustomerID 
JOIN OrderItems AS OI ON O.OrderID = OI.OrderID
JOIN Products AS P ON P.ProductID = OI.ProductID
ORDER BY LastName, OrderDate, ProductName

--q5

SELECT Products.ProductName, Products.ListPrice
FROM Products 
JOIN Products as P 
ON Products.ProductID <> P.ProductID and Products.ListPrice = P.ListPrice
Order BY ProductName

--q6

SELECT CategoryName, ProductID
FROM Categories Left JOIN Products ON Categories.CategoryID = Products.CategoryID
WHERE ProductID is null

--q7

SELECT 'Shipped' as ShipStatus, OrderID, OrderDate
FROM Orders
WHERE ShipDate is not NULL
UNION
SELECT 'Not Shipped' as ShipStatus, OrderID, OrderDate
FROM Orders
WHERE ShipDate is NULL
ORDER BY OrderDate


