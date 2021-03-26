DROP PROCEDURE IF EXISTS specimensSum
GO

CREATE OR ALTER PROCEDURE specimensSum(@tytul NVARCHAR(300) = NULL, @autor NVARCHAR(200) = NULL, @rokwydania INT = NULL) AS
BEGIN
	DECLARE @query NVARCHAR(max)
	SET @query = N'
		SELECT SUM(quantity) AS result FROM (
			SELECT book.Ksiazka_ID, COUNT(specimen.Egzemplarz_ID) as quantity
			FROM dbo.Ksiazka AS book, dbo.Egzemplarz AS specimen
			WHERE
				(book.Ksiazka_ID = specimen.Ksiazka_ID) AND
				(book.Tytul = @tytul OR @tytul IS NULL) AND
				(book.Autor = @autor OR @autor IS NULL) AND
				(book.Rok_Wydania = @rokwydania OR @rokwydania IS NULL)
			GROUP BY book.Ksiazka_ID) AS summary'
	--PRINT @query
	EXECUTE sp_executesql @query, N'@tytul NVARCHAR(300), @autor NVARCHAR(200), @rokwydania INT', @tytul = @tytul, @autor = @autor, @rokwydania = @rokwydania
END
GO

EXEC specimensSum @tytul = NULL, @autor = 'Eric L. Brown', @rokwydania = NULL
GO