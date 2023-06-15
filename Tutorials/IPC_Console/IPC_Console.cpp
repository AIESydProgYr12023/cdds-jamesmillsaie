#include <iostream>

#include "Application.h"
#include "ReadApplication.h"
#include "WriteApplication.h"

using IPCConsole::Application;
using IPCConsole::ReadApplication;
using IPCConsole::WriteApplication;

int main()
{
	std::cout << "Choose an app: " << std::endl;
	std::cout << "1: Write App" << std::endl;
	std::cout << "2: Read App" << std::endl;

	int appId = 0;
	std::cin >> appId;

	try
	{
		Application* app = nullptr;
		if (appId == 1)
			app = new WriteApplication();
		else if (appId == 2)
			app = new ReadApplication();
		
		if(app == nullptr)
			throw std::exception();

		app->Run();
	}
	catch (std::exception e)
	{
		std::cout << "No app for id: " << appId 
			<< std::endl;

		return -1;
	}

	return 0;
}