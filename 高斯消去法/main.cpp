#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int row, list;
char inputPath[] = "Input.txt";
char outputPath[] = "Output.txt";
char xPath[] = "OutX.txt";

int main()
{
	//声明要调用的函数
	double** readMatrix(char path[], int row, int list);
	void writeMatrix(char path[], double** a, int row, int list);
	void writeMatrix(char path[], double* a, int num);
	double* gaussian(double** matrix, int row, int list);

	//局部变量
	int i, j, k;
	double** matrix;
	double* xOut;

	//输入目标矩阵的行列数
	scanf_s("%d %d", &row, &list);

	//读取矩阵数据
	matrix = readMatrix(inputPath, row, list);

	//高斯消去法
	xOut = gaussian(matrix, row, list);

	//输出
	writeMatrix(outputPath, matrix, row, list);
	writeMatrix(xPath, xOut, row);
}

/*创建一个 m* n 大小的动态内存，并将文件中的值存进去*/
double** readMatrix(char path[], int row, int list)
{
	FILE* fp;
	int i, j;
	//创建动态内存，储存矩阵
	double** a;//声明一个二重指针
	a = (double**)malloc(row * sizeof(double*));//创建m个存放 double 类型指针的变量的内存空间
	for (i = 0; i < list; i++)
	{
		a[i] = (double*)malloc(list * sizeof(double));//创建n个存放 double 类型的变量的内存空间
	}

	//只读方式打开文件
	fp = fopen(path, "r");

	//按行读取数据,并将数据存放在动态内存中
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < list; j++)
		{
			fscanf(fp, "%lf", &a[i][j]);//按行读取，并把值传递到 a[i][j] 的地址中
		}
	}
	//关闭文件
	fclose(fp);
	return a;
}

/*创建输出文件，并将计算的结果写入文件中*/
void writeMatrix(char path[], double** a, int row, int list)
{
	FILE* fp;
	int i, j;

	//打开输出文件并清除文件的数据，如果没有文件则创建一个文件
	fp = fopen(path, "w");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < list; j++)
		{
			fprintf(fp, "%lf    ", a[i][j]);//按行读取，并把值赋给 a[i][j] 中
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}
/*创建输出x文件，并将计算的结果写入文件中*/
void writeMatrix(char path[], double* xOut, int num)
{
	FILE* fp;
	int i;

	//打开输出文件并清除文件的数据，如果没有文件则创建一个文件
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
	/*消去过程*/
	for (i = 0; i < row - 1; i++)
	{
		for (j = i + 1; j < row; j++)
		{
			a = matrix[j][i];
			b = matrix[i][i];
			for (k = i; k < list; k++)
			{
				matrix[j][k] = matrix[j][k] * b - a * matrix[i][k];//这里是将分式计算先通分后作商
			}
		}
	}
	/*回代过程*/
	double* x;
	//创建动态内存，存储x的值
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
				printf("方程无解");
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