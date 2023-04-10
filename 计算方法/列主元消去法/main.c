#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include"Extension.h"

char inputPath[] = "MainInput.txt";
char outputPath[] = "MainOutput.txt";

int main()
{
	int rowNum, listNum;//行列数
	double** dp;//矩阵数据指针
	int a, b, c, d;
	double tmpK;
	double* tmpp;

	printf("请在文件中输入矩阵，并在控制台输入矩阵的行列数：");
	scanf("%d %d", &rowNum, &listNum);

	dp = ReadMatrix(inputPath, rowNum, listNum);

	for (a = 0; a < rowNum - 1; a++)
	{
		//变换主元
		for (d = a + 1; d < rowNum; d++)
		{
			if (dp[a][a] < dp[d][a])
			{
				tmpp = dp[a];
				dp[a] = dp[d];
				dp[d] = tmpp;
			}
		}

		//消元
		for (b = a + 1; b < rowNum; b++)
		{
			tmpK = -dp[b][a] / dp[a][a];
			for (c = a; c < listNum; c++)
			{
				dp[b][c] += tmpK * dp[a][c];
			}
		}
	}

	//输出结果
	WriteMatrix(outputPath, dp, rowNum, listNum);
	return 0;
}