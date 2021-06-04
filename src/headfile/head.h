#include <stdio.h>                           //标准库
#include <string.h>                          //strcmp();
#include <stdlib.h>                          //system();srand();rand();
#include <unistd.h>                          //可使用sleep();
#include <time.h>                            //time(NULL);
#include <sys/stat.h>                        //Linux专用，用于获取文件字节数

#include "kbhit_input.h"
#include "menu.h"
#include "pid.h"

#define Clear system("clear");               //清屏->兼容问题
#define Print printf("\033[1;33m\033[1;1H-----------------------------------------\033[2;1H|\033[2;3H本次局数：%-3d局\033[2;20H|\033[2;23H当前局数：%d\033[2;41H|\033[3;1H|---------------------------------------|\033[4;1H|\033[4;3H玩家血量：%d\033[4;20H|\033[4;23H玩家攻击力：%d\033[4;41H|\033[5;1H|---------------------------------------|\033[6;1H|\033[6;3HNPC 血量：%d\033[6;20H|\033[6;23HNPC攻击力：%d\033[6;41H|\033[7;1H|---------------------------------------|\033[1;33m\033[8;13H1.攻击\033[8;24H2.防御\033[9;18H请选择\033[0m",count,i,my.x,my.g,npc.x,npc.g);

struct data{                                 //定义存放角色数据的结构体Data
	int x;                               //血量
	int x2;                              //备份的血量，用于战斗结束后恢复血量
	int g;                               //攻击力
	int v;                               //胜利的次数
}my={500,500,0,0},npc={500,500,0,0};         //分别定义存放玩家和NPC数据的结构体函数

char pass[10];

void welcome();                              //主菜单打印
void game();                                 //游戏
void data();                                 //游戏记录
void help();                                 //帮助
void save(int count);                        //保存
float size();                                //获取字节数

