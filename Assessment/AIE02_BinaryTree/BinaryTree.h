/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#pragma once

class TreeNode;

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	bool IsEmpty() const;
	void Insert(int _value);
	void Remove(int _value);
	TreeNode* Find(int _value);

	void PrintOrdered();
	void PrintUnordered();

	void Draw(TreeNode* _selected = nullptr);

private:
	//Find the node with the specified value.
	bool FindNode(int _searchValue, TreeNode*& _foundNode, TreeNode*& _foundParent);

	//Used to recurse through the nodes in value order and print their values.
	void PrintOrderedRecurse(TreeNode* _node);
	void PrintUnorderedRecurse(TreeNode* _node);

	void Draw(TreeNode* _node, int _x, int _y, int _horizontalSpacing, TreeNode* _selected = nullptr);

	//The root node of the tree
	TreeNode* m_root;
};