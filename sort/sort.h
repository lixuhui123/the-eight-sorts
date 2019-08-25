#pragma once
#include<stdio.h>
#include<stdlib.h>
void printfarray(int * arr, int n);
void sort(int *src, int n);
void MergeSort(int *src, int n);
 
void dealMergeSort(int *src, int* tmp, int  str, int  end);
void MergeSort(int *src, int n);
void swap(int* a, int*b);
int doublepointway1(int *src, int start, int end);
int doublepointway2(int *src, int start, int end);
void dealquicksort(int *src, int start, int end);
void quicksort(int *src, int n);
int digway(int* src, int strat, int end);