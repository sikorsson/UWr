WITH tree AS
(
	SELECT leaf.ProductCategoryID FROM SalesLT.ProductCategory AS leaf
	LEFT JOIN SalesLT.ProductCategory AS child ON child.ParentProductCategoryID = leaf.ProductCategoryID
	WHERE child.ProductCategoryID IS NULL
)
SELECT SalesLT.ProductCategory.Name AS CategoryName, SalesLT.Product.Name
FROM SalesLT.Product 
JOIN SalesLT.ProductCategory ON SalesLT.ProductCategory.ProductCategoryID = SalesLT.Product.ProductCategoryID
WHERE SalesLT.ProductCategory.ProductCategoryID NOT IN (SELECT ProductCategoryID FROM tree)

----------------------

UPDATE SalesLT.Product
SET ProductCategoryID = 3
WHERE ProductID = 712
--wczesniej ProductCategoryID było 23

UPDATE SalesLT.ProductCategory
SET ParentProductCategoryID = 5
WHERE ProductCategoryID = 6
--wczesniej ParentProductCategoryID = 1