from io import open
from time import time

def bubbleSort(arr) :
    n = len(arr)
    for i in range(n) :
        for j in range(0, n - i - 1):
            if int(arr[j]) > int(arr[j + 1]) :
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

tam = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
fileIn = "Entradas/testN.txt"
fileOut = "Salidas/BubbleSort/pyt_outN.txt"

for i in range(10) :
    entrada = fileIn.replace('N', str(i))
    salida = fileOut.replace('N', str(i)) 
    
    _out = open(salida, "w")
    for j in range(10) :
        _in = open(entrada, "r")
        data = _in.readlines()
        _in.close()
        arr = [0] * tam[j]
        
        for k in range (tam[j]) :
            arr[k] = int(data[i])

        t0 = time()
        bubbleSort(arr)
        t1 = time()
        tiempo = t1 - t0
        arr.clear()
        print(tiempo)
        _out.write(str(tam[j])+" "+str(tiempo)+"\n")
    _out.close()
        

