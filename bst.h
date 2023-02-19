#ifndef bst_h
#define bst_h


#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include <cstring>
#include <time.h>

using namespace std;


struct Node { //a struct because without it it doesnt work but (can we also add here the appearances)
    string data;
    int app=1;
    Node* left;
    Node* right;
}*rr;

class BinaryTree {
    private:
        struct Node* root;
    public:
        BinaryTree() {
            root = NULL;
        }
         ~BinaryTree();
        Node* createNode(string);
        Node* insertNode(Node*, string);
        Node* deleteNode(Node*, string);
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);


        int search (Node* , string);
        int rtimes (Node* , string);
        


        Node* findMinimum(Node*);

        // helps to get the root node in main function
      
        Node* getRoot() {
            return root;
        }

        // helps to update root ptr after insertion
       
        void setRoot(Node* ptr) {
            root = ptr; 
        }
};


 BinaryTree :: ~BinaryTree() //a destructor to free more ram
{
 delete[] root;
 root=nullptr;
}

//it helps to insert 
Node* BinaryTree :: createNode(string n) {
    Node* newNode = new struct Node();
    newNode->data = n;
    newNode->app=1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; 
}

//it helps in delete
Node* BinaryTree :: findMinimum(Node* rootPtr) {
    while(rootPtr->left != NULL) {
        rootPtr = rootPtr->left;
    }
    return rootPtr;
}

//insertion algorithm
Node* BinaryTree :: insertNode(Node* rootPtr, string n) {
    if(rootPtr == NULL) {
        return createNode(n);
    }
    if(n < rootPtr->data) {
        rootPtr->left = insertNode(rootPtr->left, n);
    }
    if(n > rootPtr->data) {
        rootPtr->right = insertNode(rootPtr->right, n);
    }
    if(n==rootPtr->data)
    {
      rootPtr->app+=1;
    }
    return rootPtr;
}

//delete algorithm
Node* BinaryTree :: deleteNode(Node* rootPtr, string n) {
    if(rootPtr == NULL) {
       
        return rootPtr;
    }
    else if(n < rootPtr->data) {
          rootPtr->left = deleteNode(rootPtr->left, n);
    } 
    else if(n > rootPtr->data) {
        rootPtr->right = deleteNode(rootPtr->right, n);
    } else {
        if(rootPtr->left == NULL && rootPtr->right == NULL) {
            delete rootPtr;
            rootPtr = NULL;
        }
        else if(root->left == NULL) {
            struct Node* temp = rootPtr;
              rootPtr = rootPtr->right;
            delete temp;
        }
        else if(rootPtr->right == NULL) {
            struct Node* temp = rootPtr;

            rootPtr = rootPtr->left;
            delete temp;
        } else {
            Node* temp = findMinimum(rootPtr->right);
            rootPtr->data = temp->data;
            rootPtr->left = deleteNode(rootPtr->right, temp->data);
        }
    }

    return rootPtr;
}

//all pritable ways of a tree
void BinaryTree :: inOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    
    
    inOrder(root->left);
    cout<<root->data<<", ";
    

    inOrder(root->right);
}

void BinaryTree :: preOrder(Node* root) {
    if(root == NULL) 
    return;
    cout<<root->data<<", ";

    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree :: postOrder(Node* root) {
    if(root == NULL) 
    return;
    postOrder(root->left);
    postOrder(root->right);

    cout<<root->data<<", ";
}









/*
int BinaryTree :: rtimes(Node* rootPtr,string n) {

 
    while((rootPtr->data != n) &&  (rootPtr->left != NULL)) {
        rootPtr = rootPtr->left;
        if(rootPtr->data == n)
        {
          return rootPtr->app;
          
        }
    }
    while((rootPtr->data != n) && (rootPtr->right != NULL)) {
        rootPtr = rootPtr->right;
        if(rootPtr->data == n)
        {
          return rootPtr->app;
          
        }
    }
    //return rootPtr->app;
    return 0;
}
*/


/*
int BinaryTree :: search(Node* rootPtr,string n) {

 
    while((rootPtr->data != n) &&  (rootPtr->left != NULL)) {
       
        if(n>rootPtr->data)
        {
          //return rootPtr->app;
          rootPtr = rootPtr->right;
        }
       else //!!!nope it bug the f*ck out of this whole program throws around 55 errors without any reason NOPE!!!!!!
        {
          return rootPtr->app;
          rootPtr = rootPtr->left;
          
        }
    return rootPtr->app;
    return 0;
}
*/




int BinaryTree :: search(Node* rootPtr,string key) {

    clock_t tStart = clock();
    
 
        return ((clock() - tStart)/(CLOCKS_PER_SEC/100000));

    }


int BinaryTree :: rtimes(Node* rootPtr,string key) {
        return 1;
    }




#endif