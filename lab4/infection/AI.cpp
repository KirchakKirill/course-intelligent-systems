#include "AI.h"
const int  start_depth = 4;
using namespace std;
int evaluate(gameState state, int player);
void Ai::getBestMove(gameState& state, int player, int depth)
{
	if (player == FirstPlayer)
	{
		state = minimax(state, depth, player, INT_MIN, INT_MAX).second;
		state.print();
		cout << endl;
	}
	else
	{
		state = minimax(state, depth, player, INT_MIN, INT_MAX).second;
		state.print();
		cout << endl;
	}

}

pair<int, gameState> Ai::minimax(gameState state, int depth, int player, int alpha, int beta)
{
	if (depth == 0)
	{
		return make_pair(evaluate(state, player), state);

	}
	vector<gameState>  moves = generateMoves(state, player);
	gameState res_state = state;
	int score;
	int local_best_score;
	if (moves.empty())
	{
		return make_pair(evaluate(state, player), state);
	}
	if (player == FirstPlayer)
	{
		local_best_score = INT32_MIN;

		for (gameState& move : moves)
		{

			score = minimax(move, depth - 1, SecondPlayer, alpha, beta).first;
			if (score > alpha)
			{
				alpha = score;
			}
			if (local_best_score < score)
			{
				local_best_score = score;
				res_state = move;
			}

			if (beta < alpha)
				break;

		}


	}
	else if (player == SecondPlayer)
	{

		local_best_score = INT32_MAX;
		for (gameState& move : moves)
		{

			score = minimax(move, depth - 1, FirstPlayer, alpha, beta).first;
			if (score < beta)
			{
				beta = score;
			}
			if (local_best_score > score)
			{
				local_best_score = score;
				res_state = move;
			}
			if (beta < alpha)
				break;
		}

	}

	return make_pair(local_best_score, res_state);
}

int evaluate(gameState state, int player) {
	int count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (state.field[i][j] == player) {
				count++;
			}
		}
	}
	return count;
}

//bool check_neighbours(int x, int y, const gameState& state, int player)
//{
//	return state.field[x][y] != player && state.field[x][y] != 0;
//}
//
//void Ai::set_neighbours(gameState& state, int x, int y, int player)
//{
//	for (int i = 0; i <= 1; i++)
//	{
//		for (int j = 0; j <= 1; j++)
//		{
//
//			if (x - i >= 0 && y - j >= 0 && check_neighbours(x - i, y - j, state, player))
//				state.field[x - i][y - j] = player;
//
//			if (x + i < 6 && y + j < 6 && check_neighbours(x + i, y + j, state, player))
//				state.field[x + i][y + j] = player;
//
//			if (x + i < 6 && y - j >= 0 && check_neighbours(x + i, y - j, state, player))
//				state.field[x + i][y - j] = player;
//
//			if (x - i >= 0 && y + j < 6 && check_neighbours(x - i, y + j, state, player))
//				state.field[x - i][y + j] = player;
//		}
//	}
//}



