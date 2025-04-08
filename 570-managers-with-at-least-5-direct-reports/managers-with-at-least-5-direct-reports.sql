# Write your MySQL query statement below

SELECT e.name from employee e join( SELECT managerId,count(managerid) as directreports FROM EMPLOYEE group by managerId having count(managerId) >= 5) e2 on e.id = e2.managerId;