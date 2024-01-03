#include "AI.h"

int main() 
{
	setlocale(LC_ALL,"ru");
	Ai ai;
	gameState g;
	g.init();


	ai.actionAi(g);
	return 0;
}

