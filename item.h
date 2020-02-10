//
//  item.h
//  CS201 Assignment
//
//  Created by JeongMinsol on 11/6/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

// Represents a product for sale

using namespace std;

class Item {
protected:
    string id, desc;
    int price;

public:
    Item(string _id, string _desc, int _price);
    Item(const Item & other);
    Item();
    
    // getters
    int getPrice();
    bool operator==(const Item & other) const;
    friend ostream & operator<<(ostream &, Item &);
};


#endif // ITEM_H
