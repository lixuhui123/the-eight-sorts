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
			/*��������ĺ���˼����������֣�������Ҫ����ĵ�iλҲ����tmpֵ
			���ǰ���б�����������Ǿͽ���Щ������һ������tmpӦ���ڵĵط��ڳ���
			*/
			src[j] = src[j-1];
		}
		src[j] = tmp;
		/* ����ٽ�tmp���ȥ*/
	}
 }
void printfarray(int * arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d  ", arr[i]);
	}
}
//ϣ�������ֽ���С������������ֱ�Ӳ�����������Խ����ֱ�Ӳ�������Խ��
//void ShellSort(int *src, int n)
//{
//	int i, j, k;
//	int gap, tmp;
//	for()
//}
/*�鲢���򣬽���һ����ʱ�ռ䣬�൱�ڶ������ĺ��򣬷� ��*/
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
	dealMergeSort(src, tmp,0, n-1);//�����±�
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
	//˫ָ�뷨
	/*��С����
	��һ������������ָ��һ��ָ������ͷaһ��ָ������βb��
	�ڶ�������ͷָ��Ϊ��׼ֵ�ȴ�βָ�뿪ʼ����ұȻ�׼ֵС��Ԫ�أ��ҵ�֮�󽻻�a��b��ָ���ֵ
	����������ʱb��ָ���ֵ���ǻ�׼ֵ��a��ʼ����ң��ҵ��Ȼ�׼ֵ��Ľ�����
	���Ĳ������һ�ν���֮���Ի�׼ֵ�±�Ϊ����ֵ���صݹ���õ�
		������˵һ�¿��ŵĿ�ܣ�������ģ�¶�������ǰ�������ʽ�ֲ���������ٺϳ�һ�����������
	��Ϊ����ָ�뽻�����һ�ξֲ�����֮���׼ֵ���ҵ�����Ӧ�ô��ڵ���ȷλ�ã����һ�׼ֵ��ߵ�����Ԫ��
	ֵ��С�ڻ�׼ֵ����׼ֵ�ұߵ�����Ԫ�ض����ڻ�׼ֵ��������Ҫ���ľ��ǣ��Ե�һ������õ��Ļ�׼ֵ�����������ĸ���
	�ֱ��������������������ԾͲ����˶�������ǰ������ĵݹ鷽ʽ�����ҵݹ�Ĳ���Ҳ�ܺ����ã���ÿ�εõ���
	��׼ֵΪ���ֳ���������������Ҫע�����ʵ�ֵ�ϸ�ڡ���������һ��˼ά��ת���Ǿ��ǣ�����������ָ��ķ�ʽ
	ÿ�����ڵ㶼��ָ���������Һ��ӣ���ô��Ϊ��������ȥ�����������������أ�������Ȼ��Ȼ���뵽���±꣬����
	���±����綨�ֲ�����ķ�Χ�������Լ������ö�����������ʵ�����򣬽��źõĶ�����������ƽ�ͻ�õ�����
	�������顣
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
         /* tlag��Ϊ���λ�������ж�����aָ��Ѱ�һ�����bָ��Ѱ��*/
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
	//��������
	dealquicksort(src, 0, n-1);
}
int doublepointway2(int *src, int start, int end)
{
	/* ��ŦԪ*/
	int a = start, b = end - 1;
	int mid = (start + end) / 2;
	swap(src+mid, src+end);


	while (a<=b)
	{
		/*����ʦд�����˳����������д�������������ĵ�һ�����̣�һ��һ����ɹ��ܣ��ر���дѭ��
		����������������дȻ���ٵ��ԣ�������һ���Ӵ�ʼ���ն���òſ�ʼд*/
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
/*�ڿӷ�����С����*/
	/* ʲô���ڿӷ��أ���������������������int a = strat, b = end;����һ���м����int tmp = src[strat];
	���ұ߿�ʼ�ұ�tmpֵС�ģ��ҵ���ֱ�ӽ�ֵ����aָ����ָ��Ԫ�أ���ʱbָ����ָ���λ�þ��Ǹ���Ʒ��������
	�����µĿӣ����Խ��ڿӷ���Ҳ��ΪʲôҪ��tmp��סsrc[strat]��ԭ����Ϊ����Ҫ�����ǣ�Ȼ��a��ʼ�ұ�tmp�����
	�ҵ���ֱ�Ӹ�ֵ��ԭ���ľɿӣ�Ҳ����bָ����Ǹ��ӣ�֪������ָ�뽻��һ���������
	�ܹ��ֳ������������������ˣ����������ǵݹ������������������ˣ��ݹ����˫ָ�뷨�н���*/
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
			/* bָ�����������Ľ���a���ɿ�Ҫ�����û�����Ը��ڵ�Ϊa��returnҲ���Ƿֳ���a����������*/
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