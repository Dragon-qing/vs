#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void print(int a[][10])
{
	int i = 0, j = 0;
	while (i < 10)
	{
		switch (a[i][j])
		{
		case 0:printf("  "); break;
		case 1:printf("■"); break;
		case 2:printf("□"); break;
		case 3:printf("☆"); break;
		case 4:printf("♀"); break;
		case 5:printf("★"); break;
		case 7:printf("♀"); break;
		case 9:printf("♀"); break;
		}
		printf("  ");
		j++;
		if (j == 10)
		{
			printf("\n\n");
			i++;
			j = 0;
		}
	}
}
char move1(int map[][10])
{
	int px = 0, py = 0;
	char move;
	while (map[px][py] != 4 && map[px][py] != 7)
	{
		px++;
		if (px == 10)
		{
			py++;
			px = 0;
		}
	}
	//printf("%d %d\n", px, py);
	move = _getch();
	switch (move)
	{
	case 'w':
		if (map[px - 1][py] == 0 || map[px - 1][py] == 3)
		{
			map[px - 1][py] += 4;
			map[px][py] -= 4;
		}
		else if (map[px - 1][py] == 2 || map[px - 1][py] == 5)
		{
			if (map[px - 2][py] == 0 || map[px - 2][py] == 3)
			{
				map[px][py] -= 4;
				map[px - 1][py] += 2;
				map[px - 2][py] += 2;
			}
		}
		break;
	case 's':
		if (map[px + 1][py] == 0 || map[px + 1][py] == 3)
		{
			map[px + 1][py] += 4;
			map[px][py] -= 4;
		}
		else if (map[px + 1][py] == 2 || map[px + 1][py] == 5)
		{
			if (map[px + 2][py] == 0 || map[px + 2][py] == 3)
			{
				map[px][py] -= 4;
				map[px + 1][py] += 2;
				map[px + 2][py] += 2;
			}
		}
		break;
	case 'a':
		if (map[px][py - 1] == 0 || map[px][py - 1] == 3)
		{
			map[px][py - 1] += 4;
			map[px][py] -= 4;
		}
		else if (map[px][py - 1] == 2 || map[px][py - 1] == 5)
		{
			if (map[px][py - 2] == 0 || map[px][py - 2] == 3)
			{
				map[px][py] -= 4;
				map[px][py - 1] += 2;
				map[px][py - 2] += 2;
			}
		}
		break;
	case 'd':
		if (map[px][py + 1] == 0 || map[px][py + 1] == 3)
		{
			map[px][py + 1] += 4;
			map[px][py] -= 4;
		}
		else if (map[px][py + 1] == 2 || map[px][py + 1] == 5)
		{
			if (map[px][py + 2] == 0 || map[px][py + 2] == 3)
			{
				map[px][py] -= 4;
				map[px][py + 1] += 2;
				map[px][py + 2] += 2;
			}
		}
		break;
	case' ':return' '; break;
	}
	return '0';
}
int judge(int map[][10])
{
	int i = 0;
	int j = 0;
	for (; i < 10; j++)
	{
		if (j == 10)
		{
			i++;
			j = 0;
		}
		if (map[i][j] == 3 || map[i][j]==7 ) { return 1; }
	}
	printf("**********\n恭喜通关！\n**********");
	return 0;
}
void play(int map[][10])
{
	int x = 1;
	int mep[10][10];
	int i, j;
	char y = 0;
restrat:
	for (i = 0, j = 0; i < 10; j++)
	{
		if (j == 10)
		{
			i++; j = 0;
		}
		mep[i][j] = map[i][j];
	}
	while (x)
	{
		print(mep);
		y = move1(mep);
		system("cls");
		if (y == ' ') { goto restrat; }
		x = judge(mep);
	}
	Sleep(1000);
	system("cls");
}
int main()
{
	int map1[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,0,1,3,1,0,0,0,0},
		{0,0,0,1,0,1,1,1,1,0},
		{0,1,1,1,2,0,2,3,1,0},
		{0,1,3,0,2,4,1,1,1,0},
		{0,1,1,1,1,2,1,0,0,0},
		{0,0,0,0,1,0,1,0,0,0},
		{0,0,0,0,1,3,1,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
	};
	int map2[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,1,3,0,0,0,2,0,1,0},
		{0,1,3,2,0,0,1,0,1,0},
		{0,1,3,1,2,1,0,0,1,0},
		{0,1,1,1,0,1,4,1,1,0},
		{0,0,1,0,0,0,0,1,0,0},
		{0,0,1,0,0,1,1,1,0,0},
		{0,0,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	int map3[10][10] = {
		{0,1,1,1,1,1,1,1,0,0},
		{0,1,0,0,0,0,0,1,1,1},
		{1,1,2,1,1,1,0,0,0,1},
		{1,0,4,0,2,0,0,2,0,1},
		{1,0,3,3,1,0,2,0,1,1},
		{1,1,3,3,1,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	int map4[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,0,0,0},
		{0,1,0,0,0,0,1,0,0,0},
		{0,1,0,2,2,1,1,1,1,0},
		{0,1,0,4,2,3,0,0,1,0},
		{0,1,1,0,1,3,1,0,1,0},
		{0,1,3,0,0,0,1,0,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	int map5[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,0,0},
		{0,1,3,0,3,0,3,1,0,0},
		{0,1,0,2,2,2,0,1,0,0},
		{0,1,3,2,4,2,3,1,0,0},
		{0,1,0,2,2,2,0,1,0,0},
		{0,1,3,0,3,0,3,1,0,0},
		{0,1,1,1,1,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	int map6[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,0,0},
		{0,0,1,1,1,0,4,1,0,0},
		{0,0,1,0,0,2,0,1,0,0},
		{1,1,1,0,1,0,1,1,1,0},
		{1,0,0,0,1,0,1,3,1,0},
		{1,0,1,0,0,0,2,3,1,0},
		{1,0,2,0,0,0,0,3,1,0},
		{1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	int map7[10][10] = {
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,0,0,0},
		{0,1,0,0,0,4,1,0,0,0},
		{0,1,0,3,2,0,1,0,0,0},
		{0,1,0,0,0,0,1,0,0,0},
		{0,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	char g = 2;
	while (g != '1')
	{
		printf("***********\n");
		printf("游玩需知：\n w向前\n s向后\n a向左\n d向右\n 空格可重置关卡\n 按1继续\n");
		printf("***********\n");
		g = _getch();
	}
	system("cls");
	printf("第一关\n");
	play(map1);
	printf("第二关\n");
	play(map2);
	printf("第三关\n");
	play(map3);
	printf("第四关\n");
	play(map4);
	printf("第五关\n");
	play(map5);
	printf("第六关\n");
	play(map6);
	//system("pause");
	return 0;
}