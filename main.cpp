/*
* Title: Sorting and Algorithm Efficiency
* Author: Hami Mert Doðan
* ID: 21802550
* Section: 3
* Assignment: 1
* Description: main class implemented by me (Hami Mert Doðan) to calculate efficiency of sorting algorithms.
*/
#include <iomanip>
#include <iostream>
#include <ctime>
#include "sorting.h"

void displayArray(const int* arr, const int size);
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size);
void performanceAnalysis();
void createSortAndTime(int size, int sortChoice, int randomnessChoice);

int main()
{
	int arr[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	int arr2[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	int arr3[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	int arr4[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	
	int comps = 0;
	int moves = 0;
	Sorting k;
	std::cout << "SELECTION SORT" << std::endl;
	k.selectionSort(arr, 16, comps, moves);
	displayArray(arr, 16);
	std::cout << "Comparisons:" << comps << " Moves: " << moves << std::endl;
	
	comps = 0;
	moves = 0;
	std::cout << "MERGE SORT" << std::endl;
	k.mergeSort(arr2, 16, comps, moves);
	displayArray(arr2, 16);
	std::cout << "Comparisons:" << comps << " Moves: " << moves << std::endl;
	
	comps = 0;
	moves = 0;
	std::cout << "QUICK SORT" << std::endl;
	k.quickSort(arr3, 16, comps, moves);
	displayArray(arr3, 16);
	std::cout << "Comparisons:" << comps << " Moves: " << moves << std::endl;
	
	std::cout << "RADIX SORT" << std::endl;
	k.radixSort(arr4, 16);
	displayArray(arr4, 16);
	
	return 0;
}

// function to display an array with given size.
void displayArray(const int* arr, const int size)
{
	std::cout << "Contents of the array: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

// function to create random arrays with no particular order
void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		int randomNumber = rand() % size;
		arr1[i] = randomNumber;
		arr2[i] = randomNumber;
		arr3[i] = randomNumber;
		arr4[i] = randomNumber;
	}
}

// function to create random arrays with ascending order
void createAscendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size)
{
	srand(time(0));
	arr1[0] = 1;
	arr2[0] = 1;
	arr3[0] = 1;
	arr4[0] = 1;
	for (int i = 1; i < size; i++)
	{

		int randomNumber = rand() % size + 1; // + 1 is to not get 0 from the R.N.G.
		arr1[i] = randomNumber + arr1[i - 1];
		arr2[i] = randomNumber + arr2[i - 1];
		arr3[i] = randomNumber + arr3[i - 1];
		arr4[i] = randomNumber + arr4[i - 1];
	}
}

// function to create random arrays with descending order
void createDescendingArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size)
{
	srand(time(0));
	arr1[size - 1] = 1;
	arr2[size - 1] = 1;
	arr3[size - 1] = 1;
	arr4[size - 1] = 1;
	for (int i = size - 2; i >= 0; i--)
	{

		int randomNumber = rand() % size + 1; // + 1 is to not get 0 from the R.N.G.
		arr1[i] = randomNumber + arr1[i + 1];
		arr2[i] = randomNumber + arr2[i + 1];
		arr3[i] = randomNumber + arr3[i + 1];
		arr4[i] = randomNumber + arr4[i + 1];
	}
}

// performance analysis method to analyze the sorting algorithms.
void performanceAnalysis()
{
	int arraySizes[] = { 6000, 10000, 14000, 18000, 22000, 26000, 30000 };
	std::cout << "-------------------------------------------\n";
	std::cout << "Analysis of Selection Sort\n";
	std::cout << "                    Array Size\tElapsed Time\tcompCount\tmoveCount\n";
	std::cout << "Random Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 1, 1);
	}
	std::cout << "Ascending Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 1, 2);
	}
	std::cout << "Descending Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 1, 3);
	}
	std::cout << "-------------------------------------------\n";
	std::cout << "Analysis of Merge Sort\n";
	std::cout << "                    Array Size\tElapsed Time\tcompCount\tmoveCount\n";
	std::cout << "Random Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 2, 1);
	}
	std::cout << "Ascending Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 2, 2);
	}
	std::cout << "Descending Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 2, 3);
	}
	std::cout << "-------------------------------------------\n";
	std::cout << "Analysis of Quick Sort\n";
	std::cout << "                    Array Size\tElapsed Time\tcompCount\tmoveCount\n";
	std::cout << "Random Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 3, 1);
	}
	std::cout << "ASCENDING AND DESCENDING ORDER WITH QUICKSORT CAUSES STACK OVERFLOW ERROR\n";
	std::cout << "-------------------------------------------\n";

	std::cout << "Analysis of Radix Sort\n";
	std::cout << "                    Array Size\tElapsed Time\n";
	std::cout << "Random Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 4, 1);
	}
	std::cout << "Ascending Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 4, 2);
	}
	std::cout << "Descending Order:\n";
	for (int i = 0; i < 7; i++)
	{
		createSortAndTime(arraySizes[i], 4, 3);
	}
}

