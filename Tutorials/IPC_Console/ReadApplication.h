#pragma once

#include "Application.h"

namespace IPCConsole
{
	class ReadApplication : public Application
	{
	public:
		void Run() override;

		bool CreateHandle(HANDLE& _handle);

	};
}
