#include <stdio.h>                           //标准库
#include <string.h>                          //strcmp();
#include <stdlib.h>                          //system();srand();rand();
#include <unistd.h>                          //sleep();
#include <time.h>                            //time(NULL);
#include <sys/stat.h>                        //Linux专用，用于获取文件字节数

#define print printf("\t\t     本次局数：%d局\n\t\t      当前局数：%d\n\t    玩家血量：%d\t玩家攻击力：%d\n\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",m,a,my.x,my.g,npc.x,npc.g);

struct data{                                 //定义存放角色数据的结构体Data
	int x;                               //血量
	int x2;                              //备份的血量，用于战斗结束后恢复血量
	int g;                               //攻击力
	int v;                               //胜利的次数
}my={500,500,0,0},npc={500,500,0,0};         //分别定义存放玩家和NPC数据的结构体函数

void cls();                                  //清屏
void welcome();                              //主菜单打印
void game();                                 //游戏
void save();                                 //游戏记录
void help();                                 //帮助
float size();                                //获取字节数
