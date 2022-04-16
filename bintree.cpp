/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Coding 7, Binary Search Tree
File: bintree.cpp
**********************/

#include "bintree.h"

BinTree::BinTree() {
    root = nullptr;
}

bool BinTree::isEmpty(){
   bool result = false;
    if (root == nullptr){
        result = true;
    }
    return result;
}                   //test for is empty, return T/F

int BinTree::getCount(){
    return count;
}                     //return count

bool BinTree::getRootData(Data* currentData)
{
    bool result = false;
    if (root == nullptr){
        currentData->id = -1;
        currentData->information = "";
    }
    else {
        currentData->id =  (*root).data.id;
        currentData->information =  (*root).data.information;
        result = true;
    }
    return result;
}            /*pass (by reference) an “empty” Data struct from
                                        main() and fill it with root’s data if the tree is not empty, otherwise place -1 and an
                                        empty string in the struct. Return T/F based on if data was retrieved.*/

void BinTree::displayTree() {
displayInOrder();
}                 /* Display all stats for the tree as shown in the examples and
                                        // call all display order methods.*/


bool BinTree::addNode(int id, const string* dataString){
    bool result = false;
    if (id > 0 && dataString->length() > 0) {
        DataNode *newNode = new DataNode();                         //Allocate Node
        newNode->data.id = id;
        newNode->data.information = *dataString;
        newNode->right=nullptr;
        newNode->left=nullptr;
        if (addNode(newNode, &root )) {
            result = true;
        }
    }
    return result;
}   //pass in and return the same as in previous
//structures from previous assignments.



bool BinTree::removeNode(int){
    return 0;
}               //pass in and return the same as previous structures


bool BinTree::getNode(Data* currentData, int id){
    if (id > 0) {
        return getNode(currentData, id, root);
    }
}





    //pass in and return the same as previous structures.
//you must use binary search search to retrieve the Node.
bool BinTree::contains(int id){
    bool result;
    if (id > 0) {
        result = contains(id, root);
    }
    else {
        result = false;
    }
    return result;
}                 //pass in and return the same as previous structures











int BinTree::getHeight(){
    int height = getHeight(root);
    return height;
}                    //dynamically calculate the height of the tree (do not store height,
//calculate it each time getHeight() is called.
void BinTree::displayPreOrder(){}             //do a pre-order traversal, printing as you go

void BinTree::displayPostOrder(){}            //do a post-order traversal, printing as you go



void BinTree::displayInOrder() {
    displayInOrder(root);            //do an in-order traversal, printing as you
}


void BinTree::clear(){
    clear(root);
    root = nullptr;
}                       //deallocate the tree and set it back to “empty.”
//*******************************************PRIVATE FUNCTIONS************************************************
void BinTree::clear(DataNode* tempRoot) {
        if (tempRoot->left != nullptr) {
            clear(tempRoot->left);
        }
        if (tempRoot->right != nullptr) {
            clear(tempRoot->right);
        }
    delete tempRoot;
    count=0;
}


int BinTree::getHeight(DataNode* tempRoot){
    int height=0;
    if (tempRoot != nullptr) {
        int lh = getHeight(tempRoot->left);
        int rh = getHeight(tempRoot->right);
        height = lh > rh ? lh + 1 : rh + 1;
    }
    return height;
}

    void BinTree::displayInOrder(DataNode *temproot) {

        if (temproot) {
            if (temproot->left) {
                displayInOrder(temproot->left);
            }
            cout << temproot->data.id << " " << temproot->data.information << endl;
            if (temproot->right) {
                displayInOrder(temproot->right);
            }
        }

        return;
    }

bool BinTree::addNode(DataNode* newNode, DataNode** tempRoot) {
    bool result = false;
    if (!(*tempRoot)) {                           //Check if tree exists
        *tempRoot = newNode;
        count +=1;
    }
    else if (newNode->data.id < (*tempRoot)->data.id) {                 // Check if val is < or > this nodes value
        if ((*tempRoot)->left == nullptr) {                                                     //Make new left Node
            (*tempRoot)->left = newNode;
            count +=1;
        } else {
            addNode(newNode, &(*tempRoot)->left);          //recursively call going left
        }
    } else {
        if ((*tempRoot)->right == nullptr) {
            (*tempRoot)->right = newNode;               //make new right node
            count +=1;
        }
                else {
            addNode(newNode, &(*tempRoot)->right);          //recursively call going right
                }
            }
    return result;
        }



DataNode* BinTree::removeNode(int, DataNode*){
    return 0;
}





bool BinTree::getNode(Data* currentData, int id, DataNode* tempRoot){
    bool result = false;
    if (tempRoot != nullptr) {
        if (tempRoot->data.id != id) {
            if (id < (tempRoot)->data.id) {
               result = getNode(currentData, id, (tempRoot)->left);
            }
            else {
                result = getNode(currentData, id, (tempRoot)->right);
            }
        }
        if (tempRoot->data.id == id) {
            result = true;
            currentData->id = (tempRoot)->data.id;
            currentData->information = (tempRoot)->data.information;
        }
    }
    return result;
}










bool BinTree::contains(int id, DataNode* tempRoot){
    bool result = false;
    if (tempRoot != nullptr) {
        if (tempRoot->data.id != id) {
            if (id < (tempRoot)->data.id) {
                result = contains(id, (tempRoot)->left);
            }
            else {
                result = contains(id, (tempRoot)->right);
            }
        }
        if (tempRoot->data.id == id) {
            result = true;
        }
    }
    return result;
}




void BinTree::displayPreOrder(DataNode*){}
void BinTree::displayPostOrder(DataNode*){}




BinTree::~BinTree () {

}