#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char path[] = "input.txt";//�����ļ���·��
int row;//�����ߵ�����
int n;//ͼ�ĸ���
int m = 1;//��ɫ����С����;
int main()
{
	//��������
	int** readFile(int row, char path[]);

	int** data;
	int* np;
	int i, j, k;

	printf("������ͼ�ĸ����������ߵ�����\n");
	scanf_s("%d %d", &n, &row);

	//����һ������Ϊn�����飬������ֵΪ1��
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

	fp = fopen(path, "r");//���ļ�

	//��ȡ����
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < 2; j++)
		{
			fscanf(fp, "%d", &rp[i][j]);
		}
	}

	fclose(fp);//�ر��ļ�
	return rp;//����ֵ
}