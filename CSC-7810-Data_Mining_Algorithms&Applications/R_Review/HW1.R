df <- read.csv("HW1.csv",header = F)

NU1 <- c(3,NA,5,4,2,3,NA,5)
NU2 <- c(NA,5,2,2,4,NA,1,3)

c1 <- numeric(20)
c2 <- numeric(20)

# U1, U5, U6
for(i in 1:20){
  temp <- as.numeric(df[i,])
  c1[i] <- cor(temp, NU1, use = "complete.obs")
}

# U2, U5, U20
for(i in 1:20){
  temp <- as.numeric(df[i,])
  c2[i] <- cor(temp, NU2, use = "complete.obs")
}
c1

df <- df[is.na(df)] <- 0

(df[2,1]*c1[1])+()

c <- cor(as.numeric(df[1:20,]), NU2, use = "complete.obs")
