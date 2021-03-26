SELECT SalesLT.ProductModel.Name, COUNT(SalesLT.Product.ProductID)
FROM SalesLT.ProductModel, SalesLT.Product
WHERE SalesLT.ProductModel.ProductModelID = SalesLT.Product.ProductModelID
GROUP BY SalesLT.ProductModel.ProductModelID, SalesLT.ProductModel.Name
HAVING COUNT(SalesLT.Product.ProductID) > 1