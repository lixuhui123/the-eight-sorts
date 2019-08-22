
#include"sort.h"
#include<time.h>
#define BNFSIZE 6
int main()
{
#if 1
	int src[10] = { 1,5,6,8,58,26 };
	//printfarray(src,6);
	MergeSort(src, BNFSIZE);
	putchar('\n');
	printfarray(src, 6);
#else
	 srand(time(NULL));
	int src[BNFSIZE];
	int i;
	for ( i = 0; i < BNFSIZE; ++i)
	{
		src[i] = rand()%2;
		//printf("%d \t", src[i]);
	}
	MergeSort(src, BNFSIZE);
	printfarray(src, BNFSIZE);
	putchar('\n');
#endif // 1

	system("pause");
	return 0;
}