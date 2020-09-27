from io import open
from time import time

def insertSort(arr): 
    for i in range(1, len(arr)): 
        key = arr[i] 
        j = i - 1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key 

tam = [10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
fileIn = "Entradas/testNCounting.txt"
fileOut = "Salidas/InsertSort/pyt_outN.txt"

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
        insertSort(arr)
        t1 = time()
        tiempo = t1 - t0
        tiempo = round(tiempo, 5)
        arr.clear()
        print(tiempo)
        _out.write(str(tam[j]) + " " + str(tiempo)+"\n")
    _out.close()
        

