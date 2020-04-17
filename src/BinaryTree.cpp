#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
    this->AVL = true;
    this->root = nullptr;
}

BinaryTree::~BinaryTree()
{
    if(this->root != NULL) // if not manually deleted, destructer will delete the tree
        deleteTree();
}

// public functions

void BinaryTree::insert(int value)
{
    this->root = insertIntern(this->root, createNode(value));
}

void BinaryTree::treecheck()
{
    this->Inorder(this->root);
    std::cout << "AVL: ";
    if(AVL)
        std::cout << "yes\n";
    else
        std::cout << "no\n";

    std::cout << "min: " << getMin() << ", max: " << getMax() << ", avg: " << getAvg();
}

void BinaryTree::deleteTree()
{
    deleteIntern(this->root);
    this->root = NULL;
}

int BinaryTree::getMax()
{
    Node* rightmost = this->goRight(this->root);
    return rightmost->value;
}

int BinaryTree::getMin()
{
    Node* leftmost = this->goLeft(this->root);
    return leftmost->value;
}

float BinaryTree::getAvg()
{
    return (float)this->calcSum(this->root)/this->count(this->root);
}


// private functions

Node* BinaryTree::insertIntern(Node* root, Node* newNode)
{
    if(root == nullptr)
        root = newNode;
    else
    {
        if(newNode->value > root->value)
            root->right = insertIntern(root->right, newNode);
        else if (newNode->value < root->value)
            root->left = insertIntern(root->left, newNode);
        else
            delete newNode;  // if node cannot be inserted, then delete it
    }

    return root;
}

Node* BinaryTree::createNode(int value)
{
    // creates and returns a node with value in it, insert function finds the right place

    Node* newNode = new Node;
    newNode->value = value;
    newNode->right = nullptr;
    newNode->left = nullptr;

    return newNode;
}

void BinaryTree::deleteIntern(Node* root)
{
    if(root != nullptr)
    {
        deleteIntern(root->left);
        deleteIntern(root->right);
        delete root;
    }
}

void BinaryTree::Inorder(Node* root)
{
    if(root == nullptr)
        return;

    Inorder(root->left); // go as far left as possible

    // print info
    std::cout << "bal("<<root->value << ") = " << balFac(root);
    if(balFac(root) > 1 || balFac(root) < -1)
    {
        std::cout << " (AVL Violation!)";
        AVL = false;
    }
    std::cout << "\n";

    Inorder(root->right); // go as far right as possible
}

Node* BinaryTree::goRight(Node* root)
{
    if(root->right != nullptr)
        root = goRight(root->right); // returns the most right node (max value)

    return root;
}

Node* BinaryTree::goLeft(Node* root) // returns the most left node (min value)
{
    if(root->left != nullptr)
        root = goLeft(root->left);

    return root;
}

int BinaryTree::calcSum(Node* root) // value of root + total sum of left + total sum of right
{
    if(root == nullptr)
        return 0;

    return (root->value + calcSum(root->left) + calcSum(root->right));

}

int BinaryTree::count(Node* root)
{
    int number = 0; // number starts always as zero
                    // if node is valid, increment and add to total number of left and right part of tree

    if(root != nullptr)
    {
        number++;
        number = number + count(root->right);
        number = number + count(root->left);
    }

    return number;
}

int BinaryTree::height(Node* root)
{
    if(root == nullptr)
        return 0;

    return ((height(root->left) > height(root->right) ? height(root->left) : height(root->right)) + 1);
    // go as far right and as far left (always add one to increase the value)
    // max of both is tree height
}

int BinaryTree::balFac(Node* root)
{
    return (height(root->right) - height(root->left));
}

