#include"sort.h"

/*
堆排序是对选择排序的升级

对于从小到大的排序，如果直接将数组建立为最小堆，然后循环弹出元素的话不是一个好的选择
理由可以自己好好思考一下
更加高效的做法是建立一个最大堆，然后再逐个的进行删除
*/

// 建立最大堆
void bulidMaxHeap(int array[], int maxSize)
{
	int parent, child;
	for (int i = maxSize; i >= 0; i--)
	{
		int temp = array[i];
		int parent, child;
		
		for (parent = i; parent * 2 + 1 <= maxSize; parent = child)
		{
			child = parent * 2 + 1;
			if (child + 1 <= maxSize && array[child + 1] > array[child])
				child++;
			if (temp > array[child])
				break;
			else
				array[parent] = array[child];
		}
		array[parent] = temp;
	}
}

// 从堆中删除元素
int deleteFromHeap(int array[], int maxSize)
{
	int maxValue = array[0];
	int temp = array[maxSize];

	int parent, child;
	for (parent = 0; parent * 2 + 1 <= maxSize; parent = child)
	{
		child = parent * 2 + 1;
		if (child + 1 <= maxSize && array[child + 1] > array[child])
			child++;
		if (temp > array[child])
			break;
		else
			array[parent] = array[child];
	}
	array[parent] = temp;
	return maxValue;
}

void heap_sort(int array[], int n)
{
	// 将数组调整为一个最大堆
	bulidMaxHeap(array, n - 1);

	// 将元素从堆顶逐个的弹出到堆尾
	for (int i = 0; i < n; i++)
		array[n - 1 - i] = deleteFromHeap(array, n - i - 1);
}