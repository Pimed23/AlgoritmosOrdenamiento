#include <stdio.h>
#include <stdlib.h>
#include <ctime>

// FUNCTION'S PROTOTYPE
void merge(int *, int, int, int);
void mergeSort( int *, int );
void mergeSort( int *, int, int);
// MAIN FUNCTION
int main() {
    int tam[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    FILE *in, *out;
    unsigned t0, t1;

    for(int i = 0; i < 10; ++i) {
        char fileIn[] = "Entradas/test_.txt";
        fileIn[13] = i + 48;

        char fileOut[] = "Salidas/MergeSort/cpp_out_.txt";
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
            mergeSort(arr, tam[j]);
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
void merge( int *arr, int left, int mid, int right ) {

    int *temp = new int[ right - left + 1 ];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while( i <= mid && j <= right ) {
        if( arr[ i ] <= arr[ j ])
            temp[ k++ ] = arr[ i++ ];
        else
            temp[ k++ ] = arr[ j++ ];
    }

    while( i <= mid )
        temp[ k++ ] = arr[ i++ ];
    while( j <= right )
        temp[ k++ ] = arr[ j++ ];
    for( k = 0, i = left; i <= right; ++i, ++k )
        arr[ i ] = temp[ k ];
 
    delete[] temp;
}

void mergeSort( int *arr, int size ) {
 
    mergeSort( arr, 0, size - 1 );
}

void mergeSort( int *arr, int left, int right ) {
    
    int mid = ( left + right ) / 2;

    if( left < right ) {
        mergeSort( arr, left, mid );
        mergeSort( arr, mid + 1, right );
        merge( arr, left, mid, right );
    }
}
