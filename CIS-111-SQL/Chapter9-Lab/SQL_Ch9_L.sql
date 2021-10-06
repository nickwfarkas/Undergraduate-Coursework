--Ch 9 Practice Lab

--q1
SELECT 
ListPrice, 
DiscountPercent, 
Round((ListPrice * DiscountPercent), 2) as 'DiscountAmount'
FROM Products

--q2
SELECT 
OrderDate, 
YEAR(OrderDate) as 'Year', 
DAY(OrderDate) as 'Day', 
DATEADD(DAY, 30, OrderDate) as 'Plus 30 Days'
FROM Orders

--q3
SELECT
CardNumber,
LEN(CardNumber) as  'Length',
RIGHT(CardNumber, 4) as 'Last 4',
CONCAT('XXXX-XXXX-XXXX-', RIGHT(CardNumber, 4)) as 'Secret'
FROM Orders

--q4
SELECT
OrderID,
OrderDate,
DATEADD(DAY, 2, OrderDate) as 'ApproxShipDate',
ShipDate,
DATEDIFF(DAY, OrderDate, ShipDate) as 'ActualShipTime'
FROM Orders
WHERE MONTH(OrderDate) = 3 and YEAR(OrderDate) = 2016