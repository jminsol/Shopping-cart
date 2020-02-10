//
//  cart.hpp
//  lab 12
//
//  Created by JeongMinsol on 11/17/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#ifndef cart_hpp
#define cart_hpp

#include <iostream>
#include <ostream>
#include <vector>

#include <stdio.h>
#include "counteditem.hpp"

using namespace std;

class Cart {
    
private:
    vector<countedItem> shopping_cart;
   
    
public:
    //No constructor
    Cart& operator += (Item &item);
    float total();
    friend ostream & operator<<(ostream & os, Cart & obj);
};

#endif /* cart_hpp */
