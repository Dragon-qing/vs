#pragma once
#include "Base.h"
class Shap4 :
	public Base
{
protected:
	int temp1[4][4] =
	{
		{ 0,0,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,1,0 }
	};
	int temp2[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,1,0 },
		{ 1,0,0,0 },
		{ 0,0,0,0 }
	};
	int temp3[4][4] =
	{
		{ 0,0,0,0 },
		{ 1,1,0,0 },
		{ 0,1,0,0 },
		{ 0,1,0,0 }
	};
	int temp4[4][4] =
	{
		{ 0,0,0,0 },
		{ 0,0,1,0 },
		{ 1,1,1,0 },
		{ 0,0,0,0 }
	};
};

