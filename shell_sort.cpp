#include"sort.h"

/*
ϣ�������ǲ��������������
�㷨���ж�ζ����Ĳ�������
ÿ�μ���𽥼�С��1�����ڲ�ͬ���������е����㷨���ܲ�ͬ
��˺�����ѧ��������˺ܶ಻ͬ����������
�±ߴ�����ʹ�õ���sedgewick��������
*/

// ��������ֵ
int sedgewick(int sedgewickIndex)
{
	if (sedgewickIndex % 2 == 0)
	{
		int temp = sedgewickIndex / 2;
		return 9 * pow(4, temp) - 9 * pow(2, temp) + 1;
	}
	else
	{
		int temp = (sedgewickIndex + 3) / 2;
		return pow(4, temp) - 3 * pow(2, temp) + 1;
	}
}

void shell_sort(int array[], int n)
{
	// ����ȷ��sedgewick�ĳ�ʼֵ
	int sedgewickIndex = 0;
	while (1)
	{
		if (sedgewick(sedgewickIndex) < n)
			sedgewickIndex++;
		else
		{
			sedgewickIndex--;
			break;
		}
	}

	// ��ʼ��һ���ļ�����ж�β�������
	for (;sedgewickIndex >= 0; sedgewickIndex--)
	{
		int sed = sedgewick(sedgewickIndex);
		for (int p = sed; p < n; p++)
		{
			int temp = array[p];
			int i = p;
			for (; i >= sed && array[i - sed] > temp; i -= sed)
			{
				array[i] = array[i - sed];
			}
			array[i] = temp;
		}
	}
}