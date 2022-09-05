#include "pch.h"
#include "TicTac.h"
#include "Header1.h"
#include <iostream>

TicTac::TicTac(int size) :
	size(size)
{
	BuildMatrix();
}

TicTac::~TicTac()
{
	for (int i = 0; i < size; i++)
		delete[]matrix[i];
}

void TicTac::ComputerTurn()
{
	int row = GetRandomIntInSizeRange();
	int column = GetRandomIntInSizeRange();
	while (matrix[row][column] != ' ')
	{
		row = GetRandomIntInSizeRange();
		column = GetRandomIntInSizeRange();
	}
	std::cout << "Computer turn: " << row << " " << column << std::endl;
	SetCellValue(row, column, 'O');
	ShowMatrix();
}

void TicTac::PlayerTurn()
{
	std::cout << "Your turn: " << std::endl;
	std::cout << "Write row: ";
	int row = InputInt();
	while (row < 0 || row > size - 1)
	{
		std::cout << "Row must be in the range of 0 to " << size - 1 << ": ";
		row = InputInt();
	}
	std::cout << "Write column: ";
	int column = InputInt();
	while (column < 0 || column > size - 1)
	{
		std::cout << "Column must be in the range of 0 to " << size - 1 << ": ";
		column = InputInt();
	}
	while (matrix[row][column] != ' ')
	{
		std::cout << "Incorrect. Try again: " << std::endl;
		std::cout << "Write row: ";
		row = InputInt();
		while (row < 0 || row > size - 1)
		{
			std::cout << "Row must be in the range of 0 to " << size - 1 << ": ";
			row = InputInt();
		}
		std::cout << "Write column: ";
		column = InputInt();
		while (column < 0 || column > size - 1)
		{
			std::cout << "Column must be in the range of 0 to " << size - 1 << ": ";
			column = InputInt();
		}
	}
	SetCellValue(row, column, 'X');
}

void TicTac::GameProcess()
{
	ShowMatrix();
	while (!CheckWinner())
	{
		PlayerTurn();
		if (CheckWinner())
		{
			ShowWinMessage(true);
			break;
		}

		ComputerTurn();
		if (CheckWinner())
			ShowWinMessage(false);
	}
}

bool TicTac::CheckWinner()
{
	bool player_winner = false;
	bool computer_winner = false;
	int player = 0;
	int computer = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 'X')
			{
				player++;
				if (player == size)
					player_winner = true;
			}
			if (matrix[i][j] == 'O')
			{
				computer++;
				if (computer == size)
					computer_winner = true;
			}
		}
		player = 0;
		computer = 0;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[j][i] == 'X')
			{
				player++;
				if (player == size)
					player_winner = true;
			}
			if (matrix[j][i] == 'O')
			{
				computer++;
				if (computer == size)
					computer_winner = true;
			}
		}
		player = 0;
		computer = 0;
	}
	for (int i = 0; i < size; i++)
	{
		if (matrix[i][i] == 'X')
		{
			player++;
			if (player == size)
				player_winner = true;
		}
		if (matrix[i][i] == 'O')
		{
			computer++;
			if (computer == size)
				computer_winner = true;
		}
	}
	player = 0;
	computer = 0;

	for (int i = 0; i < size; i++)
	{
		if (matrix[i][size - 1 - i] == 'X')
		{
			player++;
			if (player == size)
				player_winner = true;
		}
		if (matrix[i][size - 1 - i] == 'O')
		{
			computer++;
			if (computer == size)
				computer_winner = true;
		}
	}

	return player_winner || computer_winner;
}

void TicTac::ShowMatrix()
{
	std::cout << "   ";
	for (int i = 0; i < size; i++)
		std::cout << i << " | ";

	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << i << "| ";
		for (int j = 0; j < size; j++)
			std::cout << matrix[i][j] << " | ";

		std::cout << std::endl << "-|";
		for (int n = 0; n < size; n++)
			std::cout << "---|";

		std::cout << std::endl;
	}
}

void TicTac::ShowWinMessage(bool is_player_won)
{
	if (is_player_won)
	{
		ShowMatrix();
		std::cout << "\nYou win" << std::endl;
	}
	else
		std::cout << "\nComputer win" << std::endl;
}

int TicTac::GetRandomIntInSizeRange()
{
	return rand() % size;
}

void TicTac::BuildMatrix()
{
	matrix = new char*[size];

	for (int row = 0; row < size; row++)
	{
		matrix[row] = new char[size];
		for (int column = 0; column < size; column++)
		{
			row = row;
			column = column;
			SetCellValue(row, column, ' ');
		}
	}
}

void TicTac::SetCellValue(int row, int column, char symbol)
{
	matrix[row][column] = symbol;
}