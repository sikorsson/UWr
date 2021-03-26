DROP FUNCTION IF EXISTS borrowedBooks
GO

CREATE OR ALTER FUNCTION borrowedBooks(@days INT) RETURNS TABLE AS
RETURN
	SELECT 
		reader.PESEL, COUNT(rental.Wypozyczenie_ID) AS specimens_number
	FROM	
		dbo.Czytelnik AS reader,
		dbo.Wypozyczenie AS rental
	WHERE
		reader.Czytelnik_ID = rental.Czytelnik_ID AND
		rental.Liczba_Dni >= @days
	GROUP BY reader.PESEL
GO


SELECT * FROM borrowedBooks(1)