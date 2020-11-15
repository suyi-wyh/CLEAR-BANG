#pragma once

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define ROW 9                      //行
#define COLUMN  9                      //列
#define MAX_ROW ROW+2                //大行
#define MAX_COLUMN COLUMN+2             //大列
#define BANG_NUMBER 10              // 雷数
#define TRUE 1                        //  正确
#define FALSE 0                            //错误 

static int map[MAX_ROW][MAX_COLUMN];             //  储存雷的地图
static char show_map[MAX_ROW][MAX_COLUMN];         //打印的地图


void ShowMenu();  // 打印菜单
void InitMap(); //地图初始化
void Show_BangMap();  //打印地图
void OpenMap(int x, int y);  // 展开判断
int  GetBangNum(int x, int y); //判断雷数
int  IsFull();  //判断游戏结束
void Playing();   //游戏过程

void CheckFirst(); //检查首次选择时选择的不是雷