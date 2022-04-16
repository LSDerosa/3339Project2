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
    cout <<"DISPLAY TREE"<<endl;
    cout <<"=============================================="<<endl;
    if (isEmpty()) {
        cout << "Tree is empty" << endl;
    }
    else {
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height "<<getHeight()<<endl;
    cout << "Node Count "<<getCount()<<endl;
    displayPreOrder();
    displayInOrder();
    displayPostOrder();
    cout <<"=============================================="<<endl;
    }                 /* Display all stats for the tree as shown in the examples and
                                            // call all display order methods.*/


bool BinTree::addNode(int id, const string* dataString){
    bool result=false;
    if (id > 0 && dataString->length() > 0) {
        DataNode *newNode = new DataNode();                         //Allocate Node
        newNode->data.id = id;
        newNode->data.information = *dataString;
        newNode->right=nullptr;
        newNode->left=nullptr;
        result = (addNode(newNode, &root));
    }
    return result;
}   //pass in and return the same as in previous
//structures from previous assignments.



bool BinTree::removeNode(int id){
    bool result = false;
    int tempCount = count;
    root = removeNode(id, root);
    if (count < tempCount){
        result = true;
    }
    return result;
}               //pass in and return the same as previous structures




bool BinTree::getNode(Data* currentData, int id){
    bool result = false;
    if (id > 0) {
        result = getNode(currentData, id, root);
    }
    return result;
}


bool BinTree::contains(int id){
    bool result;
    if (id > 0) {
        result = contains(id, root);
    }
    else {
        result = false;
    }
    return result;
}


int BinTree::getHeight(){                    //dynamically calculate the height of the tree
    int height = getHeight(root);
    return height;
}

void BinTree::displayPreOrder(){
    cout <<endl<< "Pre-Order Traversal" << endl;
    displayPreOrder(root);
}             //do a pre-order traversal, printing as you go

void BinTree::displayPostOrder(){
    cout <<endl<< "Post-Order Traversal" << endl;
    displayPostOrder(root);
}            //do a post-order traversal, printing as you go



void BinTree::displayInOrder() {
    cout <<endl<< "In-Order Traversal" << endl;
    displayInOrder(root);            //do an in-order traversal, printing as you
}


void BinTree::clear(){              //deallocate the tree and set it back to “empty.”
    clear(root);
    root = nullptr;
}
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



bool BinTree::addNode(DataNode* newNode, DataNode** tempRoot) {
    bool result=false;
    if (!(*tempRoot)) {
        *tempRoot = newNode;
        count +=1;
        result = true;
    }
    else if (newNode->data.id < (*tempRoot)->data.id) {          // Check if val is < or > this nodes value
        if ((*tempRoot)->left == nullptr) {                      //Make new left Node
            (*tempRoot)->left = newNode;
            count +=1;
            result = true;
        } else {
            addNode(newNode, &(*tempRoot)->left);                //recursively call going left
        }
    } else {
        if ((*tempRoot)->right == nullptr) {
            (*tempRoot)->right = newNode;                        //make new right node
            count +=1;
            result = true;
        }
        else {
            addNode(newNode, &(*tempRoot)->right);
        }
    }
    return result;
}

DataNode* BinTree::removeNode(int id, DataNode* root){
    if(root != nullptr) {
        if (root->data.id != id) {
            if (id < (root)->data.id) {
                root->left = removeNode(id, root->left);
            }
            else {
                root->right = removeNode(id, root->right);
            }
        }
        if (root->data.id == id) {
            DataNode *temp;
            if (root->left == nullptr) {                         //Node with one child or no child
                temp = root->right;
                delete root;
                root = temp;
                count--;
            }
            else if (root->right == nullptr) {                   //Node with one child or no child
                temp = root->left;
                delete root;
                root = temp;
                count--;
            }
            else {                                              //Node with 2 children
                temp=minValueNode(root->right);
                root->data.id = temp->data.id;
                root->data.information = temp->data.information;
                root->right = removeNode(temp->data.id, root->right);
                }
        }
    }
return root;
    }


DataNode* BinTree::minValueNode(DataNode* node) {
DataNode* current = node;
while (current && current->left != nullptr) {
    current = current->left;
}
return current;
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
}
void BinTree::displayPreOrder(DataNode* tempRoot){
    if (tempRoot) {
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
        displayPreOrder(tempRoot->left);
        displayPreOrder(tempRoot->right);

    }

}


void BinTree::displayPostOrder(DataNode *tempRoot) {
        if (tempRoot) {
        displayPostOrder(tempRoot->left);
        displayPostOrder(tempRoot->right);
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
    }

}




BinTree::~BinTree () {
    clear();
}