#include"sort.h"
#include<time.h>
#define BNFSIZE 6000
//N^2的复杂度都是稳定的，归并也稳定在nlogn内只有它，一共logn层每层n个
/* 在这里把八大排序都写上*/
int a = 3;
int main()
{
#if 0
	int src[6] = { 5,32,32,6,0,8 };
	////printfarray(src,10);
	//MergeSort(src, 6);
	//putchar('\n');
	quicksort(src, 6);
	printfarray(src, 6);
	/*const char *p = "hellow";
	char ch = *(p++);
	printf("%c", ch);
	int i = 0;
	i = (i++);
	printf("%d", i);*/
	//const char *p = "hellow";//常量指针指针指向不能修改；
	//*(p+1) = 'E';
	//int s = 0;
	//{
	//	int a = 5;
	//	s += a++;//s=s+a++

	//}
	//s += a++;
	//printf("%d\n", s);
#else
	 srand(time(NULL));
	int src[BNFSIZE];
	int i;
	for ( i = 0; i < BNFSIZE; ++i)
	{
		src[i] = rand()% BNFSIZE;
		//printf("%d \t", src[i]);
	}
	//MergeSort(src, BNFSIZE);
	quicksort(src, BNFSIZE);
	printfarray(src, BNFSIZE);
	putchar('\n');
#endif // 1

	system("pause");
	return 0;
}
