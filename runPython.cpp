#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	cout << "running bubble" << endl;
	system("python3 BubbleSort.py");
	cout << "running insertion" << endl;
	system("python3 InsertionSort.py");
	cout << "running selection" << endl;
	system("python3 SelectionSort.py");
	cout << "running merge" << endl;
	system("python3 MergeSort.py");
	cout << "running heap" << endl;
	system("python3 HeapSort.py");
}
