import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class MergeSort{
	void merge(int arr[], int l, int m, int r) { 
		int n1 = m - l + 1; 
		int n2 = r - m; 

		int L[] = new int[n1]; 
		int R[] = new int[n2]; 

		for (int i = 0; i < n1; ++i) 
			L[i] = arr[l + i]; 
		for (int j = 0; j < n2; ++j) 
			R[j] = arr[m + 1 + j]; 

		int i = 0, j = 0; 

		int k = l; 
		while (i < n1 && j < n2) { 
			if (L[i] <= R[j]) { 
				arr[k] = L[i]; 
				i++; 
			} 
			else { 
				arr[k] = R[j]; 
				j++; 
			} 
			k++; 
		} 

		while (i < n1) { 
			arr[k] = L[i]; 
			i++; 
			k++; 
		} 

		while (j < n2) { 
			arr[k] = R[j]; 
			j++; 
			k++; 
		} 
	} 

	void mergeSort(int arr[], int l, int r) { 
		if (l < r) { 
			int m = (l + r) / 2; 
			mergeSort(arr, l, m); 
			mergeSort(arr, m + 1, r); 
			merge(arr, l, m, r); 
		} 
	}    

    public static void main(String[] args) {
        int tam[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
        double t0, t1;

        for(int i = 0; i < 10; ++i) {
            String fileIn = "Entradas/test";
            String fileOut = "Salidas/MergeSort/jav_out";

            fileIn = fileIn.concat(String.valueOf(i)+".txt");
            fileOut =  fileOut.concat(String.valueOf(i)+".txt");

            File out = new File(fileOut);

            try {
                FileWriter fw = new FileWriter(out);
                for(int j = 0; j < 10; ++j) {
                    int arr[] = new int[tam[j]];
    
                    try {
                        File in = new File(fileIn);
                        Scanner myReader = new Scanner(in);
                        int lineCount = 0;
                        while(myReader.hasNextLine() & (lineCount != tam[j])) {
                            String data = myReader.nextLine();
                            arr[lineCount] = Integer.parseInt(data);
                            ++lineCount;
                        }
    
                        MergeSort bs = new MergeSort();
                        t0 = System.currentTimeMillis();
                        bs.mergeSort(arr, 0, tam[j] - 1);
                        t1 = System.currentTimeMillis();
                        double time = (t1 - t0) / 1000;
                        System.out.println(time);
                        fw.write(String.valueOf(tam[j]) + " " +String.valueOf(time) + "\n");
                        myReader.close();
    
                    } catch(FileNotFoundException e) {
                        System.out.println("An error occurred.");
                        e.printStackTrace();
                    }
                }
                fw.close();
            } catch(Exception ex) {
                System.out.println("An error ocurred");
                ex.printStackTrace();
            }
        }
    }
}

