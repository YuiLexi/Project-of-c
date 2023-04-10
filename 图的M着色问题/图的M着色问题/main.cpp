#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

char path[] = "Input.txt";

int main()
{
	int row;//连接线的线数
	int n;//图的个数
	int m = 0;//颜色的个数(最先为1);

	int** readFile(int row, char path[]);

	int** data;
	int* np;
	int a;

	printf("请输入图的个数和连接线的线数\n");
	scanf_s("%d %d", &n, &row);

	//创建一个长度为n的数组，并赋初值为1；
	np = (int*)malloc(n * sizeof(int));
	data = readFile(row, path);
	for (a = 0; a < n; a++)
	{
		np[a] = 1;
	}

	for (a = 0; a < row; a++)
	{
		if (np[data[a][0]] == np[data[a][1]])
		{
			if (data[a][0] < data[a][1])
			{
				np[data[a][1]] += 1;
			}
			if (data[a][0] > data[a][1])
			{
				np[data[a][0]] += 1;
			}
		}
	}
	for (a = 0; a < n; a++)
	{
		if (m < np[a])
			a = np[a];
	}

	//输出颜色数m
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

	//打开文件，读取数据，并关闭文件
	fp = fopen(path, "r");//打开文件
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < 2; j++)
		{
			fscanf(fp, "%d", &rp[i][j]);
		}
	}
	fclose(fp);

	return rp;//返回值
}