DROP TYPE IF EXISTS Readers
GO

CREATE TYPE Readers AS TABLE(czytelnik_id INT)
GO

DROP PROCEDURE IF EXISTS daysSum
GO

CREATE OR ALTER PROCEDURE daysSum @readers Czytelnicy READONLY AS
BEGIN
	SELECT 
		input.czytelnik_id, SUM(rental.Liczba_Dni) AS result
	FROM	
		@readers AS input,
		dbo.Czytelnik AS readers,
		dbo.Wypozyczenie AS rental
	WHERE
		readers.Czytelnik_ID = rental.Czytelnik_ID AND
		readers.Czytelnik_ID = input.czytelnik_id
	GROUP BY 
		input.czytelnik_id
END
GO

DECLARE @id_czyt Czytelnicy
INSERT INTO @id_czyt VALUES (1)
INSERT INTO @id_czyt VALUES (2)
INSERT INTO @id_czyt VALUES (3)

EXEC daysSum @id_czyt
GO