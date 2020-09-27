from io import open
from time import time

def heapify (array, size, indice):
    largest = indice
    l = 2 * indice + 1
    r = 2 * indice + 2
    if l < size and array[l] > array[largest]:
        largest = l
    if r < size and array[r] > array[largest]:
        largest = r
    if largest != indice:
        array[indice], array[largest] = array[largest], array[indice]
        heapify(array, size, largest)

def heapSort(array, size):
    for i in range (int(size / 2) - 1, -1, -1):
        heapify(array, size , i)
    for i in range (size - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        heapify(array, i, 0)

tam = [100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]
fileIn = "Entradas/testN.txt"
fileOut = "Salidas/HeapSort/pyt_outN.txt"

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
        heapSort(arr,tam[j])
        t1 = time()
        tiempo = t1 - t0
        tiempo = round(tiempo, 5)
        arr.clear()
        print(tiempo)
        _out.write(str(tam[j]) + " " + str(tiempo)+"\n")
    _out.close()
        

