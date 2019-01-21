#include"sort.h"

/*
算法的核心思想是将两个已经排序完毕的子序列合并为一个完整的大序列
在任何情况下的时间复杂度为nlogn
具有稳定性

算法有两种实现的方法，分别是递归和非递归的

归并排序在内部排序的时候基本上不会被使用，因为会占用额外的空间
但是在外部排序中就相当有用了
*/

// 递归版本的代码
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

void merge_sort_recursive(int array[], int n)
{
	// 申请一个临时数组
	int *tempArray = new int[n]();

	m_sort(array, tempArray, 0, n - 1);

	delete[] tempArray;
}



// 非递归版本的代码
void merge1(int array1[], int array2[], int left, int mid, int right)
{
	int leftPtr = left;
	int rightPtr = mid + 1;
	int allPtr = left;

	while (leftPtr <= mid && rightPtr <= right)
	{
		if (array1[leftPtr] < array1[rightPtr])
			array2[allPtr++] = array1[leftPtr++];
		else
			array2[allPtr++] = array1[rightPtr++];
	}
	while (leftPtr <= mid)
		array2[allPtr++] = array1[leftPtr++];
	while (rightPtr <= right)
		array2[allPtr++] = array1[rightPtr++];	
}

void merge_pass(int array1[], int array2[], int n, int length)
{
	int i;
	for (i = 0; i <= n - 2 * length; i += 2 * length)
		merge1(array1, array2, i, i + length - 1, i + 2 * length - 1);
	if (i + length < n)
		merge1(array1, array2, i, i + length - 1, n - 1);
	else
	{
		for (; i < n; i++)
			array2[i] = array1[i];
	}
}

void merge_sort_nonrecursive(int array[], int n)
{
	int *tempArray = new int[n]();
	int length = 1;

	while (length < n)
	{
		merge_pass(array, tempArray, n, length);
		length *= 2;
		merge_pass(tempArray, array, n, length);
		length *= 2;
	}

	delete[] tempArray;
}