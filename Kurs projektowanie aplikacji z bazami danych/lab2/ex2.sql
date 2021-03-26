DROP TABLE IF EXISTS firstnames
GO

CREATE TABLE firstnames (
	id INT PRIMARY KEY,
	firstname CHAR(20)
)
GO

INSERT INTO firstnames VALUES(1, 'Jakub')
INSERT INTO firstnames VALUES(2, 'Paweł')
INSERT INTO firstnames VALUES(3, 'Grzegorz')
INSERT INTO firstnames VALUES(4, 'Maciej')
INSERT INTO firstnames VALUES(5, 'Łukasz')
INSERT INTO firstnames VALUES(6, 'Antoni')
INSERT INTO firstnames VALUES(7, 'Kacper')
INSERT INTO firstnames VALUES(8, 'Piotr')
INSERT INTO firstnames VALUES(9, 'Zenon')
INSERT INTO firstnames VALUES(10, 'Wiktor')
GO

DROP TABLE IF EXISTS lastnames
GO

CREATE TABLE lastnames (
	id INT PRIMARY KEY,
	lastname CHAR(20)
)
GO

INSERT INTO lastnames VALUES(1, 'Kowalski')
INSERT INTO lastnames VALUES(2, 'Sowa')
INSERT INTO lastnames VALUES(3, 'Nowak')
INSERT INTO lastnames VALUES(4, 'Tracz')
INSERT INTO lastnames VALUES(5, 'Zamachowski')
INSERT INTO lastnames VALUES(6, 'Pazura')
INSERT INTO lastnames VALUES(7, 'Stoch')
INSERT INTO lastnames VALUES(8, 'Tomczuk')
INSERT INTO lastnames VALUES(9, 'Mickiewicz')
INSERT INTO lastnames VALUES(10, 'Słowacki')
GO

DROP TABLE IF EXISTS fldata
GO

CREATE TABLE fldata (
	firstname CHAR(20),
	lastname CHAR(20),
	CONSTRAINT pk_personID PRIMARY KEY (firstname, lastname)
)
GO

DROP PROCEDURE IF EXISTS insertRandomPairs
GO

CREATE OR ALTER PROCEDURE insertRandomPairs @n INT AS
BEGIN
	IF OBJECT_ID('fldata') IS NULL THROW 50000, 'fldata does not exist', 1;
	TRUNCATE TABLE fldata

	DECLARE @i INT
	SET @i = 0

	DECLARE @firstnames_count INT
	DECLARE @lastnames_count INT
	DECLARE @possibilities INT
	SET @firstnames_count = (SELECT COUNT(DISTINCT firstname) FROM dbo.firstnames)
	SET @lastnames_count = (SELECT COUNT(DISTINCT lastname) FROM dbo.lastnames)
	SET @possibilities = @firstnames_count * @lastnames_count

	IF (@n > @possibilities)
		THROW 50001, 'n is larger than the number of all possible pairs', 1;

	WHILE (@i < @n)
	BEGIN
		DECLARE @firstname CHAR(20)
		SET @firstname = (SELECT TOP 1 firstname FROM firstnames ORDER BY NEWID())
		DECLARE @lastname CHAR(20)
		SET @lastname = (SELECT TOP 1 lastname FROM lastnames ORDER BY NEWID())

		IF NOT EXISTS (SELECT * FROM fldata WHERE firstname = @firstname AND lastname = @lastname)
		BEGIN
			INSERT INTO fldata VALUES(@firstname, @lastname)
			SET @i = @i + 1
		END
	END
	SELECT * FROM fldata
END
GO

EXEC insertRandomPairs @n = 10
GO