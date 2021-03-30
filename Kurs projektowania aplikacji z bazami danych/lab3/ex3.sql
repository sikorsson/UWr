DROP TABLE IF EXISTS Cache
GO

CREATE TABLE Cache(
	ID INT IDENTITY PRIMARY KEY,
	UrlAddress VARCHAR(255),
	LastAccess DATETIME
)
GO

DROP TABLE IF EXISTS History
GO

CREATE TABLE History(
	ID INT IDENTITY PRIMARY KEY,
	UrlAddress VARCHAR(255),
	LastAccess DATETIME
)
GO

DROP TABLE IF EXISTS Params
GO

CREATE TABLE Params(
	Nam VARCHAR(255),
	Val INT
)
GO

INSERT INTO Params VALUES('max_cache', 3)
GO

-------------------------------------------

CREATE OR ALTER TRIGGER cacheCheck ON Cache INSTEAD OF INSERT AS
BEGIN
	DECLARE @new_address VARCHAR(255)
	DECLARE @new_last DATETIME
	SELECT @new_address = UrlAddress, @new_last = LastAccess FROM INSERTED
	IF EXISTS(SELECT 1 FROM Cache WHERE UrlAddress = @new_address)
		UPDATE Cache SET LastAccess = @new_last WHERE UrlAddress = @new_address
	ELSE
	BEGIN
		DECLARE @rows INT = (SELECT COUNT(*) FROM Cache)
		DECLARE @maxRows INT = (SELECT TOP 1 Val FROM Params)
		IF (@rows < @maxRows)
			INSERT INTO Cache SELECT UrlAddress, LastAccess FROM INSERTED
		ELSE
		BEGIN
			DECLARE @old_id INT, @old_address VARCHAR(255), @old_last DATETIME
			SELECT TOP 1 @old_id = ID, @old_address = UrlAddress, @old_last = LastAccess FROM Cache ORDER BY LastAccess
			IF EXISTS(SELECT 1 FROM History WHERE UrlAddress = @old_address)
				UPDATE History SET LastAccess = @old_last WHERE UrlAddress = @old_address
			ELSE
				INSERT INTO History VALUES(@old_address, @old_last)
			DELETE FROM Cache WHERE ID = @old_id
			INSERT INTO Cache SELECT UrlAddress, LastAccess FROM INSERTED				
		END
	END
END
GO

INSERT INTO Cache VALUES('google.com', '2021-03-27 18:12:00')
INSERT INTO Cache VALUES('google.com', '2021-03-27 18:15:00')
INSERT INTO Cache VALUES('reddit.com', '2021-03-27 19:00:00')
INSERT INTO Cache VALUES('youtube.com', '2021-03-27 19:30:00')
INSERT INTO Cache VALUES('facebook.com', '2021-03-27 20:00:00')