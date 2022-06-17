#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Systems
{
    char name[50];
    float price;
    int hardDrive;
    int quanity;
};

void printSystems(struct Systems[3]);
float sellSystem(int, struct Systems[3]);
float sellController(struct Systems inventory[3], int);
void sellGames(char *, int *);

int main()
{
    int mainMenuChoice = 0;
    int systemSelect = 0;
    int controllerSelect = 0;
    float systemCost = 0;
    float controllerCost = 0;
    float gameCost = 0;
    float gameTotal = 0;
    float systemTotal = 0;
    float controllerTotal = 0;
    int gameCount = 0;
    char * boughtgames[10];
    struct Systems inventory[3];
    strcpy(inventory[0].name, "Nintendo Switch");
    inventory[0].price = 299.99;
    inventory[0].hardDrive = 256;
    inventory[0].quanity = 5;
    strcpy(inventory[1].name, "PlayStation 4");
    inventory[1].price = 299.99;
    inventory[1].hardDrive = 1000;
    inventory[1].quanity = 10;
    strcpy(inventory[2].name, "XboxOne");
    inventory[2].price = 249.99;
    inventory[2].hardDrive = 500;
    inventory[2].quanity = 15;
    
    while(mainMenuChoice != 6)
    {
        printf("Please make a selection from the following options:\n1. Print Systems\n2. Buy Systems\n3. Buy Contollers\nSelection: ");
        scanf("%d", &mainMenuChoice);
        
        switch(mainMenuChoice)
        {
            case 1:
                printSystems(inventory);
                break;
            case 2:
                printf("Which system would you like to buy?\n1. Nintendo Sitch\n2. Playstation 4\n3. Xbox One\nSelection: ");
                scanf("%d", &systemSelect);
                systemCost = sellSystem(systemSelect, inventory);
                systemTotal = systemTotal + systemCost;
                break;
            case 3:
                printf("Which controller would you like to buy?\n1. Nintendo Sitch Pro Controller $69.99\n2. Playstation 4 DualShock Controller $59.99\n3. Xbox One Controller $49.99\nSelection: ");
                scanf("%d", &controllerSelect);
                controllerCost = sellController(inventory, controllerSelect);
                controllerTotal = controllerTotal + controllerCost;
                break;
                
                
                
        }
    }
    
    
    return 0;
}

void printSystems(struct Systems inventory[3])
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        if(inventory[i].hardDrive > 999)
        {
            printf("%d. System Name: %s, Price: %.2f, Harddrive: %dTB, Quantity: %d\n",
                   i + 1, inventory[i].name, inventory[i].price, (inventory[i].hardDrive)/1000, inventory[i].quanity);
        }
        else
        {
            printf("%d. System Name: %s, Price: %.2f, Harddrive: %dGB, Quantity: %d\n",
                   i + 1, inventory[i].name, inventory[i].price, inventory[i].hardDrive, inventory[i].quanity);
        }
    }
}

float sellSystem(int system, struct Systems inventory[3])
{
    int userQuanity = 0;
    
    printf("How many %s?", inventory[system-1].name);
    scanf("%d", &userQuanity);
    
    return (inventory[system-1].price * userQuanity);
}

float sellController(struct Systems inventory[3], int controller)
{
    int userQuanity = 0;
    float price = 0;
    int j = system - 1;
    switch(controller)
    {
        case 1:
            price = 69.99;
            break;
        case 2:
            price = 59.99;
            break;
        case 3:
            price = 49.99;
            break;
        case 6:
            break;
    }
    printf("How many %s controllers?", inventory[j].name);
    scanf("%d", &userQuanity);
    
    return (price * userQuanity);
}

void intbuffer()
{
    int buff;
    scanf("%d", &buff);
}

void charbuffer()
{
    char buff[50];
    scanf("%s", buff);
}

