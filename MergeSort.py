from io import open
from time import time

def mergeSort(arr): 
    if len(arr) > 1: 
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]

        mergeSort(L)
        mergeSort(R)
  
        i = j = k = 0

        while i < len(L) and j < len(R): 
            if int(L[i]) < int(R[j]): 
                arr[k] = L[i] 
                i+= 1
            else: 
                arr[k] = R[j] 
                j+= 1
            k+= 1
          
        while i < len(L): 
            arr[k] = L[i] 
            i+= 1
            k+= 1
          
        while j < len(R): 
            arr[k] = R[j] 
            j+= 1
            k+= 1

tam = [100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000]
fileIn = "Entradas/testN.txt"
fileOut = "Salidas/MergeSort/pyt_outN.txt"

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
        mergeSort(arr)
        t1 = time()
        tiempo = t1 - t0
        tiempo = round(tiempo, 5)
        arr.clear()
        print(tiempo)
        _out.write(str(tam[j]) + " " + str(tiempo)+"\n")
    _out.close()
        

