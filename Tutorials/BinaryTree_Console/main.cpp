#include <iostream>

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    // Constructor
    Node() : value(0) {}

    // Overloaded Constructor
    Node(int _value) : value(_value) {}

    // Overloaded Constructor
    Node(int _value, Node* _left, Node* _right) : value(_value), left(_left), right(_right) {}

};

void PreOrderPrint(Node* _n)
{
    // TODO 
}

void PostOrderPrint(Node* _n)
{
    // TODO 
}

Node* Find(Node* _n, int _value)
{
    // TODO
    return nullptr;
}

void Insert(Node* _root, Node* _nodeToInsert)
{
    // TODO 
}

void Remove(Node* _root, Node* _nodeToRemove)
{
    // TODO
}

int Height(Node* _n)
{
    // TODO
    return 0;
}

int Depth(Node* _root, Node* _n)
{
    // TODO
    return 0;
}

int main()
{
    Node root(6,
        new Node(4,
            new Node(2, nullptr, nullptr),
            new Node(5, nullptr, nullptr)),
        new Node(8,
            new Node(7, nullptr, nullptr),
            new Node(9, nullptr, nullptr)));

    // TODO
    // Test the methods above

    return 0;
}