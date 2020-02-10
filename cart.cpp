//
//  cart.cpp
//  lab 12
//
//  Created by JeongMinsol on 11/17/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>


#include "cart.h"
#include "counteditem.hpp"

using namespace std;
//operator += for Cart
Cart& Cart :: operator += (Item &item){
    //Get iterator for vector
    vector<countedItem>:: iterator it;
    
    
    it= find(shopping_cart.begin(), shopping_cart.end(), item);
    // when there is nothing same product in the shopping cart -> add that product to the shopping_cart
    if (it == shopping_cart.end())
        shopping_cart.push_back(item);
    //When there is same product, only increase quantity
    else
        it -> add1();
    
    return *this;
    
}


//total() to count the totla cost of all shopping cart items
float Cart:: total() {
    float total =0;
    //Calcultate all the price with iterator
    for (auto it = shopping_cart.begin(); it != shopping_cart.end(); it ++){
        total += it -> getPrice();
    }
    //Since the total price is in cents, change to dollars
    total = total * 0.01;
    return total;
}

// Display all the inforamtion of items in the shopping cart
ostream& operator<<(ostream & os, Cart & obj){
    auto sp = obj.shopping_cart;
    for( auto it = sp.begin() ; it!= sp.end(); it++)
        os << *it;
    return os;
}
