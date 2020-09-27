from io import open
from time import time

def countSort(arr): 
    maxN = int(max(arr))
    minN = int(min(arr))
    rangeN = maxN - minN + 1
    count = [0 for _ in range(rangeN)]
    output = [0 for _ in range(len(arr))]

    for i in range(0, len(arr)):
        count[arr[i]-minN] += 1
    
    for i in range(1, len(count)):
        count[i] += count[i-1]

    for i in range(len(arr)-1, -1, -1):
        output[count[arr[i]-minN] - 1] = arr[i]
        count[arr[i] - minN] -= 1

    for i in range(0, len(arr)):
        arr[i] = output[i]

    return arr

tam = [15000, 30000, 45000, 60000, 75000, 90000, 105000, 120000, 135000, 150000]
fileIn = "Entradas/testNCounting.txt"
fileOut = "Salidas/CountSort/pyt_outN.txt"

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
        countSort(arr)
        t1 = time()
        tiempo = t1 - t0
        tiempo = round(tiempo, 5)
        arr.clear()
        print(tiempo)
        _out.write(str(tam[j]) + " " + str(tiempo)+"\n")
    _out.close()
        

