#include"sort.h"

/*
�������Ƕ�ѡ�����������

���ڴ�С������������ֱ�ӽ����齨��Ϊ��С�ѣ�Ȼ��ѭ������Ԫ�صĻ�����һ���õ�ѡ��
���ɿ����Լ��ú�˼��һ��
���Ӹ�Ч�������ǽ���һ�����ѣ�Ȼ��������Ľ���ɾ��
*/

// ��������
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

// �Ӷ���ɾ��Ԫ��
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
	// ���������Ϊһ������
	bulidMaxHeap(array, n - 1);

	// ��Ԫ�شӶѶ�����ĵ�������β
	for (int i = 0; i < n; i++)
		array[n - 1 - i] = deleteFromHeap(array, n - i - 1);
}