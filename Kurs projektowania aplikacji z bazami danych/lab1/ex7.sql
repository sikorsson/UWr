DROP TABLE IF EXISTS M1
GO
DROP TABLE IF EXISTS S1
GO

CREATE TABLE M1 (
	K INT NOT NULL,
	V VARCHAR(20),
	PRIMARY KEY(K)
)

CREATE TABLE S1 (
	K INT NOT NULL,
	MFK INT,
	V VARCHAR(20),
	PRIMARY KEY(K),
	FOREIGN KEY (MFK) REFERENCES M1(K)
)

--ON UPDATE
	--NO ACTION nie zadziała, bo foreign key musi się odnosić do jakiegoś pola
	--SET NULL zadziała i ustawi wartość na null
	--CASCADE zaktualizuje wartość
--ON DELETE
	--NO ACTION nie zadziała, bo foreign key musi się odnosić do jakiegoś pola
	--SET NULL zadziała i ustawi wartość na null
	--CASCADE usunie wiersz

INSERT INTO M1 VALUES(5, 'asd')
INSERT INTO S1 VALUES(1, 5, 'asd')

UPDATE M1 SET K = 2 WHERE K = 5
DELETE FROM M1 WHERE K = 5

SELECT * FROM S1
JOIN M1 ON M1.K = S1.MFK

------------------------------------

DROP TABLE IF EXISTS M2
GO
DROP TABLE IF EXISTS S2
GO

CREATE TABLE M2 (
	K1 INT NOT NULL,
	K2 INT NOT NULL,
	V VARCHAR(20),
	PRIMARY KEY(K1, K2)
)

CREATE TABLE S2 (
	K INT NOT NULL,
	MFK1 INT,
	MFK2 INT,
	V VARCHAR(20),
	PRIMARY KEY(K),
	FOREIGN KEY (MFK1, MFK2) REFERENCES M2(K1, K2)
)

INSERT INTO M2 VALUES(1, 2, 'asd')
INSERT INTO S2 VALUES(10, 1, 2, 'asd')

UPDATE M2 SET K1 = 3 WHERE K1 = 1
DELETE FROM M2 WHERE K1 = 5

SELECT * FROM S2
JOIN M2 ON M2.K1 = S2.MFK1 AND M2.K2 = S2.MFK2