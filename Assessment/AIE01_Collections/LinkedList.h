#pragma once

#include <initializer_list>
#include <iostream>

using std::initializer_list;

template<class T>
class LinkedList
{
public:
    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;

        Node(const T& _value) : value(_value) {}
    };

    struct Iterator
    {
    public:
        Node* node = nullptr;

    public:
        Iterator() : node(nullptr) {}
        Iterator(Node* _node) : node(_node) {}

        Iterator& Next()
        {
            if (node != nullptr)
                node = node->next;

            return *this;
        }

        Iterator& Prev()
        {
            if (node != nullptr)
                node = node->prev;

            return *this;
        }

    public:
        // Increment / Decrement operators
        Iterator& operator++() { return Next(); }
        Iterator& operator--() { return Prev(); }

        // Equality operators
        bool operator==(const Iterator& _rhs) { return node == _rhs.node; }
        bool operator!=(const Iterator& _rhs) { return node != _rhs.node; }

        // Iterator getters
        Iterator& operator+(const int _shiftAmount)
        {
            Iterator iter = *this;

            for (int i = 0; i < _shiftAmount; i++)
            {
                iter = iter.Next();
                // Check if ended
            }

            return iter;
        }

        Iterator& operator-(const int _shiftAmount)
        {
            Iterator iter = *this;

            for (int i = _shiftAmount; i > 0; i--)
            {
                iter = iter.Prev();
                // Check if we are outside the bounds of the list
            }

            return iter;
        }

        // Dereference Operators
        T& operator*() { return node->value; }
        T* operator->() { return &node->value; }

    };

    LinkedList() = default;

    LinkedList(initializer_list<T> _list)
    {
        for (auto iter = _list.begin(); iter != _list.end(); iter++)
            PushBack(*iter);
    }

    ~LinkedList() = default;

    void PushBack(T _value)
    {
        Node* node = new Node(_value);
        m_count++;

        if (IsEmpty())
        {
            m_first = node;
            m_last = node;
        }
        else
        {
            m_last->next = node;
            node->prev = m_last;
            m_last = node;
        }
    }

    void PopBack()
    {
        if (IsEmpty())
            return;

        Node* last = m_last;
        m_last = m_last->prev;

        if (m_last != nullptr)
            m_last->next = nullptr;

        if (m_last == nullptr)
            m_first = nullptr;

        delete last;
        m_count--;
    }

    void PushFront(T _value)
    {
        // TODO
    }

    void PopFront()
    {
        if (IsEmpty())
            return;

        Node* first = m_first;
        m_first = m_first->next;

        if (m_first != nullptr)
            m_first->prev = nullptr;

        if (m_first == nullptr)
            m_last = nullptr;

        delete first;
        m_count--;
    }

    void Clear()
    {
        // TODO
    }

    // return the iterator that would be in this location after removing
    Iterator Remove(Iterator _iter)
    {
        Node*& nodeToRemove = _iter.node;
        if (nodeToRemove == nullptr)
            return _iter;

        if (nodeToRemove == m_first)
        {
            PopFront();
            return Iterator(m_first);
        }
        else if (nodeToRemove == m_last)
        {
            PopBack();
            return Iterator(m_last);
        }
        else
        {
            nodeToRemove->prev->next = nodeToRemove->next;
            nodeToRemove->next->prev = nodeToRemove->prev;

            Node*& next = nodeToRemove->next;
            delete nodeToRemove;
            m_count--;
            return Iterator(next);
        }
    }

    Iterator RemoveAt(const int _index)
    {
        return Iterator();
    }

    // Find the first iterator/node that contains this value
    Iterator Find(T _value)
    {
        return Iterator();
    }

    // Insert the value at this iterator
    void Insert(Iterator _iter, const T& _value)
    {

    }

    // Return the value at this index
    T& At(const int _index)
    {
        return T();
    }

    // Check if any nodes contain this value
    bool Contains(const T& _value)
    {
        return false;
    }

    void Sort(int(*_comparer)(Iterator, Iterator))
    {

    }

    // Find the index of this value, otherwise return -1
    int IndexOf(const T& _value) 
    { 
        return -1; 
    }

    // Is this list completely empty
    bool IsEmpty() 
    { 
        return m_first == nullptr && m_last == nullptr; 
    }

    // Amount of items in the list
    unsigned int Count() { return m_count; }

    Node* FirstNode() { return m_first; }
    Node* LastNode() { return m_last; }

    Iterator Begin() { return Iterator(m_first); }
    Iterator Back() { return Iterator(m_last); }
    Iterator End() { return Iterator(); }

private:
    Node* m_first = nullptr;
    Node* m_last = nullptr;

    unsigned int m_count = 0;

};