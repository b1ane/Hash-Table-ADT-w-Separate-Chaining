//
//  hash.h
//  Hash Table ADT using Separate Chaining
//
//  Created by blane on 10/22/22.
//

//using separate chaining -- uses linked list
//array based -- when collision occurs -- create LINKED list at array index

#ifndef hash_h
#define hash_h

#include <iostream>
#include <vector>
using namespace std;

struct node {
    int value; //value to insert
    int key; //accesses value (array index)
    node* next; //pointer to next node when collision occurs
    
};

class Hash {
private:
    //pointer to pointer to array/hashtable
    node **table;
    
public:
    //constructor -- creates table, sets all values to null
    Hash() {
        //node created, points to an array of size 10
        table = new node *[10];
        //loop through array (0-9)
        for(int i = 0; i < 10; i++) {
            table[i] = nullptr;
        }
    }
    
    //finds index to insert value
    int HashFunction(int val) {
        //hash function -- h(x) = val % 9
        int x = val % 9;
        return x;
    }
    
    void Insert(int val) {                //ex: val = 10
        //create new node to store value
        node *newNode = new node;
        newNode->value = val;
        newNode->key = HashFunction(val);      //key = 1
        newNode->next = nullptr;
        
        //to insert -- check if node in array already points to a node
        if (table[newNode->key] == nullptr) {     //checks table[1] = null
            table[newNode->key] = newNode;        //set new node
        }
        else {
            //if index is NOT empty -- insert newNode behind it
            table[newNode->key]->next = newNode;
        }
    }
    
    void Display() {
        //loop through table
        for( int i = 0; i < 10; i++ ) {
            node* cu = table[i];
            while (cu != nullptr) {
                cout << "INDEX: " << cu->key << endl;
                cout << "VALUE: " << cu->value << endl;
                cu = cu->next;
            }
        }
        cout << endl;
    }
    
    
    int Diff() { //add values in each NON-empty array index, output difference between min and max
        
        int x = 0;
        int counter = 0;
        int retVal = 0;
        
        //loop through table,counts number of non-empty indicies
        for(int i = 0; i < 10; i++) {
            if(table[i] != nullptr) {
                counter = counter + 1;
            }
        }
        
        //vector created, stores sum of values in each index
        vector<int> vec;
        
        for(int i = 0; i < 10; i++) {
            
            node* cu = table[i];
            while(cu != nullptr) {
                x = x + cu->value;
                cu = cu ->next;
                if(table[i] == nullptr) {
                    break;
                }
            }
            if(x!=0) {
                vec.push_back(x);
            }
            x = 0;
        }
         
        int max = 0;
        int min = 0;
        
        for( int i = 0; i < counter; i++) {
            int y = vec.at(0);
            if (y < vec.at(i)) {
                max = vec.at(i);
            }
            else {
                min = y;
            }
        }

        retVal = max - min;
        
        return retVal;
    }
    
    
    
    
    
    
};


#endif /* hash_h */
