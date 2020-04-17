#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree
{
    public:
        BinaryTree();
        virtual ~BinaryTree();

        void insert(int);
        void deleteTree();

        void treecheck();
        int getMax();
        int getMin();
        float getAvg();


    private:
        Node* root;
        bool AVL;

        Node* createNode(int); // inserting data
        Node* insertIntern(Node*, Node*);

        void deleteIntern(Node*); // delete
        void Inorder(Node*);      // traverse

        Node* goRight(Node*);   // get max
        Node* goLeft(Node*);    // get min
        int calcSum(Node*);     // get sum
        int count(Node*);       // get count
        int height(Node*);      // get height
        int balFac(Node*);      // get balance factor


};

#endif // BINARYTREE_H
