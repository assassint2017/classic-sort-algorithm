#include"sort.h"

/*
�����������ڵ����������е��������ر���ʱ����ʱ���ÿһ�����ݽ����ƶ������ĵ�ʱ��ǳ���
�����ʱ�����Ҫһ������м������

����������㷨ʹ�õ��Ǽ򵥵Ĳ�������
*/

int* table_sort(int array[], int n)
{
	// ��ʼ����
	int *table = new int[n];
	for (int i = 0; i < n; i++)
		table[i] = i;

	// ��������
	for (int p = 1; p < n; p++)
	{
		int temp = array[table[p]];
		int i = p;
		for (; i > 0 && array[table[i - 1]] > temp; i--)
		{
			table[i] = table[i - 1];
		}
		table[i] = p;
	}

	return table;
}