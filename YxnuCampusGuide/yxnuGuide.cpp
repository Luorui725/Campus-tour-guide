#define _CRT_SECURE_NO_WARNINGS
#include <easyx.h>
#include <conio.h>
#include <stdio.h>

//����ͼ�����ݵ�˳���Ŀ���Ƿ������ͼ�β���
typedef struct {
	int* x;
	int* y;
	int* width;
	int* height;
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
void insertGraphSqList(GraphSqList* L, int i, int width, int height, int x, int y)
{
	L->x[i] = x;
	L->y[i] = y;
	L->width[i] = width;
	L->height[i] = height;
}

//����һ����ť
void UI_button(int x, int y, int w, int h, const char* text)
{
	setfillcolor(GREEN);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	setbkmode(TRANSPARENT);
	settextstyle(16, 0, "����");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void Menu_UI()
{
	/*����һ�����ڲ˵�ͼ�ε�˳���*/
	GraphSqList* ui;
	ui = (GraphSqList*)malloc(sizeof(GraphSqList));

	/*����һ��960 * 720���ڲ����ñ���Ϊ��ɫ*/
	initgraph(960, 720, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	/*����������¼��˳������Ϊ0*/
	initGraphSqList(ui);
	insertGraphSqList(ui, 0, 960, 720, 0, 0);

	/*title����*/
	//������⣬���Ϊ1
	setfillcolor(GREEN);
	insertGraphSqList(ui, 1, 200, 30, (ui->width[0] - 200) / 2, 30);
	solidrectangle(ui->x[1], ui->y[1], ui->x[1] + ui->width[1], ui->y[1] + ui->height[1]);
	//���������ı�
	settextcolor(RGB(173, 0, 74));
	settextstyle(16, 0, "����");
	setbkmode(TRANSPARENT);
	char title[] = "��Ϫʦ��ѧԺУ԰����";
	outtextxy(ui->x[1] + ((ui->width[1] - textwidth(title)) / 2), ui->y[1] + ((ui->height[1] - textheight(title)) / 2), title);

	/*����ģ��һ �������ͼ��*/
	//���찴ť1�����Ϊ2
	//setfillcolor(GREEN);
	insertGraphSqList(ui, 2, 200, 30, ui->x[1], 130);
	UI_button(ui->x[2], ui->y[2], ui->width[2], ui->height[2], "�����ͼ");

	ExMessage msg;
	if (peekmessage(&msg, EM_MOUSE)) {
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			outtextxy(400, 400, "����������");
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