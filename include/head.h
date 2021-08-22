#include "include.h"
#include <time.h>                            //time(NULL);

#define Print printf("\033[1;33m\033[1;1H-----------------------------------------\033[2;1H|\033[2;3H本次局数：%-3d局\033[2;20H|\033[2;23H当前局数：%d\033[2;41H|\033[3;1H|---------------------------------------|\033[4;1H|\033[4;3H玩家血量：%d\033[4;20H|\033[4;23H玩家攻击力：%d\033[4;41H|\033[5;1H|---------------------------------------|\033[6;1H|\033[6;3HNPC 血量：%d\033[6;20H|\033[6;23HNPC攻击力：%d\033[6;41H|\033[7;1H|---------------------------------------|\033[1;33m\033[8;13H1.攻击\033[8;24H2.防御\033[9;18H请选择\033[0m",count,i,my.hp,my.str,npc.hp,npc.str);

struct data{                                 //定义存放角色数据的结构体Data
	int hp;                              //血量
	int back_hp;                         //备份的血量，用于战斗结束后恢复血量
	int str;                             //攻击力
	int back_str;                        //备份的攻击力
	int V;                               //胜利次数
};

extern struct data my,npc;         //分别定义存放玩家和NPC数据的结构体函数

void welcome(int m);//主菜单打印
void game();//游戏
void data();//游戏记录
void help();//帮助
void save(int count);//保存
float size();//获取字节数
void stop();//在截获SIGINT信号时执行的函数

