#include"sort.h"

/*
表排序适用于当待排数据中单个数据特别大的时候，这时候对每一个数据进行移动所消耗的时间非常多
因此这时候就需要一个表进行间接排序

这里的排序算法使用的是简单的插入排序
*/

int* table_sort(int array[], int n)
{
	// 初始化表
	int *table = new int[n];
	for (int i = 0; i < n; i++)
		table[i] = i;

	// 插入排序
	for (int p = 1; p < n; p++)
	{
		int temp = array[table[p]];
		int i = p;
		for (; i > 0 && array[table[i - 1]] > temp; i--)
		{
			table[i] = table[i - 1];
		}
		table[i] = p;
	}

	return table;
}