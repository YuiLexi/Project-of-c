#include<stdio.h>
#include<math.h>
int main()
{
	float x[6];
	int i;
	float a[6][7] = { 0.5,-0.5,0,0,0,0,-1,
				   -0.5,1.5,-0.5,-0.25,0.25,0,0,
				   0,-0.5,1.5,0.25,-0.25,0,0,
				   0,-0.25,0.25,1.5,-0.5,0,0,
				   0,0.25,-0.25,-0.5,1.5,-0.5,0,
				   0,0,0,0,-0.5,0.5,0 };
	void ping(float*, int, float[]);
	ping(a[0], 6, x);
	for (i = 0; i <= 5; i++)printf("x[%d]=%f\n", i, x[i]);
	printf("\n");
}
//改进平方根法
void ping(float* u, int n, float x[])
{
	int i, r, k;
	for (r = 0; r <= n - 1; r++)
	{
		for (i = r; i <= n; i++)
			for (k = 0; k <= r - 1; k++)
				*(u + r * (n + 1) + i) -= *(u + r * (n + 1) + k) * (*(u + k * (n + 1) + i));

		for (i = r + 1; i <= n - 1; i++)
		{
			*(u + i * (n + 1) + r) = *(u + r * (n + 1) + i) / (*(u + r * (n + 1) + r));
		}
	}
	for (i = n - 1; i >= 0; i--)
	{
		for (r = n - 1; r >= i + 1; r--)
			*(u + i * (n + 1) + n) -= *(u + i * (n + 1) + r) * x[r];
		x[i] = *(u + i * (n + 1) + n) / (*(u + i * (n + 1) + i));
	}
}