#include<stdlib.h>
#include<stdio.h>

void ApplyToA(int s);
void ReadB(int s);

int main()
{
    int seed = 100;
    
    ApplyToA(seed);
    ReadB(seed);
    
    return 0;
}

void ApplyToA(int s)
{
    FILE *fpread;
    FILE *fpwrite;
    srand(s);
    
    fpread = fopen("A.txt", "r");
    fpwrite = fopen("B.txt", "w");
    char temp = ' ';

    while(!feof(fpread))
    {
        int num = (int)(fgetc(fpread))-48;
        
        if(num != 0 && num != 1)
        {
             continue;
        }
        
        temp = (char)((num^(rand()%2))+48);

        fputc(temp, fpwrite);
    }
    
    fclose(fpread);
    fclose(fpwrite);
}

void ReadB(int s)
{
    FILE *fpread1;
    FILE *fpread2;
    srand(s);
    
    fpread1 = fopen("A.txt", "r");
    fpread2 = fopen("B.txt", "r");
    
    while(!feof(fpread2))
    {
        int num1 = (int)(fgetc(fpread2))-48;
        int num2 = (int)(fgetc(fpread1))-48;
        
        if(num1 != 0 && num1 != 1)
        {
            continue;
        }
        
        int c = num1^(rand()%2);
    }
    
    fclose(fpread1);
    fclose(fpread2);
}
