DROP TABLE IF EXISTS Products
GO

CREATE TABLE Products(
	ID INT PRIMARY KEY,
	ProductName VARCHAR(30)
)
GO


DROP TABLE IF EXISTS Rates
GO

CREATE TABLE Rates(
	Currency VARCHAR(3) PRIMARY KEY,
	PricePLN MONEY
)
GO

DROP TABLE IF EXISTS Prices
GO

CREATE TABLE Prices(
	ProductID INT REFERENCES Products(ID),
	Currency VARCHAR(3) REFERENCES Rates(Currency),
	Price MONEY
)
GO

INSERT INTO Products VALUES(1, 'winogrona')
INSERT INTO Products VALUES(2, 'kiwi')
INSERT INTO Products VALUES(3, 'marchew')

INSERT INTO Rates VALUES('PLN', 1.00)
INSERT INTO Rates VALUES('EUR', 4.63)
INSERT INTO Rates VALUES('USD', 3.93)
INSERT INTO Rates VALUES('RUB', 0.05)
INSERT INTO Rates VALUES('CZK', 0.18)

INSERT INTO Prices VALUES(1, 'PLN', 8.00)
INSERT INTO Prices VALUES(2, 'PLN', 7.00)
INSERT INTO Prices VALUES(3, 'PLN', 3.49)
INSERT INTO Prices VALUES(1, 'EUR', 1.72)
INSERT INTO Prices VALUES(1, 'USD', 2.03)
INSERT INTO Prices VALUES(2, 'RUB', 140.00)
INSERT INTO Prices VALUES(2, 'CZK', 38.88)
INSERT INTO Prices VALUES(3, 'EUR', 0.75)
INSERT INTO Prices VALUES(3, 'CZK', 19.38)

--------------------------------------------------------------------

DECLARE rates_cursor CURSOR FOR SELECT Currency, PricePLN FROM Rates
DECLARE products_cursor CURSOR FOR SELECT ProductID, Currency, Price FROM Prices
DECLARE @r_curr VARCHAR(3), @r_pln MONEY
DECLARE @p_productid INT, @p_curr VARCHAR(3), @p_price MONEY
DECLARE @current_price MONEY
DECLARE @delete BIT

OPEN products_cursor
FETCH NEXT FROM products_cursor INTO @p_productid, @p_curr, @p_price
SET @current_price = (SELECT Price FROM Prices WHERE ProductID = @p_productid AND Currency = 'PLN')
WHILE (@@FETCH_STATUS = 0)
BEGIN
	OPEN rates_cursor
	FETCH NEXT FROM rates_cursor INTO @r_curr, @r_pln
	SET @delete = 1
	WHILE(@@FETCH_STATUS = 0)
	BEGIN
		IF(@p_curr = @r_curr)
		BEGIN
			SET @p_price = @current_price / @r_pln
			UPDATE Prices
			SET Price = @p_price
			WHERE ProductID = @p_productid AND Currency = @p_curr
			SET @delete = 0
		END
		FETCH NEXT FROM rates_cursor INTO @r_curr, @r_pln
	END
	IF(@delete=1)
		DELETE FROM Prices WHERE ProductID = @p_productid AND Currency = @p_curr
	CLOSE rates_cursor
	FETCH NEXT FROM products_cursor INTO @p_productid, @p_curr, @p_price
	SET @current_price = (SELECT Price FROM Prices WHERE ProductID = @p_productid AND Currency = 'PLN')
END
CLOSE products_cursor
DEALLOCATE rates_cursor
DEALLOCATE products_cursor
GO