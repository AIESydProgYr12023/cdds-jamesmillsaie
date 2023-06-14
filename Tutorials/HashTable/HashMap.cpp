#include "HashMap.h"

unsigned int DefaultHash(const char* _str)
{
	unsigned int hash = 0;

	for (int i = 0; _str[i] != '\0'; ++i)
	{
		hash += (int)_str[i];
	}

	return hash;
}