--Proj 2

--q1

--DROP VIEW NFvwOrderItemProducts

CREATE VIEW NFvwOrderItemProducts  
AS  
SELECT Orders.OrderID, OrderDate, TaxAmount, ShipDate,
ItemPrice, DiscountAmount,
(ItemPrice - DiscountAmount) as FinalPrice, 
Quantity, (ItemPrice - DiscountAmount) * Quantity as ItemTotal,
ProductName
FROM Orders 
JOIN OrderItems ON Orders.OrderID = OrderItems.OrderID
JOIN Products ON Products.ProductID = OrderItems.ProductID
GO

--q2

CREATE VIEW NFvwProductSummery  
AS  
SELECT ProductName, COUNT(OrderID) as OrderCount, SUM(FinalPrice) as OrderTotal
FROM NFvwOrderItemProducts
GROUP BY ProductName
GO

--q3

DECLARE @count INT
SET @count =
(
    SELECT COUNT(ProductID)
    FROM Products
)
IF(@count >= 7)
    PRINT 'The number of products is greater than 7'
ELSE
    PRINT 'The number of products is less than 7'


--q4

DECLARE @i INT;
SET @i = 1;
PRINT 'Common Factors of 10 and 20';
WHILE(@i <= 20)
BEGIN
    IF((20 % @i = 0) AND (10 % @i = 0))
        PRINT @i;
    SET @i = @i + 1;
END

--q5

CREATE PROC NFspInsertCategory
    @CategoryName VARCHAR(50)
AS
-- Insert rows into table 'Categories' in schema '[dbo]'
INSERT INTO [dbo].[Categories]
( -- Columns to insert data into
 [CategoryName]
)
VALUES
( -- First row: values for the columns in the list above
 @CategoryName
)

EXEC NFspInsertCategory @CategoryName = 'Snacks'
EXEC NFspInsertCategory @CategoryName = 'Misc'

--q6

CREATE FUNCTION NFfnDiscountPrice(@itemID INT)
    RETURNS MONEY
BEGIN
    RETURN
    (
        SELECT (itemPrice - DiscountAmount) 
        FROM OrderItems
        WHERE ItemID = @itemID
    )
END;

DROP FUNCTION NFfnDiscountPrice

--q7 Check

CREATE FUNCTION NFfnItemTotal(@itemID INT)
    RETURNS MONEY
BEGIN
    RETURN
    (
        SELECT NFfnDiscountPrice(@itemID) * Quantity
        FROM OrderItems
        WHERE ItemID = @itemID
    )
END;

--q8

SELECT * INTO NFProducts FROM Products

CREATE TRIGGER NFProducts_INSERT
    ON NFProducts
    AFTER INSERT
AS
    UPDATE NFProducts
    SET DateAdded = GETDATE()
    WHERE DateAdded IS NULL