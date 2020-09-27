#include <stdio.h>
#include <stdlib.h>
#include <ctime>

// FUNCTION'S PROTOTYPE
void heapify(int *, int, int);
void heapSort( int *, int );
void swap(int &, int &);
// MAIN FUNCTION
int main() {
    int tam[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    FILE *in, *out;
    unsigned t0, t1;

    for(int i = 0; i < 10; ++i) {
        char fileIn[] = "Entradas/test_.txt";
        fileIn[13] = i + 48;

        char fileOut[] = "Salidas/HeapSort/cpp_out_.txt";
        fileOut[26] = i + 48;

        out = fopen(fileOut, "w");
        for(int j = 0; j < 10; ++j) {
            int *arr = new int[tam[j]];
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
            heapSort(arr, tam[j]);
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
void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void heapify ( int * array, int size, int indice){
	int largest = indice;
	int l = 2 * indice + 1;
	int r = 2 * indice + 2;

	if(l < size && array[l] > array[largest])
			largest = l;

	if(r < size && array[r] > array[largest])
			largest = r;

	if(largest != indice){
		swap(array[indice], array[largest]);
		heapify(array, size, largest);
	}
}
void heapSort(int *array, int size){
	for(int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for(int i = size - 1; i > 0; i--){
		swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}