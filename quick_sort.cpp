#include"sort.h"

/*
快速排序是现实应用中，最快的排序算法，应用范围比较广
是面试中比较爱问的一种排序算法

算法使用的策略是分而治之
首先选取主元 划分子集

主元的选取对算法性能有很大的影响，如果把第一个元素当做主元，效果不好
比较经典的做法是将头中尾三者的中位数当做主元

由于算法中使用到了递归，那么就要使用到堆栈，这就对于比较小型的规模的数据来说可能
反而没有那些简单的排序算法来的快，因此快速排序适用于大规模的数据，小规模的数据使用简单排序就可以了
*/

int median3(int array[], int left, int right)
{
	// 首先计算中点的位置
	int mid = (left + right) / 2;

	// 下面的三个判断把数组的头、中、尾调整为从小到大的顺序
	if (array[left] > array[mid])
	{
		int temp = array[left];
		array[left] = array[mid];
		array[mid] = temp;
	}
	if (array[left] > array[right])
	{
		int temp = array[left];
		array[left] = array[right];
		array[right] = temp;
	}
	if (array[mid] > array[right])
	{
		int temp = array[mid];
		array[mid] = array[right];
		array[right] = temp;
	}

	// 接下来将中位数与右边的倒数第二个数进行交换
	{
		int temp = array[mid];
		array[mid] = array[right - 1];
		array[right - 1] = temp;
	}

	// 最后返回中位数作为主元
	return array[right - 1];
}

void sort(int array[], int left, int right)
{
	if (left < right)
	{
		// 首先选取主元
		int pivot = median3(array, left, right);

		// 子集划分
		int leftPtr = left;
		int rightPtr = right - 1;

		while (true)
		{
			while (array[++leftPtr] < pivot);
			while (array[--rightPtr] > pivot);
			if (leftPtr < rightPtr)
			{
				int temp = array[leftPtr];
				array[leftPtr] = array[rightPtr];
				array[rightPtr] = temp;
			}
			else break;
		}

		// 将主元交换到最终的正确位置
		int temp = array[leftPtr];
		array[leftPtr] = array[right - 1];
		array[right - 1] = temp;

		// 分别递归的去处理左右两个子序列
		sort(array, left, leftPtr - 1);
		sort(array, leftPtr + 1, right);
	}
	
}

void quick_sort(int array[], int n)
{
	sort(array, 0, n - 1);
}