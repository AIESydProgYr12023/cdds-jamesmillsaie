#pragma once

#include <Windows.h>
#include <string>

using std::string;

namespace IPCConsole
{
	class Application
	{
	public:
		const LPCWSTR MEMORY_ID = L"MessageSharedMemory";
		string* message;

	public:
		virtual void Run() = 0;

	};
}