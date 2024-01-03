#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Game
{
public:
	const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const string plus = "+";
	const string minus = "-";
	const string forward = ">";
	const string backward = "<";
	const string trigger = ".";
	int pos = 0;

	string findShortest(int magicInd, string* fields)

	{
		int tmp = pos;
		string best;
		while (true)
		{
			string res;
			if (tmp == pos)
			{
				res = Trigger(letterDis(fields[tmp], magicInd));
			}
			else if (pos < tmp)
			{
				for (int i = 0; i < tmp - pos; i++)
				{
					res += forward;
				}
				res += Trigger(letterDis(fields[tmp], magicInd));

			}
			else
			{
				for (int i = 0; i < 30 - pos + tmp; i++)
				{
					res += forward;
				}
				res += Trigger(letterDis(fields[tmp], magicInd));
			}
			++tmp;
			if (tmp == 30)
			{
				tmp = 0;
			}
			if (tmp == pos)
			{
				break;
			}
			if (best.length() == 0)
			{
				best = res;

			}
			else if (res.length() <= best.length())
			{
				best = res;

			}

		}
		while (true)
		{
			string res;
			if (tmp == pos)
			{
				res = Trigger(letterDis(fields[tmp], magicInd));
			}
			else if (tmp < pos)
			{
				for (int i = 0; i < pos - tmp; i++)
				{
					res += backward;
				}
				res += Trigger(letterDis(fields[tmp], magicInd));

			}
			else
			{
				for (int i = 0; i < 30 - pos + tmp; i++)
				{
					res += backward;
				}
				res += Trigger(letterDis(fields[tmp], magicInd));
			}

			--tmp;
			if (tmp == -1)
			{
				tmp = 29;
			}
			if (tmp == pos)
			{
				break;
			}
			if (best.length() == 0)
			{
				best = res;

			}
			else if (res.length() <= best.length())
			{
				best = res;

			}

		}
		
		return best;

	}
	int letterDis(const string& start, int dest)
	{
		int startPos = alphabet.find(start);
		
			if (startPos < dest)
			{
				int spinUp = dest - startPos;
				int spinDown = 27 - dest + startPos;

				return spinUp <= spinDown ? spinUp : -spinDown;
			}
			else if (startPos > dest)
			{
				int spinUp = 27 - startPos + dest;
				int spinDown = startPos - dest;
				return spinUp <= spinDown ? spinUp : -spinDown;
			}
		
		return 0;
	}
	int steps(const string& str)
	{
		int counter = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '<')
			{
				--counter;
			}
			else if (str[i] == '>') {
				++counter;
			}
		}
		return counter;
	}
	string Trigger(int limit)
	{
		string res;
		for (int i = 0; i < abs(limit); i++)
		{
			if (limit <= 0)
			{
				res += minus;
			}
			else
			{
				res += plus;
			}

		}
		res += trigger;
		return res;
	}


};

int main()
{
	Game g;
	string fields[30];
	string magic_phrase;
	getline(cin, magic_phrase);
	for (int i = 0; i < 30; i++)
	{
		fields[i] = " ";
	}
	string shortest;
	for (auto c : magic_phrase)
	{
		string best = g.findShortest(g.alphabet.find(c), fields);
		shortest += best;

		int steps = g.steps(best);

		if (steps < 0 && g.pos - steps < 0) {
			g.pos = 30 - (steps + g.pos);
		}
		else if (steps > 0 && g.pos + steps > 29) {
			steps = 30 - g.pos;
			g.pos = steps;
		}
		else {
			g.pos += steps;
		}
		fields[g.pos] = c;
	}
	cout << shortest<<endl;
	return 0;
}