#include "headfile/head.h"                                //引入头文件
#include <stdio.h>
#include <unistd.h>

int main() {
	/*隐藏光标*/
	printf("\033[?25l");
	kbhit2();

	srand(time(NULL));                                //随机数
	my.g = npc.g = rand()%(60-30)+30;                 //随机初始攻击力

	while(1) {                                //主菜单
		welcome(1);                                //打印主菜单
		switch (input()) {
			case 0x30:
				Clear
				/*显示光标*/
				printf("\033[?25h");
				kbhit2();
				return 0;                 //判断是否等于“0”，如果是，就退出程序
				break;
			case 0x31:
				Clear
				game();
				break;
			case 0x32:
				Clear
				data();
				break;
			case 0x33:
				Clear
				help();
				break;
			case 0x39:
				Clear
				if(remove("./save.txt") == EOF) {
					perror("\033[1;31mremove\033[0m");
					input();
				}
				break;
		}
		Clear
	}                                                 //如果都不正确，重新开始
	printf("\033[?25h");
	kbhit2();
	return 0;                                         //结束main函数，退出程序
}

void welcome(int m) {                                          //打印开始界面
	Clear
	menu("welcome");
	printf("\033[1;33m\033[8;11H1.开始游戏\033[8;37H2.游戏记录\033[9;11H3.游戏帮助\033[9;37H0.退出游戏\033[0m\n");
	printf("\033[2;32m\033[6;26H↑\033[10;26H↓\033[0m");
	printf("\033[11;52H\033[2;32m%d/2\033[1;33m",m);
	Menu
}

