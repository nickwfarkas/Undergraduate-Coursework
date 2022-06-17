def correlation(xList, yList):
    import statistics
    xBar = statistics.mean(xList)
    yBar = statistics.mean(yList)
    xStd = statistics.stdev(xList)
    yStd = statistics.stdev(yList)
    num = 0.0
    for i in range(len(xList)):
	    num = num + (xList[i] - xBar) * (yList[i] - yBar)
    corr = num / ((len(xList) - 1) * xStd * yStd)
    return corr
