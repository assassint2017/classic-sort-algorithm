#include"sort.h"

/*
桶排序是一种特殊的排序，算法适用于数值可能性已知，并且这个数量是要远远小于数据的数量的
此时的算法复杂度有可能达到最快的线性

由于本工程中的模拟数据数据量是十万 取值可能性只有1000，所以符合算法的使用条件

但是在实际的实验中，调整取值为10 100 1000 10000，对速度的影响不大，而且并没有快速排序快
如果取值和数据量相等都是十万的时候，速度就下降了一倍
如果取值比数据量小十倍的时候，速度下降了进十倍e

可见取值对于算法性能的影响
*/

struct listNode
{
	int value;
	listNode *next;

	listNode()
	{
		value = 0;
		next = nullptr;
	}
};

void bucket_sort(int array[], int n, int numBucket)
{
	// 建桶
	listNode *buckets = new listNode[numBucket]();

	// 每一个数据进桶
	for (int i = 0; i < n; i++)
	{
		listNode *tempNode = new listNode();
		tempNode->value = array[i];
		tempNode->next = buckets[array[i]].next;
		buckets[array[i]].next = tempNode;
	}

	// 将数据从桶中输出
	for (int i = 0, j = 0; i < numBucket; i++)
	{
		while (buckets[i].next)
		{
			listNode *tempNode = buckets[i].next;
			array[j++] = tempNode->value;

			buckets[i].next = tempNode->next;

			delete tempNode;
		}
	}

	// 释放堆内存
	delete[] buckets;
}