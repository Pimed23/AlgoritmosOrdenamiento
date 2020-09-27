#include <stdio.h>
#include <stdlib.h>
#include <ctime>

// FUNCTION'S PROTOTYPE
void selectionSort( int *, int );

// MAIN FUNCTION
int main() {
    int tam[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    FILE *in, *out;
    unsigned t0, t1;

    for(int i = 0; i < 10; ++i) {
        char fileIn[] = "Entradas/test_.txt";
        fileIn[13] = i + 48;

        char fileOut[] = "Salidas/SelectionSort/cpp_out_.txt";
        fileOut[29] = i + 48;

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
            selectionSort(arr, tam[j]);
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
void selectionSort(int *arr, int n) {  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++) {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
	int temp = arr[min_idx];
	arr[min_idx] = arr[i];
	arr[i] = temp;
    }  
}  
  
