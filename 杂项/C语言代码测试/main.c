#pragma warning(disable:4996)
#include<stdio.h>
#include<malloc.h>

typedef struct Books
{
	int id;
	struct Books* Bp;
}Books;

int main()
{
	Books* init(int n);
	void print(Books * fbp);
	Books* p;
	p = init(10);
	print(p);
}

/// <summary>
/// ���ɶ�Ӧ���������
/// </summary>
/// <param name="n">����Ľ����</param>
/// <returns>���ر�ͷָ��</returns>
Books* init(int n)
{
	Books* fBp = NULL;
	Books* tmp = NULL;
	int a;
	fBp = (Books*)malloc(sizeof(Books));

	tmp = fBp;
	for (a = 0; a < n; a++)
	{
		(*tmp).id = a;
		(*tmp).Bp = (Books*)malloc(sizeof(Books));
		tmp = (*tmp).Bp;
		(*tmp).Bp = NULL;
	}
	return fBp;
}

/// <summary>
/// ������������������������͵���
/// </summary>
/// <param name="fbp">ָ���ͷ��ָ��</param>
void print(Books* fbp)
{
	if ((*fbp).Bp == NULL)
		return;
	printf("%d\n", (*fbp).id);
	print((*fbp).Bp);
	//printf("%d\n", (*fbp).id);
}