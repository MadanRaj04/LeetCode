# Write your MySQL query statement below

SELECT u.unique_id, e.name from Employees e left join EmployeeUNI u ON e.id = u.id;