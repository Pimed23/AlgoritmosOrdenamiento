#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> algoritmos = { "BubbleSort", "InsertSort", "MergeSort", "QuickSort", "SelectionSort", "HeapSort", "CountSort" };
    vector<string> lenguajes = {"/cpp_out", "/jav_out", "/pyt_out"};
    string init = "../Salidas/";
    
    for(int i = 0; i < 7; ++i) {
        for(int j = 0; j < 3; ++j) {
            int tam = 100000;
            double c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
            string outs = algoritmos[i] + lenguajes[j] + ".txt";
            ofstream fileOut(outs, ios::out);

            for(int k = 0; k < 10; ++k) {
                string path = init + algoritmos[i] + lenguajes[j] + to_string(k) + ".txt";
                ifstream fileIn(path, ios::in);
                
                if( fileIn.fail())
                    break;
                
                string linea;
                int count = 0;
                double num;
                while(getline(fileIn, linea)) {
                    size_t pos = linea.find(" ");
                    num = atof(linea.substr(pos).c_str());

                    switch(count) {
                        case 0: c0 += num; break;
                        case 1: c1 += num; break;
                        case 2: c2 += num; break;
                        case 3: c3 += num; break;
                        case 4: c4 += num; break;
                        case 5: c5 += num; break;
                        case 6: c6 += num; break;
                        case 7: c7 += num; break;
                        case 8: c8 += num; break;
                        case 9: c9 += num; break;
                        default: break;
                    }
                    ++count;
                }
            }

            if( i == 0 || i == 1 || i == 4 )
                tam = tam / 10;
            else if( i == 6 )
                tam = 15000;

            fileOut << 1 * tam << " " << c0 / 10.0f << endl;
            fileOut << 2 * tam << " " << c1 / 10.0f << endl;
            fileOut << 3 * tam << " " << c2 / 10.0f << endl;
            fileOut << 4 * tam << " " << c3 / 10.0f << endl;
            fileOut << 5 * tam << " " << c4 / 10.0f << endl;
            fileOut << 6 * tam << " " << c5 / 10.0f << endl;
            fileOut << 7 * tam << " " << c6 / 10.0f << endl;
            fileOut << 8 * tam << " " << c7 / 10.0f << endl;
            fileOut << 9 * tam << " " << c8 / 10.0f << endl;
            fileOut << 10 * tam << " " << c9 / 10.0f << endl;
        }
    }
    return 0;
}