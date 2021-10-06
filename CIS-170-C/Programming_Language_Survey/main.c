//
//  Nicholas Farkas
//  Ch2_Hw1_P1
//  09-11-19
//  Program 1
//  Survey's Students on Programming Languages
//


#include <stdio.h>

int main()
{
    int html = 0;
    int java = 0;
    int cPlusPlus = 0;
    int cSharp = 0;
    int javaScript = 0;
    int php = 0;
    int python = 0;
    int studentTotal = 0;
    int web = 0;
    int oop;
    
    // Data in
    printf("Welcome to the Programming Survey 2019\n");
    printf("Please Enter the Total number of Students who know:\n");
    printf("HTML: ");
    scanf("%i", &html);
    printf("Java: ");
    scanf("%i", &java);
    printf("C++: ");
    scanf("%i", &cPlusPlus);
    printf("C#: ");
    scanf("%i", &cSharp);
    printf("JavaScript: ");
    scanf("%i", &javaScript);
    printf("PhP: ");
    scanf("%i", &php);
    printf("Python: ");
    scanf("%i", &python);
    
    //Calculations
    studentTotal = (html + java + cPlusPlus + cSharp + javaScript + php + python);
    web = (html + javaScript + php);
    oop = (java + cSharp + cPlusPlus + python);
    
    //Data Out
    printf("\nTotal Students: %i \n", studentTotal);
    printf("Total who know Web Languages: %i \n", web);
    printf("Total who know Object Oriented Languages: %i \n", oop);
    
}


