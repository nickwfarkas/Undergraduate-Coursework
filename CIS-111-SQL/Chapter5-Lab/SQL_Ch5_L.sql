--q1
Select COUNT(DISTINCT(OrderID)) as 'Count', SUM(TaxAmount) as 'Total'
FROM Orders

--q2
SELECT 
CategoryName, 
COUNT(DISTINCT(ProductID)) as ProductCount, 
MAX(ListPrice) as GreatestPrice
FROM Categories, Products
GROUP BY CategoryName
ORDER BY COUNT(DISTINCT(ProductID))

--q3
SELECT 
((SUM(ItemPrice))*Quantity) as 'Original Sum', 
((SUM(DiscountAmount))*Quantity) as 'Discount Sum', 
EmailAddress
FROM Customers 
JOIN Orders On Customers.CustomerID = Orders.CustomerID 
JOIN OrderItems ON Orders.OrderID = OrderItems.OrderID
GROUP BY EmailAddress, Quantity
ORDER BY (COUNT(DISTINCT(ProductID)) - ((SUM(DiscountAmount))*Quantity)) DESC

--q4
SELECT EmailAddress, COUNT(*) as OrderCount, SUM((ItemPrice - DiscountAmount) * Quantity) as TotalAmount
FROM Customers 
JOIN Orders ON Customers.CustomerID = Orders.CustomerID 
JOIN OrderItems ON Orders.OrderID = OrderItems.OrderID
GROUP BY EmailAddress
HAVING COUNT(*) > 1
ORDER BY SUM(OrderItems.ItemPrice) DESC


--q5
SELECT EmailAddress, COUNT(*) as OrderCount, SUM((ItemPrice - DiscountAmount) * Quantity) as TotalAmount
FROM Customers 
JOIN Orders ON Customers.CustomerID = Orders.CustomerID 
JOIN OrderItems ON Orders.OrderID = OrderItems.OrderID
WHERE  ItemPrice > 400
GROUP BY EmailAddress
HAVING COUNT(*) > 1
ORDER BY SUM(OrderItems.ItemPrice)

--q6
SELECT ProductName, SUM((ItemPrice - DiscountAmount)*Quantity) as TotalAmount
FROM Products, OrderItems
GROUP BY ProductName WITH ROLLUP

--q7
SELECT EmailAddress, COUNT(DISTINCT ProductID) as 'Products Ordered'
FROM Customers 
JOIN Orders ON Customers.CustomerID = Orders.CustomerID
JOIN OrderItems ON OrderItems.OrderID = Orders.OrderID
GROUP BY EmailAddress
HAVING COUNT(DISTINCT ProductID) >  1