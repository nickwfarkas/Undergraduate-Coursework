--q1
SELECT DISTINCT CategoryName
FROM Categories
WHERE Categories.CategoryID IN
(
    SELECT Products.CategoryID
    FROM Products
)
ORDER BY CategoryName

--q2
SELECT ProductName, ListPrice
FROM Products
WHERE ListPrice >
(
    SELECT AVG(ListPrice) FROM Products
)

--q3
SELECT CategoryName
FROM Categories
WHERE NOT EXISTS
(
    SELECT productID
    FROM Products
    WHERE Products.CategoryID = Categories.CategoryID
)

--q4
SELECT Customers.EmailAddress, MAX(Calculate.[Order Total])
FROM Customers JOIN
(
    SELECT EmailAddress, OrderItems.OrderID, SUM((ItemPrice - DiscountAmount)* Quantity) as 'Order Total'
    FROM Customers
    JOIN Orders ON Customers.CustomerID = Orders.CustomerID
    JOIN OrderItems ON Orders.OrderID = OrderItems.OrderID
    GROUP BY EmailAddress, OrderItems.OrderID
) as 
Calculate ON Customers.EmailAddress = Calculate.EmailAddress
GROUP BY Customers.EmailAddress

--q5
SELECT ProductName, DiscountPercent
FROM Products
WHERE DiscountPercent NOT IN
(
    SELECT DiscountPercent
    FROM Products
    GROUP BY DiscountPercent
    HAVING COUNT(DiscountPercent) > 1
)
ORDER BY ProductName

--q6
SELECT EmailAddress, OrderID, OrderDate
FROM Customers
JOIN Orders ON Customers.CustomerID = Orders.CustomerID
WHERE OrderDate IN
(
    SELECT MIN(OrderDate)
    FROM Orders
    GROUP BY CustomerID
)
