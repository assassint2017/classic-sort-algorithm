#include"sort.h"

/*
每次选择一个最小值放到已经排序好的序列的最后端

算法的时间复杂度不区分最好和最坏情况
都是O(n2)
*/

void selection_sort(int array[], int n)
{
	for (int p = 0; p < n; p++)
	{
		// 循环，线性扫描最小值所在的位置
		int min = INT_MAX, minPos = p;
		for (int i = p; i < n; i++)
		{
			if (array[i] < min)
			{
				min = array[i];
				minPos = i;
			}
		}
		
		// 交换元素
		int temp = array[p];
		array[p] = array[minPos];
		array[minPos] = temp;
	}
}