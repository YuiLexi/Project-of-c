#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"Extension.h"

/// <summary>
/// 读取文件中的矩阵数据
/// </summary>
/// <param name="path">文件路径</param>
/// <param name="rowNum">行数</param>
/// <param name="listNum">列数</param>
/// <returns>矩阵指针</returns>
double** ReadMatrix(char path[], int rowNum, int listNum)
{
	FILE* fp;
	double** datap;
	int a, b, c;

	//创建内存，存放矩阵数据
	datap = (double**)malloc(rowNum * sizeof(double*));
	for (a = 0; a < listNum; a++)
	{
		datap[a] = (double*)malloc(listNum * sizeof(double));
	}
	//打开文件，并读取数据后，关闭文件
	fp = fopen(path, "r");
	for (a = 0; a < rowNum; a++)
	{
		for (b = 0; b < listNum; b++)
		{
			fscanf(fp, "%lf", &datap[a][b]);//或者写成
			//fscanf(fp, "%lf", (*(datap + a) + b));
		}
	}
	fclose(fp);
	return datap;
}

/// <summary>
/// 向输出文件写入矩阵数据
/// </summary>
/// <param name="path">输出文件路径</param>
/// <param name="datap">数据源</param>
/// <param name="rowNum">输出行数</param>
/// <param name="listNum">输出列数</param>
void WriteMatrix(char path[], double** datap, int rowNum, int listNum)
{
	FILE* fp;
	int a, b;
	fp = fopen(path, "w");

	//向输出文件中写入数据
	for (a = 0; a < rowNum; a++)
	{
		for (b = 0; b < listNum; b++)
		{
			fprintf(fp, "%lf", datap[a][b]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}