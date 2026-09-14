#include "treeNode.h"
#include<iostream>

int main(){
    TreeNode* root = new TreeNode(10);
    std::cout << sizeof(*root) << '\n';
    delete root;
}