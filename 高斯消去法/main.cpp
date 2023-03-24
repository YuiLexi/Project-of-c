#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int row, list;
char inputPath[] = "Input.txt";
char outputPath[] = "Output.txt";
char xPath[] = "OutX.txt";

int main()
{
	//����Ҫ���õĺ���
	double** readMatrix(char path[], int row, int list);
	void writeMatrix(char path[], double** a, int row, int list);
	void writeMatrix(char path[], double* a, int num);
	double* gaussian(double** matrix, int row, int list);

	//�ֲ�����
	int i, j, k;
	double** matrix;
	double* xOut;

	//����Ŀ������������
	scanf_s("%d %d", &row, &list);

	//��ȡ��������
	matrix = readMatrix(inputPath, row, list);

	//��˹��ȥ��
	xOut = gaussian(matrix, row, list);

	//���
	writeMatrix(outputPath, matrix, row, list);
	writeMatrix(xPath, xOut, row);
}

/*����һ�� m* n ��С�Ķ�̬�ڴ棬�����ļ��е�ֵ���ȥ*/
double** readMatrix(char path[], int row, int list)
{
	FILE* fp;
	int i, j;
	//������̬�ڴ棬�������
	double** a;//����һ������ָ��
	a = (double**)malloc(row * sizeof(double*));//����m����� double ����ָ��ı������ڴ�ռ�
	for (i = 0; i < list; i++)
	{
		a[i] = (double*)malloc(list * sizeof(double));//����n����� double ���͵ı������ڴ�ռ�
	}

	//ֻ����ʽ���ļ�
	fp = fopen(path, "r");

	//���ж�ȡ����,�������ݴ���ڶ�̬�ڴ���
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < list; j++)
		{
			fscanf(fp, "%lf", &a[i][j]);//���ж�ȡ������ֵ���ݵ� a[i][j] �ĵ�ַ��
		}
	}
	//�ر��ļ�
	fclose(fp);
	return a;
}

/*��������ļ�����������Ľ��д���ļ���*/
void writeMatrix(char path[], double** a, int row, int list)
{
	FILE* fp;
	int i, j;

	//������ļ�������ļ������ݣ����û���ļ��򴴽�һ���ļ�
	fp = fopen(path, "w");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < list; j++)
		{
			fprintf(fp, "%lf    ", a[i][j]);//���ж�ȡ������ֵ���� a[i][j] ��
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}
/*�������x�ļ�����������Ľ��д���ļ���*/
void writeMatrix(char path[], double* xOut, int num)
{
	FILE* fp;
	int i;

	//������ļ�������ļ������ݣ����û���ļ��򴴽�һ���ļ�
	fp = fopen(path, "w");

	for (i = 0; i < num; i++)
	{
		fprintf(fp, "%lf\n", xOut[i]);
	}
	fclose(fp);
}

double* gaussian(double** matrix, int row, int list)
{
	int i, j, k;
	double a, b, sum;
	/*��ȥ����*/
	for (i = 0; i < row - 1; i++)
	{
		for (j = i + 1; j < row; j++)
		{
			a = matrix[j][i];
			b = matrix[i][i];
			for (k = i; k < list; k++)
			{
				matrix[j][k] = matrix[j][k] * b - a * matrix[i][k];//�����ǽ���ʽ������ͨ�ֺ�����
			}
		}
	}
	/*�ش�����*/
	double* x;
	//������̬�ڴ棬�洢x��ֵ
	x = (double*)malloc(row * sizeof(double));
	for (i = row - 1; i >= 0; i--)
	{
		sum = 0;
		if (matrix[i][list - 2] == 0)
		{
			if (matrix[i][list - 1] == 0)
			{
				x[i] = 0;
			}
			else
			{
				printf("�����޽�");
			}
		}
		else
		{
			//j = list - 2;
			for (j = list - 2; j > i; j--)
			{
				sum += x[j] * matrix[i][j];
			}
			x[i] = (matrix[i][list - 1] - sum) / matrix[i][i];
		}
	}
	return x;
}