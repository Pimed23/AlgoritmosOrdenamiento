import numpy as np
from matplotlib import pyplot as plt

algoritmos = ["BubbleSort", "CountSort", "HeapSort", "InsertSort", "MergeSort", "QuickSort", "SelectionSort"]

for i in range(7) :
    pathcpp = "../Promedios/" + algoritmos[i] + "/cpp_out.txt"
    pathjav = "../Promedios/" + algoritmos[i] + "/jav_out.txt"
    pathpyt = "../Promedios/" + algoritmos[i] + "/pyt_out.txt"

    x1,y1 = np.loadtxt( pathcpp, delimiter=' ' , unpack=True)
    x2,y2 = np.loadtxt( pathjav , delimiter=' ' , unpack=True)
    x3,y3 = np.loadtxt( pathpyt, delimiter=' ' , unpack=True)

    plt.plot(x1,y1*6,color="blue", label = algoritmos[i] + " en C++")
    plt.plot(x2,y2*6,color="yellow", label = algoritmos[i] + " en Java")
    plt.plot(x3,y3*6,color="red", label = algoritmos[i] + " en Python")

    plt.legend()
    plt.title('Algoritmo' + algoritmos[i])
    plt.xlabel('Cantidad de datos')
    plt.ylabel('Tiempo de ejecucion (segundos)')
    plt.text(240000,15000,r'$O(n^2)$', fontsize=12)
    plt.savefig(algoritmos[i] + '.png')
    plt.close()
