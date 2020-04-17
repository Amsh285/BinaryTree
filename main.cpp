#include <iostream>
#include <fstream>
#include <string>

#include "BinaryTree.h"


int main()
{

    std::string filename;
    std::cout << "enter filename: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);

    if(file.fail()){
        std::cout << "file not found";
        return 1;
    }

    BinaryTree tree;
    int value = 0;

    while(file >> value){
        tree.insert(value);
    }

    tree.treecheck();
    file.close();
    return 0;
}
