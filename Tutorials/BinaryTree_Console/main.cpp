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

void PreOrderPrint(Node* _n, const char* _dir)
{
    if (_n != nullptr)
    {
        std::cout << _dir << ": " << _n->value << std::endl;
        PreOrderPrint(_n->left, "Left");
        PreOrderPrint(_n->right, "Right");
    }
}

void PostOrderPrint(Node* _n, const char* _dir)
{
    if (_n != nullptr)
    {
        PostOrderPrint(_n->left, "Left");
        PostOrderPrint(_n->right, "Right");
        std::cout << _dir << ": " << _n->value << std::endl;
    }
}

void InOrderPrint(Node* _n, const char* _dir)
{
    if (_n != nullptr)
    {
        InOrderPrint(_n->left, "Left");
        std::cout << _dir << ": " << _n->value << std::endl;
        InOrderPrint(_n->right, "Right");
    }
}

Node* Find(Node* _n, int _value)
{
    Node* current = _n;
    Node* parent = nullptr;

    while (current != nullptr && current->value != _value)
    {
        // Update parent to current
        parent = current;

        if (_value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return current;
}

void Find(Node* _n, int _value, Node*& _parent)
{
    while (_n != nullptr && _n->value != _value)
    {
        _parent = _n;

        if (_value < _n->value)
            _n = _n->left;
        else
            _n = _n->right;
    }
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

    PreOrderPrint(&root, "root");
    std::cout << std::endl;
    PostOrderPrint(&root, "root");
    std::cout << std::endl;
    InOrderPrint(&root, "root");
    std::cout << "---------------" << std::endl;

    return 0;
}