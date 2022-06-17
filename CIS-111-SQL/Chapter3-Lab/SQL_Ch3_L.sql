--Q1
SELECT ProductCode, ProductName, ListPrice, DiscountPercent
From Products

--Q2
SELECT LastName + ', ' + FirstName as FullName
From Customers
Where LastName >= 'M' 
Order BY LastName


--Q3

SELECT ProductName, ListPrice, DateAdded
FROM Products
WHERE ((ListPrice > 500) And (ListPrice < 2000))
ORDER BY DateAdded DESC

--Q4

SELECT 
ProductName, 
ListPrice,  
DiscountPercent,
ListPrice * (DiscountPercent/100) as DiscountAmount,
ListPrice - (ListPrice * (DiscountPercent/100)) as DiscountPrice
From Products
ORDER BY DiscountPrice DESC

--Q5

SELECT
ItemID,
ItemPrice,
DiscountAmount,
Quantity,
ItemPrice * Quantity as PriceTotal,
DiscountAmount * Quantity as DiscountTotal,
(ItemPrice - DiscountAmount) * Quantity as ItemTotal
FROM OrderItems
WHERE (ItemPrice - DiscountAmount) * Quantity > 500
ORDER BY ItemTotal DESC

--Q6
SELECT OrderID, OrderDate, ShipDate
FROM Orders
WHERE ShipDate is null


