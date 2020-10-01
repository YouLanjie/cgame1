#include "src/head.h"
int main(){
	char a[5];
	int b=1;
	if(b!=0){
		printf("\t\t程序初始化中……\n");
		system("mkdir file");
		system("touch file/save.txt");
		srand(time(NULL));
		my.g=npc.g=rand()%(450-400)+400;
		my.g=npc.g=rand()%(60-30)+30;
		b=0;
	}
	while(strcmp("0",a)!=0){
		welcome();
		scanf("%s",a);
		getchar();
		cls();
		if(strcmp("0",a)==0) return 0;
		else if(strcmp("1",a)==0) game();
		else if(strcmp("2",a)==0) set();
		else if(strcmp("3",a)==0) help();
		else printf("\t\t\t 错误\n\n");
	}
	cls();
	return 0;
}
void cls(){system("clear");}
void welcome(){
	cls();
	printf("\t\t\twelcome\n\n");
	printf("\t\t1、开始游戏——————————1\n");
	printf("\t\t2、游戏记录——————————2\n");
	printf("\t\t3、游戏帮助——————————3\n");
	printf("\t\t4、退出游戏——————————0\n");
	printf("\t\t       请选择( )\b\b");
}
void game(){
	int m,a,aa,ab,b=0,c,d=2,e=0,f;
	char ma[3]="n";
	my.v=npc.v=0;
	printf("\t\t      你想玩几局？");
	scanf("%d",&m);
	getchar();
	if(m==0) return;
	else if(m>=100){
		cls();
		printf("\t\t 这么多局，您确定吗？Y/n\n\t\t\t  ");
		scanf("%c",ma);
		getchar();
		if(strcmp("n",ma)==0 || strcmp("N",ma)==0) return;
	}
	else if(m<0) return;
	cls();
	printf("\t\t     本次局数：%d局\n\t\t      按Enter继续\n\t\t\t  ",m);
	getchar();
	cls();
	for(a=1;a<=m;a++){
		b=0;
		while(b!=1){
			srand(time(NULL));
			d=2;
			printf("\t\t     本次局数：%d局\n",m);
			printf("\t\t      当前局数：%d\n",a);
			printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
			printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
			printf("\t\t\t请选择：\n\t\t\t攻击——1\n\t\t\t防御——2\n\t\t\t   ");
			scanf("%d",&c);
			getchar();
			printf("\n\n");
			if(c==0){
				cls();
				printf("\t  您确定要退出吗？您的记录将不会保存！\n\t\t\t ");
				scanf("%s",ma);
				if(strcmp("y",ma)==0 || strcmp("Y",ma)==0) return;
				printf("\n");
				cls();
			}
			else if(c==1){
				cls();
				printf("\t\t     本次局数：%d局\n",m);
				printf("\t\t      当前局数：%d\n",a);
				printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
				printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
				printf("\t\t     你率先发动攻击，\n");
				d=rand()%(10-0);
				if(d==0 || d==4 || d==5 || d==6){
					cls();
					npc.x=npc.x-my.g;
					if(npc.x<0) npc.x=0;
					printf("\t\t     本次局数：%d局\n",m);
					printf("\t\t      当前局数：%d\n",a);
					printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
					printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
					printf("\t\t     你率先发动攻击，\n");
					printf("\t    你精准的刺中了NPC,NPC血量减少%d\n",my.g);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
					if(npc.x<=0){
						npc.x=0;
						b=1;
						e=1;
						continue;
					}
				}
				else if(d==1){
					cls();
					printf("\t\t     本次局数：%d局\n",m);
					printf("\t\t      当前局数：%d\n",a);
					printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
					printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
					printf("\t\t     你率先发动攻击，\n");
					printf("\t    但是，你扑了个空，未能伤害到NPC。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
				}
				else if(d==2 || d==3){
					cls();
					my.x=my.x-npc.g;
					if(my.x<0) my.x=0;
					printf("\t\t     本次局数：%d局\n",m);
					printf("\t\t      当前局数：%d\n",a);
					printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
					printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
					printf("\t\t     你率先发动攻击，\n");
					printf("\t    你因为太过于紧张，反而被NPC击中。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
					if(my.x<=0){
						my.x=0;
						b=1;
						e=2;
						continue;
					}
				}
				else if(d==7 || d==8 || d==9 || d==10){
					cls();
					aa=rand()%(5-0)+1;
					ab=npc.g-aa;
					my.x=my.x-ab;
					if(my.x<0) my.x=0;
					printf("\t\t     本次局数：%d局\n",m);
					printf("\t\t      当前局数：%d\n",a);
					printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
					printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
					printf("\t\t     你率先发动攻击，\n");
					printf("    你手慢了一点，被NPC击中，因为你防御着，你的血量减少%d。\n",ab);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
					if(my.x<=0){
						my.x=0;
						b=1;
						e=2;
						continue;
					}
				}
			}
			else{
				cls();
				printf("\t\t     本次局数：%d局\n",m);
				printf("\t\t      当前局数：%d\n",a);
				printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
				printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
				printf("\t\t     你选择了防御。\n");
				d=rand()%(20-0);
				if(d==0){
					cls();
					npc.x=npc.x-15;
					if(npc.x<0) npc.x=0;
					printf("\t\t     本次局数：%d局\n",m);
					printf("\t\t      当前局数：%d\n",a);
					printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
					printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
					printf("\t\t     你选择了防御。\n");
					printf("      在你防御的时候顺便击中了NPC，使NPC的血量减少15。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
					if(npc.x<=0){
						npc.x=0;
						b=1;
						e=1;
						continue;
					}
				}
				else if(d==20){
					cls();
					my.x=my.x-npc.g;
					if(my.x<0) my.x=0;
					printf("\t\t     本次局数：%d局\n",m);
					printf("\t\t      当前局数：%d\n",a);
					printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
					printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
					printf("\t\t     你选择了防御。\n");
					printf("     你没有防御好，导致敌人打中了你，你的血量减少%d。\n",npc.g);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
					if(my.x<=0){
						my.x=0;
						b=1;
						e=2;
						continue;
					}
				}
				else{
					cls();
					printf("\t\t     本次局数：%d局\n",m);
					printf("\t\t      当前局数：%d\n",a);
					printf("\t    玩家血量：%d\t玩家攻击力：%d\n",my.x,my.g);
					printf("\t    NPC 血量：%d\tNPC攻击力：%d\n\n\n\n",npc.x,npc.g);
					printf("\t\t     你选择了防御。\n");
					printf("\t  你防住了敌人的攻击，但是这已经很勉强了。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
				}
			}
			cls();
		}
		cls();
		if(e==1){
			printf("\t\t此回合玩家胜利\n");
			sleep(3);
			if(a==m){
				break;
			}
			my.v++;
			cls();
			printf("\t      请选择要提升的属性\n\t\t  血量————1\n\t\t 攻击力————2\n\t\t      ");
			scanf("%d",&f);
			srand(time(NULL));
			if(f==1){
				my.x=my.x2;
				npc.x=npc.x2;
				my.x=my.x+rand()%(100-30)+30;
				my.x2=my.x;
				npc.x=npc.x+rand()%(40-30)+30;
				npc.x2=npc.x;
			}
			else{
				my.x=my.x2;
				npc.x=npc.x2;
				my.g=my.g+rand()%(20-10)+10;
				npc.g=npc.g+rand()%(9-1)+1;
			}
		}
		else if(e==2){
			printf("\t\t此回合NPC胜利\n");
			sleep(3);
			if(a==m)
			{
				break;
			}
			npc.v++;
			my.x=my.x2;
			npc.x=npc.x;
			my.x=my.x+rand()%(40-10)+10;
			my.x2=my.x;
			npc.x=npc.x+rand()%(60-40)+40;
			npc.x2=npc.x;
		}
		cls();
	}
	FILE *fp=fopen("file/save.txt","a");
	if(!fp) return;
	if(my.v==npc.v){
		printf("\t\t\t平局\n");
		fprintf(fp,"\t 局数：%d  玩家赢：%d  NPC赢：%d  平局\n",m,my.v,npc.v);
		sleep(3);
	}
	else if(my.v<npc.v){
		printf("\t\t      NPC胜利\n");
		fprintf(fp,"\t 局数：%d  玩家赢：%d  NPC赢：%d  NPC赢\n",m,my.v,npc.v);
		sleep(3);
	}
	else if(my.v>npc.v){
		printf("\t\t      玩家胜利\n");
		fprintf(fp,"\t 局数：%d  玩家赢：%d  NPC赢：%d  玩家赢\n",m,my.v,npc.v);
		sleep(3);
	}
	fclose(fp);
	cls();
	return;
}
void set(){
	char a[70];
	int b=size()/70+1,i;
	cls();
	FILE *fp=fopen("file/save.txt","rb");
	if(!fp) return;
	printf("\t\t       游戏记录\n");
	for(i=0;i!=b;i++){
		fgets(a,70,fp);
		printf("%s",a);
	}
	fclose(fp);
	printf("\t\t      按Enter退出\n\t\t\t  ");
	getchar();
	cls();
	return;
}
void help(){
	cls();
	printf("\t\t\t 帮助\n");
	printf("\t1、在主界面时选择项目对应的数字即可。\n");
	printf("\t2、注意，游戏进行的全程只能输入整数，不可输入小数、字符串。\n");
	printf("\t3、如果有bug，请上报，我知道了会改的。\n");
	printf("\t4、不要在Windows下运行此程序。\n\n\n");
	printf("\t\t     按Enter退出\n\t\t\t  ");
	getchar();
	cls();
	return;
}
float size(){
	float fsize;	
	struct stat statbuf;
	stat("file/save.txt",&statbuf);
	fsize=statbuf.st_size;	
	return fsize;
}
