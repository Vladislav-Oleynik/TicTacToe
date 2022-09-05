#pragma once

class TicTac 
{
public:
	static const int min_size = 3;
	static const int max_size = 10;

private:
	int size;
	char **matrix;

public:
	TicTac(int size = 0);

	~TicTac();

	void ComputerTurn();

	void PlayerTurn();

	void GameProcess();
	bool CheckWinner();

private:
	void ShowMatrix();

	void ShowWinMessage(bool is_player_won);

	int GetRandomIntInSizeRange();

	void BuildMatrix();

	void SetCellValue(int row, int column, char symbol);
};