#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>		//这里使用了里面的一个随机数生成，用来生成随机概率
#include<malloc.h>		//动态内存相关的库
#include<graphics.h>	//画图相关的库
#include<math.h>		//数学运算相关的库
#include <windows.h>	//延时函数

#define PI acos(-1)		//获取圆周率的值
#define ISTIME 1		//是否动态画图。1表示进行动态画图，0表示不进行动态画图

//结构体，用于存储当前 节点的连接情况
typedef struct LinkDot
{
	int id;					//当前访问的节点的标号
	int linkId;				//与之相连的节点的标号
	struct LinkDot* nextp;	//下一条边，也就是下一个linkDot的地址
}LinkDot;

int main()
{
	LinkDot* init(int n, float p);
	//void print(LinkDot * ldp);
	void draw(LinkDot * p, double* dp);
	double* angles(int N);

	int N;				//获取当前的节点数 N
	float P;			//获取当前的生成概率
	LinkDot* fp;		//获取链表的表头地址
	double* dp;			//等间隔角的数组指针

	//设置窗口属性
	initgraph(1200, 800);		//窗口大小1200X800
	setbkcolor(WHITE);			//设置背景颜色
	setlinecolor(BLUE);			//设置坐标轴的颜色
	cleardevice();				//清除屏幕内容
	setorigin(600, 400);		//设定坐标原点
	line(-600, 0, 600, 0);		//绘制X轴
	line(0, -400, 0, 400);		//绘制Y轴

	printf("请输入N和K（偶数）的值：\n");
	scanf("%d %f", &N, &P);

	dp = angles(N);				//在 0-2Π 上等间隔采样出 N 个角度
	fp = init(N, P);			//初始化 “节点连接表”
	draw((*fp).nextp, dp);		//画出对应的图像

	system("pause");			//暂停程序，等待下一步运行
	return 0;
}

/// <summary>
/// 创建节点的连接情况的链表数据,链表的第一个元素存放数据
/// </summary>
/// <param name="n">节点数N</param>
/// <param name="k">邻居个数K</param>
/// <returns>头节点指针</returns>
LinkDot* init(int n, float p)
{
	LinkDot* ldfp = NULL;//链表的表头指针
	LinkDot* tmp = NULL;//中间变量
	int a, b, c;

	//创建第一个节点，而第一个节点储存节点连接情况；并且先把该节点的下一个指针初始化为NULL
	ldfp = (LinkDot*)malloc(sizeof(LinkDot));
	(*ldfp).id = -1;
	(*ldfp).nextp = NULL;

	//遍历算法，通过动态创建链表，将所有节点的连接情况保存到链表中
	tmp = ldfp;
	for (a = 0; a < n - 1; a++)
	{
		for (b = a + 1; b < n; b++)
		{
			//rand() 会随机生成 0-RAND_MAX 之间的整数，因此生成的数除以RAND_MAX就得到0-1之间随机概率；
			//前面的 1.0 是为了自动转换为浮点除法，而不是采用整数除法（取整）。
			if (1.0 * rand() / RAND_MAX < p)
			{
				(*tmp).nextp = (LinkDot*)malloc(sizeof(LinkDot));
				tmp = (*tmp).nextp;
				(*tmp).id = a;
				(*tmp).linkId = b;
				(*tmp).nextp = NULL;	//每次将新创建的指针初始化为NULL，是一个很好的习惯
			}
		}
	}
	return ldfp;
}

/// <summary>
/// 画出对应的网络图像
/// </summary>
/// <param name="p">节点连接情况的链表</param>
/// <param name="dp">等间隔角的数组</param>
void draw(LinkDot* p, double* dp)
{
	void issleep(char b);
	int x1, y1, x2, y2;
	if (p == NULL)
		return;
	setlinecolor(RED);
	if ((*p).id != -1)
	{
		x1 = (int)(300 * cos(dp[(*p).id]));
		y1 = (int)(300 * sin(dp[(*p).id]));
		x2 = (int)(300 * cos(dp[(*p).linkId]));
		y2 = (int)(300 * sin(dp[(*p).linkId]));
		line(x1, y1, x2, y2);
	}
	issleep(ISTIME);
	draw((*p).nextp, dp);
}
/// <summary>
/// 将 0-2Π 等间隔采样出 N 个角度
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
double* angles(int n)
{
	double* dp;
	int a;
	dp = (double*)malloc(n * sizeof(double));
	for (a = 0; a < n; a++)
	{
		dp[a] = a * (2 * PI / n);
	}
	return dp;
}
/// <summary>
/// 程序暂停函数，用于是否采用动态显示
/// </summary>
/// <param name="b"></param>
void issleep(char b)
{
	if (b)
		Sleep(100);
}