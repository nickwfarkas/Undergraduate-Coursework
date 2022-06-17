#Calculate the t-statistic for the difference in unemployment rate between July 2019 and July 2020. The data are below. Make the answer a positive number and round it to the nearest tenth.

# Country	A	B	C	D	E	F
# July 2019	3.6	4.0	5.5	12.0	10.5	7.0
# July 2020	6.9	7.0	9.0	14.3	13.2	10.0


J2019 <- c(3.6, 4.0, 5.5, 12.0, 10.5, 7.0)
J2020 <- c(6.9, 7.0, 9.0, 14.3, 13.2, 10.0)

t.test(J2020-J2019)
