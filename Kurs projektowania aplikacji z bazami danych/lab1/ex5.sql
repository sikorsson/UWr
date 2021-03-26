SELECT SalesLT.Customer.LastName, SalesLT.Customer.FirstName, SUM(SalesLT.SalesOrderDetail.UnitPriceDiscount*SalesLT.SalesOrderDetail.OrderQty*SalesLT.SalesOrderDetail.UnitPrice)
FROM SalesLT.SalesOrderHeader 
JOIN SalesLT.Customer ON SalesLT.SalesOrderHeader.CustomerID = SalesLT.Customer.CustomerID
JOIN SalesLT.SalesOrderDetail ON SalesLT.SalesOrderHeader.SalesOrderID = SalesLT.SalesOrderDetail.SalesOrderID 
GROUP BY SalesLT.Customer.LastName, SalesLT.Customer.FirstName