#include"sort.h"

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
int doublepointway1(int *src, int start, int end)
{
	//双指针法
	/*从小到大
	第一步：定义两个指针一个指向数组头a一个指向数组尾b；
	第二步：以头指针为基准值先从尾指针开始向后找比基准值小的元素，找的之后交换a，b所指向的值
	第三步：此时b所指向的值就是基准值，a开始向后找，找到比基准值大的交换。
	第四步：完成一次交换之后，以基准值下标为返回值返回递归调用点
		在这里说一下快排的框架，快排是模仿二叉树的前序遍历方式局部排序，最后再合成一个有序数组的
	因为左右指针交错完成一次局部排序之后基准值就找到了它应该存在的正确位置，并且基准值左边的所有元素
	值都小于基准值，基准值右边的所有元素都大于基准值。接下来要做的就是（以第一次排序得到的基准值当做二叉树的根）
	分别排它的左右子树，所以就参照了二叉树的前序遍历的递归方式，而且递归的参数也很好设置，以每次得到的
	基准值为根分出它的左右子树。要注意的是实现的细节。在这里有一个思维的转变那就是：二叉树是以指针的方式
	每个根节点都会指向它的左右孩子，那么作为数组怎样去区分它的左右子树呢，我们自然而然的想到了下标，我们
	用下标来界定局部排序的范围，可以自己动手用二叉树的样子实现排序，将排好的二叉树向上推平就会得到它的
	有序数组。
	*/
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
         /* tlag作为标记位，用来判断是让a指针寻找还是让b指针寻找*/
		}
		
 	}

	return flag ? b : a;

}
void dealquicksort(int *src, int start, int end)
{
	int mid;
	if (start<end)
	{
		mid = digway( src,  start,   end);
		dealquicksort( src, start, mid-1);
		dealquicksort(src, mid + 1, end);
	}
}
void quicksort(int *src, int n)
{
	//快速排序
	dealquicksort(src, 0, n-1);
}
int doublepointway2(int *src, int start, int end)
{
	/* 枢纽元*/
	int a = start, b = end - 1;
	int mid = (start + end) / 2;
	swap(src+mid, src+end);


	while (a<=b)
	{
		/*从老师写代码的顺序来看，他写的是做这个问题的第一次流程，一点一点完成功能，特别是写循环
		跳出条件总是最后才写然后再调试，并不是一下子从始到终都想好才开始写*/
		while (a < end && src[a] <= src[end])
		{

			a++;
		}
		while (b > 0 && src[b] >= src[end])
		{
			b--;

		}
		if (a==b && (a==0 || a==end))
		{
			break;
		}
		if (a<b)
		{
			swap(src + a, src + b);
		}
		
	}
		swap(src + a, src + end);
		return a;
}
/*挖坑法，从小到大*/
	/* 什么是挖坑法呢，我们来这样做。记数组int a = strat, b = end;设置一个中间变量int tmp = src[strat];
	从右边开始找比tmp值小的，找到后直接将值赋给a指针所指的元素，此时b指针所指向的位置就是个废品，产生个
	待更新的坑，所以叫挖坑法。也是为什么要用tmp记住src[strat]的原因，因为它将要被覆盖，然后a开始找比tmp大的数
	找到后直接赋值给原来的旧坑，也就是b指向的那个坑，知道两个指针交错，一次排序完成
	能够分出二叉树的左右子树了，接下来就是递归来分排序区的事情了，递归设计双指针法有讲。*/
int digway(int* src, int strat, int end)
{
	
	int a = strat, b = end;
	int tmp = src[strat];
	while (1)
	{
		while (src[b] >= tmp)
		{
			b--;
		}
		if (a<b)
		{
			src[a] = src[b];
		}
		else
		{
			src[a] = tmp;
			return a;
			/* b指针主动产生的交错，a（旧坑要填）所以没动所以根节点为a，return也就是分出了a的左右子树*/
		}
		
		while (src[a]<=tmp)
		{
			a++;
		}
		if (a<b)
		{
			src[b] = src[a];
		}
		else
		{
			src[b] = tmp;
			return b;
		}
		
	}
}