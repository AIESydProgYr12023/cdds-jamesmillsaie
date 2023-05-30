#pragma once

template<class T>
class LinkedList
{
public:
    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    LinkedList()
    {
    }

    ~LinkedList()
    {
    }

    void PushBack(T value)
    {
        // TODO
    }

    void PopBack()
    {
        // TODO
    }

    void PushFront(T _value)
    {
        // TODO
    }

    void PopFront()
    {
        // TODO
    }

    void Clear()
    {
        // TODO
    }

    Node* FirstNode() { return m_first; }
    Node* LastNode() { return m_last; }

protected:

private:
    Node* m_first = nullptr;
    Node* m_last = nullptr;

};