void game() {                                             //游戏函数
	int count = 0;                                    //局数信息
	int iinput = 0,aa,ab,c,d=0,e=0,f;                        //定义一大堆变量
	char ma='n';

	printf("\033[1;1H你想玩几局？\n");
	while (iinput != 0x0A) {
		printf("\033[s\033[1;1H你想玩几局？%d\033[u",count);
		kbhit2();
		iinput = input();
		if (iinput > 0x2F && iinput < 0x3A) {
			if (count == 0) {
				Clear
				printf("\033[1;1H你想玩几局？\n");
				if (iinput == 0x30) {
					continue;
				}
			}
			count = count * 10 + ( iinput - 48 );
			printf("%c",iinput);
			kbhit2();
		}
		else if (iinput == 0x7F) {
			Clear
			printf("\033[1;1H你想玩几局？\n");
			if (count != 0) {
				count /= 10;
			}
			else if (count < 10) {
				count = 0;
			}
			printf("\033[1D%d",count);
			kbhit2();
		}
		else if (iinput == 0x0A) {
			break;
		}
		else {
			iinput = 0x00;
		}
	}

	if(count == 0) return;
	else if(count < 0) return;
	else if(count > 1000) return;                         //谁会这么闲玩这么多局
	else if(count >= 100) {                               //勉强还能忍
		Clear
		printf("\t\t 这么多局，您确定吗？Y/n\n\t\t\t  ");
		iinput = input();
		if(iinput =='y' || iinput=='Y') {
			Clear
		}
		else {
			return;
		}
	}
	Clear
	for(int i = 1; i <= count; i++) {
		while(1) {
			srand(time(NULL));     /*随机数*/
			Print
			c = input();
			printf("\033[32m");
			if(c == 0x30) {
				Clear
				printf("\033[1;1H您确定要退出吗？您的记录将不会保存！\n");
				iinput = input();
				if(iinput =='y' || iinput =='Y') {
					my.x=my.x2;
					npc.x=npc.x;
					return;
				}
				Clear
			}
			else if(c == 0x31) {
				Clear
				d=rand()%(10-0);

				if(d==0 || d==4 || d==5 || d==6) {      //击中
					Clear
					npc.x=npc.x-my.g;
					if(npc.x<0) npc.x=0;
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("\t    你精准的刺中了NPC,NPC血量减少%d\n",my.g);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					input();

					if(npc.x<=0) {
						npc.x=0;
						e=1;
						break;
					}
				}
				else if(d==1) {                        //扑空
					Clear
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("\t    但是，你扑了个空，未能伤害到NPC。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					input();
				}

				else if(d==2 || d==3) {                //反击
					Clear
					my.x=my.x-npc.g;
					if(my.x<0) my.x=0;
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("\t    你因为太过于紧张，反而被NPC击中。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					input();
					if(my.x<=0){
						my.x=0;
						e=2;
						break;
					}
				}

				else if(d==7 || d==8 || d==9 || d==10){    //反击加防御
					Clear
					aa=rand()%(5-0)+1;
					ab=npc.g-aa;
					my.x=my.x-ab;

					if(my.x<0) my.x=0;
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("    你手慢了一点，被NPC击中，因为你防御着，你的血量减少%d。\n",ab);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					input();

					if(my.x<=0){
						my.x=0;
						e=2;
						break;
					}
				}
			}
			else {
				d=rand()%(20-0);
				if(d==0){                       //反击敌人
					Clear
					npc.x=npc.x-15;

					if(npc.x<0) npc.x=0;

					Print
					printf("\033[10;10H你选择了防御。\n");
					printf("      在你防御的时候顺便击中了NPC，使NPC的血量减少15。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					input();

					if(npc.x<=0){
						npc.x=0;
						e=1;
						break;
					}
				}
				else if(d==20){                  //被打中
					Clear
					my.x=my.x-npc.g;
					if(my.x<0) my.x=0;
					Print
					printf("\033[10;10H你选择了防御。\n");
					printf("     你没有防御好，导致敌人打中了你，你的血量减少%d。\n",npc.g);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					input();
					if(my.x<=0){
						my.x=0;
						e=2;
						break;
					}
				}
				else{                          //只有防御
					Clear
					Print
					printf("\033[10;10H你选择了防御。\n");
					printf("\t  你防住了敌人的攻击，但是这已经很勉强了。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					input();
				}
			}
			printf("\033[0m\n");
			Clear
		}
		Clear
		if(e == 1){
			printf("\t\t此回合玩家胜利\n");
			printf("\t\t      按Enter继续\n\t\t\t  ");
			while (input() != 0x0A)
			my.v++;
			my.x=my.x2;
			npc.x=npc.x2;
			if(i == count) break;             //到达局数
			Clear
			printf("\t      请选择要提升的属性\n\t\t  血量————1\n\t\t 攻击力————2\n\t\t      ");
			srand(time(NULL));
			if(input() == 0x31){
				my.x2 = my.x = my.x + rand()%(100 - 30) + 30;
				npc.x2 = npc.x = npc.x + rand()%(40 - 30) + 30;
			}
			else{
				my.g = my.g + rand()%(20 - 10) + 10;
				npc.g = npc.g + rand()%(9 - 1) + 1;
			}
		}
		else if(e == 2){
			printf("\t\t此回合NPC胜利\n");
			printf("\t\t      按Enter继续\n\t\t\t  ");
			while (input() != 0x0A)
			npc.v++;
			my.x = my.x2;
			npc.x = npc.x2;
			if(i == count) break;
			my.x = my.x+rand()%(40-10)+10;
			my.x2 = my.x;
			npc.x = npc.x+rand()%(60-40)+40;
			npc.x2 = npc.x;
		}
		Clear
	}
	Clear
	save(count);
	return;
}

void data(){
	int a,b;

	a = size();

	if (a != 0) {
		printf("\t\t\t\t游戏记录\n");
		system("cat ./save.txt");
		puts("\t\t\t\t 按Enter退出：");
		while (b != 0) if (kbhit()) b = 0;
	}
	else if(a == 0) {
		printf("\t\t\t\t什么都没有呢！\n");
		puts("\t\t\t\t 按Enter返回：");
		while (b != 0) if (kbhit()) b = 0;
		return;
	}
	Clear
	return;
}

void help(){
	Clear
	printf("\t\t\t 帮助\n");
	printf("\t1、在主界面时选择项目对应的数字即可。\n");
	printf("\t2、注意，游戏进行的全程只能输入整数，不可输入小数、字符串。\n");
	printf("\t3、如果有bug，请上报，我知道了会改的。\n");
	printf("\t4、不要在Windows下运行此程序。\n\n\n");
	printf("\t\t     按Enter退出\n\t\t\t  ");
	input();
	Clear
	return;
}

void save(int count) {
	FILE * fp;

	if (access("./save.txt",0) == EOF) {
		fp = fopen("./save.txt","w");             //创建save.txt文件，存储游戏数据。如果有需要可以自行修改
		if (!fp) {
			perror("fopen");
			input();
		}
		fclose(fp);
	}
	fp = fopen("./save.txt","a");
	if(!fp) {
		perror("\033[1;31mfopen\033[0m");
		return;
	}
	if(my.v==npc.v){
		fprintf(fp,"局数：%-3d玩家赢：%-3dNPC赢：%-3d平局\n",count,my.v,npc.v);
		printf("\t\t      按Enter继续\n\t\t\t  ");
	}
	else if(my.v<npc.v){
		fprintf(fp,"局数：%-3d玩家赢：%-3dNPC赢：%-3dNPC赢\n",count,my.v,npc.v);
		printf("\t\t      按Enter继续\n\t\t\t  ");
	}
	else if(my.v>npc.v){
		fprintf(fp,"局数：%-3d玩家赢：%-3dNPC赢：%-3d玩家赢\n",count,my.v,npc.v);
		printf("\t\t      按Enter继续\n\t\t\t  ");
	}
	fclose(fp);

	return;
}

float size(){
	float fsize;	
	struct stat statbuf;
	stat("./save.txt",&statbuf);
	fsize=statbuf.st_size;	
	return fsize;
}

