/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Coding 7, Binary Search Tree
File: bintree.h
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"
#include <iostream>
#include <iomanip>
#include <algorithm>


using std::cout;
using std::endl;
using std::string;

class BinTree {
public:
    BinTree();

    bool isEmpty();                     //test for is empty, return T/F

    int getCount();                     //return count

    bool getRootData(Data*);            /*pass (by reference) an “empty” Data struct from
                                        main() and fill it with root’s data if the tree is not empty, otherwise place -1 and an
                                        empty string in the struct. Return T/F based on if data was retrieved.*/

    void displayTree();                 /* Display all stats for the tree as shown in the examples and
                                        // call all display order methods.*/

    void clear();                       //deallocate the tree and set it back to “empty.”

    bool addNode(int, const string*);   //pass in and return the same as in previous
                                        //structures from previous assignments.
    bool removeNode(int);               //pass in and return the same as previous structures

    bool getNode(Data*, int);           //pass in and return the same as previous structures.
                                        //you must use binary search search to retrieve the Node.
    bool contains(int);                 //pass in and return the same as previous structures

    int getHeight();                    //dynamically calculate the height of the tree (do not store height,
                                        //calculate it each time getHeight() is called.
    void displayPreOrder();             //do a pre-order traversal, printing as you go

    void displayPostOrder();            //do a post-order traversal, printing as you go

    void displayInOrder();              //do an in-order traversal, printing as you go
    ~BinTree(); //Destructor
    int count = 0;
    DataNode *root;
    DataNode* minValueNode(DataNode*);
private:
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**); //DONE
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
};


#endif /* BINTREE_BINTREE_H */

