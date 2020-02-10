//
//  catalog.h
//  lab 12
//
//  Created by JeongMinsol on 11/17/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#ifndef catalog_h
#define catalog_h

#include <iostream>
#include <fstream>
#include <map>
#include "item.h"


using namespace std;

class Catalog : public Item {
//protected:
//    string id;
    
private:
    string filename;
    //map for item info depending on its id
    map<string,Item*> catl;
public:
    //two constructor; basic and one string parameter
    Catalog();
    Catalog(const string& filename);
    Item& get(string input);
    friend ostream & operator<<(ostream &, Catalog &);

};

#endif /* catalog_h */
