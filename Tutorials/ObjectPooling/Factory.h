#pragma once

template<class OBJECT>
class Factory
{
public:
	Factory() = default;

	virtual OBJECT* Create(unsigned char _id) = 0;

};