#include"sort.h"

/*
ÿ��ѡ��һ����Сֵ�ŵ��Ѿ�����õ����е�����

�㷨��ʱ�临�ӶȲ�������ú�����
����O(n2)
*/

void selection_sort(int array[], int n)
{
	for (int p = 0; p < n; p++)
	{
		// ѭ��������ɨ����Сֵ���ڵ�λ��
		int min = INT_MAX, minPos = p;
		for (int i = p; i < n; i++)
		{
			if (array[i] < min)
			{
				min = array[i];
				minPos = i;
			}
		}
		
		// ����Ԫ��
		int temp = array[p];
		array[p] = array[minPos];
		array[minPos] = temp;
	}
}