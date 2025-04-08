# Write your MySQL query statement below

select p.product_id, IFNULL(round((sum(p.price * c.units))/(sum(c.units)),2),0) as average_price from prices p left join unitssold c on p.product_id = c.product_id and c.purchase_date between p.start_date and p.end_date group by p.product_id;