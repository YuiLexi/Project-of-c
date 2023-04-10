#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"Extension.h"

/// <summary>
/// ��ȡ�ļ��еľ�������
/// </summary>
/// <param name="path">�ļ�·��</param>
/// <param name="rowNum">����</param>
/// <param name="listNum">����</param>
/// <returns>����ָ��</returns>
double** ReadMatrix(char path[], int rowNum, int listNum)
{
	FILE* fp;
	double** datap;
	int a, b, c;

	//�����ڴ棬��ž�������
	datap = (double**)malloc(rowNum * sizeof(double*));
	for (a = 0; a < listNum; a++)
	{
		datap[a] = (double*)malloc(listNum * sizeof(double));
	}
	//���ļ�������ȡ���ݺ󣬹ر��ļ�
	fp = fopen(path, "r");
	for (a = 0; a < rowNum; a++)
	{
		for (b = 0; b < listNum; b++)
		{
			fscanf(fp, "%lf", &datap[a][b]);//����д��
			//fscanf(fp, "%lf", (*(datap + a) + b));
		}
	}
	fclose(fp);
	return datap;
}

/// <summary>
/// ������ļ�д���������
/// </summary>
/// <param name="path">����ļ�·��</param>
/// <param name="datap">����Դ</param>
/// <param name="rowNum">�������</param>
/// <param name="listNum">�������</param>
void WriteMatrix(char path[], double** datap, int rowNum, int listNum)
{
	FILE* fp;
	int a, b;
	fp = fopen(path, "w");

	//������ļ���д������
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