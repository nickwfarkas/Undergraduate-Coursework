//
//
//  InClass Assignment 5
//
//  Created by Nicholas Farkas, Lewis Tensley on 11/20/19.
//
//

#include <stdio.h>

void inputTaxData(float *, float *, float *);

void calculateTaxes(float, float, float, float *, float *, float *);

void displayTaxData(float, float, float);

int main()
{
    float cRate;
    float sRate;
    float totalSales;
    float county;
    float state;
    float total;
    
    inputTaxData(&cRate, &sRate, &totalSales);
    
    calculateTaxes(cRate, sRate, totalSales, &county, &state,&total);
    
    displayTaxData(county, state, total);
    
    return 0;
}

//Gets input from user

void inputTaxData(float * cRate, float * sRate, float * totalSales)
{
    printf("The amount of county sales tax percentage: ");
    scanf("%f", cRate);
    
    printf("The amount of state sales tax percentage: ");
    scanf("%f", sRate);
    
    printf("The total sales for month: ");
    scanf("%f", totalSales);
}

//Calculates Taxes From User Input

void calculateTaxes(float cRate, float sRate, float totalSales, float * county, float * state, float * totalS)
{
    float countyTax;
    float stateTax;
    float total;
    
    //Calculates County Tax
    countyTax = (cRate/100) * totalSales;
    
    //Calculates State Tax
    stateTax = (sRate/100) * totalSales;
    
    //Calculates Total Tax
    total = stateTax + countyTax;
    
    //Pointers Dereference
    
    *county = countyTax;
    
    *state = stateTax;
    
    *totalS = total;

}

//View Results

void displayTaxData(float county, float state, float total)
{
    printf("The amount of county sales tax: $%.2f\n", county);
    printf("The amount of state sales tax: $%.2f\n", state);
    printf("The total sales tax: $%.2f\n", total);
}
