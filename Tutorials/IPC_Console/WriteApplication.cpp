#include "WriteApplication.h"

#include <iostream>

namespace IPCConsole
{
	void WriteApplication::Run()
	{
		HANDLE handle = nullptr;
		if (!CreateHandle(handle))
			return;

		system("cls");

		while (true)
		{
			string input;

			std::cout << "Input a message: ";
			std::cin >> input;

			if (!input.empty())
			{
				if (input == "exit")
					break;

				*message = input.c_str();
			}

			system("cls");
		}

		CloseHandle(handle);
		UnmapViewOfFile(message);
	}

	bool WriteApplication::CreateHandle(HANDLE& _handle)
	{
		_handle = CreateFileMapping(
			INVALID_HANDLE_VALUE,
			nullptr,
			PAGE_READWRITE,
			0, sizeof(string),
			MEMORY_ID
		);

		if (_handle == nullptr)
		{
			std::cout << "Couldn't create file mapping!" <<
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