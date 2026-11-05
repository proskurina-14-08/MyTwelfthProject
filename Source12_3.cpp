#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream arrFile("out.txt");
	int sizeArray{};

	if (arrFile.is_open())
	{
		std::cout << "Enter size of your array: ";
		std::cin >> sizeArray;
		arrFile << sizeArray << std::endl;
		int* array{ new  int[sizeArray] {} };

		for (int index{ 0 }; index < sizeArray; index++)
		{
			std::cout << std::endl << "arr[" << index << "] = ";
			std::cin >> array[index];
		}

		for (int index{ 0 }; index < sizeArray; index++)
		{
			arrFile << array[(sizeArray - 1) - index] << ' ';
		}
		std::cout << std::endl;
		delete[] array;
	}
	arrFile.close();
	return 0;
}