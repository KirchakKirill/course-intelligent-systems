#include "population.h"
using namespace std;

/*����� � ������������ ��������� : ����� ���������� ������� ���� ����������.
�������� :  ������������ ��������*/
int main()
{
	setlocale(LC_ALL, "rus");
	population* p = new population(100,50,10);
	p->gen_algorithm();
	delete p;
	


	_CrtDumpMemoryLeaks();
	return 0;
}