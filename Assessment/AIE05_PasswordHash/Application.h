#pragma once

#include <functional>

using std::exception;

using std::function;
typedef function<unsigned int(const char* _data, unsigned int _size)> HashFunction;

struct NotAuthorisedException : public exception
{
	const char* what() const throw ()
	{
		return "Not Authorised";
	}
};

class Application
{
public:
	Application();
	~Application();

	void Run();

private:
	int m_authHash = 0;

	// This is the Basic Hash method from the lecture
	static unsigned int BasicHash(const char* _data, unsigned int _size);

	// Your Hash function... Needs to be implemented in the CPP file
	static unsigned int MyHash(const char* _data, unsigned int _size);

	// this method allows us to change which _hash function is used.
	HashFunction hashFn = Application::MyHash;

private:
	bool Authenticate();
	int PromptPassword();

};