#pragma once
#include<vector>
#include <iostream>
using namespace std;
struct gameState
{
	int field[6][6];
	int x=-1;
	int y=-1;
	void init()
	{
		for (size_t i = 0; i < 6; i++)
		{
			int* arr = field[i];
			fill(arr,arr+6,0);
		}
		x = 0;
		y = 0;
		field[0][0] = 2;
		field[5][5] = 2;
		field[0][5] = 1;
		field[5][0] = 1;
	}
	void print()
	{
		cout << "  ";
		for (int i = 0; i < 6; i++)
		{
			cout << i<<" ";
		}
		cout << endl<<"  ";
		for (int i = 0; i < 6; i++)
		{
			cout << "--";
		}
		cout << endl;
		for (size_t i = 0; i < 6; i++)
		{
			cout << i << "|";
			for (size_t j = 0; j < 6; j++)
			{
				std::cout << field[i][j] << ' ';
			}
			std::cout << endl;
		}
		cout << endl;
	}


};

class Ai
{
private:

	void getBestMove(gameState& field , int player, int depth);
	vector<gameState> generateMoves(gameState state, int player);
	pair<int, gameState> minimax(gameState state, int depth, int player,int,int);
	bool player_move(gameState& state, int player);
	int FirstPlayer;
	int SecondPlayer;
public:
	void actionAi(gameState state);
	Ai() :FirstPlayer(1), SecondPlayer(2) {};
};