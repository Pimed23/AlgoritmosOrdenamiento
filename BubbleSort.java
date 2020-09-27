import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class BubbleSort {
    void bubbleSort(int[] arr) {  
        int n = arr.length;  
        int temp = 0;  
        for(int i = 0; i < n; ++i) {  
            for(int j = 1; j < n - i; ++j) {  
                if(arr[j - 1] > arr[j]){  
                    temp = arr[j - 1];  
                    arr[j - 1] = arr[j];  
                    arr[j] = temp;  
                }  
            }  
        } 
    }   

    public static void main(String[] args) {
        int tam[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
        double t0, t1;

        for(int i = 0; i < 10; ++i) {
            String fileIn = "Entradas/test";
            String fileOut = "Salidas/BubbleSort/jav_out";

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
    
                        BubbleSort bs = new BubbleSort();
                        t0 = System.currentTimeMillis();
                        bs.bubbleSort(arr);
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
            }
        }
    }
}

