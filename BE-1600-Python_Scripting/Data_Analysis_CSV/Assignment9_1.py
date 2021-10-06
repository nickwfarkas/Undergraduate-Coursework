import csv
import sys

def csvExtract(fileName):
    with open(fileName) as csvFile:
        nums = [1,5,7,11,13]
        mins = []
        maxs = []
        skipHeads(csvFile,5)
        csvReader = csv.reader(csvFile,delimiter=',')
        headers = next(csvReader)
        for i in nums:
            mins.append(findMin(csvReader,i))
            skipHeads(csvFile,6)
        for i in nums:
            maxs.append(findMax(csvReader,i))
            skipHeads(csvFile,6)
    csvFile.close()
    printFormat(headers,mins,maxs)

def findMax(csvReader,col):
    maxValue = ['',0]
    for row in csvReader:
        if float(removePercent(row[col])) > float(maxValue[1]):
            maxValue[0] = row[0]
            maxValue[1] = removePercent(row[col])
    return maxValue

def findMin(csvReader,col):
    maxValue = ['',sys.maxsize]
    for row in csvReader:
        if float(removePercent(row[col])) < float(maxValue[1]):
            maxValue[0] = row[0]
            maxValue[1] = removePercent(row[col])
    return maxValue

def removePercent(value):
    return value.strip('%')

def skipHeads(csvFile,j):
    csvFile.seek(0)
    for i in range(j):
        next(csvFile)

def printFormat(headers,mins,maxs):
    nums = [1,5,7,11,13]
    print("{0:<31s}: {1:<25s} {2:>5s}  {3:<20s} {4:>5s}".format("Indicator","Min","","Max",""))
    print(92*'-')
    for i in range(len(nums)):
        print("{0:<31s}: {1:<25s} {2:>5s}  {3:<20s} {4:>5s}".format(headers[nums[i]],mins[i][0],str(mins[i][1]),maxs[i][0],str(maxs[i][1])))

csvExtract("riskfactors.csv")
