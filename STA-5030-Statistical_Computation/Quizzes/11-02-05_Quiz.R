X <- c(6.5, 15.5, 15.2, 10.8, 3.7, 11.2, 11.2, 10.5, 6.8, 5.1, 5.7, 5.9, 6.8, 4.1, 10.4)
Y <- c("X1","X1","X1","X1","X1","X1","X2","X2","X2","X2","X2","X3","X3","X3","X3")
Z <- pairwise.t.test(X, Y, pool.sd = TRUE, p.adjust.method="bonferroni")
Z$p.value

K <- kruskal.test(X,Y)

