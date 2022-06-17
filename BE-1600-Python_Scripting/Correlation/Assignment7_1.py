import csv

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

def correlation_of_petal_lengths():
    petalLengthCm = {}

    with open('Iris.csv') as csvFile:
        csvReader = csv.reader(csvFile, delimiter=',')
        next(csvReader)
        for row in csvReader:
            if (row[4] not in petalLengthCm.keys()):
                petalLengthCm[row[4]] = [float(row[2])]
            else:
                petalLengthCm[row[4]].append(float(row[2]))

    print("setosa petal length: "+str(petalLengthCm.get("Iris-setosa")))
    print("virginica petal length: "+str(petalLengthCm.get("Iris-virginica")))
    print("correlation between setosa and virginica petal length: "
          +str(round(correlation(petalLengthCm.get("Iris-setosa"),petalLengthCm.get("Iris-virginica")),2)))


correlation_of_petal_lengths()
