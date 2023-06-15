#include "ReadApplication.h"

#include <iostream>
#include <string>

using std::string;

namespace IPCConsole
{
	void ReadApplication::Run()
	{
		HANDLE handle = nullptr;
		if (!CreateHandle(handle))
			return;

		system("cls");

		while (true)
		{
			std::cout << "The current message is: " <<
				*message << std::endl;

			Sleep(500);

			if (!message->empty())
			{
				if (*message == "exit")
					break;
			}

			system("cls");
		}

		CloseHandle(handle);
		UnmapViewOfFile(message);
	}

	bool ReadApplication::CreateHandle(HANDLE& _handle)
	{
		_handle = OpenFileMapping(
			FILE_MAP_ALL_ACCESS,
			FALSE,
			MEMORY_ID
		);

		if (_handle == nullptr)
		{
			std::cout << "Couldn't open file mapping!" <<
				std::endl;

			return false;
		}

		message = (string*)MapViewOfFile(
			_handle,
			FILE_MAP_ALL_ACCESS,
			0, 0,
			sizeof(string)
		);

		if (message == nullptr)
		{
			std::cout << "Couldn't map message to Shared Memory"
				<< std::endl;

			return false;
		}

		return true;
	}
}