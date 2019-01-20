#include"sort.h"

/*
算法的思想类似于抽牌，每次抽出一张牌，然后向一个
已经排好序的序列中插入到一个正确的位置

由于冒泡排序中，交换一个元素需要三步操作，插入排序只需要一次，因此速度上还是要快很多的

最好情况 O(n)
最坏情况 O(n2)
算法同样是稳定的
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