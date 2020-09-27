import numpy as np
from matplotlib import pyplot as plt

lenguajes = ["/cpp_out.txt", "/jav_out.txt", "/pyt_out.txt"]
leng = ["CPP", "JAVA", "PYTHON"]

for i in range(3) :
    pathbs = "../Promedios/BubbleSort/" + lenguajes[i]
    pathcs = "../Promedios/CountSort/" + lenguajes[i]
    pathhs = "../Promedios/HeapSort/" + lenguajes[i]
    pathis = "../Promedios/InsertSort/" + lenguajes[i]
    pathms = "../Promedios/MergeSort/" + lenguajes[i]
    pathqs = "../Promedios/QuickSort/" + lenguajes[i]
    pathss = "../Promedios/SelectionSort/" + lenguajes[i]

    x1,y1 = np.loadtxt( pathbs, delimiter=' ' , unpack=True)
    x2,y2 = np.loadtxt( pathcs, delimiter=' ' , unpack=True)
    x3,y3 = np.loadtxt( pathhs, delimiter=' ' , unpack=True)
    x4,y4 = np.loadtxt( pathis, delimiter=' ' , unpack=True)
    x5,y5 = np.loadtxt( pathms, delimiter=' ' , unpack=True)
    x6,y6 = np.loadtxt( pathqs, delimiter=' ' , unpack=True)
    x7,y7 = np.loadtxt( pathss, delimiter=' ' , unpack=True)

    plt.plot(x1,y1*6,color="blue", label = "BubbleSort")
    plt.plot(x2,y2*6,color="yellow", label = "CountSort")
    plt.plot(x3,y3*6,color="red", label = "HeapSort")
    plt.plot(x4,y4*6,color="green", label = "InsertSort")
    plt.plot(x5,y5*6,color="purple", label = "MergeSort")
    plt.plot(x6,y6*6,color="orange", label = "QuickSort")
    plt.plot(x7,y7*6,color="black", label = "SelectionSort")

    plt.legend()
    plt.title('Comparacion en ' + leng[i])
    plt.xlabel('Cantidad de datos')
    plt.ylabel('Tiempo de ejecucion (segundos)')
    plt.text(240000,15000,r'$O(n^2)$', fontsize=12)
    plt.savefig( leng[i] + '.png')
    plt.close()
