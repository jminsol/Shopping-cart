//
//  main.cpp
//  HW 7
//
//  Created by JeongMinsol on 11/17/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip> // for setprecision(2)


#include "catalog.h"
#include "item.h"

//default catalog
Catalog:: Catalog() : Item(){

    Item apple("4403", "apple", 50),
    banana("4468", "banana", 29),
    cantaloupe("4093", "cantaloupe", 299);

    catl.insert(pair<string, Item*> ("4403", new Item (apple)));
    catl.insert(pair<string, Item*> ("4468", new Item (banana)));
    catl.insert(pair<string, Item*> ("4093", new Item (cantaloupe)));
    
}

//When they receive one string parameter
Catalog:: Catalog(const string& filename) {
    
    //read text file
    ifstream cart;
    cart.open(filename);

    if(!cart.good())
        cerr << "File is not open" << endl;
    else{
        while(cart.good()){
            //read id and price each since they are seperated with space
            while(cart >> id >> price){
                //get the rest of string for description
                getline(cart, desc);
                catl.insert(pair<string, Item*> (id, new Item(id, desc, price)));
            }
        }
    }
}

//Support get(string)
//Retreieve info from id of map
Item& Catalog:: get(string input){
    return *catl[input];
}
// print the info from catalog
ostream & operator<<(ostream & out, Catalog & obj){
    auto allCatl = obj.catl;
    for (auto it = allCatl.begin(); it!= allCatl.end(); it ++)
        out << *it -> second;
    return out;
}



