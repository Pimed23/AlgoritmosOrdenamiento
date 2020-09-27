from io import open
from time import time
import sys
import gc
sys.setrecursionlimit(1000000)

def partition(arr, low, high):
    i = low - 1
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]
    return (i+1)

def quickSort(arr, low, high): 
    if len(arr) == 1:
        return arr
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi -1)
        quickSort(arr, pi+1, high)

tam = [100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]
fileIn = "Entradas/testN.txt"
fileOut = "Salidas/QuickSort/pyt_outN.txt"

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
            arr[k] = int(data[k])

        t0 = time()
        quickSort(arr, 0, tam[j] -1 )
        t1 = time()
        tiempo = t1 - t0
        tiempo = round(tiempo, 5)
        del arr
        gc.collect()
        print(tiempo)
        _out.write(str(tam[j]) + " " + str(tiempo)+"\n")
    _out.close()
        

