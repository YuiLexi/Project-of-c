#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>		//��̬�ڴ���صĿ�
#include<graphics.h>	//��ͼ��صĿ�
#include<math.h>		//��ѧ������صĿ�
#include <windows.h>	//��ʱ����

#define PI acos(-1)		//��ȡԲ���ʵ�ֵ
#define ISTIME 1		//�Ƿ�̬��ͼ��1��ʾ���ж�̬��ͼ��0��ʾ�����ж�̬��ͼ

//�ṹ�壬���ڴ洢��ǰ �ڵ���������
typedef struct LinkDot
{
	int id;					//��ǰ���ʵĽڵ�ı��
	int linkId;				//��֮�����Ľڵ�ı��
	struct LinkDot* nextp;	//��һ���ߣ�Ҳ������һ��linkDot�ĵ�ַ
}LinkDot;

int main()
{
	LinkDot* init(int n, int k);
	//void print(LinkDot * ldp);
	void draw(LinkDot * p, double* dp);
	double* angles(int N);

	int N, K;			//��ȡ��ǰ�Ľڵ��� N ���Լ� K ��ֵ
	LinkDot* fp;		//��ȡ����ı�ͷ��ַ
	double* dp;			//�ȼ���ǵ�����ָ��

	//���ô�������
	initgraph(1200, 800);		//���ڴ�С1200X800
	setbkcolor(WHITE);			//���ñ�����ɫ
	setlinecolor(BLUE);			//�������������ɫ
	cleardevice();				//�����Ļ����
	setorigin(600, 400);		//�趨����ԭ��
	line(-600, 0, 600, 0);		//����X��
	line(0, -400, 0, 400);		//����Y��

	printf("������N��K��ż������ֵ��\n");
	scanf("%d %d", &N, &K);

	dp = angles(N);
	fp = init(N, K);
	draw((*fp).nextp, dp);

	system("pause");
	return 0;
}

/// <summary>
/// �����ڵ�������������������,����ĵ�һ��Ԫ�ش������
/// </summary>
/// <param name="n">�ڵ���N</param>
/// <param name="k">�ھӸ���K</param>
/// <returns>ͷ�ڵ�ָ��</returns>
LinkDot* init(int n, int k)
{
	LinkDot* ldfp = NULL;//����ı�ͷָ��
	LinkDot* tmp = NULL;//�м����
	int a, b, c;

	//������һ���ڵ㣬�����Ȱѽڵ����һ��ָ���ʼ��ΪNULL
	ldfp = (LinkDot*)malloc(sizeof(LinkDot));
	(*ldfp).id = -1;
	(*ldfp).nextp = NULL;

	//�����㷨��ͨ����̬�������������нڵ������������浽������
	tmp = ldfp;
	for (a = 0; a < n; a++)
	{
		for (b = 0; b < (k / 2); b++)
		{
			(*tmp).nextp = (LinkDot*)malloc(sizeof(LinkDot));
			tmp = (*tmp).nextp;
			(*tmp).id = a;
			if (a + b + 1 >= n)
			{
				(*tmp).linkId = a + b + 1 - n;
			}
			else
			{
				(*tmp).linkId = a + b + 1;
			}
			(*tmp).nextp = NULL;			//ÿ�ν��´�����ָ���ʼ��ΪNULL����һ���ܺõ�ϰ��
		}
	}
	return ldfp;
}

/// <summary>
/// ������Ӧ������ͼ��
/// </summary>
/// <param name="p">�ڵ��������������</param>
/// <param name="dp">�ȼ���ǵ�����</param>
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
/// �� 0-2�� �ȼ�������� N ���Ƕ�
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
/// ������ͣ�����������Ƿ���ö�̬��ʾ
/// </summary>
/// <param name="b"></param>
void issleep(char b)
{
	if (b)
		Sleep(100);
}