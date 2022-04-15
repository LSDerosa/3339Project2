/*
 * Your comment header here
 */

#include "bintree.h"


BinTree::BinTree() {
    root = nullptr;
}



bool BinTree::isEmpty(){
    return 0;
}                   //test for is empty, return T/F

int BinTree::getCount(){
    return 0;
}                     //return count

bool BinTree::getRootData(Data*)
{
    return 0;
}            /*pass (by reference) an “empty” Data struct from
                                        main() and fill it with root’s data if the tree is not empty, otherwise place -1 and an
                                        empty string in the struct. Return T/F based on if data was retrieved.*/

void BinTree::displayTree() {

}                 /* Display all stats for the tree as shown in the examples and
                                        // call all display order methods.*/

void BinTree::clear(){}                       //deallocate the tree and set it back to “empty.”

bool BinTree::addNode(int id, const string* dataString){
    bool result = false;
    if (id > 0 && dataString->length() > 0) {
        DataNode *newNode = new DataNode();                         //Allocate Node
        newNode->data.id = id;
        newNode->data.information = *dataString;
        newNode->right = nullptr;
        newNode->lefnewNode, (root))){
               ret = nullptr;
           if (addNode(sult = true;
               count += 1;
           }

    }
    return result;
}   //pass in and return the same as in previous
//structures from previous assignments.



bool BinTree::removeNode(int){
    return 0;
}               //pass in and return the same as previous structures

bool BinTree::getNode(Data*, int){
    return 0;
}           //pass in and return the same as previous structures.
//you must use binary search search to retrieve the Node.
bool BinTree::contains(int){
    return 0;
}                 //pass in and return the same as previous structures

int BinTree::getHeight(){
    return 0;
}                    //dynamically calculate the height of the tree (do not store height,
//calculate it each time getHeight() is called.
void BinTree::displayPreOrder(){}             //do a pre-order traversal, printing as you go

void BinTree::displayPostOrder(){}            //do a post-order traversal, printing as you go

void BinTree::displayInOrder(){}              //do an in-order traversal, printing as you go

//PRIVATE FUNCTIONS
void BinTree::clear(DataNode*){}

bool BinTree::addNode(DataNode* newNode, DataNode** root) {
    bool result = false;
    if (!(*root)) {                           //Check if tree exists
        *root = newNode;
    }
    else if (newNode->data.id < (*root)->data.id) {                 // Check if val is < or > this nodes value
        if ((*root)->left == nullptr) {                                                     //Make new Node
            (*root)->left = newNode;
        } else {
            addNode(newNode, &(*root)->left);          //recursively call going left
        }
    } else {
        if ((*root)->right == nullptr) {
            (*root)->right = newNode;
        }
                else {
            addNode(newNode, &(*root)->right);
                }
            }
    return result;
        }



DataNode* BinTree::removeNode(int, DataNode*){
    return 0;
}
bool BinTree::getNode(Data*, int, DataNode*){
    return 0;
}
bool BinTree::contains(int, DataNode*){
    return 0;
}
int BinTree::getHeight(DataNode*){
    return 0;
}
void BinTree::displayPreOrder(DataNode*){}
void BinTree::displayPostOrder(DataNode*){}
void BinTree::displayInOrder(DataNode*){}



BinTree::~BinTree () {

}