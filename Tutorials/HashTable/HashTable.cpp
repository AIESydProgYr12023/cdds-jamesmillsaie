#include <iostream>

#include "HashMap.h"

#include <string>

using std::string;

unsigned int ELFHash(const char* _key)
{
	unsigned int hash = 0, x = 0;

	for (int i = 0; _key[i] != '\0'; ++i)
	{
		hash = (hash << 4) + (int)_key[i];
		if ((x = hash & 0xF0000000L) != 0)
		{
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}

	return (hash & 0x7FFFFFFF);
}

unsigned int BKDRHash(const char* _key)
{
	unsigned int hash = 0;

	for (int i = 0; _key[i] != '\0'; ++i)
	{
		hash = (hash * 1313) + (int)_key[i];
	}

	return (hash & 0x7FFFFFFF);
}

int main()
{
	HashMap<string, ELFHash>* hashMap = new HashMap<string, ELFHash>();

	std::cout << "---------------------" << std::endl;
	std::cout << "|  Hash Table Test  |" << std::endl;
	std::cout << "---------------------" << std::endl;

	hashMap->AddValue((char*)"John Morgan", new string("16 Collins St"));
	hashMap->AddValue((char*)"Alex Roberts", new string("3 Albert Rd"));
	hashMap->AddValue((char*)"Margaret Adams", new string("3/21 Green Av"));

	std::cout << std::endl;
	std::cout << " Getting address for 'John Morgan': " << *hashMap->GetValue((char*)"John Morgan") << std::endl;
	std::cout << " Getting address for 'Alex Roberts': " << *hashMap->GetValue((char*)"Alex Roberts") << std::endl;
	std::cout << " Getting address for 'Margaret Adams': " << *hashMap->GetValue((char*)"Margaret Adams") << std::endl;

	return 0;
}