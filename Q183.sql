select name as "Customers" from customers where id not in (Select distinct customerId from orders);

Select name as Customers from Customers where id NOT IN(Select customerId from Orders);

# Select c1.name as Customers from Customers as c1 LEFT JOIN Orders as o1 ON c1.id=o1.customerId
# where o1.id IS NULL;

# Select c1.name as Customers from Orders as o1 RIGHT JOIN Customers as c1 ON c1.id=o1.customerId
# where o1.id IS NULL;

