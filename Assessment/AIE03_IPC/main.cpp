#include "EntityEditorApp.h"
#include "EntityDisplayApp.h"

#include <string>
#include <iostream>
#include <functional>

using std::string;
using std::function;

typedef function<bool(int _value)> ValidatorFunction;

int PromptInt(const string& _message, ValidatorFunction validatorFn)
{
	while (true)
	{
		try
		{
			std::cout << _message;
			std::string input;
			std::getline(std::cin, input);
			auto result = std::stoi(input);
			if (validatorFn(result))
				return result;
			else
				throw "Failed Validation";
		}
		catch (...)
		{
			std::cout << "Invalid Input!" << std::endl;
		}
	}
}

int main()
{
	std::cout << "1. Run Display" << std::endl;
	std::cout << "2. Run Editor" << std::endl;
	int prompt = PromptInt("Run: ", [](int _val) {
		return _val == 1 || _val == 2;
	});

	Application* app = nullptr;

	if (prompt == 1)
		app = new EntityDisplayApp(800, 450);

	if (prompt == 2)
		app = new EntityEditorApp(800, 450);

	app->Run();

	delete app;

	return 0;
}