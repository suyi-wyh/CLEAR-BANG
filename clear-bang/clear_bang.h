#pragma once

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define ROW 9                      //��
#define COLUMN  9                      //��
#define MAX_ROW ROW+2                //����
#define MAX_COLUMN COLUMN+2             //����
#define BANG_NUMBER 10              // ����
#define TRUE 1                        //  ��ȷ
#define FALSE 0                            //���� 

static int map[MAX_ROW][MAX_COLUMN];             //  �����׵ĵ�ͼ
static char show_map[MAX_ROW][MAX_COLUMN];         //��ӡ�ĵ�ͼ


void ShowMenu();  // ��ӡ�˵�
void InitMap(); //��ͼ��ʼ��
void Show_BangMap();  //��ӡ��ͼ
void OpenMap(int x, int y);  // չ���ж�
int  GetBangNum(int x, int y); //�ж�����
int  IsFull();  //�ж���Ϸ����
void Playing();   //��Ϸ����

void CheckFirst(); //����״�ѡ��ʱѡ��Ĳ�����