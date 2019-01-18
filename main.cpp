/*
经典排序算法的c++实现
1：冒泡排序
2：插入排序
3：希尔排序
4：选择排序
5：堆排序
6：快速排序
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
	int array[arrayMaxLen] = { 0 };
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
	bubble_sort(array, arrayMaxLen);  // 冒泡排序 ms

	// 停止计时
	clock_t end = clock();

	// 打印已经排序好的数组
	cout << "-----------------after sort------------------" << endl;
	for (int i = 0; i < arrayMaxLen; i++)
	{
		cout << setw(4) << array[i] << ' ';
		if (i!= 0 && i % 20 == 0)
			cout << endl;
	}

	// 打印排序算法消耗时间
	cout << endl << "time: " << static_cast<double>(end - start) << " ms" << endl;

	system("pause");
	return EXIT_SUCCESS; 
}