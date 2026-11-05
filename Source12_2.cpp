#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream arrFile("in.txt");
	int sizeArray{};

	if (arrFile.is_open())
	{
		arrFile >> sizeArray;
		int* array{ new  int[sizeArray] {} };

		for (int index{ 0 }; index < sizeArray; index++)
		{
			arrFile >> array[(sizeArray - 1) - index];
		}

		for (int index{ 0 }; index < sizeArray; index++)
		{
			std::cout << array[index] << ' ';
		}
		std::cout << std::endl;
		delete[] array;
	}
	arrFile.close();
	return 0;
}