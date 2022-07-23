select product_id from products where low_fats='Y' and recyclable='Y'

select product_id from products where (low_fats='Y')
INTERSECT
select product_id from products where (recyclable='Y')
