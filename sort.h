#ifndef  SORT_H
#define SORT_H

#include<iostream>
#include<cmath>

void bubble_sort(int array[], int n);
void insertion_sort(int array[], int n);
void shell_sort(int array[], int n);
void selection_sort(int array[], int n);
void heap_sort(int array[], int n);
void merge_sort_recursive(int array[], int n);
void merge_sort_nonrecursive(int array[], int n);
void quick_sort(int array[], int n);
void bucket_sort(int array[], int n, int numBucket);
void radix_sort(int array[], int n, int pass, int numBucket);
int* table_sort(int array[], int n);

#endif // ! SORT_H
