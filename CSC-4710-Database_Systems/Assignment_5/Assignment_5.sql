--q1

SELECT DISTINCT Subjects.s_firstname, Subjects.s_lastname
FROM Subjects INNER JOIN Answers
ON Subjects.s_id = Answers.s_id
ORDER BY Subjects.s_lastname ASC;

--q2

SELECT s.s_firstname, s.s_lastname
FROM(
  SELECT Subjects.s_firstname, Subjects.s_lastname, COUNT(Answers.s_id) AS c, Subjects.s_age
  FROM Subjects INNER JOIN Answers
  ON Subjects.s_id = Answers.s_id
  GROUP BY Answers.s_id
) s
WHERE s.c = 3
ORDER BY s.s_age DESC;

--q3

SELECT Answers.a_id, 
Answers.a_q1,
(IF(Answers.a_q2 = 5, 1,
 	IF(Answers.a_q2 = 4, 2, 
 		IF(Answers.a_q2 = 2, 4, 
 			IF(Answers.a_q2 = 1, 5, 3))))) AS a_q2,
Answers.a_q3,
(IF(Answers.a_q4 = 5, 1,
 	IF(Answers.a_q4 = 4, 2, 
 		IF(Answers.a_q4 = 2, 4, 
 			IF(Answers.a_q4 = 1, 5, 3))))) AS a_q4,
Answers.a_q5,
(IF(Answers.a_q6 = 5, 1,
 	IF(Answers.a_q6 = 4, 2, 
 		IF(Answers.a_q6 = 2, 4, 
 			IF(Answers.a_q6 = 1, 5, 3))))) AS a_q6,
 Answers.a_q7,
 (IF(Answers.a_q8 = 5, 1,
 	IF(Answers.a_q8 = 4, 2, 
 		IF(Answers.a_q8 = 2, 4, 
 			IF(Answers.a_q8 = 1, 5, 3))))) AS a_q8
 FROM Answers;

 --q4

SELECT positive_scale.a_id, (positive_scale.a_q1+positive_scale.a_q3+positive_scale.a_q5+positive_scale.a_q7)/4 AS construct_1, (positive_scale.a_q2+positive_scale.a_q4+positive_scale.a_q6+positive_scale.a_q8)/4 AS construct_2
FROM
(SELECT Answers.a_id, 
Answers.a_q1,
(IF(Answers.a_q2 = 5, 1,
 	IF(Answers.a_q2 = 4, 2, 
 		IF(Answers.a_q2 = 2, 4, 
 			IF(Answers.a_q2 = 1, 5, 3))))) AS a_q2,
Answers.a_q3,
(IF(Answers.a_q4 = 5, 1,
 	IF(Answers.a_q4 = 4, 2, 
 		IF(Answers.a_q4 = 2, 4, 
 			IF(Answers.a_q4 = 1, 5, 3))))) AS a_q4,
Answers.a_q5,
(IF(Answers.a_q6 = 5, 1,
 	IF(Answers.a_q6 = 4, 2, 
 		IF(Answers.a_q6 = 2, 4, 
 			IF(Answers.a_q6 = 1, 5, 3))))) AS a_q6,
 Answers.a_q7,
 (IF(Answers.a_q8 = 5, 1,
 	IF(Answers.a_q8 = 4, 2, 
 		IF(Answers.a_q8 = 2, 4, 
 			IF(Answers.a_q8 = 1, 5, 3))))) AS a_q8
 FROM Answers) positive_scale
 GROUP BY positive_scale.a_id;

 --q5

SELECT positive_scale.s_id, (AVG(positive_scale.a_q1)+AVG(positive_scale.a_q3)+AVG(positive_scale.a_q5)+AVG(positive_scale.a_q7))/4 AS construct_1, (AVG(positive_scale.a_q2)+AVG(positive_scale.a_q4)+AVG(positive_scale.a_q6)+AVG(positive_scale.a_q8))/4 AS construct_2
FROM
(SELECT Subjects.s_id, 
Answers.a_q1,
(IF(Answers.a_q2 = 5, 1,
 	IF(Answers.a_q2 = 4, 2, 
 		IF(Answers.a_q2 = 2, 4, 
 			IF(Answers.a_q2 = 1, 5, 3))))) AS a_q2,
Answers.a_q3,
(IF(Answers.a_q4 = 5, 1,
 	IF(Answers.a_q4 = 4, 2, 
 		IF(Answers.a_q4 = 2, 4, 
 			IF(Answers.a_q4 = 1, 5, 3))))) AS a_q4,
Answers.a_q5,
(IF(Answers.a_q6 = 5, 1,
 	IF(Answers.a_q6 = 4, 2, 
 		IF(Answers.a_q6 = 2, 4, 
 			IF(Answers.a_q6 = 1, 5, 3))))) AS a_q6,
 Answers.a_q7,
 (IF(Answers.a_q8 = 5, 1,
 	IF(Answers.a_q8 = 4, 2, 
 		IF(Answers.a_q8 = 2, 4, 
 			IF(Answers.a_q8 = 1, 5, 3))))) AS a_q8
 FROM Subjects LEFT JOIN Answers ON Answers.s_id = Subjects.s_id) positive_scale
 GROUP BY positive_scale.s_id;