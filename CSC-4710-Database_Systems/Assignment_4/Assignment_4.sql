DROP TABLE IF EXISTS Subjects;
CREATE TABLE Subjects(
    s_id int,
    s_firstname varchar(50),
    s_lastname varchar(50),
    s_age int,
    s_country varchar(50)
);

DROP TABLE IF EXISTS Answers;
CREATE TABLE Answers(
    a_id int,
    s_id int,
    a_surveyNum int,
    a_surveyDate date,
    a_q1 int,
    a_q2 int,
    a_q3 int,
    a_q4 int,
    a_q5 int,
    a_q6 int,
    a_q7 int,
    a_q8 int
);

-- Subject Data

INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (1,"Robin","Mccarthy",30,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (2,"Eloise","Cunningham",35,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (3,"Curtis","Little",18,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (4,"Maxim","Townsend",22,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (5,"Aiden","Fischer",24,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (6,"Fleur","Donnelly",24,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (7,"Grover","Henderson",43,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (8,"Jamie","Charles",30,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (9,"Harris","Bush",31,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (10,"Isabella","Stewart",20,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (11,"Caroline","Herbert",18,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (12,"Ayla","Hawkins",25,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (13,"Rhys","Barber",22,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (14,"Umar","Jacobs",30,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (15,"Tilly","Kirk",27,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (16,"Anika","Crawford",27,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (17,"Kane","Walters",35,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (18,"Margaret","Potter",32,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (19,"Nora","Cox",43,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (20,"Nicolas","Ochoa",24,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (21,"Yasin","Farmer",26,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (22,"Abby","Myers",44,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (23,"Gerald","Bartlett",34,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (24,"Kenneth","Wolf",29,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (25,"Charlotte","Whelan",25,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (26,"Stephen","Harrington",24,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (27,"Frederick","Robertson",32,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (28,"Rhea","Morgan",20,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (29,"Isabel","Stevenson",39,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (30,"Miriam","Sheppard",21,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (31,"Kitty","Kavanagh",35,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (32,"Alina","Richardson",35,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (33,"Maryam","Steele",29,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (34,"Lowri","Riley",39,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (35,"Sienna","Black",44,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (36,"Haroon","Spence",27,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (37,"Jac","Burns",18,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (38,"Anna","Jensen",36,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (39,"Khadija","Garner",40,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (40,"Jean","Smith",30,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (41,"Joel","Watson",35,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (42,"Mohamed","Alexander",31,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (43,"Sam","Adams",40,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (44,"Ibrahim","Mitchell",24,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (45,"Jake","Reese",39,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (46,"Jason","Barnett",21,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (47,"Bella","Buchanan",36,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (48,"Millie","Nguyen",34,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (49,"Charles","Lovell",20,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (50,"Frazer","Peters",41,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (51,"Zachary","Thompson",21,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (52,"Farhan","Floyd",40,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (53,"Paige","Barrett",33,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (54,"Nora","Spencer",43,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (55,"Renee","Zhang",45,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (56,"Catherine","Peterson",19,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (57,"Vincent","Jenkins",32,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (58,"Aron","Mathis",27,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (59,"Lawrence","Allen",42,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (60,"Chelsea","Sparks",20,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (61,"Evangeline","Medina",40,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (62,"Carl","Simpson",24,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (63,"Ellie","Martinez",38,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (64,"Alec","Conner",38,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (65,"Polly","Reid",26,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (66,"Frankie","Thomas",44,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (67,"Ismail","Jackson",35,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (68,"Mitchell","Harper",45,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (69,"Amina","Evans",27,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (70,"Adil","Moore",30,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (71,"Ayesha","Mendoza",21,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (72,"Rhonda","Pearson",20,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (73,"Daniel","Daniels",28,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (74,"Ava","Ford",24,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (75,"Hasan","Carroll",44,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (76,"Alyssa","Barker",31,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (77,"Euan","Kay",45,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (78,"Ashley","Olson",38,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (79,"Willie","Lewis",32,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (80,"Esme","Torres",33,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (81,"Samantha","Sandoval",26,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (82,"Charley","Manning",38,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (83,"Solomon","Baker",22,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (84,"Ricky","Hodges",29,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (85,"Sally","Dominguez",33,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (86,"Eddie","Osborne",20,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (87,"Andrew","Reyes",38,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (88,"Harold","George",20,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (89,"Jacqueline","Leon",28,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (90,"Ellis","Chapman",22,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (91,"Andre","Griffin",37,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (92,"Constance","Cameron",36,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (93,"Samuel","Murray",31,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (94,"Roxanne","Bradley",24,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (95,"George","Leonard",24,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (96,"Ted","Mihalcea",19,"USA");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (97,"Yahya","Castro",28,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (98,"Amanda","Perez",31,"UK");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (99,"Flora","Swigger",31,"CAN");


INSERT INTO Subjects (s_id,s_firstname,s_lastname,s_age,s_country)
 
VALUES (100,"Aoife","Kiper",23,"CAN");

-- Answer Data

INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (1,56,3,"2020-03-14",4,5,4,1,1,4,1,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (2,43,2,"2020-02-03",4,1,3,5,4,1,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (3,61,1,"2020-01-05",4,5,1,1,4,3,5,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (4,37,1,"2020-01-23",3,5,1,5,1,5,4,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (5,64,2,"2020-02-14",3,4,3,1,1,1,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (6,48,2,"2020-02-07",5,2,3,3,5,5,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (7,69,1,"2020-01-26",3,3,5,1,3,3,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (8,40,1,"2020-01-04",5,1,1,5,5,3,4,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (9,10,3,"2020-03-02",3,5,5,5,2,1,2,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (10,19,3,"2020-03-03",5,1,4,3,4,5,1,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (11,81,1,"2020-01-13",2,1,3,3,2,1,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (12,74,3,"2020-03-02",3,3,3,5,1,2,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (13,80,3,"2020-03-17",5,5,4,1,3,2,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (14,67,2,"2020-02-11",1,2,3,5,3,4,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (15,91,3,"2020-03-13",2,1,1,3,1,1,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (16,25,3,"2020-03-16",3,5,5,2,4,1,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (17,40,2,"2020-02-04",4,3,4,5,4,4,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (18,49,2,"2020-02-21",1,5,1,3,4,3,3,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (19,24,2,"2020-02-14",1,4,3,5,5,4,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (20,24,3,"2020-03-21",1,1,5,2,5,5,5,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (21,20,3,"2020-03-13",3,4,4,1,1,2,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (22,76,1,"2020-01-09",5,5,1,4,2,4,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (23,67,1,"2020-01-19",1,3,5,5,3,1,4,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (24,21,2,"2020-02-10",5,1,1,2,2,5,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (25,66,1,"2020-01-06",5,2,2,1,4,3,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (26,20,2,"2020-02-04",3,1,2,4,3,1,2,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (27,22,2,"2020-02-26",5,4,5,1,5,2,2,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (28,63,1,"2020-01-15",5,4,2,1,2,4,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (29,33,1,"2020-01-11",1,5,4,2,2,2,3,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (30,82,1,"2020-01-03",5,4,1,3,4,3,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (31,43,1,"2020-01-04",4,5,4,3,5,2,1,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (32,21,3,"2020-03-09",5,4,2,3,1,4,4,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (33,26,1,"2020-01-19",3,2,2,3,2,3,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (34,72,3,"2020-03-11",4,2,4,4,4,3,2,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (35,99,3,"2020-03-02",1,2,4,5,4,5,2,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (36,26,3,"2020-03-18",1,1,1,3,4,4,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (37,72,2,"2020-02-14",1,3,3,4,3,2,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (38,71,3,"2020-03-01",3,3,1,1,2,4,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (39,32,3,"2020-03-06",3,2,5,1,3,2,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (40,48,1,"2020-01-07",5,5,5,4,1,2,4,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (41,16,2,"2020-02-15",2,3,1,1,5,3,4,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (42,100,2,"2020-02-20",1,4,2,5,1,1,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (43,41,3,"2020-03-20",4,5,5,1,4,3,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (44,36,2,"2020-02-18",2,2,3,3,3,3,2,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (45,96,2,"2020-02-08",4,3,5,2,2,5,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (46,5,1,"2020-01-13",1,2,3,5,4,1,2,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (47,3,2,"2020-02-13",2,2,2,1,1,2,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (48,12,2,"2020-02-06",4,1,3,3,2,3,1,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (49,43,3,"2020-03-04",5,2,4,1,5,5,1,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (50,45,1,"2020-01-28",5,5,5,3,5,1,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (51,86,1,"2020-01-27",3,3,1,2,4,2,4,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (52,54,2,"2020-02-08",2,3,2,2,3,1,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (53,61,3,"2020-03-16",2,2,1,1,4,1,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (54,76,3,"2020-03-02",1,1,1,2,3,5,4,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (55,27,3,"2020-03-20",1,1,4,5,3,1,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (56,34,2,"2020-02-28",2,4,4,5,4,3,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (57,5,3,"2020-03-08",5,2,3,3,3,5,3,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (58,95,3,"2020-03-17",4,3,5,5,2,1,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (59,95,2,"2020-02-16",4,4,1,4,5,4,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (60,9,2,"2020-02-02",4,1,1,2,2,3,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (61,39,1,"2020-01-16",1,4,5,5,2,1,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (62,91,1,"2020-01-10",4,5,1,4,4,2,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (63,41,1,"2020-01-12",3,4,4,3,4,2,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (64,85,2,"2020-02-07",3,5,2,1,1,5,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (65,33,2,"2020-02-27",2,5,3,2,4,1,2,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (66,18,1,"2020-01-18",3,3,1,1,1,1,2,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (67,44,3,"2020-03-11",3,2,3,2,5,4,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (68,73,3,"2020-03-18",2,2,4,2,1,2,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (69,35,1,"2020-01-26",3,3,1,1,1,4,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (70,42,3,"2020-03-06",4,2,2,2,4,4,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (71,10,2,"2020-02-16",2,2,2,3,3,4,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (72,32,2,"2020-02-16",1,4,4,4,4,2,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (73,72,1,"2020-01-05",4,2,2,1,3,5,4,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (74,71,2,"2020-02-17",2,5,3,4,5,3,3,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (75,4,2,"2020-02-21",3,5,5,2,2,4,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (76,19,1,"2020-01-13",4,5,4,1,4,3,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (77,7,2,"2020-02-04",4,4,2,2,1,1,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (78,41,2,"2020-02-24",2,3,2,3,4,4,5,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (79,52,3,"2020-03-02",1,4,2,4,3,4,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (80,37,2,"2020-02-28",2,3,2,5,5,5,5,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (81,67,3,"2020-03-10",2,3,4,5,3,4,5,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (82,50,2,"2020-02-17",3,2,4,1,3,5,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (83,77,3,"2020-03-16",3,3,4,3,5,2,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (84,9,3,"2020-03-19",3,5,1,4,2,2,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (85,9,1,"2020-01-22",1,3,1,5,1,2,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (86,99,1,"2020-01-09",5,5,2,3,1,1,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (87,56,2,"2020-02-05",2,5,2,5,2,3,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (88,38,3,"2020-03-24",1,5,3,5,1,1,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (89,63,2,"2020-02-21",3,4,3,1,1,1,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (90,46,1,"2020-01-19",4,3,1,2,5,3,1,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (91,36,3,"2020-03-13",3,3,4,3,4,4,1,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (92,78,1,"2020-01-09",3,3,5,4,5,4,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (93,81,3,"2020-03-12",2,2,2,3,1,1,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (94,28,2,"2020-02-28",2,4,4,4,3,3,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (95,92,3,"2020-03-03",5,3,5,5,1,1,2,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (96,4,1,"2020-01-04",1,4,5,4,1,5,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (97,70,3,"2020-03-21",4,1,4,1,2,1,1,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (98,93,2,"2020-02-02",4,3,5,1,5,5,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (99,64,3,"2020-03-09",1,2,2,2,5,1,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (100,80,2,"2020-02-08",5,1,1,5,5,1,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (101,16,1,"2020-01-04",2,4,5,2,2,4,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (102,84,2,"2020-02-23",4,2,2,3,5,2,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (103,50,3,"2020-03-06",2,3,2,3,3,1,4,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (104,100,3,"2020-03-24",4,3,5,3,3,1,2,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (105,58,3,"2020-03-11",2,4,3,1,5,5,2,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (106,13,1,"2020-01-08",1,3,1,1,1,5,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (107,82,3,"2020-03-06",3,5,5,2,3,3,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (108,1,1,"2020-01-21",4,3,2,2,2,2,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (109,37,3,"2020-03-01",2,4,1,1,2,2,4,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (110,24,1,"2020-01-03",1,3,5,4,4,2,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (111,16,3,"2020-03-07",3,5,3,5,3,1,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (112,68,2,"2020-02-18",3,1,2,2,4,2,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (113,42,1,"2020-01-12",4,3,1,2,5,3,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (114,68,3,"2020-03-12",5,5,1,3,3,3,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (115,53,1,"2020-01-26",5,3,2,5,2,3,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (116,70,2,"2020-02-01",4,1,3,4,4,4,4,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (117,13,2,"2020-02-28",2,2,1,5,1,1,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (118,1,3,"2020-03-18",1,5,5,5,2,4,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (119,59,3,"2020-03-19",4,3,2,1,2,4,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (120,5,2,"2020-02-21",1,4,2,2,3,1,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (121,26,2,"2020-02-18",1,5,2,3,2,4,1,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (122,15,2,"2020-02-25",4,3,4,3,2,4,2,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (123,8,3,"2020-03-24",4,4,4,1,3,1,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (124,10,1,"2020-01-12",1,3,2,4,5,2,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (125,33,3,"2020-03-26",3,3,3,4,1,3,4,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (126,56,1,"2020-01-17",3,1,3,5,2,2,5,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (127,39,2,"2020-02-22",2,4,5,5,2,4,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (128,40,3,"2020-03-16",5,1,4,5,1,2,2,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (129,57,3,"2020-03-21",5,1,2,1,1,5,5,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (130,23,1,"2020-01-04",1,2,3,4,1,5,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (131,51,2,"2020-02-28",1,2,1,2,4,2,2,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (132,55,2,"2020-02-19",4,3,4,1,5,5,1,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (133,76,2,"2020-02-01",4,5,2,1,4,2,1,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (134,52,2,"2020-02-28",3,4,5,5,2,1,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (135,77,1,"2020-01-14",5,4,2,2,1,3,5,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (136,60,3,"2020-03-27",1,1,2,3,5,3,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (137,74,2,"2020-02-06",2,5,5,4,4,2,1,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (138,75,2,"2020-02-24",4,4,4,2,3,3,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (139,28,1,"2020-01-19",2,1,3,5,4,4,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (140,93,1,"2020-01-14",3,1,3,3,3,4,3,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (141,8,1,"2020-01-14",3,1,3,1,5,3,4,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (142,75,3,"2020-03-02",1,5,1,2,2,4,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (143,79,3,"2020-03-20",2,2,1,5,1,3,5,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (144,29,2,"2020-02-23",1,5,4,4,4,2,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (145,29,3,"2020-03-02",5,2,4,2,2,5,1,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (146,77,2,"2020-02-24",2,2,2,3,4,4,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (147,48,3,"2020-03-07",5,4,1,1,3,1,4,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (148,35,3,"2020-03-12",4,4,2,3,2,3,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (149,44,2,"2020-02-14",5,4,1,4,3,4,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (150,39,3,"2020-03-27",4,3,1,4,5,3,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (151,31,1,"2020-01-26",1,5,5,1,2,5,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (152,30,3,"2020-03-04",5,3,1,2,3,2,5,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (153,3,1,"2020-01-10",2,4,1,5,5,1,1,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (154,82,2,"2020-02-15",1,2,2,2,2,3,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (155,88,3,"2020-03-27",5,3,1,4,3,3,1,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (156,90,2,"2020-02-21",4,2,1,5,2,2,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (157,12,3,"2020-03-20",3,1,2,2,4,4,3,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (158,49,1,"2020-01-23",3,3,3,2,3,2,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (159,69,3,"2020-03-03",1,2,2,4,3,5,2,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (160,66,3,"2020-03-09",4,5,3,3,3,1,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (161,60,2,"2020-02-11",4,5,2,4,1,2,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (162,85,3,"2020-03-12",5,1,4,3,5,4,3,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (163,66,2,"2020-02-12",1,4,3,4,2,1,2,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (164,84,3,"2020-03-05",4,4,3,3,3,2,1,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (165,34,1,"2020-01-20",1,5,2,3,3,2,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (166,84,1,"2020-01-03",3,2,4,1,1,4,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (167,13,3,"2020-03-14",2,5,5,3,1,4,5,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (168,58,1,"2020-01-08",1,4,3,3,4,1,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (169,35,2,"2020-02-18",2,2,1,3,3,2,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (170,7,1,"2020-01-20",4,5,4,3,2,1,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (171,87,1,"2020-01-17",3,4,3,2,5,3,1,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (172,78,2,"2020-02-22",1,4,5,2,1,4,2,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (173,97,2,"2020-02-13",3,4,4,5,1,1,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (174,91,2,"2020-02-20",3,3,2,5,2,4,2,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (175,54,3,"2020-03-09",2,5,4,4,5,4,2,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (176,22,3,"2020-03-01",2,3,1,4,4,4,5,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (177,79,1,"2020-01-28",1,3,3,1,5,5,1,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (178,45,3,"2020-03-04",4,5,4,5,5,3,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (179,96,1,"2020-01-14",2,2,3,3,3,3,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (180,98,1,"2020-01-15",3,3,5,5,2,5,5,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (181,83,1,"2020-01-12",3,5,1,5,2,5,3,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (182,95,1,"2020-01-18",1,4,2,4,1,2,2,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (183,12,1,"2020-01-26",2,3,1,3,3,1,3,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (184,6,1,"2020-01-09",3,4,3,3,4,4,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (185,92,2,"2020-02-13",2,3,5,3,1,3,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (186,27,1,"2020-01-07",2,1,3,1,3,3,1,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (187,11,1,"2020-01-10",5,4,4,1,2,3,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (188,86,2,"2020-02-06",2,2,4,3,2,2,1,2);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (189,98,3,"2020-03-28",2,2,2,5,2,3,4,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (190,50,1,"2020-01-16",2,2,3,2,4,1,3,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (191,63,3,"2020-03-27",3,1,4,3,4,4,2,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (192,2,3,"2020-03-22",4,3,2,5,1,5,4,5);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (193,42,2,"2020-02-06",1,4,1,5,1,5,1,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (194,22,1,"2020-01-14",1,2,3,3,1,3,3,1);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (195,68,1,"2020-01-12",5,5,5,5,4,4,4,4);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (196,59,1,"2020-01-19",5,3,2,3,2,5,5,3);
INSERT INTO Answers (a_id,s_id,a_surveyNum,a_surveyDate,a_q1,a_q2,a_q3,a_q4,a_q5,a_q6,a_q7,a_q8) 
VALUES (197,11,3,"2020-03-09",1,4,2,4,4,5,1,3);
