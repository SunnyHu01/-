#include "gameCompany1.h"
#pragma warning (disable:4996)

//初始化游戏  参数1：玩家指针， 参数2：玩家名称
void INIT_GAME_Company1(void **p, char name[])  //给二级指针的原因是让乙方方便修改
{
	struct Player *player = malloc(sizeof(struct Player));
	if (player == NULL)
		return;
	strcpy(player->name, name);
	player->exp = 0;
	player->lev = 0;

	*p = player;
}

//判断游戏是否胜利；
int Iswin(int rand_data)
{
	int num = rand() % 100 + 1;  //设置随机数1-100
	if (num <= rand_data)
	{
		printf("玩家游戏胜利！\n");
		return 1;
	}
	else
	{
		printf("GAME OVER!\n");
		return 0;
	}	
}

//核心战斗  参数1：玩家， 参数2：游戏难度   返回1表示游戏胜利，返回0表示游戏失败；
void PLAY_GAME_Company1(void *p, int gamegif)
{
	struct Player *player = p;
	if (player == NULL)
		return;
	while (1)
	{	
		getchar();  
		system("cls");  //清屏
		printf("1：简单\t2：一般\t3：困难\n");
		printf("请玩家选择游戏难度：");
		scanf("%d", &gamegif);
		getchar();  //回车暂缓

		switch (gamegif)
		{
		case 1:
			if (Iswin(90) == 1)  //判断游戏是否胜利；参数是胜率
			{
				player->exp += 10;  //经验值加10；
				player->lev = player->exp / 50;  //50经验值升一级		
			}
			else
				EXIT_GAME_Company1(player);
			PRINTF_GAME_Company1(player);
			break;
		case 2:
			if (Iswin(60) == 1)
			{
				player->exp += 20;  //经验值加20；
				player->lev = player->exp / 50;  //50经验值升一级		
			}
			else
				EXIT_GAME_Company1(player);
			PRINTF_GAME_Company1(player);
			break;
		case 3:
			if (Iswin(40) == 1)
			{
				player->exp += 30;  //经验值加30；
				player->lev = player->exp / 50;  //50经验值升一级				
			}
			else
				EXIT_GAME_Company1(player);
			PRINTF_GAME_Company1(player);
			break;
		}
	}	
}

//查看玩家信息
void PRINTF_GAME_Company1(void *p)
{
	struct Player *player = p;
	if (player == NULL)
		return;
	printf("玩家：%s\t经验值：%d\t等级：%d\n", player->name, player->exp, player->lev);
}

//离开游戏
void EXIT_GAME_Company1(void *p)
{
	struct Player *player = p;
	if (player == NULL)
		return;
	PRINTF_GAME_Company1(player);
	exit(0);
}