
#include <iostream>
#include "Outfit.hpp"
#include <vector>
using namespace std;

int displayMenu();
int displayShirts(vector<Shirt>);
int displayPants(vector<Pants>);
void displayOutfit(Shirt, Pants);
vector<Pants> replacePants(vector<Pants> pantsSelection);
vector<Shirt> replaceShirt(vector<Shirt> shirtSelection);
void displayOutFits(vector<Outfit> outfits);
int randomNumber();

int main()
{
    vector<Shirt> shirts;
    vector<Pants> pants;
    vector<Outfit> outfits;
    
    char keepGoing = 'y';
    int i = 0;
    string color;
    string temp;
    Shirt tempShirt(" ", " ");
    Pants tempPants(" ", " ");
    int userChoice;
    char happiness = 'n';
    char userShirt = 'n';
    int shirtChoice = -1;
    int pantChoice = -1;
    
    while (keepGoing == 'y')
    {
        cout<<"Enter the shirt color: ";
        cin>>color;
        tempShirt.setColor(color);
        cout<<"Enter the shirt type: ";
        cin>>temp;
        tempShirt.setType(temp);
        shirts.insert(shirts.begin()+i, tempShirt);
        i++;
        cout<<"Enter another shirt (y/n): ";
        cin>>keepGoing;
    }
    
    keepGoing = 'y';
    i = 0;
    
    while (keepGoing == 'y')
    {
        cout<<"Enter the pant color: ";
        cin>>color;
        tempShirt.setColor(color);
        cout<<"Enter the pant style: ";
        cin>>temp;
        tempShirt.setType(temp);
        pants.insert(pants.begin()+i, tempPants);
        i++;
        cout<<"Enter another pair of pants (y/n): ";
        cin>>keepGoing;
    }
    
    cout<<"Please choose from the following menu"<<endl;
    userChoice = displayMenu();
    
    while (happiness == 'n')
    {
        switch (userChoice)
        {
            case 1:
                cout<<"not available";
                break;
            case 2:
                shirtChoice = displayShirts(shirts);
                break;
            case 3:
                pantChoice = displayPants(pants);
                break;
            case 4:
                shirts = replaceShirt(shirts);
                break;
            case 5:
                pants = replacePants(pants);
            case 6:
                displayOutFits(outfits);
            default:
                break;
        }
        if(shirtChoice != -1 || pantChoice != -1)
        {
            cout<<"Are you happy with your choices of\nShirt: "<<shirts[shirtChoice-1]<< "Pants (y/n): "<<pants[pantChoice-1];
            cin>>happiness;
        }
    }
    
    int j;
    
    
    return 0;
}

int randomNumber()
{
    srand (time(NULL));
    int randomNumber = (rand()%5);
    return randomNumber;
}

int displayMenu()
{
    int userChoice;
    cout<<"1: Select a random outfit;\n2: Select a shirt from a list;\n3: Select a pair of pants from a list;\n4: Replace a shirt from your wardrobe;\n5: Replace a pair of pants from your wardrobe;\n6: Quit and display weekly outfits;"<<endl;
    cin>>userChoice;
    return userChoice;
}

int displayShirts(vector<Shirt> shirtSelection)
{
    int userChoice;
    for (int i = 0; i < shirtSelection.size(); i++)
    {
        cout<<i+1<<". "<<shirtSelection[i]<<endl;
    }
    cout<<endl<<"Which shirt would you like to wear: ";
    cin>>userChoice;
    
    return userChoice;
}

int displayPants(vector<Pants> pantsSelection)
{
    int userChoice;
    for (int i = 0; i < pantsSelection.size(); i++)
    {
        cout<<i+1<<". "<<pantsSelection[i]<<endl;
    }
    cout<<endl<<"Which pair of pants would you like to wear: ";
    cin>>userChoice;
    
    return userChoice;
}

void displayOutFits(vector<Outfit> outfits)
{
    for (int i = 0; i < outfits.size(); i++)
    {
        cout<<outfits[i]<<endl;
    }
}

void displayOutFit(Shirt shirt, Pants pant)
{
    cout<<"Shirt: ";
    cout<<shirt;
    cout<<" & "<<"Pants: ";
    cout<<pant<<endl;
}

vector<Pants> replacePants(vector<Pants> pantsSelection)
{
    int userChoice;
    for (int i = 0; i < pantsSelection.size(); i++)
    {
        cout<<i+1<<". "<<pantsSelection[i]<<endl;
    }
    cout<<endl<<"Which pair of pants would you like to replace your current pair with: ";
    cin>>userChoice;

    cin >> pantsSelection[userChoice];

    return pantsSelection;
}

vector<Shirt> replaceShirt(vector<Shirt> shirtSelection)
{
    int userChoice;
    for (int i = 0; i < shirtSelection.size(); i++)
    {
        cout<<i+1<<". "<<shirtSelection[i]<<endl;
    }
    cout<<endl<<"Which shirt would you like to replace your current shirt with: ";
    cin >> userChoice;
    
    cin >> shirtSelection[userChoice];
    
    return shirtSelection;
}

