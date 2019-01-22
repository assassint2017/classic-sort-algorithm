/*
经典排序算法的c++实现
从小到大的排序
算法的耗时是三次实验的平均结果

1：冒泡排序
2：插入排序
3：希尔排序
4：选择排序
5：堆排序
6: 归并排序
7：快速排序
8：桶排序
9：基数排序
10：表排序
*/

#include<iostream>
#include<iomanip>
#include<time.h>
#include"sort.h"

using namespace std;

int main()
{
	// 定义数组的最大长度
	const int arrayMaxLen = 1e5;  

	// 初始化一个未排序的数组，数组中的每一个值是0~1000的整数
	int *array = new int[arrayMaxLen]();
	for (int i = 0; i < arrayMaxLen; i++)
		array[i] = rand() % 1000;
	
	// 打印未排序的数组
	cout << "-----------------before sort------------------" << endl;
	for (int i = 0; i < arrayMaxLen; i++)
	{
		cout << setw(4) << array[i] << ' ';
		if (i != 0 && i % 20 == 0)
			cout << endl;
	}

	// 开始计时
	clock_t start = clock();

	// 开始排序 
	// bubble_sort(array, arrayMaxLen);  // 冒泡排序 23889ms 
	// insertion_sort(array, arrayMaxLen);  // 插入排序 4587ms
	// shell_sort(array, arrayMaxLen);  // 希尔排序 12ms 
	// selection_sort(array, arrayMaxLen);  // 选择排序 7161ms
	// heap_sort(array, arrayMaxLen);  // 堆排序 15ms  
	// merge_sort_recursive(array, arrayMaxLen);  // 归并排序 递归版本 12.5ms 
	// merge_sort_nonrecursive(array, arrayMaxLen);  // 归并排序 非递归版本 9ms
	quick_sort(array, arrayMaxLen);  // 快速排序 8ms
	// bucket_sort(array, arrayMaxLen, 1000);  // 桶排序 25ms
	// radix_sort(array, arrayMaxLen, 6, 10); // 基数排序 142ms
	// int *table = table_sort(array, arrayMaxLen);  // 表排序 6780ms

	// 停止计时
	clock_t end = clock();

	// 打印已经排序好的数组
	cout << "-----------------after sort------------------" << endl;
	for (int i = 0; i < arrayMaxLen; i++)
	{
		cout << setw(4) << array[i] << ' ';
		if (i % 20 == 0)
			cout << endl;
	}

	//// 表排序 打印已经排序好的数组
	//cout << "-----------------after sort------------------" << endl;
	//for (int i = 0; i < arrayMaxLen; i++)
	//{
	//	cout << setw(4) << array[table[i]] << ' ';
	//	if (i % 20 == 0)
	//		cout << endl;
	//}

	// 打印排序算法消耗时间
	cout << endl << "time: " << static_cast<double>(end - start) << " ms" << endl;

	delete[] array;
	system("pause");
	return EXIT_SUCCESS; 
}