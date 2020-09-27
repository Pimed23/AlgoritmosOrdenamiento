#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	cout << "running quicksort" << endl;
	system("javac QuickSort.java");
	system("java QuickSort");
	cout << "running merge" << endl;
	system("javac MergeSort.java");
	system("java MergeSort");	
}
