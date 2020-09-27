#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>
using namespace std;

// FUNCTION'S PROTOTYPE
void countSort( int *, int );
int max(int *, int);
int min(int *, int);
// MAIN FUNCTION
int main() {
    int tam[] = {15000, 30000, 45000, 60000, 75000, 90000, 105000, 120000, 135000, 150000};
    FILE *in, *out;
    unsigned t0, t1;

    for(int i = 0; i < 10; ++i) {
        char fileIn[] = "Entradas/test_Counting.txt";
        fileIn[13] = i + 48;

        char fileOut[] = "Salidas/CountSort/cpp_out_.txt";
        fileOut[26] = i + 48;

        out = fopen(fileOut, "w");
        for(int j = 0; j < 10; ++j) {
            int *arr = new int[tam[j]+1];
            char *lineBuff = NULL;
            size_t lineBuffSize = 0;
            ssize_t lineSize;
            int lineCount = 0;
            
            in = fopen(fileIn, "r");
            if(!in) {
                fprintf(stderr, "Error opening file '%s'\n", fileIn);
                return EXIT_FAILURE;
            }
            
            lineSize = getline(&lineBuff, &lineBuffSize, in);

            while(lineSize >= 0 && lineCount <= tam[j]) {
                arr[lineCount] = atoi(lineBuff);
                lineSize = getline(&lineBuff, &lineBuffSize, in);
                ++lineCount;
            }

            free(lineBuff);
            lineBuff = NULL;
            t0 = clock();
            countSort(arr, tam[j]);
            t1 = clock();
            double time = (double(t1 - t0) / CLOCKS_PER_SEC);
            
            fprintf(out, "%i %lf\n", tam[j], time);
            printf("%i %lf\n", tam[j], time);
            delete[] arr;
            fclose(in);
        }   
        fclose(out);
    }
    return 0;
}

// FUNCTION'S DEFINITION
int max(int *array, int size){
	int maxNumber = array[1];
	for(int i=2; i <= size; i++){
		if(array[i] > maxNumber)
		       maxNumber = array[i];	
	}
	return maxNumber;
}

int min(int *array, int size){
	int minNumber = array[0];
	for(int i=1; i < size; i++){
		if(array[i] < minNumber)
			minNumber = array[i];
	}
	return minNumber;
}
void countSort(int *array, int size) {
	int output[size + 1];
	int maxNumber = max(array, size); 
	int count[maxNumber + 1];

	for (int i = 0; i <= maxNumber; i++)
		count[i] = 0;

	for (int i = 1;	i <= size; i++)
		count[array[i]]++;

	for (int i = 1; i <= maxNumber; i++)
		count[i] += count[i-1];

	for (int i = size; i >= 1; i--){
		output[count[array[i]]] = array[i];
		count[array[i]] -= 1;
	}

	for(int i= 1; i <= size; i++)
		array[i] = output[i];
}
