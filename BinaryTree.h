#pragma once
#include "TreeNode.h"

class BinaryTree
{
	friend class TreeNode;
protected:
	TreeNode* root;
	TreeNode* DeleteNodePrivate(TreeNode*& node, int val);
	TreeNode* InsertNodePrivate(TreeNode* node, int val);
	TreeNode* FindMin(TreeNode* node);
	void InOrderPrivate(TreeNode* root);
	TreeNode* PreOrderPrivate(TreeNode* root);
	TreeNode* PostOrderPrivate(TreeNode* root);
public:
	BinaryTree();
	void DeleteNode(int data);
	void InsertNode(int data);
	void InOrder();
	void PreOrder();
	void PostOrder();
	~BinaryTree();
};

