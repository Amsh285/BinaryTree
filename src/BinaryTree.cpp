#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
    this->AVL = true;
    this->root = nullptr;
}

BinaryTree::~BinaryTree()
{
    if(this->root != NULL)
        deleteTree();
}

// public functions

void BinaryTree::insert(int value)
{
    this->root = insertIntern(this->root, createNode(value));
}

void BinaryTree::printInorder()
{
    this->Inorder(this->root);
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
            delete newNode;
    }

    return root;
}

Node* BinaryTree::createNode(int value)
{
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

    Inorder(root->left);
    std::cout << root->value << std::endl;
    Inorder(root->right);
}

Node* BinaryTree::goRight(Node* root)
{
    if(root->right != nullptr)
        root = goRight(root->right);

    return root;
}

Node* BinaryTree::goLeft(Node* root)
{
    if(root->left != nullptr)
        root = goLeft(root->left);

    return root;
}

int BinaryTree::calcSum(Node* root)
{
    if(root == nullptr)
        return 0;

    return (root->value + calcSum(root->left) + calcSum(root->right));

}

int BinaryTree::count(Node* root)
{
    int number = 0;

    if(root != nullptr)
    {
        number++;
        number = number + count(root->right);
        number = number + count(root->left);
    }

    return number;
}



