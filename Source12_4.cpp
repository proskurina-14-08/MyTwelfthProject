#include <iostream>
#include <fstream>
#include <string>

int** create_two_dim_array(int rows, int cols);
void print_two_dim_array(int** arr, int rows, int cols);
void delete_two_dim_array(int** arr, int row);

int main()
{
	std::ifstream arrFile("in.txt");
	int rows{};
	int cols{};
	if (arrFile.is_open())
	{
		arrFile >> rows;
		arrFile >> cols;
		int** arr{ create_two_dim_array(rows, cols) };
		for (int row{ 0 }; row < rows; ++row)
			{
				for (int col{ 0 }; col < cols; ++col)
				arrFile >> arr[row][(cols - 1) - col];
		}
		print_two_dim_array(arr, rows, cols);
		delete_two_dim_array(arr, rows);
	}
	arrFile.close();
	return 0;
}

int** create_two_dim_array(int rows, int cols)
{
	int** arr{ new int* [rows] };
	for (int index{ 0 }; index < rows; ++index)
	{
		arr[index] = new int[cols];
	}
	return arr;
}

void print_two_dim_array(int** arr, int rows, int cols)
{
	for (int row{ 0 }; row < rows; ++row)
	{
		for (int col{ 0 }; col < cols; ++col)
		{
			std::cout << arr[row][col] << ' ';
		}
		std::cout << std::endl;
	}
}
void delete_two_dim_array(int** arr, int rows)
{
	for (int link{ 0 }; link < rows; ++link)
	{
		delete[] arr[link];
	}
	delete[] arr;
}