#include <stdio.h>                           //标准库
#include <string.h>                          //strcmp();
#include <stdlib.h>                          //system();srand();rand();
#include <unistd.h>                          //sleep();
#include <time.h>                            //time(NULL);
#include <sys/stat.h>
struct data{
	int x;
	int x2;
	int g;
	int v;
}my={500,500,0,0},npc={500,500,0,0};
void cls();
void welcome();
void game();
void set();
void help();
float size();
