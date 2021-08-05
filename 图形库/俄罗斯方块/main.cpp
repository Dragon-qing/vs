#include"Game.h"
int main()
{
	Game a;
	initgraph(450, 600);
	a.Gamescene();
	a.Nextblock();
	Sleep(500);
	while (1) {
		a.newblock();
		a.check();
	}
	system("PAUSE");
	closegraph();
	return 0;
}