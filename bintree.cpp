/*********************
Name: Lucas De Rosa
Cosc 2436
Purpose: Coding 7, Binary Search Tree
File: bintree.cpp
**********************/

#include "bintree.h"


//****************CONSTRUCTOR*************************
BinTree::BinTree() {
    root = nullptr;
}

//************************************************************************************************************
//***************PUBLIC FUNCTIONS*****************************************************************************
//************************************************************************************************************


//*********PUBLIC UTILITY FUNCTIONS**************************


bool BinTree::addNode(int id, const string* dataString){            //***ADD NODE TO TREE IN ORDER
    bool result;
    if (id > 0 && dataString->length() > 0) {
        DataNode *newNode = new DataNode();                         //allocate and fill node
        newNode->data.id = id;
        newNode->data.information = *dataString;
        newNode->right=nullptr;
        newNode->left=nullptr;
        result = (addNode(newNode, &root));
    }
    else {
        result = false;
    }
    return result;
}

bool BinTree::removeNode(int id){                                   //***DELETE ID IF IT EXISTS AND REORGANIZE TREE
    bool result = false;
    int tempCount = count;
    root = removeNode(id, root);
    if (count < tempCount){
        result = true;
    }
    return result;
}

void BinTree::clear(){                                              //***SET TREE TO EMPTY AND DEALLOCATE***
    clear(root);
    root = nullptr;
}


//*******************PUBLIC GET FUNCTIONS*******************

bool BinTree::getRootData(Data* currentData)                        //***RETURN ROOT DATA
{
    bool result = false;
    if (root == nullptr){
        currentData->id = -1;
        currentData->information = "";
    }
    else {
        currentData->id = (*root).data.id;
        currentData->information =  (*root).data.information;
        result = true;
    }
    return result;
}

bool BinTree::getNode(Data* currentData, int id){               //***SEARCH FOR NODE AND RETURN DATA IF EXISTS
    bool result = false;
    if (id > 0) {
        result = getNode(currentData, id, root);
    }
    return result;
}


bool BinTree::contains(int id){                                 //***RETURN T/F IF ID IS FOUND IN TREE
    bool result;
    if (id > 0) {
        result = contains(id, root);
    }
    else {
        result = false;
    }
    return result;
}

bool BinTree::isEmpty(){                                        //***RETURN T/F IS TREE IS EMPTY
    bool result = false;
    if (root == nullptr){
        result = true;
    }
    return result;
}

//*************PUBLIC DISPLAY AND TREE STAT FUNCTIONS*********************

void BinTree::displayTree() {                                      //***DISPLAY TREE AND ALL TREE STATS
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
}

int BinTree::getCount(){                                //***RETURN NUMBER OF NODES
    return count;
}

int BinTree::getHeight(){                               //***DYNAMICALLY CALCULATE TREE HEIGHT
    int height = getHeight(root);
    return height;
}

void BinTree::displayPreOrder(){                        //***PRE-ORDER PRINTING
    cout <<endl<< "Pre-Order Traversal" << endl;
    displayPreOrder(root);
}

void BinTree::displayPostOrder(){                       //***POST-ORDER PRINTING
    cout <<endl<< "Post-Order Traversal" << endl;
    displayPostOrder(root);
}


void BinTree::displayInOrder() {                        //***IN-ORDER PRINTING
    cout <<endl<< "In-Order Traversal" << endl;
    displayInOrder(root);
}


//************************************************************************************************************
//*******************************************PRIVATE FUNCTIONS************************************************
//************************************************************************************************************


//*********PRIVATE UTILITY FUNCTIONS**************************

bool BinTree::addNode(DataNode* newNode, DataNode** tempRoot) {             //***ADDS NODE TO TREE***
    bool result=true;
    if (!(*tempRoot)) {
        *tempRoot = newNode;
        count +=1;
    }
    else if (newNode->data.id <= (*tempRoot)->data.id) {                   //check if val is < or > this nodes value
                                                                            //duplicates go left
                              //IF GOING RIGHT
        if ((*tempRoot)->left == nullptr) {                                 //make new left Node
            (*tempRoot)->left = newNode;
            count +=1;
        } else {
            addNode(newNode, &(*tempRoot)->left);                  //recursively call going left
        }
    }
                                //IF GOING RIGHT
    else {
        if ((*tempRoot)->right == nullptr) {
            (*tempRoot)->right = newNode;                                  //make new right node
            count +=1;
        }
        else {
            addNode(newNode, &(*tempRoot)->right);
        }
    }
    return result;
}

DataNode* BinTree::removeNode(int id, DataNode* root){          //***FINDS NODE IN TREE, DELETES, REORGANIZES***
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
            if (root->left == nullptr) {                         //node with one child or no child
                temp = root->right;
                delete root;
                root = temp;
                count--;
            }
            else if (root->right == nullptr) {                   //node with one child or no child
                temp = root->left;
                delete root;
                root = temp;
                count--;
            }
            else {                                              //node with 2 children
                temp=minValueNode(root->right);
                root->data.id = temp->data.id;
                root->data.information = temp->data.information;
                root->right = removeNode(temp->data.id, root->right);
            }
        }
    }
    return root;
}

void BinTree::clear(DataNode* tempRoot) {                   //***CLEARS TREE AND DEALLOCATES***
    if (tempRoot->left != nullptr) {
        clear(tempRoot->left);
    }
    if (tempRoot->right != nullptr) {
        clear(tempRoot->right);
    }
    delete tempRoot;
    count=0;
}



//*******************PRIVATE GET FUNCTIONS*******************

bool BinTree::getNode(Data* currentData, int id, DataNode* tempRoot){      //***SEARCH FOR NODE AND RETURN DATA IF EXISTS
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


bool BinTree::contains(int id, DataNode* tempRoot){                     //***RETURN T/F IF ID EXISTS IN TREE
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


//*************PRIVATE DISPLAY AND TREE STAT FUNCTIONS*********************

int BinTree::getHeight(DataNode* tempRoot){                                 //***DYNAMICALLY CALCULATE HEIGHT***
    int height=0;
    if (tempRoot != nullptr) {
        int lh = getHeight(tempRoot->left);
        int rh = getHeight(tempRoot->right);
        height = lh > rh ? lh + 1 : rh + 1;
    }
    return height;
}

void BinTree::displayInOrder(DataNode *temproot) {                          //***IN-ORDER TREE DISPLAY***

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

void BinTree::displayPreOrder(DataNode* tempRoot){                              //***PRE-ORDER TREE DISPLAY***
    if (tempRoot) {
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
        displayPreOrder(tempRoot->left);
        displayPreOrder(tempRoot->right);

    }

}

void BinTree::displayPostOrder(DataNode *tempRoot) {                            //***POST-ORDER TREE DISPLAY***
    if (tempRoot) {
        displayPostOrder(tempRoot->left);
        displayPostOrder(tempRoot->right);
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
    }

}

//*********HELPER FUNCTIONS**************************


DataNode* BinTree::minValueNode(DataNode* node) {              //***FINDS SMALLEST NODE***
DataNode* current = node;
while (current && current->left != nullptr) {
    current = current->left;
}
return current;
}

//*********DESTRUCTOR**************************

BinTree::~BinTree () {                                      //***DESTRUCTOR***
    clear();
}