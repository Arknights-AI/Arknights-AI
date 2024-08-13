#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
/*
    棋盘:
        map[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: map[3][6] = 1  表示(3,6)的位置是黑子
*/
int map[19][19];
// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag;
// -------------------- 数据设计 --------------------


// -------------------- service --------------------
/*
    负责人: 张三
    功能: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();
/*
    *难点1
    负责人: 张三
    功能: 根据传入的坐标(map对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);
/*
    负责人: 张三
    功能: 在指定位置落子
        如果map[x][y]是空地 则修改map[x][y]的值:改为相应颜色(flag对应颜色)
        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------



// -------------------- view --------------------
/*
    功能: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        进入游戏: 调用游戏界面函数gameView();
        进入设置: 敬请期待...
        退出游戏: 调用exit(0);
*/
void menuView();
/*
    负责人: 张三
    功能: 根据map数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowMap();
/*
    负责人: 张三
    功能: 根据flag的值  打印游戏胜利界面  用户可以按任意键回到主菜单
    参数: void
    返回值: void
*/
void winView();
/*
    *难点2
    负责人: 张三
    功能: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowMap())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
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
    //使地图中所有格都变为空地
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 19; j++)
        {
            map[i][j] = 0;
        }
    }
    //当前回合为黑棋
    flag = 0;
}
//检查
int isWin(int x, int y)
{
    int player = (flag % 2 == 0) ? 1 : 2;
    int count = 1;
    // 垂直方向检查
    for (int i = 1; i < 5; i++) {
        if (x + i < 19 && map[x + i][y] == player) count++;
        else break;
    }
    for (int i = 1; i < 5; i++) {
        if (x - i >= 0 && map[x - i][y] == player) count++;
        else break;
    }
    if (count >= 5) return player;




    // 水平方向检查
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

    // 正对角线方向检查
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

    // 反对角线方向检查
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

    // 如果没有找到五子连珠，则返回0
    return 0;
}



int playerMove(int x, int y)
{
    if (map[x][y] == 0)
    {
        int player = (flag % 2 == 0) ? 1 : 2;
        map[x][y] = player;
        return 1;//落子成功
    }
    else
    {
        return 0;//落子失败
    }
}

void menuView()
{
    printf("1.进入游戏\n");
    printf("2.进入设置\n");
    printf("3.退出游戏\n");

    int election;
    scanf("%d", &election);
    switch (election)
    {
    case 1:
        gameView();
        break;
    case 2:
        printf("更多内容敬请期待");
        break;
    case 3:
        exit(0);
        break;
    }


}

void gameView_ShowMap() {
    int i, j;
    printf("  ");
    // 打印列号
    for (j = 0; j < 19; j++) {
        printf("%2d", j);
    }
    printf("\n");

    for (i = 0; i < 19; i++) {
        printf("%2d", i); // 打印行号
        for (j = 0; j < 19; j++) {
            if (map[i][j] == 0) {
                printf("– "); // 空位打印点
            }
            else if (map[i][j] == 1) {
                printf("● "); // 黑棋打印黑圆
            }
            else if (map[i][j] == 2) {
                printf("○ "); // 白棋打印白圆
            }
        }
        printf("\n");
    }
}
void winView()
{
    char a[100] = { (flag % 2 == 0) ? "黑子胜利" : "白子胜利" };
    printf("%s\n",a);
    _getch(); // 用户按下任意键后继续执行
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
            printf("请再下一枚棋子\n");
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