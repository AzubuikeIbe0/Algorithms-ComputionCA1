#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() : BinaryTree(){}


int BinarySearchTree::GetHeightPrivate(TreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }

    int LeftHeight = GetHeightPrivate(node->left);

    int RightHeight = GetHeightPrivate(node->right);

    int Total = 1 + max(LeftHeight, RightHeight);

    return Total;
}



void BinarySearchTree::GetHeight()
{
    cout << GetHeightPrivate(root) << endl;
}


void BinarySearchTree::DeleteTreePrivate(TreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    DeleteTreePrivate(node->left);

    DeleteTreePrivate(node->right);

    delete node;
}



BinarySearchTree::~BinarySearchTree()
{
    DeleteTreePrivate(root);
}
