#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gameCompany1.h"
#pragma warning (disable:4996)

//��ʼ����Ϸ  ����1�����ָ�룬 ����2���������
typedef void(*INIT_GAME)(void **player, char name[]);  //������ָ���ԭ�������ҷ������޸�

//����ս��  ����1����ң� ����2����Ϸ�Ѷ�   ����1��ʾ��Ϸʤ��������0��ʾ��Ϸʧ�ܣ�
typedef void(*PLAY_GAME)(void *player, int gamegif);

//�鿴�����Ϣ
typedef void(*PRINTF_GAME)(void *player);

//�뿪��Ϸ
typedef void(*EXIT_GAME)(void *player);

//�׷�����ʵ��
void PlayGame(INIT_GAME init_game, PLAY_GAME play_game, PRINTF_GAME print_game, EXIT_GAME exit_game)
{
	//��ʼ����Ϸ
	void *p = NULL;
	char buf[1024] = { 0 };
	printf("������������ƣ�");
	scanf("%s", buf);

	init_game(&p, buf);

	//����ս��
	int gamegif = 0;
	/*printf("1����\t2��һ��\t3������\n");
	printf("�����ѡ����Ϸ�Ѷȣ�");
	scanf("%d", &gamegif);*/

	play_game(p, gamegif);

	//�鿴�����Ϣ
	//print_game(p);

	//�뿪��Ϸ
	//exit_game(p);
}

int main()
{
	//////�׷��ĳ���ʵ��///////////
	//ʵ�ּ׷��ӿڣ����к���ָ��ȫ�����������Ҵ������Ϸ��ܣ�
	srand((unsigned int)time(NULL));  //�������
	PlayGame(INIT_GAME_Company1, PLAY_GAME_Company1, PRINTF_GAME_Company1, EXIT_GAME_Company1);

	system("pause");
	return 0;
}