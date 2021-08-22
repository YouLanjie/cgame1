#include "../include/head.h"                                //引入头文件
#include <signal.h>

struct data my={500,500,0,0,0},npc={500,500,0,0,0};         //分别定义存放玩家和NPC数据的结构体函数

int main() {
	/*隐藏光标*/
	printf("\033[?25l");
	signal(SIGINT,stop);
	srand(time(NULL));                                //随机数
	my.str = npc.str = rand()%(60-29)+30;             //随机初始攻击力

	while(1) {                                        //主菜单
		welcome(1);                               //打印主菜单
		switch (Input()) {
			case 0x30:
				Clear
				/*显示光标*/
				printf("\033[?25h");
				KbhitNoTime();
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
					perror("\033[1;31m[main]mremove\033[0m");
					Input();
				}
				break;
		}
		Clear
	}                                                 //如果都不正确，重新开始
	printf("\033[?25h");
	KbhitNoTime();
	return 0;                                         //结束main函数，退出程序
}

void welcome(int m) {                                          //打印开始界面
	Clear
	printf("\033[1;33m\033[8;11H1.开始游戏\033[8;37H2.游戏记录\033[9;11H3.游戏帮助\033[9;37H0.退出游戏\033[0m\n");
	Menu("welcome",m,1);
}

