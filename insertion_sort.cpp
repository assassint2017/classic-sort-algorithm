#include"sort.h"

/*
�㷨��˼�������ڳ��ƣ�ÿ�γ��һ���ƣ�Ȼ����һ��
�Ѿ��ź���������в��뵽һ����ȷ��λ��

����ð�������У�����һ��Ԫ����Ҫ������������������ֻ��Ҫһ�Σ�����ٶ��ϻ���Ҫ��ܶ��

������ O(n)
���� O(n2)
�㷨ͬ�����ȶ���
*/

void insertion_sort(int array[], int n)
{
	for (int p = 1; p < n; p++)
	{
		int temp = array[p];
		int i = p;
		for (; i > 0 && array[i - 1] > temp; i--)
		{
			array[i] = array[i - 1];
		}
		array[i] = temp;
	}
}