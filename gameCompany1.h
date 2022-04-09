////////////////乙方具体实现/////////////
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//玩家结构体
struct Player
{
	char name[64]; //玩家姓名
	int lev; // 玩家等级
	int exp;  //玩家经验
};

//初始化游戏  参数1：玩家指针， 参数2：玩家名称
void INIT_GAME_Company1(void **player, char name[]);  //给二级指针的原因是让乙方方便修改

//核心战斗  参数1：玩家， 参数2：游戏难度   返回1表示游戏胜利，返回0表示游戏失败；
void PLAY_GAME_Company1(void *player, int gamegif);

//查看玩家信息
void PRINTF_GAME_Company1(void *player);

//离开游戏
void EXIT_GAME_Company1(void *player);

