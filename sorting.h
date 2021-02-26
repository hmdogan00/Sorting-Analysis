/*
* Title: Sorting and Algorithm Efficiency
* Author: Hami Mert Doðan
* ID: 21802550
* Section: 3
* Assignment: 1
* Description: sorting class' header implemented by me (Hami Mert Doðan) to calculate efficiency of sorting algorithms.
*/
#pragma once
class Sorting
{
public:
	void selectionSort(int* arr, const int size, int& compCount, int& moveCount);
	int indexOfLargest(const int theArray[], int size, int& compCount);
	void mergeSort(int* arr, const int size, int& compCount, int& moveCount);
	void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount);
	void merge(int arr[], int first, int mid, int last, int&compCount, int& moveCount);
	void quickSort(int* arr, const int size, int& compCount, int& moveCount);
	void quickSort(int* arr, int first, int last, int& compCount, int& moveCount);
	void partition(int arr[], int first, int last, int& pivotIndex, int& compCount, int& moveCount);
	void radixSort(int* arr, const int size);
	void sortDigit(int* arr, const int size, int mul);
	void swap(int& x, int& y);
	
private:
};

