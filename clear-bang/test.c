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
			printf("��Ϸ������");
			return;
		default:
			printf("��������");
		}
		test();
	}
}

int main()
{
	test();
	return 0;
}