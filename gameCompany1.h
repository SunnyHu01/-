////////////////�ҷ�����ʵ��/////////////
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��ҽṹ��
struct Player
{
	char name[64]; //�������
	int lev; // ��ҵȼ�
	int exp;  //��Ҿ���
};

//��ʼ����Ϸ  ����1�����ָ�룬 ����2���������
void INIT_GAME_Company1(void **player, char name[]);  //������ָ���ԭ�������ҷ������޸�

//����ս��  ����1����ң� ����2����Ϸ�Ѷ�   ����1��ʾ��Ϸʤ��������0��ʾ��Ϸʧ�ܣ�
void PLAY_GAME_Company1(void *player, int gamegif);

//�鿴�����Ϣ
void PRINTF_GAME_Company1(void *player);

//�뿪��Ϸ
void EXIT_GAME_Company1(void *player);

