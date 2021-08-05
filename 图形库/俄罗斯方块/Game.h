#pragma once
#include"Shap1.h"
#include"Shap2.h"
#include"Shap3.h"
#include"Shap4.h"
#include"Shap5.h"
typedef int(*p)[4];
#define start_x 20
#define start_y 20
#define KEY_UP		72
#define	KEY_RIGHT	77
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_SPACE	32
#define Born_x      80
#define Born_y		20
 enum move_dir_t {
	MOVE_DOWN=0,
	MOVE_LEFT=1,
	MOVE_RIGHT=2
} ;
class Game :public Shap1, Shap2, Shap3, Shap4, Shap5
{
	int color[5] = {
	GREEN, CYAN,  MAGENTA, BROWN, YELLOW
	};
	int visit[20][10]; //访问数组
	int markColor[20][10]; //表示对应位置的颜色
	int speed;
public:
	Game() { 
		memset(visit,0,sizeof(visit)); 
		memset(markColor, 0, sizeof(markColor));
		speed = 500;
	}
	p findshape(int number);
	void Nextblock();
	void Gamescene();
	void Drawblock(int x, int y, int index,int dir);
	void Clearblock(int x, int y, int dir, int index);
	bool moveable(int x, int y, move_dir_t d);
	void failCheck();		//检测游戏是否结束
	bool rotatable(int x, int y, block_dir_t dir);
	void wait(int interval);
	void mark(int x, int y);
	void move();
	void newblock();
	void down(int x);
	void addScore(int lines);
	void updateGrade();
	void check();
	void Clearblock();
};