#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::ifstream inFile("in.txt");
	if (inFile.is_open())
	{
		std::string data{};
		while (inFile >> data)
		{
			std::cout << data << std::endl;
		}
	}
	inFile.close();
	return EXIT_SUCCESS;
}