#pragma once

class TreeNode
{
public:
	TreeNode(int _value);
	~TreeNode();

	bool HasLeft() { return (m_left != nullptr); }
	bool HasRight() { return (m_right != nullptr); }

	int GetData() { return m_value; }
	TreeNode* GetLeft() { return m_left; }
	TreeNode* GetRight() { return m_right; }

	void SetData(int _value) {  }
	void SetLeft(TreeNode* _node) {  }
	void SetRight(TreeNode* _node) {  }

	void Draw(int _x, int _y, bool _selected = false);

private:
	// this could also be a pointer to another object if you like
	int m_value;

	// _node's children
	TreeNode* m_left;
	TreeNode* m_right;
};

