#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() : root(nullptr) {}

// A pointer to root of the node to be modified
TreeNode* BinaryTree::InsertNodePrivate(TreeNode* node, int val)
{
	// If node is null, create and new TreeNode and return
	if (node == nullptr)
	{
		return new TreeNode(val);
	}

	// If the value to be inserted is less than the data
	if (val < node->data)
	{
		// Insert in the left subtree
		node->left = InsertNodePrivate(node->left, val);
	}
	// if the node is greater than the data in node to be inserted
	else
	{
		// Insert the the right subtree
		node->right = InsertNodePrivate(node->right, val);
	}
	return node;
}

void BinaryTree::InsertNode(int data)
{
	root = InsertNodePrivate(root, data);
}

TreeNode* BinaryTree::FindMin(TreeNode* node)
{
	if (node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}

TreeNode* BinaryTree::DeleteNodePrivate(TreeNode*& node, int val)
{
	//Base case when tree has no node
	if (node == nullptr) {
		return nullptr;
	}

	// Check if the current node is the node to be deleted
	if (node->data == val)
	{
		//Check if the node no left child
		if (node->left == nullptr)
		{
			TreeNode* temp = node->right;
			delete node;
			node = temp; // Update the link to the deleted node
		}
		// Check if the node has no right child
		else if (node->right == nullptr)
		{
			TreeNode* temp = node->left;
			delete node;
			node = temp; // Update the link to the deleted node
		}
		// When node has both left and right children
		else
		{
			// Find minimum value node in the right subtree
			TreeNode* MinRight = FindMin(node->right);
			// Replace the current nodes value with the minimum value
			node->data = MinRight->data;
			//Delete the minimum value node from the right subtree
			DeleteNodePrivate(node->right, MinRight->data);
		}
	}
	else
	{
		// When the current node is not the node to be deleted
		if (val > node->data)
		{
			// Delete the right node recursively
			DeleteNodePrivate(node->right, val);
		}
		else
		{
			// Delete the left node recursively
			DeleteNodePrivate(node->left, val);
		}
	}

	return node;
}

void BinaryTree::DeleteNode(int data)
{
	DeleteNodePrivate(root, data);
}

void BinaryTree::InOrderPrivate(TreeNode* root)
{
	// Check if root is empty
	if (root == nullptr)
	{
		// If true return;
		return;
	}

	// Recursively print the left subtree
	//Go left most
	InOrderPrivate(root->left);
	// Print data
	cout << root->data << ", ";
	// Recursively, print the right subtree
	InOrderPrivate(root->right);

}

void BinaryTree::InOrder()
{
	InOrderPrivate(root);
}


BinaryTree::~BinaryTree()
{
	if (root == nullptr) {
		return;
	}

}