#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <chrono>
std::vector<std::string> create_seq(int start, int target, std::unordered_map<int, std::string> operations, std::unordered_map<int, int> parents);
std::vector<std::string> create_seq2(int start, int target, std::unordered_map<int, std::string> operations);

/*Решить вводные задачи поиска :

1.Даны два целых числа – например, 2 и 100, а также две операции – «прибавить 3» и «умножить на 2».Найти минимальную последовательность операций, позволяющую получить из первого числа второе.
2.То же самое, что и в пункте 1, однако добавляется операция «вычесть 2».
3.Реализовать задание из пункта 1 методом обратного поиска – от целевого состояния к начальному.Сравнить эффективность.
4.Дополнительное задание.Реализовать метод двунаправленного поиска для решения задачи из пункта 1.*/

std::vector<std::string> Search(int start, int target) {
	std::queue<int> q;
	std::unordered_map<int, int> visited;
	std::unordered_map<int, std::string> operations;
	std::unordered_map<int, int> parents;
	int prev_cur;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == target)
			break;

		prev_cur = current;
		int add3 = current + 3;
		int mul2 = current * 2;

		if (add3 <= target && visited.find(add3) == visited.end()) {
			q.push(add3);
			visited[add3] = true;
			operations[add3] = "+3";
			parents[add3] = prev_cur;

		}

		if (mul2 <= target && visited.find(mul2) == visited.end()) {
			q.push(mul2);
			visited[mul2] = true;
			operations[mul2] = "X2";
			parents[mul2] = prev_cur;



		}
	}

	// Восстановление последовательности операций
	return create_seq(start,target,operations,parents);
}
std::vector<std::string> Search2(int start, int target) {
	std::queue<int> q;
	std::unordered_map<int, int> visited;
	std::unordered_map<int, std::string> operations;
	std::unordered_map<int, int> parents;
	int prev_cur;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == target)
			break;

		prev_cur = current;
		int add3 = current + 3;
		int mul2 = current * 2;
		int sub2 = current - 2;

		if (add3 <= target && visited.find(add3) == visited.end()) {
			q.push(add3);
			visited[add3] = true;
			operations[add3] = "+3";
			parents[add3] = prev_cur;
			
		}

		if (mul2 <= target && visited.find(mul2) == visited.end()) {
			q.push(mul2);
			visited[mul2] = true;
			operations[mul2] = "X2";
			parents[mul2] = prev_cur;
			
			

		}

		if (sub2>=start&&visited.find(sub2) == visited.end())
		{
			q.push(sub2);
			visited[sub2] = true;
			operations[sub2] = "-2";
			parents[sub2] = prev_cur;
		}
	}

	// Восстановление последовательности операций
	return create_seq(start, target, operations, parents);
}

std::vector<std::string> reverseSearch(int start, int target) {
	std::queue<int> q;
	std::unordered_map<int, int> visited;
	std::unordered_map<int, std::string> operations;

	q.push(target);
	visited[target] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == start)
			break;

		int add3 = current - 3;
		int mul2 = current / 2;

		if (visited.find(add3) == visited.end()) {
			q.push(add3);
			visited[add3] = true;
			operations[add3] = "+3";
		}

		if (mul2 * 2 == current && visited.find(mul2) == visited.end()) {
			q.push(mul2);
			visited[mul2] = true;
			operations[mul2] = "X2";
		}
	}

	// Восстановление последовательности операций
	return create_seq2(start, target, operations);
}




std::vector<std::string> create_seq(int start, int target,  std::unordered_map<int, std::string> operations,  std::unordered_map<int, int> parents)
{
	std::vector<std::string> sequence;
	int current = target;
	while (parents[current] !=start ) {
		sequence.push_back(operations[current]);

		if (operations[current] == "+3")
			current -= 3;
		else if (operations[current] == "X2")
			current /= 2;
		else if (operations[current] == "-2")
			current += 2;
	}
	sequence.push_back(operations[current]);
	return sequence;
}

std::vector<std::string> create_seq2(int start, int target,  std::unordered_map<int, std::string> operations)
{
	std::vector<std::string> sequence;
	int current = start;
	while (current != target) {
		sequence.push_back(operations[current]);

		if (operations[current] == "+3")
			current += 3;
		else if (operations[current] == "X2")
			current *= 2;
		else if (operations[current] == "-2")
			current -= 2;
	}
	return sequence;
}

