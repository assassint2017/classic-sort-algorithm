#include"sort.h"

/*
���������Ͱ���������������򣬼ȱ���Ҫ��֪ȡֵ���ܵĸ���
Ͱ����������������Զ����ȡֵ�����ĸ���
��������������ȡֵ����Զ�����������ĸ���
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
	// ��Ͱ
	queue *buckets = new queue[numBucket]();

	for (int p = 0; p < pass; p++)
	{
		// ÿһ�����ݽ�Ͱ
		for (int i = 0; i < n; i++)
		{
			listNode *tempNode = new listNode();
			tempNode->value = array[i];

			// ����������Ӧ��λ��Ӧ�÷ŵ���һ��Ͱ��
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

		// �����ݴ�Ͱ�����
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
	// �ͷŶ��ڴ�
	delete[] buckets;
}