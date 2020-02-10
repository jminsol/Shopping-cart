//
//  counteditem.cpp
//  LAB 12
//
//  Created by JeongMinsol on 11/6/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#include <iomanip>
#include "counteditem.hpp"
#include "item.h"

//Default constructor
countedItem:: countedItem(): Item(){
    count=0;
    id="";
    desc="";
    price =0;
}

//constructor
countedItem:: countedItem (const Item &rhs) : Item(rhs) {
    Item::operator=(rhs);
    count=1;
}

// function add1
void countedItem:: add1 (){
    count +=1;
}

//getPrice() overriding
int countedItem:: getPrice() {
    int cost;
    cost = count*price;
    
    return cost;
}


//output operator
ostream & operator<<(ostream & os, countedItem & obj){
    os << "ID: " << obj.id << " " << obj.desc << " unit price: $" << fixed << setprecision(2) << obj.price *0.01
    << " quantity: " << obj.count << endl;
    return os;
}

