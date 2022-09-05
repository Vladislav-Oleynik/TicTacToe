#include "pch.h"
#include "TicTac.h"
#include "utils.h"
#include <iostream>
#include <ctime>

int main()
{	
	srand(static_cast<unsigned int>(time(nullptr)));
	TicTac tt(InputMatrixSize());
	tt.GameProcess();
	system("pause");
}