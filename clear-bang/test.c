#include"clear_bang.h"

void test()
{
	ShowMenu();
	int a;
	while (TRUE)
	{
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:

			Playing();
			break;
		case 2:
			printf("游戏结束！");
			return;
		default:
			printf("输入有误");
		}
		test();
	}
}

int main()
{
	test();
	return 0;
}