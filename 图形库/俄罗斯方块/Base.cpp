#include "Base.h"
Base::Base():score(0),index(0),nextindex(1),dir(up),level(1)
{
	for(int r=0;r<22;r++)
		for (int c = 0; c < 12; c++)
		{
			if (r == 0 || r == 21 || c == 0 || c == 11)
				map[r][c] = 9;
			else map[r][c] = 0;
		}
}
void Base::show()
{
	IMAGE bk;
	loadimage(&bk, "bk.jpg", 450, 600);
	putimage(0,0,&bk);
	
	for (int r = 0; r < 22; r++)
		for (int c = 0; c < 12; c++)
		{
			switch (map[r][c])
			{
			case 0:
				setfillcolor(BLACK);
				solidrectangle(c * mapsize, r * mapsize, (c + 1) * mapsize, (r + 1) * mapsize);
				break;
			case 9:	
				setfillcolor(BLUE);
				fillrectangle(c * mapsize, r * mapsize, (c + 1) * mapsize, (r + 1) * mapsize);
				break;
			};
		}
	setfillcolor(BLACK);
	solidrectangle(300, 0, 300 + 4 * mapsize, 0 + 4 * mapsize);
}
void Base::Showscore()
{
	char text[20] ;
	sprintf_s(text,"分数：%d",score);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(25,0,"隶书");
	outtextxy(0, 500, "上:变形 下:下落 左:左移 右:右移");
	setbkmode(OPAQUE);
	settextcolor(WHITE);
	outtextxy(300,120,text);
	sprintf_s(text, "等级：%d", level);
	outtextxy(300, 145, text);
}