void game() {                                             //游戏函数
	int count = 0;                                    //局数信息
	int in = 0,d=0,win=0;                     //定义一大堆变量
	unsigned long RandomSeed = 0;
	FILE * fp;
	pid_t pid;

	while (in != 0x0A) {
		Clear
		printf("\033[1;1H你想玩几局？%d\n%d",count,count);
		KbhitNoTime();
		in = Input();
		if (in > 0x2F && in < 0x3A) {
			if (count == 0) {
				if (in == 0x30) {
					if (count == 0) {
						continue;
					}
				}
			}
			count = count * 10 + ( in - 48 );
			KbhitNoTime();
		}
		else if (in == 0x7F) {
			Clear
			printf("\033[1;1H你想玩几局？\n");
			if (count != 0) {
				count /= 10;
			}
			else if (count < 10) {
				count = 0;
			}
			KbhitNoTime();
		}
		else if (in == 0x0A) {
			break;
		}
		else {
			in = 0x00;
		}
	}

	if(count == 0) {
		return;
	}
	else if(count < 0) {
		return;
	}
	else if(count >= 100) {                               //勉强还能忍
		Clear
		printf("这么多局，您确定吗？Y/n\n\t\t\t  ");
		in = Input();
		if(in =='y' || in=='Y') {
			Clear
		}
		else {
			return;
		}
	}
	Clear
	srand(time(NULL));
	RandomSeed = rand()%10001;
	fp = fopen("./temp.txt","w");
	if (fp == NULL) {
		perror("\033[1;31m[init]fopen\033[0m");
		Input();
		return;
	}
	fclose(fp);
	pid = fork();
	if (pid == EOF) {
		perror("\033[1;31mfork\033[0m");
		Input();
		return;
	}
	while (pid == 0) {
		srand(RandomSeed);
		RandomSeed += rand()%(10000 - 99) + 100;
		fp = fopen("./temp.txt","w");
		if (fp == NULL) {
			perror("\033[1;31m[write]fopen\033[0m");
			Input();
			exit(1);
		}
		fprintf(fp, "%ld", RandomSeed);
		fclose(fp);
		system("sleep 0.001");
		printf("\033[1;60H      \033[1;60H%ld\033[1;1H",RandomSeed);
		KbhitNoTime();
	}
	for(int i = 1; i <= count; i++) {
		while(1) {
			Print
			in = Input();
			printf("\033[32m");
			fp = fopen("./temp.txt", "r");
			if (fp == NULL) {
				perror("\033[1;31m[read]fopen\033[0m");
				Input();
				kill(pid, 1);
				return;
			}
			fscanf(fp,"%ld",&RandomSeed);
			fclose(fp);
			srand(RandomSeed);     /*随机数*/
			printf("\033[2;60H      \033[2;60H%ld",RandomSeed);

			if(in == 0x30) {
				Clear
				printf("\033[1;1H您确定要退出吗？您的记录将不会保存！\n");
				in = Input();
				if(in =='y' || in =='Y') {
					my.str=my.back_str;
					npc.str=npc.back_str;
					remove("./temp.txt");
					kill(pid, 1);
					return;
				}
				Clear
			}
			else if(in == 0x31) {
				Clear
				d = rand()%(10-0);

				if(d == 0 || d == 4 || d == 5 || d == 6) {      //击中
					Clear
					npc.hp -= my.str;
					if(npc.hp <= 0) {
						npc.hp = 0;
						win = 1;
					}
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("\t    你精准的刺中了NPC,NPC血量减少%d\n",my.str);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					Input();
				}
				else if(d == 1) {                        //扑空
					Clear
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("\t    但是，你扑了个空，未能伤害到NPC。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					Input();
				}

				else if(d == 2 || d == 3) {                //反击
					Clear
					my.hp -= npc.str;
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("\t    你反而被NPC击中。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					Input();
					if(my.hp <= 0){
						my.hp = 0;
						win = 2;
						break;
					}
				}

				else if(d == 7 || d == 8 || d == 9 || d == 10){    //被反击加防御
					Clear
					my.hp -= (npc.str - rand()%(5 - 0) +1);
					if(my.hp <= 0){
						my.hp = 0;
						win = 2;
					}
					Print
					printf("\033[10;10H你率先发动攻击，\n");
					printf("    你手慢了一点，被NPC击中，因为你防御着，你的血量减少%d。\n",npc.str - rand()%(5 - 0) +1);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					Input();
				}
			}
			else {
				d = rand()%(20 - 0);
				if(d == 0){                       //反击敌人
					Clear
					npc.hp -= 15;
					if(npc.hp <= 0) {
						npc.hp = 0;
						win = 1;
					}
					Print
					printf("\033[10;10H你选择了防御。\n");
					printf("      在你防御的时候顺便击中了NPC，使NPC的血量减少15。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					Input();
				}
				else if(d == 20){                  //被打中
					Clear
					my.hp -= npc.str;
					if(my.hp <= 0){
						my.hp = 0;
						win = 2;
					}
					Print
					printf("\033[10;10H你选择了防御。\n");
					printf("     你没有防御好，导致敌人打中了你，你的血量减少%d。\n",npc.str);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					Input();
				}
				else{                          //只有防御
					Clear
					Print
					printf("\033[10;10H你选择了防御。\n");
					printf("\t  你防住了敌人的攻击，但是这已经很勉强了。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					Input();
				}
			}
			printf("\033[0m\n");
			if (win != 0) {
				break;
			}
			Clear
		}
		Clear
		if(win == 1){
			printf("\t\t此回合玩家胜利\n");
			printf("\t\t      按Enter继续\n\t\t\t  ");
			while (Input() != 0x0A) {}                      //使用循环卡住程序
			my.V++;
			my.hp = my.back_hp;
			npc.hp=npc.back_hp;
			if(i == count) break;             //到达局数
			Clear
			printf("\t      请选择要提升的属性\n\t\t  血量————1\n\t\t 攻击力————2\n\t\t      ");
			srand(time(NULL));
			if(Input() == 0x31){
				my.back_hp = my.hp += rand()%(150 - 40) + 40;
				npc.back_hp = npc.hp += rand()%(40 - 20) + 20;
			}
			else{
				my.str = my.str + rand()%(30 - 10) + 20;
				npc.str = npc.str + rand()%(9 - 1) + 1;
			}
		}
		else if(win == 2){
			printf("\t\t此回合NPC胜利\n");
			printf("\t\t      按Enter继续\n\t\t\t  ");
			while (Input() != 0x0A) {}                     //使用循环卡住程序
			npc.V++;
			my.hp = my.back_hp;
			npc.hp = npc.back_hp;
			if(i == count) break;
			my.back_hp = my.hp += rand()%(40-10)+10;
			npc.back_hp = npc.hp += rand()%(60-40)+40;
		}
		win = 0;
		Clear
	}
	remove("./temp.txt");
	kill(pid, 1);
	Clear
	save(count);
	return;
}

void data(){
	FILE *fp;
	char a[200][200];
	int count = 0,count2 = 1;

	if (access("./save.txt", 0) == EOF) {
		fp = fopen("./save.txt", "w");
		if (!fp) {
			perror("\033[1;31m[data]fopen\033[0m");
			Input();
			return;
		}
		fclose(fp);
	}
	fp = fopen("./save.txt", "r");
	if (!fp) {
		perror("\033[1;31m[data]fopen\033[0m");
		Input();
		return;
	}
	if (fgets(a[0], sizeof(a), fp) != NULL) {
		do {
			count++;
		}while (fgets(a[count], sizeof(a), fp) != NULL);
	}
	else {
		printf("\033[8;23H\033[1;32m什么都没有呢！\033[0m\n");
	}
	while (1) {
		Menu2("游戏记录");
		printf("\033[5;1H\n");
		while (count2%5 != 0 && count2 < count) {
			printf("\033[1;33m\033[11C%s\033[0m",a[count2 - 1]);
			KbhitNoTime();
			count2++;
		}
		if (count2 < count) {
			count2++;
		}
		printf("\033[15;1H%d",count2);
		if (Input() == 0x1B) {
			getchar();
		}
		else {
			Clear
			return;
		}
		switch (getchar()) {
			case 0x41:
			case 0x44:
				if (count2 - 5 > 0) {
					count2 -= 5;
				}
				else {
					count2 = 1;
				}
				break;
			case 0x42:
			case 0x43:
				break;
			default:
				Clear
				return;
				break;
		}
		printf("\033[15;1H%d",count2);
		Clear
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
	Input();
	Clear
	return;
}

void save(int count) {
	FILE * fp;

	if (access("./save.txt",0) == EOF) {
		fp = fopen("./save.txt","w");             //创建save.txt文件，存储游戏数据。如果有需要可以自行修改
		if (!fp) {
			perror("\033[1;31m[save]fopen\033[0m");
			Input();
		}
		fclose(fp);
	}
	fp = fopen("./save.txt","a");
	Clear
	if(!fp) {
		perror("\033[1;31mfopen\033[0m");
		return;
	}
	if(my.V == npc.V){
		printf("局数：%-3d玩家赢：%-3dNPC赢：%-3d平局\n",count,my.V,npc.V);
		fprintf(fp,"局数：%-3d玩家赢：%-3dNPC赢：%-3d平局\n",count,my.V,npc.V);
		printf("\t\t      按Enter继续\n\t\t\t  ");
	}
	else if(my.V < npc.V){
		printf("局数：%-3d玩家赢：%-3dNPC赢：%-3dNPC赢\n",count,my.V,npc.V);
		fprintf(fp,"局数：%-3d玩家赢：%-3dNPC赢：%-3dNPC赢\n",count,my.V,npc.V);
		printf("\t\t      按Enter继续\n\t\t\t  ");
	}
	else if(my.V > npc.V){
		printf("局数：%-3d玩家赢：%-3dNPC赢：%-3d玩家赢\n",count,my.V,npc.V);
		fprintf(fp,"局数：%-3d玩家赢：%-3dNPC赢：%-3d玩家赢\n",count,my.V,npc.V);
		printf("\t\t      按Enter继续\n\t\t\t  ");
	}
	fclose(fp);
	Input();
	Clear
	return;
}

void stop() {
	Clear
	printf("\033[?25h退出\n");
	exit(0);
}
