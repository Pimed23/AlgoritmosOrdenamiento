#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	cout << "running insertion" << endl;
	system("g++ InsertSort.cpp -o insertsort");
	system("./insertsort");
	cout << "running selection" << endl;
	system("g++ SelectionSort.cpp -o selectionsort");
	system("./selectionsort");
}
