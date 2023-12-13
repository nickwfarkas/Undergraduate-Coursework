//Nicholas Farkas
//Sales Report Assignment

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void readFile(int *, int *, float *, string *);
void populateArrays(int *, int *, float *, string *);
void numberToMonth(int *, string *);
void writeFile(int *, string *, float *);
float monthlyTotals(string *, string, float *);

int main()
{
    int numericMonth[5];
    int id[5];
    float sales[5];
    string line[5];

    readFile(id, numericMonth, sales, line);

    return 0;
}

//takes in user file
void readFile(int id[5], int numericMonth[5], float sales[5], string line[5])
{
    ifstream inputfile;

    string filename;

    string month[5];

    cout<< "Enter the file name you want to open: ";
    cin >> filename;

    inputfile.open(filename);

    int i = 0;

    while (!inputfile.eof())
    {
        getline(inputfile, line[i]);
        i++;
    }

    inputfile.close();

    populateArrays(id, numericMonth, sales, line);

    numberToMonth(numericMonth, month);

    writeFile(id, month, sales);
}

//Organizes information and prints it to file
void writeFile(int id[5], string month[5], float sales[5])
{
    ofstream outputFile;
    
    string filename;

    float octoberSales = monthlyTotals(month, "October", sales);
    float novemberSales = monthlyTotals(month, "November", sales);
    float decemberSales = monthlyTotals(month, "December", sales);

    cout<< "Enter your file name (No Spaces): ";
    cin >> filename;
    
    outputFile.open(filename);
    
    outputFile<<"                         Koz's Klunkers"<<endl;
    outputFile<<"              2019 Used Car Quarterly Sales Report"<<endl;
    outputFile<<"Sales Person ID            Month of Sale           Amount of Sales"<<endl;
    outputFile<<"=================================================================="<<endl;
    outputFile<<"   "<<id[0]<<"                         "<<month[0]<<"                  $   "
        <<fixed<<setprecision(2)<<sales[0]<<endl;
    outputFile<<"   "<<id[1]<<"                         "<<month[1]<<"                 $   "
        <<fixed<<setprecision(2)<<sales[1]<<endl;
    outputFile<<"   "<<id[2]<<"                         "<<month[2]
        <<"                 $   "<<fixed<<setprecision(2)<<sales[2]<<endl<<endl;

    outputFile<<"Total Sales:                              $ "
        <<fixed<<setprecision(2)<<(sales[0]+sales[1]+sales[2])<<endl;
    outputFile<<"Commission:                               $ "
        <<fixed<<setprecision(2)<<(.26*(sales[0]+sales[1]+sales[2]))<<endl<<endl;

    outputFile<<"   "<<id[3]<<"             "<<month[3]<<"       $   "
        <<fixed<<setprecision(2)<<sales[3]<<endl;
    outputFile<<"   "<<id[4]<<"             "<<month[4]<<"       $   "
        <<fixed<<setprecision(2)<<sales[4]<<endl<<endl;

    outputFile<<"Total Sales:                              $ "
        <<fixed<<setprecision(2)<<(sales[3]+sales[4])<<endl;
    outputFile<<"Commission:                               $ "
        <<fixed<<setprecision(2)<<(.26*(sales[3]+sales[4]))<<endl<<endl;

    outputFile<<"                       Monthly Totals Summary"<<endl;
    outputFile<<"=================================================================="<<endl<<endl;

    outputFile<<"   October              $   "<<fixed<<setprecision(2)<<octoberSales<<endl;
    outputFile<<"   November             $   "<<fixed<<setprecision(2)<<novemberSales<<endl;
    outputFile<<"   December             $   "<<fixed<<setprecision(2)<<decemberSales<<endl<<endl;

    outputFile<<"Total Quarterly Sales:                               $ "
        <<fixed<<setprecision(2)<<(octoberSales + novemberSales + decemberSales)<<endl;
    outputFile<<"Total Commission Paid:                               $ "
        <<fixed<<setprecision(2)<<(.26*(octoberSales + novemberSales + decemberSales))<<endl<<endl;


    cout<<"Success"<<endl;
    
    outputFile.close();
    
}

//Calculates monthly totals for sales
float monthlyTotals(string monthAr[5], string month, float sales[5])
{
    float salesTotal = 0;

    for(int i = 0; i < 5; i++)
    {
        if (monthAr[i] == month)
        {
            salesTotal += sales[i];
        }
    }
    return salesTotal;
}

//Populates arrays of information taken from file
void populateArrays(int id[5], int month[5], float sales[5], string line[5])
{
    for(int i = 0; i < 5; i++)
    {
        id[i] = stoi(line[i].substr(0,4));
        month[i] = stoi(line[i].substr(5,6));
        sales[i] = stof(line[i].substr(8,14));
    }
}

//Converts months number to string
void numberToMonth(int numberMonth[5], string wordMonth[5])
{
    
    for(int i = 0; i < 5; i++)
    {
        switch (numberMonth[i])
        {
        case 1:
            wordMonth[i] = "January";
            break;
        case 2:
            wordMonth[i] = "Feburary";
            break;
        case 3:
            wordMonth[i] = "March";
            break;
        case 4:
            wordMonth[i] = "April";
            break;
        case 5:
            wordMonth[i] = "May";
            break;
        case 6:
            wordMonth[i] = "June";
            break;
        case 7:
            wordMonth[i] = "July";
            break;
        case 8:
            wordMonth[i] = "August";
            break;
        case 9:
            wordMonth[i] = "September";
            break;
        case 10:
            wordMonth[i] = "October";
            break;
        case 11:
            wordMonth[i] = "November";
            break;
        case 12:
            wordMonth[i] = "December";
            break;
        default:
            wordMonth[i] = "Default";
            break;
        }
    }

}




