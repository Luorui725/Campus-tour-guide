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
	fillroundrect(x, y, x + w, y + h, 10, 10);
	LOGFONT f;
	gettextstyle(&f);
	f.lfWeight = 800;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

void Menu_UI()
{
	/*����һ�����ڲ˵�ͼ�ε�˳���*/
	GraphSqList* ui = NULL;
	ui = (GraphSqList*)malloc(sizeof(GraphSqList));

	/*����һ��1280 * 720���ڲ����ñ���Ϊ��ɫ*/
	initgraph(1280, 720, EW_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();

	/*��������ͼƬ*/
	IMAGE bk;
	loadimage(&bk, "./bk.jpg", 1280, 720);
	putimage(0, 0, &bk);

	/*����������¼��˳������Ϊ0*/
	initGraphSqList(ui);
	insertGraphSqList(ui, 0, 1280, 720, 0, 0);

	/*title����*/
	//������⣬���Ϊ1
	setfillcolor(GREEN);
	insertGraphSqList(ui, 1, 500, 60, (ui->width[0] - 500) / 2, 10);
	solidroundrect(ui->x[1], ui->y[1], ui->x[1] + ui->width[1], ui->y[1] + ui->height[1], 10, 10);
	
	//���������ı�
	settextcolor(RGB(0, 0, 0));
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 40;
	f.lfWeight = 1000;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	char title[] = "��Ϫʦ��ѧԺУ԰����";
	outtextxy(ui->x[1] + ((ui->width[1] - textwidth(title)) / 2), ui->y[1] + ((ui->height[1] - textheight(title)) / 2), title);
	

	/*����ģ��һ �������ͼ��*/
	//���찴ť1�����Ϊ2
	insertGraphSqList(ui, 2, 200, 50, ui->x[1] + (ui->width[1] - 200) / 2, 100);
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