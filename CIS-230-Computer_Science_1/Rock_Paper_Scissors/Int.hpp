//
//  Int.hpp
//  Rock_Paper_Scissors
//
//  Created by Nicholas Farkas on 5/9/20.
//  Copyright © 2020 Nicholas Farkas. All rights reserved.
//

#ifndef Int_hpp
#define Int_hpp

#include <stdio.h>

class Int
{
public:
    int i;
    
    Int();
    Int(int);
    Int& operator ++();
};

#endif /* Int_hpp */
