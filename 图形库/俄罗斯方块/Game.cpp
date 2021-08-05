#include"Game.h"
void Game::Clearblock()
{
	setfillcolor(BLACK);
    solidrectangle(300, 0, 300 + 4 * mapsize, 0 + 4 * mapsize);

}
void Game::Nextblock()
{
	Clearblock();
	srand(time(NULL)); 
	Base::nextindex = rand() % 5;
	Drawblock(300, 0, Base::nextindex, Base::dir);
}
void Game::Gamescene()
{
	Base::show();
	Base::Showscore();
}
void Game::Drawblock(int x, int y, int index,int dir)
{
	int (*shap)[4] = findshape(index*4+dir);
	setfillcolor(color[index]);
	int x2, y2;
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (shap[r][c] == 1)
			{
				x2 = x + c * mapsize;
				y2 = y + r * mapsize;
				fillrectangle(x2, y2, x2 + 1 * mapsize, y2 + 1 * mapsize);
			}
		}
	}
}
void Game::Clearblock(int x, int y, int dir, int index)
{
	int(*shap)[4] = findshape(index*4+dir);
	
	int x2, y2;
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (shap[r][c] == 1)
			{
				x2 = x + c * mapsize;
				y2 = y + r * mapsize;
				setfillcolor(BLACK);
				solidrectangle(x2, y2, x2 + 1 * mapsize, y2 + 1 * mapsize);
			}
		}
	}
}
p Game::findshape(int number)
{
	switch (number)
	{
	case 0:
		return Shap1::temp1;
	case 1:
		return Shap1::temp2;
	case 2:
		return Shap1::temp3;
	case 3:
		return Shap1::temp4;
	case 4:
		return Shap2::temp1;
	case 5:
		return Shap2::temp2;
	case 6:
		return Shap2::temp3;
	case 7:
		return Shap2::temp4;
	case 8:
		return Shap3::temp1;
	case 9:
		return Shap3::temp2;
	case 10:
		return Shap3::temp3;
	case 11:
		return Shap3::temp4;
	case 12:
		return Shap4::temp1;
	case 13:
		return Shap4::temp2;
	case 14:
		return Shap4::temp3;
	case 15:
		return Shap4::temp4;
	case 16:
		return Shap5::temp1;
	case 17:
		return Shap5::temp2;
	case 18:
		return Shap5::temp3;
	case 19:
		return Shap5::temp4;
	default:
		exit(1);
	}
}
bool Game::moveable(int x0, int y0, move_dir_t moveDir)
{
	int x = (y0 - start_x) / mapsize;
	int y = (x0 - start_y) / mapsize;
	int id = Base::index * 4 + Base::dir;
	bool ret = true;
	int (*shape)[4];
	shape = findshape(id);
	if (moveDir == MOVE_DOWN) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (shape[i][j] == 1 &&
					(x + i + 1 >= 20 || visit[x + i + 1][y + j] == 1)) {
					ret = false;
				}
			}
		}
	}
	else if (moveDir == MOVE_LEFT) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (shape[i][j] == 1 &&
					(y + j == 0 || visit[x + i][y + j - 1] == 1)) {
					ret = false;
				}
			}
		}

	}
	else if (moveDir == MOVE_RIGHT) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (shape[i][j] == 1 &&
					(y + j + 1 >= 10 || visit[x + i][y + j + 1] == 1)) {
					ret =false;
				}
			}
		}
	}

	return ret;
}
void Game::failCheck()
{
	if (!moveable(Born_x, Born_y, MOVE_DOWN)) {
		setcolor(WHITE);
		settextstyle(30, 0, "Consolas");
		outtextxy(50, 120, "GAME OVER!");
		Sleep(1000);
		system("pause");
		closegraph();
		exit(0);
	}
}
bool Game::rotatable(int x, int y, block_dir_t dir)
{
	int id = Base::index * 4 + dir;
	int xIndex = (y - start_x) / 20;
	int yIndex = (x - start_y) / 20;
	int(*block)[4] = findshape(id);
	block = findshape(id);
	if (!moveable(x, y, MOVE_DOWN)) {
		return false;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[i][j] == 1 &&
				(yIndex + j < 0 || yIndex + j >= 10 || visit[xIndex + i][yIndex + j] == 1)) {
				return false;
			}
		}
	}

	return true;
}
void Game::wait(int interval)
{
	int count = interval / 10;
	for (int i = 0; i < count; i++) {
		Sleep(10);
		if (_kbhit()) {
			return;
		}
	}
}
void Game::mark(int x,int y)
{
	int id = Base::index * 4 + Base::dir;
	int x2 = (y - start_x) / 20;
	int y2 = (x - start_y) / 20;
	int(*block)[4];
	block = findshape(id);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (block[i][j] == 1) {
				visit[x2 + i][y2 + j] = 1;
				markColor[x2 + i][y2 + j] = color[Base::index];
			}
		}
	}

}
void Game::move()
{
	int x = Born_x;
	int y = Born_y;
	int k = 0;
	int curSpeed = speed;

	// 检测游戏是否结束
	failCheck();

	// 持续向下降落
	while (1) {
		if (_kbhit()) {
			int key =_getch();
			if (key == KEY_SPACE) {
				_getch();
			}
		}

		// 清除当前方块
		Clearblock(x, y+k,Base::dir,Base::index);

		if (_kbhit()) {
			int key =_getch();

			if (key == KEY_UP) {
				block_dir_t nextDir = (block_dir_t)((Base::dir + 1) % 4);
				if (rotatable(x, y + k, nextDir)) {
					Base::dir = nextDir;
				}
			}
			else if (key == KEY_DOWN) {
				curSpeed = 50;
			}
			else if (key == KEY_LEFT) {
				if (moveable(x, y + k + 20, MOVE_LEFT)) {
					x -= 20;
				}
			}
			else if (key == KEY_RIGHT) {
				if (moveable(x, y + k + 20, MOVE_RIGHT)) {
					x += 20;  //x = x + 20;
				}
			}
		}

		k += 20;

		// 绘制当前方块
		Drawblock(x, y + k, Base::index, Base::dir);

		wait(curSpeed);

		// 方块的“固化”处理
		if (!moveable(x, y + k, MOVE_DOWN)) {
			mark(x, y + k);
			break;
		}
	}
}
void Game::newblock() {
	// 确定即将使用的方块的类别
	Base::index = Base::nextindex;

	// 绘制刚从顶部下降的方块
	Drawblock(Born_x, Born_y,Base::index,Base::dir);

	// 让新出现的方块暂停一会
	Sleep(100); //0.1秒

	// 在右上角区域，绘制下一个方块
	Nextblock();

	// 方块降落
	move();
}
void Game::down(int x)
{
	for (int i = x; i > 0; i--) {
		// 消除第i行
		for (int j = 0; j < 10; j++) {
			if (visit[i - 1][j]) {
				visit[i][j] = 1;
				markColor[i][j] = markColor[i - 1][j];
				setfillcolor(markColor[i][j]);
				fillrectangle(20 * j + start_x, 20 * i + start_y, 20 * j+20 + start_x, 20 * i + 20 + start_y);
			}
			else {
				visit[i][j] = 0;
				setfillcolor(BLACK);
				solidrectangle(20 * j + start_x, 20 * i + start_y, 20 * j + 20 + start_x, 20 * i + 20 + start_y);
			}
		}
	}

	setfillcolor(BLACK);
	for (int j = 0; j < 10; j++) {
		visit[0][j] = 0;
		solidrectangle(20 * j + start_x, 0, 20 * j + 20 + start_x, 0);
	}
}
void Game::addScore(int lines)
{
	char str[20];
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	settextstyle(25, 0, "隶书");
	Base::score += lines * 10;
	sprintf_s(str, "%d", Base::score);
	outtextxy(375, 120, str);
}
void Game::updateGrade()
{
	
	Base::level = Base::score / 50;//50分一等级
	char str[20];
	sprintf_s(str, "%d", Base::level);
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(375, 145, str);

	// 更新速度, 等级越高，速度越快，speed越小！
	// 最慢：500， 最快是100
	speed = 500 - Base::level * 100;
	if (speed <= 100) {
		speed = 100;
	}
}
void Game::check()
{
	int i, j;
	int clearLines = 0;

	for (i = 19; i >= 0; i--) {
		// 检查第i行有没有满
		for (j = 0; j < 10 && visit[i][j]; j++);
		if (j >= 10) {
			down(i);  
			i++;  
			clearLines++;
		}
	}

	// 更新分数
	addScore(clearLines);

	// 更新等级(更新等级提示，更新速度）
	updateGrade();
}
