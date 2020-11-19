// clear_bang.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"clear_bang.h"

void ShowMenu()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("**********输入1 开始游戏*********\n");
	printf("**********输入0 退出游戏*********\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t请输入：\n");

}



void InitMap()
{
	int count = 0;

	for (int i = 0; i < MAX_ROW; i++)// 初始化地图
		for (int j = 0; j < MAX_COLUMN; j++)
		{
			map[i][j] = 0;
			show_map[i][j] = '*';
		}

	while (count < BANG_NUMBER)        //埋雷
	{
		int x = rand() % ROW + 1;
		int y = rand() % COLUMN + 1;
		if (map[x][y] != 1)
		{
			map[x][y] = 1;
			++count;
		}
	}
}

void Show_BangMap()
{
	system("CLS");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("\n");
	printf("\t");                  //打印 行列数
	for (int i = 1; i <= ROW; i++)
		printf("%d\t", i);
	printf("\n");
	for (int i = 1; i <= ROW; i++)  //  打印地图
	{
		printf("%d ", i);
		for (int j = 1; j <= COLUMN; j++)
			printf("\t%c ", show_map[i][j]);
		printf("\n");
	}
}

void CheckFirst()   //第一次输入时 检查判断
{
	int x; 
	int y;
	int count = 0;
	printf("输入坐标：\n");
	scanf_s("%d%d",&x,&y);
	while (TRUE)
	{
		if (x > 0 && y > 0 && x <= ROW && y <= COLUMN) // 判断输入是否合法
		{
			if (map[x][y] == 1)   //  如果第一次命中雷元素
			{
				map[x][y] = 0;
				while (TRUE)    //  重新排放一个雷元素
				{
					int x = rand() % ROW + 1;
					int y = rand() % COLUMN + 1;
					if (map[x][y] != 1)
					{
						map[x][y] = 1;
						break;
					}
				}
			}
			OpenMap(x, y);
			Show_BangMap();
			break;
		}
		else
		{
			printf("输入不合法");
			CheckFirst();
		}
	}


}

int GetBangNum(int x, int y)       //判断雷数
{
	//将周围的所有格子的数加起来来判断是否有雷
	return map[x - 1][y - 1] + map[x][y - 1] + map[x + 1][y - 1] + map[x - 1][y] + map[x + 1][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1];
}

void OpenMap(int x, int y)         //判断展开
{
	if (GetBangNum(x, y) == 0)
	{
		show_map[x][y] = ' ';
		if (x - 1 > 0 && y - 1 > 0 && show_map[x - 1][y - 1] == '*')
			OpenMap(x - 1, y - 1);
		if (x - 1 > 0 && show_map[x - 1][y] == '*')
			OpenMap(x - 1, y);
		if (y - 1 > 0 && show_map[x][y - 1] == '*')
			OpenMap(x, y - 1);
		if (x + 1 <= ROW && y + 1 <= COLUMN && show_map[x + 1][y + 1] == '*')
			OpenMap(x + 1, y + 1);
		if (y + 1 <= COLUMN && show_map[x][y + 1] == '*')
			OpenMap(x, y + 1);
		if (x + 1 <= ROW && show_map[x + 1][y] == '*')
			OpenMap(x + 1, y);
		if (x - 1 > 0 && y + 1 <= COLUMN && show_map[x - 1][y + 1] == '*')
			OpenMap(x - 1, y + 1);
		if (x + 1 <= ROW && y - 1 >= 0 && show_map[x + 1][y - 1])
			OpenMap(x + 1, y - 1);
	}
	else
		show_map[x][y] = GetBangNum(x, y) + 48;
}

int  IsFull()   // 判断游戏是否结束
{
	int count = 0;
	for (int i = 1; i <= ROW; i++)
		for (int j = 1; j <= COLUMN; j++)
			if (show_map[i][j] == '*')
				++count;
	if (count == BANG_NUMBER)
		return TRUE;
	else
		return FALSE;
}

void Playing()
{
	srand((unsigned int)time(NULL));
	InitMap();
	Show_BangMap();
	int x, y;
	CheckFirst();
	while (TRUE)
	{
		printf("输入坐标：\n");
		scanf_s("%d%d", &x, &y);
		if (x > 0 && y > 0 && x <= ROW && y <= COLUMN)
		{
			if (map[x][y] == 1)        //踩雷
			{
				for (int i = 1; i <= ROW; i++)
					for (int j = 1; j <= COLUMN; j++)
						if (show_map[i][j] == '*')
							show_map[i][j] = '!';
				Show_BangMap();
				printf("\n");
				printf("失败！！游戏结束！！");
				break;
			}
			else                    //没有踩雷
			{
				if (GetBangNum(x, y) == 0)
					OpenMap(x, y);
				else
					show_map[x][y] = GetBangNum(x, y) + 48;
				Show_BangMap();
			}

			if (IsFull() == TRUE)     //判断胜利
			{
				for (int i = 1; i <= ROW; i++)
					for (int j = 1; j <= COLUMN; j++)
						if (show_map[i][j] == '*')
							show_map[i][j] = '!';
				void Show_BangMap();
				printf("游戏胜利！！！\n\n\n");
				break;
			}
		}
		else
			printf("输入有误");
	}
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
