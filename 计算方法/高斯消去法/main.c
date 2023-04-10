#pragma warning(disable:4996)
#include<stdio.h>
#include"Extension.h"

char inputPath[] = "Input.txt";
char outputPath[] = "Output.txt";

int main()
{
	int rowNum, listNum;//������
	double** dp;//��������ָ��
	int a, b, c, d;
	double tmpK;

	printf("�����ļ���������󣬲��ڿ���̨����������������");
	scanf("%d %d", &rowNum, &listNum);

	dp = ReadMatrix(inputPath, rowNum, listNum);

	for (a = 0; a < listNum - 1; a++)
	{
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