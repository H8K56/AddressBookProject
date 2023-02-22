/** \file QuickSortExample.cpp
*  \brief     Small example of using quickSort
*  \details   Small example of using quickSort to sort the elements of an array and record the time it takes
*  \author    Harald Gjermundrod
*  \version   0.1
*  \date      2017-2017
*  \bug       No bugs so far
*  \copyright University of Nicosia.
*/
#include <iostream>
#include <chrono>
#include <ctime>
#include <cassert>

using namespace std;

const int MAX_NUM = 5000;
const bool SHOW_NUMBERS = true;

void fillArray(long nums[], const int size);
void quickSort(long nums[], const int left, const int right);
int partition(long nums[], const int left, const int right);

/**
*  Function main is the driver of the program
*  @return Returns <code>0</code>
*/
int main() {
	int startTime, endTime;
	long numbers[MAX_NUM];

	srand(time(NULL));

	//startTime = time(NULL); // Resolution seconds
	startTime = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count(); // Resolution milliseconds

	fillArray(numbers, MAX_NUM);

	if (SHOW_NUMBERS) { // Also print out the numbers to the screen, may affect the accuracy of timings between runs
		cout << "\nUnsorted: ";
		for (int i = 0; i < MAX_NUM; ++i)
			cout << " " << numbers[i];
	}

	quickSort(numbers, 0, MAX_NUM - 1);

	if (SHOW_NUMBERS) { // Also print out the numbers to the screen, may affect the accuracy of timings between runs
		cout << "\nSorted: ";
		for (int i = 0; i < MAX_NUM; ++i)
			cout << " " << numbers[i];
	}

	//endTime = time(NULL); // Resolution seconds
	endTime = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count(); // Resolution milliseconds

	cout << "\nTime spent in iterative is: " << endTime - startTime;

	return 0;
}

/**
* Function <code>fillArray</code> fills in the array with random numbers
* <BR>
* @param nums The array that will contain the numbers
* @param size The size of the array
*/
void fillArray(long nums[], const int size){
	assert(size > 0);

	for (int i = 0; i < size; ++i)
		nums[i] = rand() % 100000;
}

/**
* Function <code>partition</code> splits the array into two half, around the pivot value.
* <BR>
* @param nums The array that contain the numbers
* @param left The left index
* @param right The right index
*/
int partition(long nums[], const int left, const int right){
	int i = left, j = right;
	long tmp;
	long pivot = nums[(left + right) / 2];

	// partition
	while (i <= j) {
		while (nums[i] < pivot)
			++i;
		while (nums[j] > pivot)
			--j;
		if (i <= j) {
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
			++i;
			--j;
		}
	}
	return i;
}

/**
* Function <code>quickSort</code> sorts the values in the array
* <BR>
* @param nums The array that contain the numbers
* @param left The left index
* @param right The right index
*/
void quickSort(long nums[], const int left, const int right){
	assert(left >= 0 && right > left);

	int idx = partition(nums, left, right);

	// recursion
	if (left < idx - 1)
		quickSort(nums, left, idx - 1);
	if (idx < right)
		quickSort(nums, idx, right);
}