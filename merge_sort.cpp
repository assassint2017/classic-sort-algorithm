#include"sort.h"

/*
�㷨�ĺ���˼���ǽ������Ѿ�������ϵ������кϲ�Ϊһ�������Ĵ�����
���κ�����µ�ʱ�临�Ӷ�Ϊnlogn
�����ȶ���

�㷨������ʵ�ֵķ������ֱ��ǵݹ�ͷǵݹ��
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

// �ݹ�汾�Ĵ���
void merge_sort_recursive(int array[], int n)
{
	// ����һ����ʱ����
	int *tempArray = new int[n]();

	m_sort(array, tempArray, 0, n - 1);

	delete[] tempArray;
}

// �ǵݹ�汾�Ĵ���
void merge_sort_nonrecursive(int array[], int n)
{

}