void fill_moves(vector<gameState>& moves, int x, int y, gameState state, int player)
{
	int check_repeat[6][6];
	for (size_t i = 0; i < 6; i++)
	{
		int* arr = check_repeat[i];
		fill(arr, arr + 6, 0);
	}
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{

			if (i == 0 && j == 0)
			{
				continue;
			}
			int col_to = y - j;
			int row_to = x - i;
			if (row_to >= 0 && col_to >= 0 && state.field[row_to][col_to] == 0)
			{

				if (check_repeat[row_to][col_to] == 0)
				{
					gameState move = state;
					move.x = row_to;
					move.y = col_to;
					if (i == 2 || j == 2)
					{
						move.field[row_to][col_to] = player;
						move.field[x][y] = 0;

						check_repeat[row_to][col_to] = 1;
					}
					else
					{
						move.field[row_to][col_to] = player;
						check_repeat[row_to][col_to] = 1;
					}
					// заражение соседних
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (abs(i - row_to) <= 1 && abs(j - col_to) <= 1 && move.field[i][j] != 0)
								move.field[i][j] = player;
						}
					}
					moves.push_back(move);
				}


			}
			col_to = y + j;
			row_to = x + i;
			if (row_to < 6 && col_to < 6 && state.field[row_to][col_to] == 0)
			{

				if (check_repeat[row_to][col_to] == 0)
				{
					gameState move = state;
					move.x = row_to;
					move.y = col_to;
					if (i == 2 || j == 2)
					{
						move.field[row_to][col_to] = player;
						move.field[x][y] = 0;

						check_repeat[row_to][col_to] = 1;
					}
					else
					{
						move.field[row_to][col_to] = player;
						check_repeat[row_to][col_to] = 1;
					}
					// заражение соседних
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (abs(i - row_to) <= 1 && abs(j - col_to) <= 1 && move.field[i][j] != 0)
								move.field[i][j] = player;
						}
					}
					moves.push_back(move);
				}


			}
			col_to = y - j;
			row_to = x + i;
			if (row_to < 6 && col_to >= 0 && state.field[row_to][col_to] == 0)
			{

				if (check_repeat[row_to][col_to] == 0)
				{
					gameState move = state;
					move.x = row_to;
					move.y = col_to;
					if (i == 2 || j == 2)
					{
						move.field[row_to][col_to] = player;
						move.field[x][y] = 0;

						check_repeat[row_to][col_to] = 1;
					}
					else
					{
						move.field[row_to][col_to] = player;
						check_repeat[row_to][col_to] = 1;
					}
					// заражение соседних
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (abs(i - row_to) <= 1 && abs(j - col_to) <= 1 && move.field[i][j] != 0)
								move.field[i][j] = player;
						}
					}
					moves.push_back(move);
				}


			}
			col_to = y + j;
			row_to = x - i;
			if (row_to >= 0 && col_to < 6 && state.field[row_to][col_to] == 0)
			{

				if (check_repeat[row_to][col_to] == 0)
				{
					gameState move = state;
					move.x = row_to;
					move.y = col_to;
					if (i == 2 || j == 2)
					{
						move.field[row_to][col_to] = player;
						move.field[x][y] = 0;

						check_repeat[row_to][col_to] = 1;
					}
					else
					{
						move.field[row_to][col_to] = player;
						check_repeat[row_to][col_to] = 1;


					}

					// заражение соседних
					for (int i = 0; i < 6; i++)
					{
						for (int j = 0; j < 6; j++)
						{
							if (abs(i - row_to) <= 1 && abs(j - col_to) <= 1 && move.field[i][j] != 0)
								move.field[i][j] = player;
						}
					}


					moves.push_back(move);
				}


			}
		}
	}
}

vector<gameState> Ai::generateMoves(gameState state, int player) {
	vector<gameState> moves;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (state.field[i][j] == player) {

				fill_moves(moves, i, j, state, player);

			}
		}
	}

	return moves;
}

bool Ai::player_move(gameState& state, int player)
{

	bool flag = true;
	int from_x;
	int from_y;
	int x_to;
	int y_to;
	// считываем ходы с консоли
	while (flag)
	{
		while (true)
		{
			cout << "from: ";
			cin >> from_x >> from_y;
			cout << "to: ";
			cin >> x_to >> y_to;
			cout << endl;

			if (!cin)
			{
				std::cin.clear(); // очистка потока ввода
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Неверный ввод!" << endl;
			}
			else
			{
				break;
			}
		}
			

		int col_to = abs(from_y - y_to);
		int row_to = abs(from_x - x_to);
		// проверяем, корректно ли задан ход
		if (state.field[from_x][from_y] != player)
		{
			cout << "Ячейка принадлежит противнику" << endl;
			continue;
		}
		if (state.field[x_to][y_to] != 0)
		{
			cout << "Ячейка уже занята" << endl;
			continue;
		}

		if (col_to > 2 || row_to > 2)
		{
			cout << "Ячейка вне вашей досягаемости" << endl;
			continue;
		}

		if (from_y < 0 || from_y > 5 || from_x < 0 || from_x > 5 || y_to < 0 || y_to > 5 || x_to < 0 || x_to > 5)
		{
			cout << "Ячейка за пределами игрового поля, попробуйте ещё раз..." << endl;
			continue;
		}

		if (col_to <= 1 && row_to <= 1)
		{
			state.field[x_to][y_to] = player;

			// заражение соседних
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (abs(i - x_to) <= 1 && abs(j - y_to) <= 1 && state.field[i][j] != 0)
						state.field[i][j] = player;
				}
			}

		}
		else if (col_to <= 2 && row_to <= 2)
		{
			state.field[from_x][from_y] = 0;
			state.field[x_to][y_to] = player;

			// заражение соседних
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (abs(i - x_to) <= 1 && abs(j - y_to) <= 1 && state.field[i][j] != 0)
						state.field[i][j] = player;
				}
			}

		}


		flag = false;
	}
	return flag;
}



