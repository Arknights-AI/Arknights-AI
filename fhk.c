#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*
    ����:
        map[i][j]��ʾ����(i,j)��ֵ
        0��ʾ�յ�
        1��ʾ����
        2��ʾ����
    ��: map[3][6] = 1  ��ʾ(3,6)��λ���Ǻ���
*/
int map[19][19];
// ��ʾ��ǰ�غ���  ż����ʾ��������  ������ʾ��������
// ��: flag = 20 ��ʾ��ǰ�ǵ�[20]������  �ɺڷ�����
int flag;
// -------------------- ������� --------------------


// -------------------- service --------------------
/*
    ������: ����
    ����: ��ʼ����Ϸ����
        �����̵�ֵ��ʼ��Ϊ0
        ��ǰ�غ���Ϊ����(flag��Ϊ0)
    ����: void
    ����ֵ: void
*/
void init();
/*
    *�ѵ�1
    ������: ����
    ����: ���ݴ��������(map��Ӧλ��)��flagֵ �ж������Ƿ��ʤ
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾû�л�ʤ
        1��ʾ����ʤ��
        2��ʾ����ʤ��
*/
int isWin(int x, int y);
/*
    ������: ����
    ����: ��ָ��λ������
        ���map[x][y]�ǿյ� ���޸�map[x][y]��ֵ:��Ϊ��Ӧ��ɫ(flag��Ӧ��ɫ)
        ���򲻲���
    ����:
        x: ��ǰ�غ����ӵ�x����
        y: ��ǰ�غ����ӵ�y����
    ����ֵ:
        0��ʾ����ʧ�� (�����Ѿ�����)
        1��ʾ���ӳɹ�

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    ����: չʾѡ��, ��ҿ���������ѡ�������Ϸ, �������û��˳���Ϸ
        ������Ϸ: ������Ϸ���溯��gameView();
        ��������: �����ڴ�...
        �˳���Ϸ: ����exit(0);
*/
void menuView();
/*
    ������: ����
    ����: ����map���� ��ӡ��Ϸ����
    ����: void
    ����ֵ: void
*/
void gameView_ShowMap();
/*
    ������: ����
    ����: ����flag��ֵ  ��ӡ��Ϸʤ������  �û����԰�������ص����˵�
    ����: void
    ����ֵ: void
*/
void winView();
/*
    *�ѵ�2
    ������: ����
    ����: ��Ϸ��������
        ��ʼ����Ϸ����(���ú���init())
        while(1){
            ��ӡ��Ϸ����(���ú���gameView_ShowMap())
            ���������������

            ����(�������Ӻ���playerMove())
                (�������ʧ�� ���¿�ʼѭ��)

            �ж���Ϸ�Ƿ�ʤ��(����ʤ���жϺ���isWin())
                (�����Ϸʤ�� ����ʤ�����溯�� Ȼ�������ǰ����)
            �л����(�޸�flagֵ)
        }
    ����: void
    ����ֵ: void
*/
void gameView();
int main()
{
    menuView();
    return 0;
}

void init()
{
    int i, j;
    //ʹ��ͼ�����и񶼱�Ϊ�յ�
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 19; j++)
        {
            map[i][j] = 0;
        }
    }
    //��ǰ�غ�Ϊ����
    flag = 0;
}
//���
int isWin(int x, int y)
{
    int player = (flag % 2 == 0) ? 1 : 2;
    int count = 1;
    // ��ֱ������
    for (int i = 1; i < 5; i++) {
        if (x + i < 19 && map[x + i][y] == player) count++;
        else break;
    }
    for (int i = 1; i < 5; i++) {
        if (x - i >= 0 && map[x - i][y] == player) count++;
        else break;
    }
    if (count >= 5) return player;




    // ˮƽ������
    count = 1;
    for (int i = 1; i < 5; i++)
    {
        if (y + i < 19 && map[x][y + i] == player) count++;
        else break;
    }
    for (int i = 1; i < 5; i++)
    {
        if (y - i >= 0 && map[x][y - i] == player) count++;
        else break;
    }
    if (count >= 5) return player;

    // ���Խ��߷�����
    count = 1;
    for (int i = 1; i < 5; i++)
    {
        if (x + i < 19 && y + i < 19 && map[x + i][y + i] == player) count++;
        else break;
    }
    for (int i = 1; i < 5; i++)
    {
        if (x - i >= 0 && y - i >= 0 && map[x - i][y - i] == player) count++;
        else break;
    }
    if (count >= 5) return player;

    // ���Խ��߷�����
    count = 1;
    for (int i = 1; i < 5; i++)
    {
        if (x + i < 19 && y - i >= 0 && map[x + i][y - i] == player) count++;
        else break;
    }
    for (int i = 1; i < 5; i++)
    {
        if (x - i >= 0 && y + i < 19 && map[x - i][y + i] == player) count++;
        else break;
    }
    if (count >= 5) return player;

    // ���û���ҵ��������飬�򷵻�0
    return 0;
}



int playerMove(int x, int y)
{
    if (map[x][y] == 0)
    {
        int player = (flag % 2 == 0) ? 1 : 2;
        map[x][y] = player;
        return 1;//���ӳɹ�
    }
    else
    {
        return 0;//����ʧ��
    }
}

void menuView()
{
    printf("1.������Ϸ\n");
    printf("2.��������\n");
    printf("3.�˳���Ϸ\n");

    int election;
    scanf("%d", &election);
    switch (election)
    {
    case 1:
        gameView();
        break;
    case 2:
        printf("�������ݾ����ڴ�");
        break;
    case 3:
        exit(0);
        break;
    }


}

void gameView_ShowMap() {
    int i, j;
    printf("  ");
    // ��ӡ�к�
    for (j = 0; j < 19; j++) {
        printf("%2d", j);
    }
    printf("\n");

    for (i = 0; i < 19; i++) {
        printf("%2d", i); // ��ӡ�к�
        for (j = 0; j < 19; j++) {
            if (map[i][j] == 0) {
                printf("�C "); // ��λ��ӡ��
            }
            else if (map[i][j] == 1) {
                printf("�� "); // �����ӡ��Բ
            }
            else if (map[i][j] == 2) {
                printf("�� "); // �����ӡ��Բ
            }
        }
        printf("\n");
    }
}
void winView()
{
    char a[100] = { (flag % 2 == 0) ? "����ʤ��" : "����ʤ��" };
    printf("%s\n",a);
    _getch(); // �û���������������ִ��
    menuView();
}

void gameView()
{
    init();
    while (1)
    {
        gameView_ShowMap();
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        int num = playerMove(x, y);
        if (num ==0)
        {
            printf("������һö����\n");
            continue;
        }
        int win = isWin(x, y);
        if (win == 1 ||win== 2)
        {
            winView();
            break;
        }
        flag++;
        
        
    }

}