int main() {
	std::vector<std::pair<int, int>> pairs{ { 2, 55 }, {1, 100}, {2, 100}, {1, 97}, {2, 1000}, {1, 10000001}};
	for (size_t i = 0; i < pairs.size(); i++)
	{
		auto begin = std::chrono::steady_clock::now();
		std::vector<std::string> sequence = reverseSearch(pairs[i].first, pairs[i].second);
		auto end = std::chrono::steady_clock::now();
		printf("Sequence of operations (%d,%d): ", pairs[i].first, pairs[i].second);
		for (int i = sequence.size() - 1; i >= 0; i--)
		{
			std::cout << sequence[i] << " ";
		}
		std::cout << std::endl;
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		std::cout << "The time: " << duration.count() << " ns\n";
	}
	

	return 0;
}

//Search2
//Sequence of operations(2, 55) : +3 X2 + 3 X2 X2 + 3
//Sequence of operations(1, 100) : +3 X2 + 3 X2 + 3 X2 X2
//Sequence of operations(2, 100) : +3 + 3 + 3 X2 + 3 X2 X2
//Sequence of operations(1, 97) : +3 X2 + 3 X2 X2 + 3 X2 + 3
//Sequence of operations(2, 1000) : +3 + 3 X2 X2 X2 X2 - 2 X2 - 2 X2 X2
//Sequence of operations(1, 10000001) : +3 X2 X2 + 3 X2 X2 X2 X2 + 3 - 2 X2 X2 X2 X2 + 3 X2 X2 X2 X2 - 2 X2 - 2 X2 X2 X2 X2 X2 X2 - 2 + 3
//Sequence of operations(3, 1001) : +3 + 3 X2 - 2 X2 X2 - 2 X2 X2 X2 + 3 X2 + 3
//Sequence of operations(3, 3001) : +3 X2 X2 X2 X2 - 2 X2 X2 X2 - 2 X2 X2 - 2 + 3

//Search
//Sequence of operations(2, 55) : +3 X2 + 3 X2 X2 + 3
//The time : 888400 ns
//Sequence of operations(1, 100) : +3 X2 + 3 X2 + 3 X2 X2
//The time : 1532100 ns
//Sequence of operations(2, 100) : +3 + 3 + 3 X2 + 3 X2 X2
//The time : 1078700 ns
//Sequence of operations(1, 97) : +3 X2 + 3 X2 X2 + 3 X2 + 3
//The time : 1112300 ns
//Sequence of operations(2, 1000) : +3 X2 + 3 X2 + 3 X2 + 3 X2 + 3 X2 X2 X2
//The time : 7034800 ns
//Sequence of operations(1, 10000001) : +3 X2 X2 + 3 X2 X2 X2 X2 X2 X2 + 3 X2 + 3 X2 X2 X2 + 3 X2 X2 X2 X2 + 3 X2 X2 + 3 X2 X2 + 3 X2 + 3
//The time : 63637860800 ns

//reverseSearch
// справо налево читать
//Sequence of operations(2, 55) : +3 X2 X2 + 3 X2 + 3
//The time : 419500 ns
//Sequence of operations(1, 100) : X2 X2 + 3 X2 + 3 X2 + 3
//The time : 450200 ns
//Sequence of operations(2, 100) : X2 X2 + 3 X2 + 3 + 3 + 3
//The time : 402300 ns
//Sequence of operations(1, 97) : +3 X2 + 3 X2 X2 + 3 X2 + 3
//The time : 399600 ns
//Sequence of operations(2, 1000) : X2 X2 X2 + 3 X2 + 3 X2 + 3 X2 + 3 X2 + 3
//The time : 916100 ns
//Sequence of operations(1, 10000001) : +3 X2 + 3 X2 X2 + 3 X2 X2 + 3 X2 X2 X2 X2 + 3 X2 X2 X2 + 3 X2 + 3 X2 X2 X2 X2 X2 X2 + 3 X2 X2 + 3
//The time : 3401300 ns
