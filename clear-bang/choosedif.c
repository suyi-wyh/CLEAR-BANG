//
//

#include"clear_bang.h"


void ShowDif()
{
	printf("*********************************\n");
	printf("*********************************\n");
	printf("*************1.simpleness********\n");
	printf("*************2.  middle  ********\n");
	printf("*************3.difficult ********\n");
	printf("*********************************\n");
	printf("*********************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
}

void ChooseDif()
{
	int flag;
	ShowDif();
	printf("\t\t");
	printf("\t«Î ‰»Î£∫");

	scanf_s("%d", &flag);
	switch (flag)
	{
	case 1:
		BANG_NUMBER = BANGNUMBER;
		ROW = BASIC_ROW;
		COLUMN = BASIC_COLUMN;
		break;
	case 2:
		BANG_NUMBER = flag * BANGNUMBER;
		ROW = flag * BASIC_ROW;
		COLUMN = flag * BASIC_COLUMN;
		break;
	case 3:
		BANG_NUMBER = flag * BANGNUMBER;
		ROW = flag * BASIC_ROW;
		COLUMN = flag * BASIC_COLUMN;
		break;
	default:
		printf(" ‰»Î”–ŒÛ");
		ChooseDif();
	}


}
//
//
//
//
//
//
//
//
//
//
//
//