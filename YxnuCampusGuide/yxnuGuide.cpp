#define _CRT_SECURE_NO_WARNINGS
#include <easyx.h>
#include <conio.h>
#include <stdio.h>

//����ͼ�����ݵ�˳���Ŀ���Ƿ������ͼ�β���
typedef struct {			
	int *x;
	int *y;
	int *width;
	int *height;
}GraphSqList;

//����һ��ͼ��˳���
void initGraphSqList(GraphSqList* L)		
{
	L->x = (int*)malloc(sizeof(int));
	L->y = (int*)malloc(sizeof(int));
	L->width = (int*)malloc(sizeof(int));
	L->height = (int*)malloc(sizeof(int));
	if (!L->x && L->y && L->width && L->height) exit(1);
}

//����һ��ͼ�ε����ݽ�˳�����ָ�룬ͼ�α�ţ���ȣ��߶ȣ�x���꣬y���꣩
void insertGraphSqList(GraphSqList* L,int i, int width, int height, int x, int y)	
{
	L->x[i] = x;
	L->y[i] = y;
	L->width[i] = width;
	L->height[i] = height;
}

void Menu_UI()
{
	/*����һ�����ڲ˵�ͼ�ε�˳���*/
	GraphSqList* ui;
	ui = (GraphSqList*)malloc(sizeof(GraphSqList));

	/*����һ��960 * 720���ڲ����ñ���Ϊ��ɫ*/
	initgraph(960, 720,EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	/*����������¼��˳������Ϊ0*/
	initGraphSqList(ui);
	insertGraphSqList(ui, 0, 960, 720, 0, 0);
	
	/*title����*/
	//������Σ����Ϊ1
	setfillcolor(GREEN);
	insertGraphSqList(ui, 1, 200, 30, (ui->width[0] - 200) / 2, 30);	
	solidrectangle(ui->x[1], ui->y[1], ui->x[1] + ui->width[1], ui->y[1] + ui->height[1]);
	//���������ı�
	settextcolor(RGB(173, 0, 74));
	settextstyle(16, 0, "����");
	setbkmode(TRANSPARENT);
	char title[] = "��Ϫʦ��ѧԺУ԰����";
	
	outtextxy(ui->x[1] + ((ui->width[1] - textwidth(title)) / 2), ui->y[1] + ((ui->height[1] - textheight(title)) / 2), title);
}

int main()
{
	Menu_UI();

	_getch();
	closegraph();
	return 0;
}