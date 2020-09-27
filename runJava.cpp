#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	cout << "running insertion" << endl;
	system("javac InsertSort.java");
	system("java InsertSort");
	cout << "running selection" << endl;
	system("javac BubbleSort.java");
	system("java BubbleSort");
	cout << "running selection" << endl;
	system("javac SelectionSort.java");
	system("java SelectionSort");
	cout << "running heap" << endl;
	system("javac HeapSort.java");
	system("java HeapSort");
	cout << "running quicksort" << endl;
	system("javac QuickSort.java");
	system("java QuickSort");
	cout << "running merge" << endl;
	system("javac MergeSort.java");
	system("java MergeSort");	
}
