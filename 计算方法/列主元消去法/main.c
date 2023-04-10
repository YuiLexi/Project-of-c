#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>
#include"Extension.h"

char inputPath[] = "MainInput.txt";
char outputPath[] = "MainOutput.txt";

int main()
{
	int rowNum, listNum;//������
	double** dp;//��������ָ��
	int a, b, c, d;
	double tmpK;
	double* tmpp;

	printf("�����ļ���������󣬲��ڿ���̨����������������");
	scanf("%d %d", &rowNum, &listNum);

	dp = ReadMatrix(inputPath, rowNum, listNum);

	for (a = 0; a < rowNum - 1; a++)
	{
		//�任��Ԫ
		for (d = a + 1; d < rowNum; d++)
		{
			if (dp[a][a] < dp[d][a])
			{
				tmpp = dp[a];
				dp[a] = dp[d];
				dp[d] = tmpp;
			}
		}

		//��Ԫ
		for (b = a + 1; b < rowNum; b++)
		{
			tmpK = -dp[b][a] / dp[a][a];
			for (c = a; c < listNum; c++)
			{
				dp[b][c] += tmpK * dp[a][c];
			}
		}
	}

	//������
	WriteMatrix(outputPath, dp, rowNum, listNum);
	return 0;
}