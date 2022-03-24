#define _CRT_SECURE_NO_WARNINGS
#include <easyx.h>
#include <conio.h>
#include <stdio.h>

//保存图形数据的顺序表，目的是方便调用图形参数
typedef struct {			
	int *x;
	int *y;
	int *width;
	int *height;
}GraphSqList;

//构造一个图形顺序表
void initGraphSqList(GraphSqList* L)		
{
	L->x = (int*)malloc(sizeof(int));
	L->y = (int*)malloc(sizeof(int));
	L->width = (int*)malloc(sizeof(int));
	L->height = (int*)malloc(sizeof(int));
	if (!L->x && L->y && L->width && L->height) exit(1);
}

//输入一个图形的数据进顺序表（表指针，图形编号，宽度，高度，x坐标，y坐标）
void insertGraphSqList(GraphSqList* L,int i, int width, int height, int x, int y)	
{
	L->x[i] = x;
	L->y[i] = y;
	L->width[i] = width;
	L->height[i] = height;
}

void Menu_UI()
{
	/*创建一个属于菜单图形的顺序表*/
	GraphSqList* ui;
	ui = (GraphSqList*)malloc(sizeof(GraphSqList));

	/*创建一个960 * 720窗口并设置背景为白色*/
	initgraph(960, 720,EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	/*将窗口数据录入顺序表，标号为0*/
	initGraphSqList(ui);
	insertGraphSqList(ui, 0, 960, 720, 0, 0);
	
	/*title设置*/
	//构造矩形，标号为1
	setfillcolor(GREEN);
	insertGraphSqList(ui, 1, 200, 30, (ui->width[0] - 200) / 2, 30);	
	solidrectangle(ui->x[1], ui->y[1], ui->x[1] + ui->width[1], ui->y[1] + ui->height[1]);
	//创建标题文本
	settextcolor(RGB(173, 0, 74));
	settextstyle(16, 0, "楷体");
	setbkmode(TRANSPARENT);
	char title[] = "玉溪师范学院校园导游";
	
	outtextxy(ui->x[1] + ((ui->width[1] - textwidth(title)) / 2), ui->y[1] + ((ui->height[1] - textheight(title)) / 2), title);
}

int main()
{
	Menu_UI();

	_getch();
	closegraph();
	return 0;
}