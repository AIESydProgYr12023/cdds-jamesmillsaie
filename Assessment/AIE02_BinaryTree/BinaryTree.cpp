/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include <raylib/raylib.h>
#include <iostream>
#include <cstdlib>

BinaryTree::BinaryTree()
{
	m_root = nullptr;
}

BinaryTree::~BinaryTree()
{
	while (m_root)
	{
		Remove(m_root->GetData());
	}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const
{
	return (m_root == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int _value)
{

}

TreeNode* BinaryTree::Find(int _value)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = nullptr;

	return FindNode(_value, pCurrent, pParent) ? pCurrent : nullptr;
}

bool BinaryTree::FindNode(int _searchValue, TreeNode*& _foundNode, TreeNode*& _foundParent)
{


	return false;
}

void BinaryTree::Remove(int _value)
{

}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_root);
	std::cout << std::endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* _node)
{

}

void BinaryTree::PrintUnordered()
{
	PrintUnorderedRecurse(m_root);
	std::cout << std::endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* _node)
{

}

void BinaryTree::Draw(TreeNode* _selected)
{
	Draw(m_root, 400, 40, 400, _selected);
}

void BinaryTree::Draw(TreeNode* _node, int _x, int _y, int _horizontalSpacing, TreeNode* _selected)
{
	_horizontalSpacing /= 2;

	if (_node)
	{
		if (_node->HasLeft())
		{
			DrawLine(_x, _y, _x - _horizontalSpacing, _y + 80, RED);

			Draw(_node->GetLeft(), _x - _horizontalSpacing, _y + 80, _horizontalSpacing, _selected);
		}

		if (_node->HasRight())
		{
			DrawLine(_x, _y, _x + _horizontalSpacing, _y + 80, RED);

			Draw(_node->GetRight(), _x + _horizontalSpacing, _y + 80, _horizontalSpacing, _selected);
		}

		_node->Draw(_x, _y, (_selected == _node));
	}
}