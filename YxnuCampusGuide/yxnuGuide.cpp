#define _CRT_SECURE_NO_WARNINGS
#include <easyx.h>
#include <conio.h>
#include <stdio.h>

//保存图形数据的顺序表，目的是方便调用图形参数
typedef struct {
	int* x;
	int* y;
	int* width;
	int* height;
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
void insertGraphSqList(GraphSqList* L, int i, int width, int height, int x, int y)
{
	L->x[i] = x;
	L->y[i] = y;
	L->width[i] = width;
	L->height[i] = height;
}

//创建一个按钮
void UI_button(int x, int y, int w, int h, const char* text)
{
	fillroundrect(x, y, x + w, y + h, 10, 10);
	LOGFONT f;
	gettextstyle(&f);
	f.lfWeight = 800;
	_tcscpy_s(f.lfFaceName, _T("楷体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void Menu_UI()
{
	/*创建一个属于菜单图形的顺序表*/
	GraphSqList* ui = NULL;
	ui = (GraphSqList*)malloc(sizeof(GraphSqList));

	/*创建一个1280 * 720窗口并设置背景为白色*/
	initgraph(1280, 720, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	/*创建背景图片*/
	IMAGE bk;
	loadimage(&bk, "./bk.jpg", 1280, 720);
	putimage(0, 0, &bk);

	/*将窗口数据录入顺序表，标号为0*/
	initGraphSqList(ui);
	insertGraphSqList(ui, 0, 1280, 720, 0, 0);

	/*title设置*/
	//构造标题，标号为1
	setfillcolor(GREEN);
	insertGraphSqList(ui, 1, 500, 60, (ui->width[0] - 500) / 2, 10);
	solidroundrect(ui->x[1], ui->y[1], ui->x[1] + ui->width[1], ui->y[1] + ui->height[1], 10, 10);
	
	//创建标题文本
	settextcolor(RGB(0, 0, 0));
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 40;
	f.lfWeight = 1000;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	char title[] = "玉溪师范学院校园导游";
	outtextxy(ui->x[1] + ((ui->width[1] - textwidth(title)) / 2), ui->y[1] + ((ui->height[1] - textheight(title)) / 2), title);
	

	/*设置模块一 “进入地图”*/
	//构造按钮1，标号为2
	insertGraphSqList(ui, 2, 200, 50, ui->x[1] + (ui->width[1] - 200) / 2, 100);
	UI_button(ui->x[2], ui->y[2], ui->width[2], ui->height[2], "进入地图");

	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE)) {
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			outtextxy(400, 400, "鼠标左键按下");
		}
	}
}

int main()
{
	Menu_UI();

	_getch();
	closegraph();
	return 0;
}