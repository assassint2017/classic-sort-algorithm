#include"sort.h"

/*
希尔排序是插入排序的升级版
算法进行多次多间隔的插入排序
每次间隔逐渐减小到1，由于不同的增量序列导致算法性能不同
因此后来的学者们提出了很多不同的增量序列
下边代码中使用的是sedgewick增量序列
*/

// 计算增量值
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
	// 首先确定sedgewick的初始值
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

	// 开始以一定的间隔进行多次插入排序
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