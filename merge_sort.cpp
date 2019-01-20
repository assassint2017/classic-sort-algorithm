#include"sort.h"

/*
算法的核心思想是将两个已经排序完毕的子序列合并为一个完整的大序列
在任何情况下的时间复杂度为nlogn
具有稳定性

算法有两种实现的方法，分别是递归和非递归的
*/

void merge(int array[], int tempArray[], int left, int mid, int right)
{
	int leftPtr = left;
	int rightPtr = mid + 1;
	int allPtr = left;

	while (leftPtr <= mid && rightPtr <= right)
	{
		if (array[leftPtr] < array[rightPtr])
			tempArray[allPtr++] = array[leftPtr++];
		else
			tempArray[allPtr++] = array[rightPtr++];
	}

	while (leftPtr <= mid)
		tempArray[allPtr++] = array[leftPtr++];
	while (rightPtr <= right)
		tempArray[allPtr++] = array[rightPtr++];
	
	for (int i = left; i <= right; i++)
		array[i] = tempArray[i];
}

void m_sort(int array[], int tempArray[], int left, int right)
{
	// 如果至少有两个元素才有必要进行排序
	if (left < right)
	{
		int mid = (left + right) / 2;

		// 对左半部分序列进行排序
		m_sort(array, tempArray, left, mid);

		// 对右半部分序列进行排序
		m_sort(array, tempArray, mid + 1, right);

		// 合并两个已经排序完毕的子序列为一个完整的大序列
		merge(array, tempArray, left, mid, right);
	}
}

// 递归版本的代码
void merge_sort_recursive(int array[], int n)
{
	// 申请一个临时数组
	int *tempArray = new int[n]();

	m_sort(array, tempArray, 0, n - 1);

	delete[] tempArray;
}

// 非递归版本的代码
void merge_sort_nonrecursive(int array[], int n)
{

}