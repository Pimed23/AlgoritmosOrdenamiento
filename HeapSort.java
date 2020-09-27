import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class HeapSort{
	void heapify(int[] array, int size, int indice){
		int temp;
		int largest = indice;
		int l = 2 * indice + 1;
		int r = 2 * indice + 2;
		
		if(l < size && array[l] > array[largest])
			largest = l;
		if(r < size && array[r] > array[largest])
			largest = r;
		if(largest != indice){
			temp = array[indice];
			array[indice] = array[largest];
			array[largest] = temp;
			heapify(array, size, largest);
		}
    }
    
	void heapSort(int[] array, int size){
		for(int i = size/2 - 1; i >= 0; --i)
			heapify(array, size, i);
		for(int i = size - 1 ; i > 0; --i){
			int temp;
			temp = array[0];
			array[0] = array[i];
			array[i] = temp;
			heapify(array, i, 0);
		}
	}    

    public static void main(String[] args) {
        int tam[] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
        double t0, t1;

        for(int i = 0; i < 10; ++i) {
            String fileIn = "Entradas/test";
            String fileOut = "Salidas/HeapSort/jav_out";

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
    
                        HeapSort bs = new HeapSort();
                        t0 = System.currentTimeMillis();
                        bs.heapSort(arr, tam[j]);
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

