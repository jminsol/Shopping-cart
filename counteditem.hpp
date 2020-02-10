//
//  counteditem.hpp
//  LAB 12
//
//  Created by JeongMinsol on 11/6/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#ifndef counteditem_hpp
#define counteditem_hpp

#include <iostream>
#include <string>

#include "item.h"

using namespace std;

class countedItem : public Item {
    
private: int count;
    
public:
    
    //Default constructor
    countedItem();
    
    // Constructor
    countedItem(const Item &item);
    
    //function
    void add1();
    
    //overrides
    int getPrice();
    
    //output operator
    friend ostream & operator<<(ostream &, countedItem &);
    
};
#endif /* counteditem_hpp */
