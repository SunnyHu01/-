#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameCompany1.h"
#pragma warning (disable:4996)

//初始化游戏  参数1：玩家指针， 参数2：玩家名称
typedef void(*INIT_GAME)(void **player, char name[]);  //给二级指针的原因是让乙方方便修改

//核心战斗  参数1：玩家， 参数2：游戏难度   返回1表示游戏胜利，返回0表示游戏失败；
typedef void(*PLAY_GAME)(void *player, int gamegif);

//查看玩家信息
typedef void(*PRINTF_GAME)(void *player);

//离开游戏
typedef void(*EXIT_GAME)(void *player);

//甲方功能实现
void PlayGame(INIT_GAME init_game, PLAY_GAME play_game, PRINTF_GAME print_game, EXIT_GAME exit_game)
{
	//初始化游戏
	void *p = NULL;
	char buf[1024] = { 0 };
	printf("请输入玩家名称：");
	scanf("%s", buf);

	init_game(&p, buf);

	//核心战斗
	int gamegif = 0;
	/*printf("1：简单\t2：一般\t3：困难\n");
	printf("请玩家选择游戏难度：");
	scanf("%d", &gamegif);*/

	play_game(p, gamegif);

	//查看玩家信息
	//print_game(p);

	//离开游戏
	//exit_game(p);
}

int main()
{
	//////甲方的初步实现///////////
	//实现甲方接口，所有函数指针全部声明，并且搭建整个游戏框架；
	srand((unsigned int)time(NULL));  //随机种子
	PlayGame(INIT_GAME_Company1, PLAY_GAME_Company1, PRINTF_GAME_Company1, EXIT_GAME_Company1);

	system("pause");
	return 0;
}