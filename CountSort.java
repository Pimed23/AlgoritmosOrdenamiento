import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class CountSort {
    void countingSort(int array[], int size) {
        int[] output = new int[size + 1];

        int max = array[0];
        for(int i = 1; i < size; i++) {
            if(array[i] > max)
                max = array[i];
        }

        int[] count = new int[max + 1];

        for(int i = 0; i < max; ++i)
            count[i] = 0;

        for(int i = 0; i < size; ++i)
            count[array[i]]++;

        for(int i = 1; i <= max; ++i)
            count[i] += count[i - 1];

        for(int i = size - 1; i >= 0; --i) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        for(int i = 0; i < size; ++i)
            array[i] = output[i];
    } 

    public static void main(String[] args) {
        int tam[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
        double t0, t1;

        for(int i = 0; i < 10; ++i) {
            String fileIn = "Entradas/test";
            String fileOut = "Salidas/CountSort/jav_out";

            fileIn = fileIn.concat(String.valueOf(i)+"Counting.txt");
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
    
                        CountSort bs = new CountSort();
                        t0 = System.currentTimeMillis();
                        bs.countingSort(arr, tam[j]);
                        t1 = System.currentTimeMillis();
                        double time = (t1 - t0) / 1000;
                        System.out.println(time);
                        fw.write(String.valueOf(tam[j]) + " " + String.valueOf(time) + "\n");
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

