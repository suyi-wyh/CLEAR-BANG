#pragma once

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define BASIC_ROW 5                      //��
#define BASIC_COLUMN 5                        //��
#define MAX_ROW 20               //����
#define MAX_COLUMN 20           //����
#define BANGNUMBER 5              // ��������
#define TRUE 1                        //  ��ȷ
#define FALSE 0                            //���� 

static int map[MAX_ROW][MAX_COLUMN];             //  �����׵ĵ�ͼ
static char show_map[MAX_ROW][MAX_COLUMN];         //��ӡ�ĵ�ͼ
int BANG_NUMBER;
int ROW;
int COLUMN;

void ShowMenu();  // ��ӡ�˵�

void ShowDif();// ��ӡ�ѶȲ˵�
void ChooseDif();//�ѶȾ���
void InitMap(); //��ͼ��ʼ��
void Show_BangMap();  //��ӡ��ͼ
void OpenMap(int x, int y);  // չ���ж�
int  GetBangNum(int x, int y); //�ж�����
int  IsFull();  //�ж���Ϸ����
void Playing();   //��Ϸ����

void CheckFirst(); //����״�ѡ��ʱѡ��Ĳ�����