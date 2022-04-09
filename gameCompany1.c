#include "gameCompany1.h"
#pragma warning (disable:4996)

//��ʼ����Ϸ  ����1�����ָ�룬 ����2���������
void INIT_GAME_Company1(void **p, char name[])  //������ָ���ԭ�������ҷ������޸�
{
	struct Player *player = malloc(sizeof(struct Player));
	if (player == NULL)
		return;
	strcpy(player->name, name);
	player->exp = 0;
	player->lev = 0;

	*p = player;
}

//�ж���Ϸ�Ƿ�ʤ����
int Iswin(int rand_data)
{
	int num = rand() % 100 + 1;  //���������1-100
	if (num <= rand_data)
	{
		printf("�����Ϸʤ����\n");
		return 1;
	}
	else
	{
		printf("GAME OVER!\n");
		return 0;
	}	
}

//����ս��  ����1����ң� ����2����Ϸ�Ѷ�   ����1��ʾ��Ϸʤ��������0��ʾ��Ϸʧ�ܣ�
void PLAY_GAME_Company1(void *p, int gamegif)
{
	struct Player *player = p;
	if (player == NULL)
		return;
	while (1)
	{	
		getchar();  
		system("cls");  //����
		printf("1����\t2��һ��\t3������\n");
		printf("�����ѡ����Ϸ�Ѷȣ�");
		scanf("%d", &gamegif);
		getchar();  //�س��ݻ�

		switch (gamegif)
		{
		case 1:
			if (Iswin(90) == 1)  //�ж���Ϸ�Ƿ�ʤ����������ʤ��
			{
				player->exp += 10;  //����ֵ��10��
				player->lev = player->exp / 50;  //50����ֵ��һ��		
			}
			else
				EXIT_GAME_Company1(player);
			PRINTF_GAME_Company1(player);
			break;
		case 2:
			if (Iswin(60) == 1)
			{
				player->exp += 20;  //����ֵ��20��
				player->lev = player->exp / 50;  //50����ֵ��һ��		
			}
			else
				EXIT_GAME_Company1(player);
			PRINTF_GAME_Company1(player);
			break;
		case 3:
			if (Iswin(40) == 1)
			{
				player->exp += 30;  //����ֵ��30��
				player->lev = player->exp / 50;  //50����ֵ��һ��				
			}
			else
				EXIT_GAME_Company1(player);
			PRINTF_GAME_Company1(player);
			break;
		}
	}	
}

//�鿴�����Ϣ
void PRINTF_GAME_Company1(void *p)
{
	struct Player *player = p;
	if (player == NULL)
		return;
	printf("��ң�%s\t����ֵ��%d\t�ȼ���%d\n", player->name, player->exp, player->lev);
}

//�뿪��Ϸ
void EXIT_GAME_Company1(void *p)
{
	struct Player *player = p;
	if (player == NULL)
		return;
	PRINTF_GAME_Company1(player);
	exit(0);
}