#include"sort.h"

/*
冒泡排序是最简单的排序算法
最好情况 O(n)
最插情况 O(n2)
坏处是时间复杂度很高
好处是如果数据是存储在链表中的，算法也没问题
而且算法具有稳定性

算法在实现的时候多添加了一个标志位
用来指示当已经排序完毕的时候可以直接跳出循环，之后的多余循环就可以不用做了
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