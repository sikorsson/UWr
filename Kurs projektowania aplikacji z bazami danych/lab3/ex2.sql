DROP TABLE IF EXISTS Employees
GO

CREATE TABLE Employees(
	ID INT PRIMARY KEY,
	SalaryGros MONEY
)
GO

DROP TABLE IF EXISTS SalaryHistory
GO

CREATE TABLE SalaryHistory(
	ID INT IDENTITY PRIMARY KEY,
	EmployeeID INT,
	Year INT,
	Month INT,
	SalaryNet MONEY,
	SalaryGros MONEY
)
GO

INSERT INTO Employees VALUES(1, 1002)
INSERT INTO Employees VALUES(2, 2002)
INSERT INTO Employees VALUES(3, 3002)
INSERT INTO Employees VALUES(4, 30238)
GO

INSERT INTO SalaryHistory VALUES(1, 2021, 1, NULL, 1000)
INSERT INTO SalaryHistory VALUES(1, 2021, 2, NULL, 1001)
INSERT INTO SalaryHistory VALUES(2, 2021, 2, NULL, 2001)
INSERT INTO SalaryHistory VALUES(3, 2021, 1, NULL, 3000)
INSERT INTO SalaryHistory VALUES(1, 2020, 1, NULL, 100)
INSERT INTO SalaryHistory VALUES(4, 2021, 1, NULL, 30201)
INSERT INTO SalaryHistory VALUES(4, 2021, 2, NULL, 30238)
GO

DROP TABLE IF EXISTS calcSalaryErrors
GO

CREATE TABLE calcSalaryErrors(
	ID INT IDENTITY PRIMARY KEY,
	EmployeeID INT,
	Year INT,
	Month INT
)
GO

-------------------------------------

CREATE OR ALTER PROCEDURE calcSalary @month INT AS
BEGIN
	TRUNCATE TABLE calcSalaryErrors
	DECLARE cEmp CURSOR FOR SELECT ID, SalaryGros FROM Employees ORDER BY ID
	DECLARE cHis CURSOR FOR SELECT ID, EmployeeID, Year, Month, SalaryNet, SalaryGros FROM SalaryHistory ORDER BY EmployeeID, Year, Month
	DECLARE @e_id INT, @e_gros MONEY
	DECLARE @h_id INT, @h_eid INT, @h_year INT, @h_month INT, @h_net MONEY, @h_gros MONEY
	DECLARE @prevMonth INT,  @sum_gros MONEY, @sum_net MONEY
	DECLARE @currYear INT = YEAR(GETDATE()), @currMonth INT = MONTH(GETDATE())
	OPEN cEmp
	FETCH NEXT FROM cEmp INTO @e_id, @e_gros
	WHILE(@@FETCH_STATUS = 0)
	BEGIN
		SET @sum_gros = 0
		OPEN cHis
		FETCH NEXT FROM cHis INTO @h_id, @h_eid, @h_year, @h_month, @h_net, @h_gros
		WHILE(@@FETCH_STATUS = 0)
		BEGIN
			IF(@e_id=@h_eid AND @currYear=@h_year AND @h_month <= @month)
			BEGIN
				IF(@sum_gros > 0 AND @h_month-@prevMonth > 1)
				BEGIN
					INSERT INTO calcSalaryErrors VALUES(@e_id, @currYear, @h_month)
					BREAK
				END
				SET @prevMonth = @h_month
				SET @sum_gros = @sum_gros + @h_gros
			END
            FETCH NEXT FROM cHis INTO @h_id, @h_eid, @h_year, @h_month, @h_net, @h_gros
			IF(@@FETCH_STATUS = -1 AND @sum_gros > 0)
			BEGIN
				IF(@prevMonth < @month AND @currMonth<=@month)
				BEGIN
					IF(@currMonth-@prevMonth > 1)
					BEGIN
						INSERT INTO calcSalaryErrors VALUES(@e_id, @currYear, @currMonth)
						BREAK
					END
					SET @sum_gros = @sum_gros + @e_gros
				END
				DECLARE @overflow INT = 0
				IF(@sum_gros > 85528)
				BEGIN
					SET @overflow = @sum_gros - 85528
					SET @sum_gros = 85528
				END
				SET @sum_net = (@sum_gros * 0.82) + (@overflow * 0.68)
				PRINT CAST(@e_id AS CHAR(10)) + ' ' + CAST((@sum_gros+@overflow) AS CHAR(10)) + ' ' + CAST(@sum_net AS CHAR(10))
			END
		END
		CLOSE cHis
		FETCH NEXT FROM cEmp INTO @e_id, @e_gros
	END
CLOSE cEmp
DEALLOCATE cEmp
DEALLOCATE cHis
END
GO

EXEC calcSalary @month = 5
GO

SELECT * FROM Employees
SELECT * FROM SalaryHistory
SELECT * FROM calcSalaryErrors