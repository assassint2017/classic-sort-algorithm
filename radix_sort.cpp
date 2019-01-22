#include"sort.h"

/*
基数排序和桶排序都属于特殊排序，既必须要已知取值可能的个数
桶排序适用于数据量远多于取值数量的个数
基数排序适用于取值数量远多于数据量的个数
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

struct queue
{
	listNode *front;
	listNode *rear;

	queue()
	{
		front = nullptr;
		rear = nullptr;
	}
};

void radix_sort(int array[], int n, int pass, int numBucket)
{
	// 建桶
	queue *buckets = new queue[numBucket]();

	for (int p = 0; p < pass; p++)
	{
		// 每一个数据进桶
		for (int i = 0; i < n; i++)
		{
			listNode *tempNode = new listNode();
			tempNode->value = array[i];

			// 计算数据相应的位数应该放到哪一个桶中
			int bucketIndex = array[i];
			for (int j = 0; j < p; j++)
				bucketIndex /= 10;
			bucketIndex %= 10;

			if (!buckets[bucketIndex].rear)
			{
				buckets[bucketIndex].front = tempNode;
				buckets[bucketIndex].rear = tempNode;
			}
			else
			{
				buckets[bucketIndex].rear->next = tempNode;
				buckets[bucketIndex].rear = tempNode;
			}
		}

		// 将数据从桶中输出
		for (int i = 0, j = 0; i < numBucket; i++)
		{
			while (buckets[i].front)
			{
				listNode *tempNode = buckets[i].front;
				array[j++] = tempNode->value;

				buckets[i].front = tempNode->next;

				delete tempNode;
			}
			buckets[i].rear = nullptr;
		}
	}
	// 释放堆内存
	delete[] buckets;
}