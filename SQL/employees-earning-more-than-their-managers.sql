/*
  Question: https://leetcode.com/problems/employees-earning-more-than-their-managers/
  Employees Earning More Than Their Managers
  
  The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.

  +----+-------+--------+-----------+
  | Id | Name  | Salary | ManagerId |
  +----+-------+--------+-----------+
  | 1  | Joe   | 70000  | 3         |
  | 2  | Henry | 80000  | 4         |
  | 3  | Sam   | 60000  | NULL      |
  | 4  | Max   | 90000  | NULL      |
  +----+-------+--------+-----------+
  Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.

  +----------+
  | Employee |
  +----------+
  | Joe      |
  +----------+
  
  Solution:
  
*/
select Employee_em_tb.Name as Employee
from Employee as Employee_em_tb, Employee as Employee_mg_tb 
where ((Employee_em_tb.ManagerId = Employee_mg_tb.Id)
        and (Employee_em_tb.Salary > Employee_mg_tb.Salary));
