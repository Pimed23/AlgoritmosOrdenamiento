#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	cout << "running insert" << endl;
	system("python3 InsertSort.py");
	cout << "running selection" << endl;
	system("python3 SelectionSort.py");
	cout << "running merge" << endl;
	system("python3 MergeSort.py");
	cout << "running heap" << endl;
	system("python3 HeapSort.py");
	cout << "running quick" << endl;
	system("python3 QuickSort.py");
}
