//
//  shopping.cpp
//  lab 12
//
//  Created by JeongMinsol on 11/20/19.
//  Copyright © 2019 JeongMinsol. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <map>

#include "catalog.h"
#include "cart.h"
#include "item.h"

using namespace std;

int main() {
    
    cout << "Simple Shopping cart program" << endl << endl;
    
    char answer;
    string fname, prd_id;
    bool right = true;
    Catalog list;
    
    // Ask user if they want to use the default catalog
    while (right)
    {
    cout << "Do you want to use the default catalog (y/n)? ";
    cin >> answer;
    
    switch (answer) {
            //When they want to use default constructor
        case 'y':
        case 'Y':
        {
            //Call the default Catalog constructor
            list = Catalog ();
            right = false;
            break;
        }
         
        case 'n':
        case'N':
        {
            //Retreive catalog from a text file
            cout << "Enter catalog file name (no spaces): ";
            cin >> fname;
            //Call the other version of constructor
            list = Catalog(fname);
            right = false;
            break;
        }
            //when a user enter invalid character, let them do it again
        default:
            cerr << "Unrecognized character." << endl;
            break;
    }
    }
    //Create cart for shopping cart from catalog
    Cart cart;
    
    do {
        
        cout << "Here is what is for sale: " << endl;
        cout << list;
        cout << "What would you like to buy? Enter the product ID: ";
        cin >> prd_id;
        
        //Cart is creating by += operator
        cart += list.get(prd_id);
        
        cout << "Your cart now has" << endl;
        cout << cart;
        
        cout << "\nDo you want to buy anything more? (y/n) ";
        cin >> answer;
        
    }
    //Repeat buying action until they said soemthing else other than 'y'
    while (answer == 'y' || answer == 'Y');
    
    //Show them a total
    cout << "Your total comes to : $" << cart.total() << endl;
    
    return 0;
}
