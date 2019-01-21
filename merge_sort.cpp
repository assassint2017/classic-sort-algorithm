#include"sort.h"

/*
�㷨�ĺ���˼���ǽ������Ѿ�������ϵ������кϲ�Ϊһ�������Ĵ�����
���κ�����µ�ʱ�临�Ӷ�Ϊnlogn
�����ȶ���

�㷨������ʵ�ֵķ������ֱ��ǵݹ�ͷǵݹ��

�鲢�������ڲ������ʱ������ϲ��ᱻʹ�ã���Ϊ��ռ�ö���Ŀռ�
�������ⲿ�����о��൱������
*/

// �ݹ�汾�Ĵ���
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
	// �������������Ԫ�ز��б�Ҫ��������
	if (left < right)
	{
		int mid = (left + right) / 2;

		// ����벿�����н�������
		m_sort(array, tempArray, left, mid);

		// ���Ұ벿�����н�������
		m_sort(array, tempArray, mid + 1, right);

		// �ϲ������Ѿ�������ϵ�������Ϊһ�������Ĵ�����
		merge(array, tempArray, left, mid, right);
	}
}

void merge_sort_recursive(int array[], int n)
{
	// ����һ����ʱ����
	int *tempArray = new int[n]();

	m_sort(array, tempArray, 0, n - 1);

	delete[] tempArray;
}



// �ǵݹ�汾�Ĵ���
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