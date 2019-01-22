#include"sort.h"

/*
Ͱ������һ������������㷨��������ֵ��������֪���������������ҪԶԶС�����ݵ�������
��ʱ���㷨���Ӷ��п��ܴﵽ��������

���ڱ������е�ģ��������������ʮ�� ȡֵ������ֻ��1000�����Է����㷨��ʹ������

������ʵ�ʵ�ʵ���У�����ȡֵΪ10 100 1000 10000�����ٶȵ�Ӱ�첻�󣬶��Ҳ�û�п��������
���ȡֵ����������ȶ���ʮ���ʱ���ٶȾ��½���һ��
���ȡֵ��������Сʮ����ʱ���ٶ��½��˽�ʮ��e

�ɼ�ȡֵ�����㷨���ܵ�Ӱ��
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
	// ��Ͱ
	listNode *buckets = new listNode[numBucket]();

	// ÿһ�����ݽ�Ͱ
	for (int i = 0; i < n; i++)
	{
		listNode *tempNode = new listNode();
		tempNode->value = array[i];
		tempNode->next = buckets[array[i]].next;
		buckets[array[i]].next = tempNode;
	}

	// �����ݴ�Ͱ�����
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

	// �ͷŶ��ڴ�
	delete[] buckets;
}