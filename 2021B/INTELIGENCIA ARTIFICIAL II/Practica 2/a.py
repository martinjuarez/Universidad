from tkinter import *
from numpy import asarray
from matplotlib.widgets import *
import time
import random
import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots(figsize=(9, 7))
fig.subplots_adjust(bottom=0.3)
t = np.arange(-2.0, 2.0, 0.001)

ax.set_xlim(-4, 4)
ax.set_ylim(-4, 4)

eta = 0.5
w = asarray([[-2.5, 1.75]])
x = asarray([[1.0, 1.0],[-0.5, 1.0],[3.0, 1.0],[-2.0, 1.0]])
d = asarray([[1.0],[-1.0],[1.0],[-1.0]])

def linea(x):
    return (-w[0][0] / w[0][1])*x + 0/w[0][1]

def perceptron(event):
    correcion()
    
def correcion():
    k=0
    l=1
    i=0
    errores = len(x)
    linea = ax.plot(x, [linea(i) for i in x])
    while k < len(x):
        print("iteracion",i)
        print("epoca",l) 
        y =  w[0][0]*x[k][0]+w[0][1]*x[k][1]
        print(w[0][0])
        print(x[k][0])
        print(w[0][1])
        print(x[k][1])
        print("y=",y)
        if y >= 0:
            y = 1
            ax.plot(x[k][0], x[k][1], 'o', color='yellow')
            plt.draw()
        else:
            y = -1
            ax.plot(x[k][0], x[k][1], 'o', color='blue')
            plt.draw()
        if y == d[k]:
            print("✔")
            print(w[0])
            errores-=1
            text_box.set_val(w[0][0])
            text_box2.set_val(w[0][1])
            text_box3.set_val(0)
            plt.draw()
        else:
            print("✘")
            e = d[k][0] - y
            w[0] = w[0] + eta * e * x[k]
            print(w[0])
            text_box.set_val(w[0][0])
            text_box2.set_val(w[0][1])
            text_box3.set_val(0)
            plt.draw()
        plt.draw()
        k+=1
        
        i+=1        
        if errores == 0:
            break
        elif k == len(x):
            l+=1           
            ax.cla()
            ax.set_xlim(-4, 4)
            ax.set_ylim(-4, 4)
            k=0
            errores = len(x)

"""
    ax.cla()
    ax.set_xlim(-4, 4)
    ax.set_ylim(-4, 4)
    plt.draw()
"""

axbox = fig.add_axes([0.035, 0.19, 0.4, 0.075])
text_box = TextBox(axbox, "w1")
text_box.set_val(w[0][0])

axbox2 = fig.add_axes([0.035, 0.10, 0.4, 0.075])
text_box2 = TextBox(axbox2, "w2")
text_box2.set_val(w[0][1])

axbox3 = fig.add_axes([0.035, 0.01, 0.4, 0.075])
text_box3 = TextBox(axbox3, "θ")
text_box3.set_val(0)

axbutton = plt.axes([0.7, 0.05, 0.1, 0.075])
bl = Button(axbutton, 'listo')
bl.on_clicked(perceptron)
                 
plt.show()    
# matplotlib auto 