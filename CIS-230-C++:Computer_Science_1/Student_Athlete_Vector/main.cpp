
#include <iostream>
#include <iomanip>
#include <vector>
#include "Athlete.hpp"
#include "Student.hpp"

using namespace std;

float Athlete::athleticFee = 125.50;

int displayMenu();
int getMenuChoice();
void addStudent(vector<Student> &students, vector<Athlete> &athlete);
int getGrade();
int playsSport();
void displayOneStudent(vector<Student> students);
void displayStudents(vector<Student> students);
void displayStudentsByGrade(vector<Student> students);
void displayAthletes(vector<Athlete> athletes);
void displayStudentsBySport(vector<Athlete> athletes);
void displayAthleteGradeSport(vector<Athlete> athletes, vector<Student> students);


int main()
{
    vector<Student> students;
    vector<Athlete> athletes;
    
    int userChoice = 0;
    
    while (userChoice != 8)
    {
        userChoice = displayMenu();
        
        switch (userChoice) {
            case 1:
                addStudent(students, athletes);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                displayOneStudent(students);
                break;
            case 4:
                displayAthletes(athletes);
                break;
            case 5:
                displayStudentsByGrade(students);
                break;
            case 6:
                displayStudentsBySport(athletes);
                break;
            case 7:
                displayAthleteGradeSport(athletes, students);
                break;
            case 8:
                cout<<endl<<"Thank you for using this program!"<<endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

int displayMenu()
{
    cout<<"Please choode from the following menu"<<endl;
    cout<<"1: Add student\n2: Print a list of enrolled students\n3: Print a list of students by last name\n4: Print a list of students who play sports\n5: Print a list of students by grade\n6: Print a list of students by sport\n7: Print a list of students by grade and sport\n8: Exit program"<<endl;
    
    return getMenuChoice();
}

int getMenuChoice()
{
    int choice;
    
    cin>>choice;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<endl<<"Not a valid entry please try again!"<<endl;
        displayMenu();
    }
    else if(choice > 7 || choice < 1)
    {
        cout<<endl<<"Please make a choice 1-7"<<endl;
        displayMenu();
    }
    
    return choice;
}

void addStudent(vector<Student>& student, vector<Athlete>& athlete)
{
    string firstName;
    string lastName;
    int grade;
    int playSport;
    string sport;
    
    cin.ignore(100, '\n');
    
    cout<<"What is the sudent's first name: ";
    getline(cin,firstName);
    
    cout<<"What is the sudent's last name: ";
    getline(cin, lastName);
    
    grade = getGrade();
    
    cout<<endl<<"Does your the student play a sport (1 - Yes, 2 - No): ";
    playSport = playsSport();
    
    Student stu(lastName, firstName, grade);
    
    cout<<endl;
    int i = 0;
    while (playSport == 1)
    {
        cin.ignore(100, '\n');
        
        cout<<"What sport does the student play: ";
        getline(cin, sport);
        
        athlete.insert(athlete.begin() + i, Athlete(firstName, lastName, sport));
        stu += Athlete::athleticFee;
        
        cout<<"Does your the student play another sport (1 - Yes, 2 - No): ";
        playSport = playsSport();
        i++;
    }
    
    student.insert(student.end(), stu);
}

int playsSport()
{
    int sport;
    
    cin>>sport;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<endl<<"Not a valid entry please try again!"<<endl;
        playsSport();
    }
    else if(sport > 2 || sport < 1)
    {
        cout<<endl<<"Please make enter 1 for yes or 2 for no"<<endl;
        playsSport();
    }
    
    return sport;
}

int getGrade()
{
    int grade;
    
    cout<<"What is the student's grade: ";
    cin>>grade;
    
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout<<endl<<"Not a valid entry please try again!"<<endl;
        getGrade();
    }
    else if(grade > 12 || grade < 9)
    {

        cout<<endl<<"Please make enter a grade 9-12"<<endl;
        getGrade();
    }
    
    return grade;
}

void displayStudents(vector<Student> students)
{
    cout<<endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout<<students[i]<<endl;
    }
}

void displayOneStudent(vector<Student> students)
{
    bool printedName = false;
    string lastName;
    cout<<"Enter the last name of the student: ";
    cin>>lastName;
    
    cout<<endl;
    for (int i = 0; i < students.size(); i++)
    {
        if(students[i] == lastName)
        {
            cout<<endl<<students[i]<<endl;
            printedName = true;
        }
    }
    if (!printedName)
    {
        cout<<"No students with last name of "<<lastName<<endl;
    }
}

void displayAthletes(vector<Athlete> athletes)
{
    cout<<endl;
    for (int i = 0; i < athletes.size(); i++)
    {
        cout<<athletes[i]<<endl;
    }
}

void displayStudentsByGrade(vector<Student> students)
{
    int grade = getGrade();
    
    cout<<endl;
    for (int i = 0; i < students.size(); i++)
    {
        if(students[i] == grade)
        {
            cout<<students[i]<<endl;
        }
    }
}

void displayStudentsBySport(vector<Athlete> athletes)
{
    cin.ignore(100, '\n');
    string sport;
    cout<<"What sport would you like to see a list of students: ";
    getline(cin, sport);
    
    cout<<endl;
    for (int i = 0; i < athletes.size(); i++)
    {
        if(athletes[i] == sport)
        {
            cout<<athletes[i]<<endl;
        }
    }
}

void displayAthleteGradeSport(vector<Athlete> athletes, vector<Student> students)
{
    cin.ignore(100, '\n');
    bool printedStudent = false;
    string sport;
    int grade;
    string tempLast;
    cout<<"What sport would you like to see: ";
    getline(cin, sport);
    
    cout<<"In which grade?"<<endl;
    grade = getGrade();
    
    for (int i = 0; i < athletes.size(); i++)
    {
        if (athletes[i] == sport)
        {
            tempLast = athletes[i].getLast();
            for (int j = 0; j < students.size(); j++)
            {
                if (students[j] == tempLast && students[j] == grade)
                {
                    cout<<students[j]<<endl;
                    printedStudent = true;
                }
            }
        }
    }
    
    if (!printedStudent)
    {
        cout<<"There is no student that plays "<<sport<<" and is in the "<<grade<<"th grade"<<endl;
    }
}
