#include "population.h"
using namespace std;

/*Поиск в пространстве состояний : поиск экстремума функции двух аргументов.
Алгоритм :  генетический алгоритм*/
int main()
{
	setlocale(LC_ALL, "rus");
	population* p = new population(100,50,10);
	p->gen_algorithm();
	delete p;
	


	_CrtDumpMemoryLeaks();
	return 0;
}