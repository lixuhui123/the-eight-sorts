#include"sort.h"

//void sort(int *src, int n)
//{
//	int i, j;
//	int tmp;
//	for (i = 1; i < n; i++)
//	{
//		tmp = src[i];
//		for (j = i; j > 0 && src[j - 1] > tmp; j--)
//		{
//			
//
//				src[j] = src[j - 1];
//
//
//
//		}
//		src[j] = tmp;
//	}
//}
void  sort(int* src, int n)
{
	int i, j;
	int tmp;
	for (i=0;i<n;++i)
	{
		tmp = src[i];
		for (j=i;j>0&&src[j-1]>tmp;--j)
		{
			/*插入排序的核心思想是这个部分，含义是要排序的第i位也就是tmp值
			如果前面有比他还大的数那就将这些数后移一个，给tmp应该在的地方腾出来
			*/
			src[j] = src[j-1];
		}
		src[j] = tmp;
		/* 最后再将tmp插进去*/
	}
 }
void printfarray(int * arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d  ", arr[i]);
	}
}
//希尔排序又叫缩小增量法，多重直接插入排序，数组越有序直接插入排序越快
//void ShellSort(int *src, int n)
//{
//	int i, j, k;
//	int gap, tmp;
//	for()
//}
/*归并排序，借助一个临时空间，相当于二叉树的后序，分 和*/
void dealMergeSort(int *src, int* tmp, int  str, int  end)
{
	if (str>=end)
	{
		return;

	}
	int mid = (str + end) / 2;
	dealMergeSort(src, tmp, str, mid);
	dealMergeSort(src, tmp, mid+1, end);
	int a = str;
	int b = mid + 1;
	int c = str;//1,5,6,15,8,26,5,55,9,0 
	while (a<=mid&&b<=end)
	{

		if (src[a]>src[b])
		{
			tmp[c] = src[a];
			a++;
		}
		else
		{
			tmp[c] = src[b];
			b++;
		}
		c++;
	}
	for ( ; a<=mid ;a++,c++)
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)
	{
		tmp[c] = src[b];
	}
	int i = 0;
	for (i = 0; i <= end; ++i)
	{
		src[i] = tmp[i];
	}
}
void MergeSort(int *src, int n)
{
	int *tmp = (int*)malloc(n * sizeof(int));
	dealMergeSort(src, tmp,0, n-1);//传入下标
	free(tmp);
}
void swap(int* a, int*b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int dooublepointway1(int *src, int start, int end)
{
	int a = start;
	int b = end;
	int flag = 0;
	while ( src[b] > src[a])
	{
		b--;
	}
	while (a < b)
	{
		swap(src + b, src + a);
		flag = !flag;

		while (src[b] >= src[a])
		{
			flag ? a++ : b--;

		}
		
 	}

	return flag ? b : a;

}
void dealquicksort(int *src, int start, int end)
{
	int mid;
	if (start<end)
	{
		mid = dooublepointway1( src,  start,   end);
		dealquicksort( src, start, mid-1);
		dealquicksort(src, mid + 1, end);
	}
}
void quicksort(int *src, int n)
{
	dealquicksort(src, 0, n-1);
}
int dooublepointway2(int *src, int start, int end)
{

	int a = start, b = end - 1;
	int tmp = (start + end) / 2;
	while (a<b)
	{
		while (a < end&&src[a] <= src[end])
		{

			a++;
		}
		while (b>0&&src[a] >= src[end])
		{
			b--;

		}
		if (a<b)
		{
			swap(src + a, src + b);
		}
		
	}
		swap(src + a, src + end);
		return a;
}