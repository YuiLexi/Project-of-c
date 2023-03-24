#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char path[] = "input.txt";//输入文件的路径
int row;//连接线的线数
int n;//图的个数
int m = 1;//颜色的最小个数;
int main()
{
	//声明函数
	int** readFile(int row, char path[]);

	int** data;
	int* np;
	int i, j, k;

	printf("请输入图的个数和连接线的线数\n");
	scanf_s("%d %d", &n, &row);

	//创建一个长度为n的数组，并赋初值为1；
	np = (int*)malloc(n * sizeof(int));

	data = readFile(row, path);

	for (i = 0; i < n; i++)
	{
		np[i] = 1;
	}

	for (i = 0; i < row; i++)
	{
		for (j = 1; j < n; j++)
		{
			for (k = j + 1; k < n + 1; k++)
			{
				if (data[i][0] == j && data[i][1] == k)
				{
					if (np[j - 1] == np[k - 1])
						np[k - 1]++;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (m <= np[i])
			m = np[i];
	}

	printf("%d", m);
}

/// <summary>
/// 读取txt文件数据
/// </summary>
/// <param name="row">行数</param>
/// <param name="path">文件的相对路径</param>
/// <returns>指向数据空间的二重指针</returns>
int** readFile(int row, char path[])
{
	FILE* fp;
	int** rp;
	int i, j;

	//创建一个row*2大小的动态空间
	rp = (int**)malloc(row * sizeof(int*));
	for (i = 0; i < row; i++)
	{
		rp[i] = (int*)malloc(2 * sizeof(int));
	}

	fp = fopen(path, "r");//打开文件

	//读取数据
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < 2; j++)
		{
			fscanf(fp, "%d", &rp[i][j]);
		}
	}

	fclose(fp);//关闭文件
	return rp;//返回值
}