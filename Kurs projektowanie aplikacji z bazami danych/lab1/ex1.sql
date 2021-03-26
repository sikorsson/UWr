SELECT DISTINCT SalesLT.Address.City
FROM SalesLT.Address, SalesLT.SalesOrderHeader
WHERE SalesLT.Address.AddressID = SalesLT.SalesOrderHeader.ShipToAddressID 
AND SalesLT.SalesOrderHeader.Status = 5 --kod 5 w dostawach oznacza "dostarczone"
ORDER BY SalesLT.Address.City ASC