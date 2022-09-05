#include "pch.h"
#include "utils.h"
#include "TicTac.h"
#include <iostream>


int InputMatrixSize()
{
	std::cout << "Write size of matrix: ";
	int size = InputInt();
	if (size < TicTac::min_size || size > TicTac::max_size)
	{
		std::cout << "The size should be in the range of " << TicTac::min_size << " to " << TicTac::max_size << std::endl;
		size = InputMatrixSize();
	}
	return size;
}

int InputInt()
{
	int x;
	std::cin >> x;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Write correct numbers: ";
		x = InputInt();
	}
	return x;
}