/* helper function to the performance analysis method that takes the size, which sort to use and the default-sort choice.
* sortChoice varies from 1 to 4, 1 = selection sort, 2 = merge sort, 3 = quick sort, other inputs make radix sort
* randomness choice varires from 1 to 3, 1 = random order, 2 = ascending, 3 = descending
*/
void createSortAndTime(int size, int sortChoice, int randomnessChoice)
{
	Sorting s;
	if (sortChoice == 1)
	{
		int comps = 0;
		int moves = 0;
		int* arr = new int[size];
		if (randomnessChoice == 1) {
			createRandomArrays(arr, arr, arr, arr, size);
		}
		else if (randomnessChoice == 2) {
			createAscendingArrays(arr, arr, arr, arr, size);
		}
		else
		{
			createDescendingArrays(arr, arr, arr, arr, size);
		}
		double duration;
		clock_t startTime = clock();
		s.selectionSort(arr, size, comps, moves);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		std::cout << "                    " << std::setw(10) << size << "\t" << std::setw(12) << duration << " ms\t"
			<< std::setw(9) << comps << "\t" << moves << std::endl;
		delete[] arr;
	}
	else if (sortChoice == 2)
	{
		int comps = 0;
		int moves = 0;
		int* arr = new int[size];
		if (randomnessChoice == 1) {
			createRandomArrays(arr, arr, arr, arr, size);
		}
		else if (randomnessChoice == 2) {
			createAscendingArrays(arr, arr, arr, arr, size);
		}
		else
		{
			createDescendingArrays(arr, arr, arr, arr, size);
		}
		double duration;
		clock_t startTime = clock();
		s.mergeSort(arr, size, comps, moves);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		std::cout << "                    " << std::setw(10) << size << "\t" << std::setw(12) << duration << " ms\t"
			<< std::setw(9) << comps << "\t" << moves << std::endl;
		delete[] arr;
	}
	else if (sortChoice == 3)
	{
		int comps = 0;
		int moves = 0;
		int* arr = new int[size];
		if (randomnessChoice == 1)
		{
			createRandomArrays(arr, arr, arr, arr, size);
		}
		else if (randomnessChoice == 2)
		{
			createAscendingArrays(arr, arr, arr, arr, size);
		}
		else
		{
			createDescendingArrays(arr, arr, arr, arr, size);
		}
		double duration;
		clock_t startTime = clock();
		s.quickSort(arr, size, comps, moves);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		std::cout << "                    " << std::setw(10) << size << "\t" << std::setw(12) << duration << " ms\t"
			<< std::setw(9) << comps << "\t" << moves << std::endl;
		delete[] arr;
	}
	else
	{
		int* arr = new int[size];
		if (randomnessChoice == 1) {
			createRandomArrays(arr, arr, arr, arr, size);
		}
		else if (randomnessChoice == 2) {
			createAscendingArrays(arr, arr, arr, arr, size);
		}
		else
		{
			createDescendingArrays(arr, arr, arr, arr, size);
		}
		double duration;
		clock_t startTime = clock();
		s.radixSort(arr, size);
		duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
		std::cout << "                    " << std::setw(10) << size << "\t" << std::setw(12) << duration << " ms" << std::endl;
		delete[] arr;
	}
}