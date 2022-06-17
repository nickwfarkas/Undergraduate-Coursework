DROP TABLE IF EXISTS drivers;
CREATE TABLE drivers(
    id int NOT NULL,
    first char(30) NOT NULL,
    last char(50) NOT NULL,
    experience int NOT NULL,
    PRIMARY KEY (id)
    
);

DROP TABLE IF EXISTS trucks;
CREATE TABLE trucks(
    id int NOT NULL,
    capacity int NOT NULL,
    status int NOT NULL,
    driver int,
    PRIMARY KEY (id),
    FOREIGN KEY (driver) REFERENCES drivers(id)
);

DROP TABLE IF EXISTS items;
CREATE TABLE items(
    id int NOT NULL,
    name char(50) NOT NULL,
    size int NOT NULL,
    PRIMARY KEY (id)
);

DROP TABLE IF EXISTS stores;
CREATE TABLE stores(
    id int NOT NULL,
    name char(100) NOT NULL,
    adress char(250) NOT NULL,
    PRIMARY KEY (id)
);

DROP TABLE IF EXISTS delivery;
CREATE TABLE delivery(
    delivery int NOT NULL,
    date date NOT NULL,
    truck int NOT NULL,
    PRIMARY KEY (delivery),
    FOREIGN KEY (truck) REFERENCES trucks(id)
);

DROP TABLE IF EXISTS delivery_store_row;
CREATE TABLE delivery_store_row(
    delivery int NOT NULL,
    store int NOT NULL,
    sequence int NOT NULL,
    item int NOT NULL,
    quantity int NOT NULL,
    FOREIGN KEY (delivery) REFERENCES delivery(delivery),
    FOREIGN KEY (store) REFERENCES stores(id),
    FOREIGN KEY (item) REFERENCES items(id)
);

SELECT * 
FROM trucks
WHERE status = 1;

SELECT * 
FROM trucks
WHERE capacity > 30;

SELECT id,name,COUNT(name)*quantity as "total"
FROM items JOIN delivery_store_row ON items.id = delivery_store_row.item
GROUP BY name;

CREATE PROCEDURE truck_setDriver (IN t_id int, IN d_id int)
BEGIN
UPDATE trucks
SET driver = d_id
WHERE id = t_id
END;

DELIMITER //

CREATE PROCEDURE truck_setDriver (IN t_id int, IN d_id int)
BEGIN
UPDATE trucks
SET driver = d_id
WHERE id = t_id;
END;
//
DELIMITER ;

INSERT INTO drivers VALUES(1, "Brenna", "Farmer", 5);
INSERT INTO drivers VALUES(2, "Patricia", "Delacruz", 10);
INSERT INTO drivers VALUES(3, "Nash", "Duran", 6);
INSERT INTO drivers VALUES(4, "Brenda", "Lucero", 7);
INSERT INTO drivers VALUES(5, "Natalee", "Hines", 10);
INSERT INTO drivers VALUES(6, "Nicolas", "Wilkinson", 5);
INSERT INTO drivers VALUES(7, "Joe", "Whitney", 7);
INSERT INTO drivers VALUES(8, "Lilliana", "Carr", 3);
INSERT INTO drivers VALUES(9, "Marlon", "Kramer", 9);
INSERT INTO drivers VALUES(10, "Kamila", "Mata", 3);

INSERT INTO trucks VALUES(1, 29, 1, 9);
INSERT INTO trucks VALUES(2, 23, 0, 3);
INSERT INTO trucks VALUES(3, 30, 1, NULL);
INSERT INTO trucks VALUES(4, 32, 1, 6);
INSERT INTO trucks VALUES(5, 39, 1, NULL);
INSERT INTO trucks VALUES(6, 27, 0, 2);

INSERT INTO items VALUES(1, "Blue box", 1);
INSERT INTO items VALUES(2 ,"Green box", 2);
INSERT INTO items VALUES(3, "Black box", 4);
INSERT INTO items VALUES(4, "Yellow box", 6);
INSERT INTO items VALUES(5, "Red box", 8);
INSERT INTO items VALUES(6, "White box", 5);
INSERT INTO items VALUES(7, "Silver box", 7);
INSERT INTO items VALUES(8, "Gold box", 9);

INSERT INTO stores VALUES(1, "Golden State Bancorp Inc.", "58 Lookout Drive");
INSERT INTO stores VALUES(2, "Vectren Corporation", "1 Bay Rd.");
INSERT INTO stores VALUES(3, "MasTec Inc.", "8403 Summerhouse Lane");
INSERT INTO stores VALUES(4, "Quanta Services Inc.", "8984 W. Trenton Lane");
INSERT INTO stores VALUES(5, "Penn Traffic Co.", "13 North Morris Ave.");
INSERT INTO stores VALUES(6, "Reliance Steel & Aluminum Co.", "7612 Brookside Lane");
INSERT INTO stores VALUES(7, "Caterpillar Inc.", "8447 Manhattan Street");
INSERT INTO stores VALUES(8, "Applera Corporation", "750 Country Street");

INSERT INTO delivery VALUES(1, STR_TO_DATE('12-5-2021', '%m-%d-%Y'), 1);
INSERT INTO delivery VALUES(2, STR_TO_DATE('12-6-2021', '%m-%d-%Y'), 3);
INSERT INTO delivery VALUES(3, STR_TO_DATE('12-6-2021', '%m-%d-%Y'), 4);
INSERT INTO delivery VALUES(4, STR_TO_DATE('12-7-2021', '%m-%d-%Y'), 5);

INSERT INTO delivery_store_row VALUES(1, 5, 1, 7, 1);
INSERT INTO delivery_store_row VALUES(1, 4, 2, 5, 1);
INSERT INTO delivery_store_row VALUES(1, 8, 3, 3, 2);
INSERT INTO delivery_store_row VALUES(2, 3, 1, 6, 3);
INSERT INTO delivery_store_row VALUES(3, 7, 1, 1, 2);
INSERT INTO delivery_store_row VALUES(3, 2, 2, 8, 2);
INSERT INTO delivery_store_row VALUES(4, 1, 1, 5, 3);
INSERT INTO delivery_store_row VALUES(4, 5, 2, 1, 2);