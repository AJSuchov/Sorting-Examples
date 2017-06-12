// hw5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <random>
#include <array>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <algorithm>

typedef std::chrono::high_resolution_clock Clock;


//Function prototypes
int * bubbleSort(int[], int);
void printArray(int[], int);
int randomGenerator(int, int);
void InsertionSort(int[], int);
void MergeSort(int[], int, int);
void QuickSort(int[], int, int);
void heapSort(int [], int );
void countingSort(int[], int);
void radixSort(int [], int );

const int n = 10; //Hardcode for testing

using namespace std;

int main()
{
	int arrTen[n]; //Sets up an array

	//Individual Arrays
	int arrBub[n];
	int arrMerg[n];
	int arrInert[n];
	int arrQuick[n];
	int arrHeap[n];
	int arrCount[n];
	int arrRadix[n];

	for (int i = 0; i < n; i++) {
		arrTen[i] = randomGenerator(n*2, 1); //Sets array spot equal to the random number generated
	}
	
	//////////////////////////////////////////////////////
	//Dont look at this section.....
	for (int i = 0; i < n; i++) {
		arrBub[i] = arrTen[i];
		arrMerg[i] = arrTen[i];
		arrInert[i] = arrTen[i];
		arrQuick[i] = arrTen[i];
		arrHeap[i] = arrTen[i];
		arrCount[i] = arrTen[i];
		arrRadix[i] = arrTen[i];
	}
	//////////////////////////////////////////////////////


	//Look at this section
	//Calls all the functions and uses the time
	

	//printArray(arrTen, n);
	cout << "BubbleSort" << endl;
	auto t1 = Clock::now();
	bubbleSort(arrBub, n);
	auto t2 = Clock::now();
	std::cout << "Delta t2-t1: "
	<< std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
	<< " nanoseconds" << std::endl;
	cout << endl;
	cout << endl;
	
	cout << "InsertionSort" << endl;
	auto t3 = Clock::now();
	InsertionSort(arrInert, n);
	auto t4 = Clock::now();
	std::cout << "Delta t4-t3: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count()
		<< " nanoseconds" << std::endl;
	cout << endl;
	cout << endl;

	cout << "Merge Sort" << endl;
	auto t5 = Clock::now();
	MergeSort(arrMerg, 0, n-1);
	auto t6 = Clock::now();
	std::cout << "Delta t6-t5: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count()
		<< " nanoseconds" << std::endl;
	cout << endl;
	cout << endl;

	cout << "QuickSort" << endl;
	auto t7 = Clock::now();
	QuickSort(arrQuick, 0, n-1);
	auto t8 = Clock::now();
	std::cout << "Delta t8-t7: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count()
		<< " nanoseconds" << std::endl;
	cout << endl;

	cout << "Heap Sort" << endl;
	auto t9 = Clock::now();
	heapSort(arrHeap, n);
	auto t10 = Clock::now();
	std::cout << "Delta t10-t9: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t10 - t9).count()
		<< " nanoseconds" << std::endl;
	cout << endl;

	cout << "Radix" << endl;
	auto t13 = Clock::now();
	radixSort(arrRadix, n);
	auto t14 = Clock::now();
	std::cout << "Delta t14-t13: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t14 - t13).count()
		<< " nanoseconds" << std::endl;
	cout << endl;

	cout << "Counting Sort" << endl;
	auto t11 = Clock::now();
	countingSort(arrCount, n);
	auto t12 = Clock::now();
	std::cout << "Delta t12-t11: "
		<< std::chrono::duration_cast<std::chrono::nanoseconds>(t12 - t11).count()
		<< " nanoseconds" << std::endl;
	cout << endl;

	return 0;
}

int randomGenerator(int len, int start) {
	//This was taken from
	//https://msdn.microsoft.com/en-us/library/bb982398.aspx
	//Because my rand % 20 + 1 kept returning the same random numbers every time the function was run
	random_device rd;   // non-deterministic generator  
	mt19937 gen(rd());  // to seed mersenne twister.  
	uniform_int_distribution<> dist(start, len); //Returns a random number
	return dist(gen);
}

