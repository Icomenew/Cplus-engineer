/***************************************************************************
*Copyright (c) 2017,Wuhan
*All rights reserved.
*
*filename: sort-Alg.cpp
*description: eight classic sort algorithm
*			  直接插入(Straight Insertion Sort)、希尔排序(Shell`s Sort)、简单选择(Simple Selection Sort)、
*			  堆排序(Heap Sort)、冒泡(Bubble Sort、快排(Quick Sort、归并(Merge Sort)、桶排序/基数排序(Radix Sort)
*
*@Version：V1.0
*@author：Frank Liu
*@time：20180416
*
*Change record 1: // Change history record, including modification date, version number, modification person and modification contents
*change-time      version          change-author         change-content

* 20180416         V1.0              Frank                  create
*******************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/**************************************************************
 *
 * 插入排序——直接插入排序(Straight Insertion Sort)
 * 时间复杂度：O(n) = 2^n
 *
***************************************************************/
void InsertSort(int arr[], int n)
{
	int i, j, temp;
	
	for (i = 1; i<n; ++i)
	{
		temp = arr[i];    //设置哨兵，标记数组边界
		for(j = i-1; j>=0 && temp<arr[j]; --j)
		{
			arr[j+1] = arr[j];   //向后移动元素一格
		}
		arr[j+1] = temp;   //插入到正确位置
	}
}

/**************************************************************
 *
 * 插入排序——希尔排序(Shell's Sort) or 缩小增量排序
 * 时间复杂度：不确定
 * 不稳定的排序。
 *
***************************************************************/
void ShellInsertSort(int arr[], int n, int dk)
{
	for(int i=dk; i<n; ++i)
	{
		if(arr[i] < arr[i-dk])  //若第i个元素大于i-1元素，直接插入;小于的话，移动有序表后插入.
		{
			int temp = arr[i];   //设置哨兵
			//arr[i] = arr[i-dk];   //首先后移一个元素
			//直接插入排序
			int j=i-dk;
			for(; j>=0 && temp < arr[j]; j-=dk)
			{
				arr[j+dk] = arr[j];
			}
			arr[j+dk] = temp;
		}
	}
}
//缩小增量迭代
void ShellSort(int arr[], int n)
{
	for(int dk = n/2; dk >= 1; dk/=2)
		ShellInsertSort(arr, n, dk);
}



/**
 * 输出数组元素
*/
void printArray(int arr[], int n)
{
	for(int i=0; i<n; ++i)
		cout << arr[i] << " ";
	cout<<endl;
}

int main()
{
	int a[] = {7,4,5,2,0,6,5,42,32,1,1,23};
	InsertSort(a, 12);
	printArray(a, 12);
	int b[] = {5,3,95,0,12,4,5,7,66,20,3,3,45};
	ShellSort(b, 13);
	printArray(b, 13);
	
	return 0;
}
