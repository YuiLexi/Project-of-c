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
/// 生成对应结点数链表
/// </summary>
/// <param name="n">链表的结点数</param>
/// <returns>返回表头指针</returns>
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
/// 将链表的内容输出出来（正序和倒序）
/// </summary>
/// <param name="fbp">指向表头的指针</param>
void print(Books* fbp)
{
	if ((*fbp).Bp == NULL)
		return;
	printf("%d\n", (*fbp).id);
	print((*fbp).Bp);
	//printf("%d\n", (*fbp).id);
}