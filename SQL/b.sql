CREATE DATABASE IF NOT EXISTS erp_lab;
USE erp_lab;

CREATE TABLE employee (
emp_id INT PRIMARY KEY,
name VARCHAR(50),
department VARCHAR(50),
salary INT
);

INSERT INTO employee VALUES
(1,'Aman','IT',50000),
(2,'Baki','DS',60000),
(3,'Chitragupt','AI',70000);

CREATE TABLE employee_delete (
emp_id INT,
name VARCHAR(50),
department VARCHAR(50),
salary INT,
deleted_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE salary_audit (
emp_id INT,
old_salary INT,
new_salary INT,
changed_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE student (
student_id INT PRIMARY KEY,
name VARCHAR(50),
course VARCHAR(50)
);

CREATE TABLE student_log (
log_id INT AUTO_INCREMENT PRIMARY KEY,
student_id INT,
message VARCHAR(100),
created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

DELIMITER $$

CREATE TRIGGER after_employee_delete
AFTER DELETE ON employee
FOR EACH ROW
BEGIN
INSERT INTO employee_delete(emp_id,name,department,salary)
VALUES(OLD.emp_id,OLD.name,OLD.department,OLD.salary);
END$$

CREATE TRIGGER after_salary_update
AFTER UPDATE ON employee
FOR EACH ROW
BEGIN
IF OLD.salary <> NEW.salary THEN
INSERT INTO salary_audit(emp_id,old_salary,new_salary)
VALUES(OLD.emp_id,OLD.salary,NEW.salary);
END IF;
END$$

CREATE TRIGGER after_student_insert
AFTER INSERT ON student
FOR EACH ROW
BEGIN
INSERT INTO student_log(student_id,message)
VALUES(NEW.student_id,'New student record inserted');
END$$

DELIMITER ;

INSERT INTO student VALUES (1,'Rahul','CSE');

UPDATE employee SET salary = 80000 WHERE emp_id = 1;

DELETE FROM employee WHERE emp_id = 2;

SELECT * FROM employee_delete;
SELECT * FROM salary_audit;
SELECT * FROM student_log;
