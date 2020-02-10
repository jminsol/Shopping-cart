//
//  item.cpp
//  LAB 12
//
//  Created by JeongMinsol on 11/6/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "item.h"

    // Constructor
Item:: Item(string _id, string _desc, int _price){
        id = _id;
        desc = _desc;
        price = _price;
    }
    
    //Copy constructor
Item:: Item(const Item& other){
    *this = other;
}

    
    //Default constructor
Item::Item () {
    id = "";
    desc="";
    price=0;
    }
    
    //getter
    int Item::getPrice()
{
        return price;
    }
    
    //overloaded
    bool Item::operator==(const Item &other) const
{
    return this->id == other.id;
}
    
    //friend operator
ostream & operator<<(ostream & os, Item & obj){
    os << "ID: " << obj.id << " " << obj.desc << " unit price: $" << fixed << setprecision(2) << obj.price *0.01 << endl;
    return os;
}


