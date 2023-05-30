#include "TreeNode.h"
#include <raylib/raylib.h>
#include <string>

TreeNode::TreeNode(int _value) : m_value(_value), m_left(nullptr), m_right(nullptr)
{
}

TreeNode::~TreeNode()
{

}

void TreeNode::Draw(int _x, int _y, bool _selected)
{
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	DrawCircle(_x, _y, 30, YELLOW);

	if (_selected == true)
		DrawCircle(_x, _y, 28, GREEN);
	else
		DrawCircle(_x, _y, 28, BLACK);

	DrawText(buffer, _x - 12, _y - 10, 12, WHITE);
}