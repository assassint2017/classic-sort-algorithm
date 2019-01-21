#include"sort.h"

/*
������������ʵӦ���У����������㷨��Ӧ�÷�Χ�ȽϹ�
�������бȽϰ��ʵ�һ�������㷨

�㷨ʹ�õĲ����Ƿֶ���֮
����ѡȡ��Ԫ �����Ӽ�

��Ԫ��ѡȡ���㷨�����кܴ��Ӱ�죬����ѵ�һ��Ԫ�ص�����Ԫ��Ч������
�ȽϾ���������ǽ�ͷ��β���ߵ���λ��������Ԫ

�����㷨��ʹ�õ��˵ݹ飬��ô��Ҫʹ�õ���ջ����Ͷ��ڱȽ�С�͵Ĺ�ģ��������˵����
����û����Щ�򵥵������㷨���Ŀ죬��˿������������ڴ��ģ�����ݣ�С��ģ������ʹ�ü�����Ϳ�����
*/

int median3(int array[], int left, int right)
{
	// ���ȼ����е��λ��
	int mid = (left + right) / 2;

	// ����������жϰ������ͷ���С�β����Ϊ��С�����˳��
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

	// ����������λ�����ұߵĵ����ڶ��������н���
	{
		int temp = array[mid];
		array[mid] = array[right - 1];
		array[right - 1] = temp;
	}

	// ��󷵻���λ����Ϊ��Ԫ
	return array[right - 1];
}

void sort(int array[], int left, int right)
{
	if (left < right)
	{
		// ����ѡȡ��Ԫ
		int pivot = median3(array, left, right);

		// �Ӽ�����
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

		// ����Ԫ���������յ���ȷλ��
		int temp = array[leftPtr];
		array[leftPtr] = array[right - 1];
		array[right - 1] = temp;

		// �ֱ�ݹ��ȥ������������������
		sort(array, left, leftPtr - 1);
		sort(array, leftPtr + 1, right);
	}
	
}

void quick_sort(int array[], int n)
{
	sort(array, 0, n - 1);
}