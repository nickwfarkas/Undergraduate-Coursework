//
//  main.cpp
//  Lab_01
//
//  Created by Nicholas Farkas on 1/13/21.
//

#include <iostream>
#include "Text.cpp"

int main(int argc, const char * argv[]) {
    char * test;
    
    char first[6] = "hello";
    
    char second[8] = "goodbye";
    
    test = first;
    
    Text t(test);
    
    test = second;
    
    cout<<t[0];
    
    
    
    return 0;
}