void printArray(int arr[], int len) { //Basic Print array function (Trivial)
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int  * bubbleSort(int arr[], int len) {
	int tempHold; //Temp Holder
	for (int i = 0; i < len; i++) { //The number of times to initiate the loop
		for (int n = 0; n < len - i - 1; n++) { //The actual spots in the array being compared using for loop
			if (arr[n] > arr[n + 1]) { //To check if the spot is smaller than next spot  
				tempHold = arr[n]; //If yes then assign tempHold to the smaller compared item
				arr[n] = arr[n + 1]; //Set the spot of larger spot to the smaller value of the comparison
				arr[n + 1] = tempHold; //Set the spot that was smaller equal to the tempHold that held the larger value
			}
		}
	}
	//printArray(arr, len); //Prints new array
	return arr;
}


void InsertionSort(int arr[], int len) {
	int TempVal; //Temporary Holder Val
	int CompVal; //The comparing Value spot
	for (int i = 1; i < len; i++) { //Runs the length of the array
		TempVal = arr[i]; //Sets the temp value to the second spot in the array
		CompVal = i - 1; //Sets the compare value starter spot behind the temp value
		while (CompVal >= 0 && arr[CompVal] > TempVal) { //Makes sure the compare value start spot is above zero and the array value is greater than the temp value
			arr[CompVal + 1] = arr[CompVal]; //While above is true, set the next spot for comparing equal to the current spot 
			CompVal = CompVal - 1; //Keep moving down the list in the opposite direction
		}
		arr[CompVal + 1] = TempVal; //Once its done go on to the next spot and set equal to temp value
	}
	//printArray(arr, len);
}

void mergeNums(int arr[], int start, int mid, int last) {
	int arr1[n]; //Sets a temporary array
	int middle = mid + 1; //sets a middle number to the sent in middle + 1
	int left = start; //Sets the left itterator to the first element
	int right = last; //Sets the right iterator to the last element
	int hold = left; //Sets a holding value to left

	while (left <= mid && middle <= right) { //While left is less than middle number and right is greater than middle + 1
		if (arr[left] <= arr[middle]) {//If the left spot in the array is less than the item in the middle element
			arr1[hold++] = arr[left++]; //The temporary array is set to the spot in original array
		}else{
			arr1[hold++] = arr[middle++]; //The temporary array is set to the middle spot
		}
	}
	while (left <= mid) { //While the left itterator is less than middle
		arr1[hold++] = arr[left++]; //The temporary array equals the left numbers of the original array
	}
	while (middle <= right) { //While middle + 1 is less than the right most number
		arr1[hold++] = arr[middle++]; //The temporary array equals the left most right item upto last in array
	}
	for (int s = start; s <= last; s++) { //Sets the original array back to the items in the temporary array
		arr[s] = arr1[s];
	}

	//printArray(arr, n);
}


void MergeSort(int arr[],int start, int end) {
	if (start < end) {
		int mid = (start+end)/2; //Gets middle of the array
		MergeSort(arr, start, mid); //Sorts everything in left of array
		MergeSort(arr, mid + 1, end); //Sorts everything right of array
		mergeNums(arr, start, mid, end); //merges it into one final array
	}
}

//Quick Sort Function 
int sortStart(int arr[], int spot1, int spot2) { //This creates the seperate sections for either below, equal, or greater than the pivot
	int pivot = arr[spot2]; //Pivot compare variable is equal to array spot
	int small = spot1 - 1; //The smaller number starts at 1 - start spot

	for (int i = spot1; i < spot2; i++) { //for the itterations from below to the value of spot2
		if (arr[i] <= pivot) { //check if the array value at spot1 is less than spot2
			small++; //Add 1 to small 
			swap(arr[i], arr[small]); //swap the values of array value and where the small itterator is at
		}
	}
	swap(arr[spot2], arr[small + 1]); //Swap the spots again
	return small + 1; //Return the itterator + 1
}

void QuickSort(int arr[], int start, int end) { //Where the recurrsion occurs
	if (start < end) { //If start is less than end
		int pos = sortStart(arr, start, end); //The position equals the values that will be sorted
		QuickSort(arr, start, pos - 1); //Quick sort for all values less than pivot
		QuickSort(arr, pos + 1, end);//Quick sort all values equal or greater than pivot
	}
}

//Heap Sort
void heapify(int arr[], int heapSize, int node)
{
	int largest = node; // Set the root
	int left = 2 * node + 1;
	int right = 2 * node + 2;

	// If the left child node is larger than the root node
	if (left < heapSize && arr[left] > arr[largest])
		largest = left;

	// If the right child is greater than the largest
	if (right < heapSize && arr[right] > arr[largest])
		largest = right;

	// If the largest is not the root
	if (largest != node)
	{
		swap(arr[node], arr[largest]);

		// Recursively heapify the sub-tree
		heapify(arr, heapSize, largest);
	}
}


void heapSort(int arr[], int heapSize)
{
	// Build the heap
	for (int node = heapSize / 2 - 1; node >= 0; node--)
		heapify(arr, heapSize, node);

	// Extract from the heap
	for (int node = heapSize - 1; node >= 0; node--)
	{
		swap(arr[0], arr[node]);

		// Recursively heapify reduced heap
		heapify(arr, node, 0);
	}
}


//Counting Sort
void countingSort(int arr[], int size) {

	int output[n]; //create output array 
	int count[n];  

	memset(count, 0, sizeof(count)); //initialize count[] with zero 

									 //input array element is the index of count array 
	for (int i = 0; i<size; i++) {
		count[arr[i]]++;
	}

	//Modify count array so each element stores sum of previous counts
	for (int i = 1; i<size; i++) {
		count[i] += count[i - 1];
	}

	//Build output array
	for (int i = 0; i < size; i++) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	//copy output array into input array arr[] 
	for (int i = 0; i<size; i++) {
		arr[i] = output[i];
	}
	printArray(arr, n);
}


//Radix Sort
int getMax(int arr[], int n) //Find max value in an array
{
	int maxval = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > maxval)
			maxval = arr[i];
	return maxval;
}

void countingSort(int arr[], int m, int exp)
{
	int output[n]; // Create the output array
	int i, count[10] = { 0 };

	//Storing the occurrences in count
	for (i = 0; i < m; i++)
		count[(arr[i] / exp) % 10]++;

	//Change count to contain position of value in the output array
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	//Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	//Copy output array into input array arr[]
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

//Radix Sort function
void radixSort(int arr[], int n)
{
	int m = getMax(arr, n);

	//Counting sort
	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSort(arr, n, exp);
}
