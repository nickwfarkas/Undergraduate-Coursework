
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include "Text.h"

Text::Text ( const char *charSeq )
{
    bufferSize = int(strlen(charSeq)) + 1;
    buffer = new char(bufferSize);
    strcpy(buffer,charSeq);
}

Text::Text ( const Text &other )
{
    bufferSize = other.bufferSize;
    buffer = other.buffer;
    strcpy(buffer, other.buffer);
}

void Text::operator = ( const Text &other )
{
    if(other.bufferSize > bufferSize)
    {
        free(buffer);
        buffer = new char(other.bufferSize);
    }
    strcpy(buffer, other.buffer);
}

Text::~Text ()
{
    delete buffer;
}

int Text::getLength () const
{
    return bufferSize;
}

char Text::operator [] ( int n ) const
{
    if(n >= strlen(buffer))
    {
        return '\0';
    }
    else
    {
        return buffer[n];
    }
}

void Text::clear ()
{
    strcpy(buffer, "");
}

void Text::showStructure() const

// Outputs the characters in a string. This operation is intended for
// testing/debugging purposes only.

{
    int j;   // Loop counter

    for (j = 0; j < bufferSize; j++)
        cout << j << "\t";
    cout << endl;
    for (j = 0; buffer[j] != '\0'; j++)
        cout << buffer[j] << "\t";
    cout << "\\0" << endl;
}

Text Text::toUpper( ) const
{
    Text temp;
    for(int i = 0; this->getLength(); i++)
    {
        temp.buffer += toupper(buffer[i]);
        temp.bufferSize += 1;
    }
    temp.buffer+='\0';
    return temp;
}

Text Text::toLower( ) const
{
    Text temp;
    for(int i = 0; this->getLength(); i++)
    {
        temp.buffer += tolower(buffer[i]);
        temp.bufferSize += 1;
    }
    temp.buffer+='\0';
    return temp;
}

bool Text::operator == ( const Text& other ) const
{
    if(strcmp(buffer, other.buffer) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Text::operator <  ( const Text& other ) const
{
    if(strcmp(buffer, other.buffer) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Text::operator >  ( const Text& other ) const
{
    if(strcmp(buffer, other.buffer) > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

