/*
 
 Nick Farkas
 
 CIS 170 - 70
 
 Batting Average and ERA Calculator
 
 */

#include <stdio.h>

float calcAvg(float, float);
float getHits(void);
float getAtBats(void);

int main()
{
    float battingAvg = 0;
    float earnedRunAvg = 0;
    
    
    return 0;
}

void outputBattingAvg()
{
    
}

float calcAvg(float dividend, float divisor)
{
    float avg = 0;
    avg = dividend / divisor;
    return avg;
}

float calcBattingAvg()
{
    float hits = 0;
    float atBats = 0;
    
    atBats = getAtBats();
    hits = getHits();
    
    return calcAvg(atBats, hits);
}

float getAtBats()
{
    float atBats = 0;
    printf("Please enter the number of at bats for the batter: ");
    scanf("%f", &atBats);
    return atBats;
}

float getHits()
{
    float hits = 0;
    printf("Please enter the number of hits for the batter: ");
    scanf("%f", &hits);
    return hits;
}

