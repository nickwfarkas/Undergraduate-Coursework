//Nicholas Farkas
//Car Class Assignment

#include<iostream>
#include <conio.h>
#include <ctime>
#include "Car.hpp"
#include "Car.cpp"

using namespace std;

double diffclock(clock_t, clock_t); 
double calcIdle(clock_t, clock_t);
bool yearValidation(int);
bool carDetailValidation(string);
void printDirections();

int main()
{
    int year;
    string make;
    string model;
    bool userStop = false;

    do
    {
        cout<<"Please enter the year of your car: ";
        cin>>year;
    }while (yearValidation(year) == false);
    
    cin.ignore(100, '\n');

    do
    {
        cout<<"Please enter the make of your car: ";
        getline(cin, make);
    } while (carDetailValidation(make) == false);

    do
    {
        cout<<"Please enter the model of your car: ";
        getline(cin, model);
    } while (carDetailValidation(model) == false);

    Car myCar(year, make, model);

    cout<<endl<<"Your "<<year<<" "<<make<<" "<<model<<" Gage:"<<endl;
    
    printDirections();

    myCar.printGage();

    clock_t start;
    clock_t stop;
    while (userStop == false)
    {
        if(myCar.getCarStatus())
        {
            start = clock();
        }

        int c = getch();

        switch (c = getch())
        {
            case 72:
                myCar.fillUp();
                break;
            case 80:
                if (!myCar.getCarStatus())
                {
                    myCar.startCar();
                    start = clock();
                }
                else
                {
                    myCar.shutOff();
                    stop = clock();
                    myCar.idling(calcIdle(start,stop));
                }
                break;
            case 75:
                myCar.brake();
                break;
            case 77:
                myCar.accelerate();
                break;
            case ' ':
                cout<<"You have chosen to exit"<<endl;
                userStop = true;
                break;

            default:
                printDirections();
                break;
        }

        stop = clock();

        if (myCar.getCarStatus())
        {
            myCar.idling(calcIdle(start,stop));
        }

        myCar.fuelToZero();

        myCar.printGage();
    }
    
    return 0;
}

void printDirections()
{
    cout<<"\nUse arrow keys"<<endl;
    cout<<"Up for fuel"<<endl;
    cout<<"Down to turn on and off"<<endl;
    cout<<"Left to break"<<endl;
    cout<<"Right for gas"<<endl;
    cout<<"Spacebar to exit\n"<<endl;
}

//Gets difference between two timers
double diffclock(clock_t clock1, clock_t clock2 ) 
{
    double diffticks = clock2 - clock1;
    double diffs = diffticks;

    return diffs;
}

//Calculates how long car has been idle and calculates fuel decrease
double calcIdle(clock_t start, clock_t stop)
{
    double diff;
    diff = diffclock(start, stop);

    return ((diff/1000)*.05);
}

//Validates User Year
bool yearValidation(int year)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"Not a valid entry please try again!"<<endl;
        return false;
    }
    else if (year > 2020 || year < 1900)
    {
        cout<<year<<" is not a valid year please try again!"<<endl;
        return false;
    }
    else
    {
        return true;
    }
}

//validates User Details for car
bool carDetailValidation(string userInput)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout<<"Not a valid entry please try again!"<<endl;
        return false;
    }
    else
    {
        return true;
    }
    
}


