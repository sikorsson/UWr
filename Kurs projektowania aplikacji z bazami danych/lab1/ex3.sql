SELECT SalesLT.Address.City, COUNT(DISTINCT SalesLT.Customer.SalesPerson) AS 'SalesPerson per City', COUNT(DISTINCT SalesLT.Customer.CustomerID) AS 'Customers per City'
FROM SalesLT.CustomerAddress
JOIN SalesLT.Address ON SalesLT.CustomerAddress.AddressID = SalesLT.Address.AddressID
JOIN SalesLT.Customer ON SalesLT.CustomerAddress.CustomerID = SalesLT.Customer.CustomerID
GROUP BY SalesLT.Address.City
