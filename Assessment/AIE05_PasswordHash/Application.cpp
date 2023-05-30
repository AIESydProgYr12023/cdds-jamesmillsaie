#include "Application.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>

using std::string;
using std::this_thread::sleep_for;
using std::chrono::seconds;

Application::Application()
{

}

Application::~Application()
{

}

void Application::Run()
{
	while (true)
	{
		try
		{
			Authenticate();
			std::cout << "Welcome to the program" << std::endl;

			break;
		}
		catch (NotAuthorisedException& ex)
		{
			std::cout << "You do not have permision to run this program" << std::endl;
			sleep_for(seconds(1));
			system("cls");
		}
	}
}

bool Application::Authenticate()
{
	m_authHash = hashFn("Aie123", 6);

	std::cout << "Login: " << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	int pwh = PromptPassword();
	std::cout << "----------------------------------------" << std::endl;

	if (pwh != m_authHash)
		throw NotAuthorisedException();

	return true;
}

int Application::PromptPassword()
{
	std::cout << "Enter a password:" << std::endl;

	string input;
	std::cin >> input;

	return hashFn(input.c_str(), input.length());
}

// This is the Basic Hash method from the lecture
unsigned int Application::BasicHash(const char* _data, unsigned int _size)
{
	unsigned int hash = 0;

	for (unsigned int i = 0; i < _size; ++i)
		hash += _data[i];

	return hash;
}

// TODO:
// Implement your own _hash method here - note: signature should match the above
unsigned int Application::MyHash(const char* _data, unsigned int _size)
{
	return 666;
}