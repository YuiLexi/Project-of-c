#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define MAX_SIZE 100 /* �������ά�� */
#define ZERO 0.000000001 /* ��һ������С��ZERO����Ϊ������0 */

bool Direct(int n, double a[][MAX_SIZE], double b[])
{
	bool flag = true;
	double y[10];
	int r;
	int i;
	int k;
	double sum_u, sum_l;
	for (r = 1; r < n; r++)
		a[r][0] = a[r][0] / a[0][0];
	for (r = 1; r < n; r++)
	{
		for (i = r; i < n; i++)
		{
			sum_u = 0;
			for (k = 0; k < r; k++)
				sum_u += a[r][k] * a[k][i];
			a[r][i] = a[r][i] - sum_u;
		}
		for (i = r + 1; i < n && r != n - 1; i++)
		{
			sum_l = 0;
			for (k = 0; k < r; k++)
				sum_l += a[i][k] * a[k][r];
			a[i][r] = (a[i][r] - sum_l) / a[r][r];
		}
	}
	//--------------------------------------------------------------------------//
	for (r = 0; r < n; r++)
	{
		if (a[r][r] == 0) //�ȼ����жϾ����˳������ʽ�Ƿ�Ϊ0
		{
			flag = false;
			return flag;
		}
	}
	//--------------------------------------------------------------------------//
	y[0] = b[0];
	double sum;
	for (i = 1; i < n; i++)
	{
		sum = 0;
		for (k = 0; k < i; k++)
			sum += a[i][k] * y[k];
		y[i] = b[i] - sum;
	}
	//--------------------------------------------------------------------------//
	b[n - 1] = y[n - 1] / a[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		sum = 0;
		for (k = i + 1; k < n; k++)
			sum += a[i][k] * b[k];
		b[i] = (y[i] - sum) / a[i][i];
	}
	return flag;
}

int main()
{
	int n, i, j;
	double a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE];

	while (scanf("%d", &n) != EOF) { /* ��ȡ�������� */
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				scanf("%lf", &a[i][j]);
			scanf("%lf", &b[i]);
		}
		/*--- ���ֱ�ӷ��Ľ� ---*/
		if (Direct(n, a, b))
		{
			printf("ֱ�ӷ������\n");
			for (j = 0; j < n; j++)
				printf("%.4lf\n", b[j]);
		}
		else
			printf("��ʽ�ֽ�ʧ�ܡ�\n");
		printf("\n");
	}
	return 0;
}