void Ai::actionAi(gameState state)
{
	state.print();
	cout << endl;
	while (true)
	{
		if (generateMoves(state,SecondPlayer).empty()|| generateMoves(state, FirstPlayer).empty())
		{
			int countPointF = evaluate(state, FirstPlayer);
			int countPointS = evaluate(state, SecondPlayer);
			if (countPointF>countPointS)
			{
				cout << "Побeдил первый игрок!!!"<<endl;
			}
			else if (countPointS > countPointF)
			{
				cout << "Побeдил второй игрок!!!" << endl;
			}
			else
			{
				cout << "Ничья" << endl;
			}

		}

		player_move(state, SecondPlayer);
		state.print();
		cout << endl;

		getBestMove(state, FirstPlayer, start_depth);

		cout << endl;

	}


}

//logs
/*
*
* 0|1 0 0 0 0 2
1|0 0 0 0 0 0
2|0 0 0 0 0 0
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1


0|1 1 0 0 0 2
1|0 0 0 0 0 0
2|0 0 0 0 0 0
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1


from: 0 5
to: 2 5

0|1 1 0 0 0 0
1|0 0 0 0 0 0
2|0 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1


0|1 1 0 0 0 0
1|1 0 0 0 0 0
2|0 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1

from: 2 5
to: 1 5

0|1 1 0 0 0 0
1|1 0 0 0 0 2
2|0 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1


0|1 1 0 0 0 0
1|1 0 0 0 0 2
2|1 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1

from: 1 5
to: 1 4
0|1 1 0 0 0 0
1|1 0 0 0 2 2
2|1 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1


0|1 1 1 0 0 0
1|1 0 0 0 2 2
2|1 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1

from: 1 4
to: 1 3

0|1 1 2 0 0 0
1|1 0 0 2 2 2
2|1 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1


0|1 0 1 1 0 0
1|1 0 0 1 1 2
2|1 0 0 0 0 2
3|0 0 0 0 0 0
4|0 0 0 0 0 0
5|2 0 0 0 0 1

from: 5 0
to: 3 0

0|1 0 1 1 0 0
1|1 0 0 1 1 2
2|2 0 0 0 0 2
3|2 0 0 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|1 0 0 1 0 0
1|1 0 0 1 1 1
2|2 0 0 0 1 1
3|2 0 0 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1

from: 2 0
to: 1 1

0|2 0 0 1 0 0
1|2 2 0 1 1 1
2|2 0 0 0 1 1
3|2 0 0 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|1 1 0 0 0 0
1|1 1 0 1 1 1
2|2 0 0 0 1 1
3|2 0 0 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1

from: 3 0
to: 2 1

0|1 1 0 0 0 0
1|2 2 0 1 1 1
2|2 2 0 0 1 1
3|2 0 0 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|1 1 0 0 0 0
1|2 2 0 0 1 1
2|1 1 0 0 1 1
3|1 1 0 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1

from: 1 1
to: 3 2

0|1 1 0 0 0 0
1|2 0 0 0 1 1
2|1 2 0 0 1 1
3|1 2 2 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|1 1 0 0 0 0
1|1 1 0 0 1 1
2|1 1 0 0 1 1
3|1 2 2 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1

from: 3 2
to: 2 3

0|1 1 0 0 0 0
1|1 1 0 0 2 1
2|1 1 0 2 2 1
3|1 2 2 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|1 0 0 0 0 0
1|1 1 0 0 2 1
2|1 1 1 1 2 1
3|1 1 1 0 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1

from: 2 4
to: 3 3

0|1 0 0 0 0 0
1|1 1 0 0 2 1
2|1 1 2 2 2 1
3|1 1 2 2 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|0 0 0 0 0 0
1|1 1 1 0 2 1
2|1 1 1 1 2 1
3|1 1 2 2 0 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1

from: 3 2
to: 3 4
0|0 0 0 0 0 0
1|1 1 1 0 2 1
2|1 1 1 2 2 2
3|1 1 0 2 2 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|0 0 0 0 0 0
1|1 1 1 1 1 1
2|1 1 1 1 1 2
3|1 1 0 2 2 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1

from: 3 3
to: 3 2
0|0 0 0 0 0 0
1|1 1 1 1 1 1
2|1 2 2 2 1 2
3|1 2 2 2 2 0
4|0 0 0 0 0 0
5|0 0 0 0 0 1


0|0 0 0 0 0 0
1|1 1 1 1 1 0
2|1 2 2 2 1 1
3|1 2 2 2 1 1
4|0 0 0 0 0 0
5|0 0 0 0 0 1


from: 3 3
to: 4 5
0|0 0 0 0 0 0
1|1 1 1 1 1 0
2|1 2 2 2 1 1
3|1 2 2 0 2 2
4|0 0 0 0 0 2
5|0 0 0 0 0 2


0|0 0 0 0 0 0
1|1 1 1 1 1 0
2|1 2 1 1 1 1
3|1 2 1 1 1 2
4|0 0 0 0 0 2
5|0 0 0 0 0 2

from: 2 1
to: 0 3

0|0 0 0 2 0 0
1|1 1 2 2 2 0
2|1 0 1 1 1 1
3|1 2 1 1 1 2
4|0 0 0 0 0 2
5|0 0 0 0 0 2


0|0 0 0 2 0 0
1|1 1 1 2 2 0
2|1 1 1 1 1 1
3|1 1 1 1 1 2
4|0 0 0 0 0 2
5|0 0 0 0 0 2

from: 1 3
to: 1 5
0|0 0 0 2 0 0
1|1 1 1 0 2 2
2|1 1 1 1 2 2
3|1 1 1 1 1 2
4|0 0 0 0 0 2
5|0 0 0 0 0 2


0|0 0 0 1 0 0
1|1 1 1 1 1 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 0 0 0 0 2
5|0 0 0 0 0 2

from: 3 5
to: 4 4
0|0 0 0 1 0 0
1|1 1 1 1 1 2
2|1 1 1 1 1 2
3|1 1 1 2 2 2
4|0 0 0 0 2 2
5|0 0 0 0 0 2


0|0 0 0 1 0 0
1|1 1 1 1 1 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 0 0 1 1 2
5|0 0 0 0 0 2

from: 1 5
to: 0 4
0|0 0 0 2 2 0
1|1 1 1 2 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 0 0 1 1 2
5|0 0 0 0 0 2


0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 0 0 1 1 2
5|0 0 0 0 0 2

from: 4 5
to: 5 4
0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 0 0 2 2 2
5|0 0 0 0 2 2


0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 0 1 1 2 2
5|0 0 0 0 2 2

from: 5 4
to: 5 3
0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 0 2 2 2 2
5|0 0 0 2 2 2


0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 1 1 2 2 2
5|0 0 0 2 2 2

from: 5 3
to: 5 2
0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|0 2 2 2 2 2
5|0 0 2 2 2 2


0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|1 1 2 2 2 2
5|0 0 2 2 2 2

from: 5 2
to: 5 1
0|0 0 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|2 2 2 2 2 2
5|0 2 2 2 2 2


0|0 1 1 1 2 0
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|2 2 2 2 2 2
5|0 2 2 2 2 2

from: 1 4
to: 0 5
0|0 1 1 1 2 2
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|2 2 2 2 2 2
5|0 2 2 2 2 2


0|1 1 1 1 2 2
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|2 2 2 2 2 2
5|0 2 2 2 2 2

from: 5 1
to: 5 0
0|1 1 1 1 2 2
1|1 1 1 1 2 2
2|1 1 1 1 1 2
3|1 1 1 1 1 2
4|2 2 2 2 2 2
5|2 2 2 2 2 2
*/