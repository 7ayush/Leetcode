select name as "Customers" from customers where id not in (Select distinct customerId from orders);
