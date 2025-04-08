# Write your MySQL query statement below

select c.contest_id, round(count(c.contest_id)/(select count(user_id) from Users) * 100,2) as percentage from users u join register c on u.user_id = c.user_id group by c.contest_id order by percentage desc,c.contest_id;