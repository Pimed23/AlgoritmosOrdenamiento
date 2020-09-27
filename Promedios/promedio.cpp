#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> algoritmos = { "BubbleSort", "InsertSort", "MergeSort", "QuickSort", "SelectionSort", "HeapSort", "CountingSort" };
    vector<string> lenguajes = {"/cpp_out", "/jav_out", "/pyt_out"};
    string init = "../Salidas/";
    
    for(int i = 0; i < 7; ++i) {
        for(int j = 0; j < 3; ++j) {
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
            fileOut << c0 / 10.0 << endl;
            fileOut << c1 / 10.0 << endl;
            fileOut << c2 / 10.0 << endl;
            fileOut << c3 / 10.0 << endl;
            fileOut << c4 / 10.0 << endl;
            fileOut << c5 / 10.0 << endl;
            fileOut << c6 / 10.0 << endl;
            fileOut << c7 / 10.0 << endl;
            fileOut << c8 / 10.0 << endl;
            fileOut << c9 / 10.0 << endl;
        }
    }
    return 0;
}