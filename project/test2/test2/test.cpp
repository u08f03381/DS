﻿#include <iostream>
using namespace std;

const int  m = 12, n = 15;//迷宮的大小
int maze[m + 2][n + 2] =
{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,//輸入迷宮地圖
1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,
1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1,
1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,
1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,
1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,
1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,
1,0,0,1,1,0,1,1,1,0,1,0,0,1,1,1,1,
1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,
1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,
1,1,1,0,0,0,1,1,0,1,1,0,0,0,1,0,1,
1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,
1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
int mark[m + 2][n + 2];//設立迷宮是否走過標志
					   //int move[8][2] = { { 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 },{ -1,0 }, { -1,1 } };
int SeekPath(int x, int y)
{
	int i, g, h;
	int move[8][2] = { { 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 },{ -1,0 },{ -1,1 } };
	if (x == 1 && y == 1) //如果到終點則找到路徑,返回 1
		return 1;
	for (i = 0; i<8; i++)//嘗試每一個方向 
	{
		g = x + move[i][0];
		h = y + move[i][1]; //探索地點的新坐標 

		if (maze[g][h] == 0 && mark[g][h] == 0)//如果該地點走得通且沒有被探索過
		{
			mark[g][h] = 1;//將這一地點置为探索過 
			if (SeekPath(g, h))//從這一地點開始新的探索,如果成功
			{
				maze[g][h] = 5;//把這一點設为通路 
				return 1;//返回1 
			}
		}
	}
	if (x == m&&y == n)
		cout << "No path!" << endl;//如果最後回到了起點,則說明沒有通路 
	return 0;//返回0
}

int main()
{
	int i, j;
	for (i = 0; i<m + 2; i++)
		for (j = 0; j<n + 2; j++)
			mark[i][j] = 0;//先將所有通路置为沒有走過

	mark[m][n] = 1;//將起點置为走過了
	if (SeekPath(m, n)) //如果走通 
	{
		cout << "(" << m << "," << n << ")" << endl;//先打出起點坐標
		maze[m][n] = 8;//將起點設为通路
		for (i = 0; i<m + 2; i++)
			for (j = 0; j<n + 2; j++)
			{
				cout << maze[i][j] << " ";
				if (j == n + 1)
					cout << endl;
			}//打印出走通後的迷宮
	}
}