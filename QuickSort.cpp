#include <stdio.h>
#include <stdlib.h>
#include <ctime>

// FUNCTION'S PROTOTYPE
void quickSort( int *, int );
void quickSort( int *, int, int);
void swap(int &, int &);
// MAIN FUNCTION
int main() {
    int tam[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    FILE *in, *out;
    unsigned t0, t1;

    for(int i = 0; i < 10; ++i) {
        char fileIn[] = "Entradas/test_.txt";
        fileIn[13] = i + 48;

        char fileOut[] = "Salidas/QuickSort/cpp_out_.txt";
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
            quickSort(arr, tam[j]);
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
void quickSort( int arr[], int size ) {

    quickSort( arr, 0, size - 1 );
}

void quickSort( int arr[], int left, int right ) {

    int i = left, j = right;
    int pivot = arr[( left + right ) / 2 ];

    while( i <= j ) {
        while ( arr[ i ] < pivot )
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap( arr[ i ], arr[ j ]);
                i++;
                j--;
        }
    }

    if (left < j)
        quickSort( arr, left, j );
    if (i < right)
        quickSort( arr, i, right );
}

void swap( int &a, int &b ) {

    int tmp = a;
    a = b;
    b = tmp;
} 
