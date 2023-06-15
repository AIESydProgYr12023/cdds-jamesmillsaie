#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using std::vector;
using std::list;

template<typename NODE_DATA, typename EDGE_DATA>
class Graph
{
public:
	struct Edge;

	struct Node
	{
		NODE_DATA data;
		vector<Edge> connections;

		Node(NODE_DATA _data);
	};

	struct Edge
	{
		Node* to;
		EDGE_DATA data;

		Edge(Node* _to);
	};

public:
	Graph() = default;
	virtual ~Graph();

	Node* AddNode(const NODE_DATA& _data);
	void AddEdge(Node* _from, Node* _to, const EDGE_DATA& _data);

	const list<Node*>& GetNodes() { return m_nodes; }

protected:
	list<Node*> m_nodes;

};

template<typename NODE_DATA, typename EDGE_DATA>
inline Graph<NODE_DATA, EDGE_DATA>::Node::Node(NODE_DATA _data)
	: data(_data)
{
}

template<typename NODE_DATA, typename EDGE_DATA>
inline Graph<NODE_DATA, EDGE_DATA>::Edge::Edge(Node* _to)
	: to(_to)
{
}

template<typename NODE_DATA, typename EDGE_DATA>
inline Graph<NODE_DATA, EDGE_DATA>::~Graph()
{
	for (auto& node : m_nodes)
		delete node;

	m_nodes.clear();
}

template<typename NODE_DATA, typename EDGE_DATA>
inline Graph<NODE_DATA, EDGE_DATA>::Node* Graph<NODE_DATA, EDGE_DATA>::AddNode(const NODE_DATA& _data)
{
	Node* node = new Node(_data);
	m_nodes.push_back(node);
	return node;
}

template<typename NODE_DATA, typename EDGE_DATA>
inline void Graph<NODE_DATA, EDGE_DATA>::AddEdge(Node* _from, Node* _to, const EDGE_DATA& _data)
{
	Edge edge = Edge(_to);
	edge.data = _data;
	_from->connections.push_back(edge);
}
