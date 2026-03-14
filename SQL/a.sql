CREATE DATABASE IF NOT EXISTS erp;
USE erp;
CREATE TABLE emp (
emp_id INT PRIMARY KEY,
name VARCHAR(50),
dept VARCHAR(50)
);
INSERT INTO emp VALUES
(1,'Aman','IT'),
(2,'Baki','DS'),
(3,'Chitragupt','AI');
CREATE TABLE emp_delete (
emp_id INT,
name VARCHAR(50),
action VARCHAR(20)
);
DELIMITER $$

CREATE TRIGGER after_emp_delete
AFTER DELETE ON emp
FOR EACH ROW
BEGIN
INSERT INTO emp_delete(emp_id, name, action)
VALUES (OLD.emp_id, OLD.name, 'Deleted');
END$$

DELIMITER ;
DELETE FROM emp WHERE emp_id = 1;
SELECT * FROM emp_delete;
