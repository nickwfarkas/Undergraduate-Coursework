--Ch 8 Practice Lab

--q1
SELECT 
ListPrice,
Cast(ListPrice as decimal(38,1)) as 'Cast to decimal',
CONVERT(int, ListPrice) as 'Convert to int',
Cast(ListPrice as int) as 'Cast to int'
FROM Products

--q2
SELECT
DateAdded,
CAST(DateAdded as date) as 'date',
CAST(DateAdded as time) as 'time',
CAST(DateAdded as varchar(7)) as 'short date'
FROM Products

--q3
SELECT 
CONVERT(varchar, OrderDate, 1) as 'MM/DD/YYYY',
CONVERT(varchar, OrderDate, 0) as 'Date with time',
CONVERT(varchar, OrderDate, 13) as 'Date with 24 hour time'
FROM Orders