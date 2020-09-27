#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	cout << "running bubble" << endl;
	system("g++ BubbleSort.cpp -o bubblesort");
	system("./bubblesort");
	cout << "running insertion" << endl;
	system("g++ InsertionSort.cpp -o insertionsort");
	system("./insertionsort");
	cout << "running selection" << endl;
	system("g++ SelectionSort.cpp -o selectionsort");
	system("./selectionsort");
	cout << "running count" << endl;
	system("g++ CountSort.cpp -o countsort");
	system("./countsort");
	cout << "running merge" << endl;
	system("g++ MergeSort.cpp -o mergesort");
	system("./mergesort");
	cout << "running quick" << endl;
	system("g++ QuickSort.cpp -o quicksort");
	system("./quicksort");
	cout << "running heap" << endl;
	system("g++ HeapSort.cpp -o heapsort");
	system("./heapsort");
}
