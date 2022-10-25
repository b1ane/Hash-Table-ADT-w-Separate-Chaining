//
//  main.cpp
//  Hash Table ADT using Separate Chaining
//
//  Created by blane on 10/21/22.
//

#include <iostream>
#include <string>
using namespace std;
#include "hash.h"
#include <sstream>

int main() {
    //given string representing an array of int
    string input;
    getline(cin, input);
    
    stringstream ss(input);
    
    Hash table;
    
    while (ss>>input) {
        int num = stoi(input);
        table.Insert(num);
    }
    
    table.Display();
    
    
    return 0;
}
