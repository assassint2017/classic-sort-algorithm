#include"sort.h"

/*
ð����������򵥵������㷨
������ O(n)
������ O(n2)
������ʱ�临�ӶȺܸ�
�ô�����������Ǵ洢�������еģ��㷨Ҳû����
�����㷨�����ȶ���

�㷨��ʵ�ֵ�ʱ��������һ����־λ
����ָʾ���Ѿ�������ϵ�ʱ�����ֱ������ѭ����֮��Ķ���ѭ���Ϳ��Բ�������
*/
void bubble_sort(int array[], int n)
{
	for (int p = n - 1; p >= 0; p--)
	{
		bool flag = true;
		for (int i = 0; i < p; i++)
		{
			if (array[i] > array[i + 1])
			{
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				flag = false;
			}
		}
		if (flag == true)
			break;
	}
}