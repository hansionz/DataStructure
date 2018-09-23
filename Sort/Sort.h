#ifndef __SORT_H__
#define __SORT_H__

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>

void InsertSort(int *num, int len);
void InsertSort_op(int arr[], int len);
void ShellSort(int *num, int len);
void SelectSort(int* num, int len);
void SelectSort_op(int* num, int len);
void HeapSort(int* num, int len);
void BubbleSort(int* num, int len);
void QuickSort(int* num, int left, int right);
void QuickSortNonR(int* num, int left, int right);
void MergeSort(int* num, int len);

#endif  //__SORT_H__