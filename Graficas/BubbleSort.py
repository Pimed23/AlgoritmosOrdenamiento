import numpy as np
from matplotlib import pyplot as plt

x1,y1 = np.loadtxt('../Promedios/BubbleSort/cpp_out.txt' , delimiter=' ' , unpack=True)
x2,y2 = np.loadtxt('../Promedios/BubbleSort/jav_out.txt' , delimiter=' ' , unpack=True)
x3,y3 = np.loadtxt('../Promedios/BubbleSort/pyt_out.txt' , delimiter=' ' , unpack=True)

plt.plot(x1,y1*6,color="blue", label = "BubbleSort en C++")
plt.plot(x2,y2*6,color="yellow", label = "BubbleSort en Java")
plt.plot(x3,y3*6,color="red", label = "BubbleSort en Python")

plt.legend()
plt.title('Algoritmo BubbleSort')
plt.xlabel('Cantidad de datos')
plt.ylabel('Tiempo de ejecucion (segundos)')
plt.text(240000,15000,r'$O(n^2)$', fontsize=12)
plt.show()