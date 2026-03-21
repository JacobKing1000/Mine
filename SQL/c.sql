USE collage;

CREATE USER 'Shawn'@'localhost'
IDENTIFIED BY 'Sway#1122';

GRANT SELECT, INSERT, UPDATE, DELETE
ON collage.* TO 'Shawn'@'localhost';

SHOW GRANTS FOR 'Shawn'@'localhost';

REVOKE DELETE ON collage.* FROM 'Shawn'@'localhost';

ALTER USER 'Shawn'@'localhost'
IDENTIFIED BY 'Candy@66A';

SELECT user, host FROM mysql.user;