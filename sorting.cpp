/*
* Title: Sorting and Algorithm Efficiency
* Author: Hami Mert Doðan
* ID: 21802550
* Section: 3
* Assignment: 1
* Description: sorting class implemented by me (Hami Mert Doðan) to calculate efficiency of sorting algorithms.
*/

#include "sorting.h"
#include <iostream>
#include <random>
const int MAX_SIZE = 30000;

// Selection sort algorithm provided by the lecture slides.
void Sorting::selectionSort(int* arr, const int size, int& compCount, int& moveCount)
{
	for (int last = size - 1; last >= 1; --last) {
		int largest = indexOfLargest(arr, last + 1, compCount);
		int temp = arr[largest];
		arr[largest] = arr[last];
		arr[last] = temp;
		moveCount += 3;
	}
}

// indexOfLargest helper method provided by the lecture slides.
int Sorting::indexOfLargest(const int theArray[], int size, int& compCount)
{
	int indexSoFar = 0;
	for (int currentIndex = 1; currentIndex < size; ++currentIndex)
	{
		compCount++;
		if (theArray[currentIndex] > theArray[indexSoFar])
			indexSoFar = currentIndex;
	}
	return indexSoFar;
}

// merge sort initializer method
void Sorting::mergeSort(int* arr, const int size, int& compCount, int& moveCount)
{
	mergeSort(arr, 0, size - 1,compCount, moveCount);
}

// merge sort recursive method provided by lecture slides.
void Sorting::mergeSort(int* arr, int first, int last, int& compCount, int& moveCount)
{
	if (first < last) 
	{
		int mid = (first + last) / 2; 

		mergeSort(arr, first, mid, compCount, moveCount);

		mergeSort(arr, mid + 1, last, compCount, moveCount);

		merge(arr, first, mid, last, compCount, moveCount);
	}

}

// merge method provided by lecture slides.
void Sorting::merge(int arr[], int first, int mid, int last, int& compCount, int& moveCount)
{
	int tempArray[MAX_SIZE];
	int first1 = first; // beginning of first sub-array
	int last1 = mid; // end of first sub-array
	int first2 = mid + 1; // beginning of second sub-array
	int last2 = last; // end of second sub-array
	int index = first1; // next available location in tempArray

	for (; (first1 <= last1) && (first2 <= last2); ++index) 
	{
		compCount++;
		if (arr[first1] < arr[first2]) 
		{
			tempArray[index] = arr[first1];
			moveCount++;
			++first1;
		}
		else 
		{
			tempArray[index] = arr[first2];
			moveCount++;
			++first2;
		}
	}
	for (; first1 <= last1; ++first1, ++index)
	{
		tempArray[index] = arr[first1];
		moveCount++;
	}
	
	for (; first2 <= last2; ++first2, ++index)
	{
		tempArray[index] = arr[first2];
		moveCount++;
	}

	for (index = first; index <= last; ++index)
	{
		arr[index] = tempArray[index];
		moveCount++;
	}
}

// quicksort initializer method
void Sorting::quickSort(int* arr, const int size, int& compCount, int& moveCount)
{
	quickSort(arr, 0, size - 1, compCount, moveCount);
}

// quicksort recursive method provided by the lecture slides
void Sorting::quickSort(int* arr, int first, int last, int& compCount, int& moveCount)
{
	int pivotIndex;

	if (first < last) 
	{
		// create the partition: S1, pivot, S2
		partition(arr, first, last, pivotIndex, compCount, moveCount);

		// sort regions S1 and S2
		quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
		quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
	}
}

// partition method provided by the lecture slides
void Sorting::partition(int arr[], int first, int last, int& pivotIndex, int& compCount, int& moveCount)
{
	moveCount++;
	int pivot = arr[first];
	// initially, everything but pivot is in unknown
	int lastS1 = first; // index of last item in S1
	int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
	for (; firstUnknown <= last; ++firstUnknown) 
	{
		// move item from unknown to proper region
		compCount++;
		if (arr[firstUnknown] < pivot) 
		{
			// belongs to S1
			++lastS1;
			swap(arr[firstUnknown], arr[lastS1]);
			moveCount += 3;
		} // else belongs to S2
	}
	// place pivot in proper position and mark its location
	swap(arr[first], arr[lastS1]);
	moveCount += 3;
	pivotIndex = lastS1;
}

// radix sort method implemented according to the pseudocode given in the slides.
void Sorting::radixSort(int* arr, const int size)
{
	int digits = 0;
	int max = arr[0];
	// find the maximum number to sort all digits
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (int multiplier = 1; max / multiplier > 0; multiplier *= 10)
	{
		sortDigit(arr, size, multiplier);
	}
}

// helper method to sort digits
void Sorting::sortDigit(int* arr, const int size, int mul)
{
	int* resultArr = new int[size];
	int counts[10];
	// initialize all array elements to 0
	for (int i = 0; i < 10; i++)
	{
		counts[i] = 0;
	}
	// increment the digits according to their numbers
	for (int i = 0; i < size; i++)
	{
		counts[(arr[i] / mul) % 10]++;
	}
	// translate the indices to digits
	for (int i = 1; i < 10; i++)
	{
		counts[i] += counts[i - 1];
	}
	// fill the result array such that the original array is sorted by the digit given in the function call
	for (int i = size - 1; i >= 0; i--)
	{
		const int index = (arr[i] / mul) % 10;
		resultArr[counts[index] - 1] = arr[i];
		counts[index]--;
	}
	// make the original array digit-sorted array
	for (int i = 0; i < size; i++)
	{
		arr[i] = resultArr[i];
	}
}

// helper function to swap two integers
void Sorting::swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}