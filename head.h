#include <stdio.h>                           //标准库
#include <string.h>                          //strcmp();
#include <stdlib.h>                          //system();srand();rand();
#include <unistd.h>                          //sleep();
#include <time.h>                            //time(NULL);

void cls();
void welcome();
void game();
void set();
void help();

float size();

int my,my_g,my_v=0,npc,npc_g,npc_v=0;
int bf1,bf2;