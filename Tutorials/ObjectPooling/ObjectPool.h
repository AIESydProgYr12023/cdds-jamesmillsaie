#pragma once

#include <vector>

#include <concepts>

#include "Factory.h"

using std::vector;

template<class T, class U>
concept Derived = std::is_base_of<U, T>::value;

template<class OBJECT, Derived<Factory<OBJECT>> FACTORY>
class ObjectPool
{
public:
	ObjectPool(int _count, unsigned char _objectId);
	~ObjectPool();

	OBJECT* Retrieve();
	void Return(OBJECT* _object);

private:
	int m_activeCount;
	unsigned char m_objectId;

	vector<OBJECT*> m_active;
	vector<OBJECT*> m_inactive;

	FACTORY* m_factory;

};

template<class OBJECT, Derived<Factory<OBJECT>> FACTORY>
inline ObjectPool<OBJECT, FACTORY>::ObjectPool(int _count, unsigned char _objectId)
{
	m_factory = new FACTORY();
	m_objectId = _objectId;

	for (int i = 0; i < _count; i++)
	{
		m_inactive.push_back(m_factory->Create(m_objectId));
	}
}

template<class OBJECT, Derived<Factory<OBJECT>> FACTORY>
inline ObjectPool<OBJECT, FACTORY>::~ObjectPool()
{
	for (auto obj : m_active)
		delete obj;

	for (auto obj : m_inactive)
		delete obj;

	if (m_factory != nullptr)
	{
		delete m_factory;
		m_factory = nullptr;
	}

	m_active.clear();
	m_inactive.clear();
	m_objectId = 0;
	m_activeCount = 0;
}

template<class OBJECT, Derived<Factory<OBJECT>> FACTORY>
inline OBJECT* ObjectPool<OBJECT, FACTORY>::Retrieve()
{
	if (m_inactive.empty())
		return nullptr;

	m_active.push_back(m_inactive[0]);
	m_inactive.erase(m_inactive.begin());

	m_activeCount++;

	return m_active[m_active.size() - 1];
}

template<class OBJECT, Derived<Factory<OBJECT>> FACTORY>
inline void ObjectPool<OBJECT, FACTORY>::Return(OBJECT* _object)
{
	if (std::ranges::find(m_active, _object) != m_active.end() && m_activeCount != 0)
	{
		m_active.erase(std::ranges::find(m_active, _object));
		m_inactive.push_back(_object);

		m_activeCount--;
	}
}