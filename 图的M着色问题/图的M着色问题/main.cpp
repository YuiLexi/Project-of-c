#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>

char path[] = "Input.txt";

int main()
{
	int row;//�����ߵ�����
	int n;//ͼ�ĸ���
	int m = 0;//��ɫ�ĸ���(����Ϊ1);

	int** readFile(int row, char path[]);

	int** data;
	int* np;
	int a;

	printf("������ͼ�ĸ����������ߵ�����\n");
	scanf_s("%d %d", &n, &row);

	//����һ������Ϊn�����飬������ֵΪ1��
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

	//�����ɫ��m
	printf("%d", m);
}

/// <summary>
/// ��ȡtxt�ļ�����
/// </summary>
/// <param name="row">����</param>
/// <param name="path">�ļ������·��</param>
/// <returns>ָ�����ݿռ�Ķ���ָ��</returns>
int** readFile(int row, char path[])
{
	FILE* fp;
	int** rp;
	int i, j;

	//����һ��row*2��С�Ķ�̬�ռ�
	rp = (int**)malloc(row * sizeof(int*));
	for (i = 0; i < row; i++)
	{
		rp[i] = (int*)malloc(2 * sizeof(int));
	}

	//���ļ�����ȡ���ݣ����ر��ļ�
	fp = fopen(path, "r");//���ļ�
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < 2; j++)
		{
			fscanf(fp, "%d", &rp[i][j]);
		}
	}
	fclose(fp);

	return rp;//����ֵ
}