#include"game.h"
void initboard(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			board[i][j] = init;
		}
	}
}
void showboard(char board[][COL], int row, int col)
{
	printf("              | 1  |  2  |   3 \n");
	printf("------------\n");
	int i = 1;
	for (; i <= row; i++)
	{
		printf("%d |  ");
		int j = 0;
		for (; j < col; j++)
		{
			printf("  %c  |", board[i - 1][j]);
		}
		printf("\n");
		printf("------------\n");
	}
}
void computermove(char board[][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = c_clor;
			break;
		}
		Sleep(1000);
	}
}
void PlayerMove(char board[][COL], int row, int col)
{
	int x, y;
	while (1) {
		printf("Please enter your pos(x,y): ");
		scanf("%d% d", &x, &y);
		if ((x >= 1) && (x <= row) && (y >= 1) && (y <= col)) {
			if (' ' == board[x - 1][y - 1]) {
				board[x - 1][y - 1] = 'x';
				break;
			}
			else {
				printf("Your pos is error!\n");
			}
		}
		else {
			printf("Enter error!Try again\n");
		}
	}
}


char judge(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++)
	{
		if (board[i][0] = !' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return board[i][0];
		}
	}
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] = !' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	if (board[1][1] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[1][1] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (; j < col; j++)
		{
			if (board[i][j] == init)
			{
				return 'NULL';
			}
		}
	}
	return 'FULL';
}
int Guess()
{
	
	int result = 0;
	result = rand() % 2;
	int g = 0;
	printf("硬币已抛出，请猜正反面< 0:正面 , 2:反面");
	scanf("%d", &g);

	if (g == result)
	{
		printf("你猜对了，你先走！\n");
		return 1;
	}
	printf("你猜错了，电脑先走！\n");
	return 0;
}


void game()
{
	srand((unsigned long)time(NULL));      /*1,你先走*/
	char board[ROW][COL];
	initboard(board, ROW, COL);
	char result = 0;
	int x = 0;
	int y = 0;
	int who = Guess();
	do {
		showboard(board, ROW, COL);
		switch (who)
		{
		case1 :
			printf("请落子：>");

			scanf("%d %d ", &x, &y);
			if (x <= 0 || x > 3 || y <= 0 || y > 3) {
				printf("your operation is illegal,please check it and try again!\n");
				continue;
			}
			if (board[x - 1][y - 1] != ' ') {
				printf("该棋盘位置已被占用，请重新输入合法的序号！\n");
				continue;
			}
			board[x - 1][y - 1] = p_clor;
			who = 0;
			printf("wait a moment...\n");
			break;
		case 0:
			computermove(board,  ROW,  COL);
			who = 1;
			printf("wait a moment...\n");
			break;
		}
		result = judge(board, ROW, COL);
		if (result != 'N') {
			break;
		}
		showboard(board, ROW, COL);
		printf("请落子：>");
		
		scanf("%d %d ", &x, &y);
		if (x <= 0 || x > 3 || y <= 0 || y > 3) {
			printf("your operation is illegal,please check it and try again!\n");
			continue;
		}
		if (board[x - 1][y - 1] != ' ') {
			printf("该棋盘位置已被占用，请重新输入合法的序号！\n");
			continue;
		}
		board[x - 1][y - 1] = p_clor;
		result = judge(board, ROW, COL);
		if (result != 'N') {
			break;
		}
		computermove(board, ROW, COL);
		result = judge(board, ROW, COL);
		if (result != 'N') {
			break;
		}
	} while (1);
	if (result == p_clor) {
		printf("Congratulation,you  win!\n");
	}
	else if (result == c_clor) {
		printf("sorry,you lost!\n");
	}
	else {
		printf("Your draw!\n");
	}
	printf("还可以，再来一把吧！\n");

}
