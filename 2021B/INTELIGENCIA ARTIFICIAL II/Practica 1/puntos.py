from matplotlib.widgets import *

import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots(figsize=(9, 7))
fig.subplots_adjust(bottom=0.3)

t = np.arange(-2.0, 2.0, 0.001)

x = []
y = []

ax.set_xlim(-4, 4)
ax.set_ylim(-4, 4)

w1 = [1]
w2 = [1]
umbral = [1]
v = [1]

cursor = Cursor(ax, useblit=True, color='red', linewidth=2)
def onClick(event):
    x1, y1 = event.xdata, event.ydata
    if x1 != None and y1 != None:
        x.append(x1)
        y.append(y1)
        ax.plot(x, y, 'o', color='green')
        plt.draw()

def submit(expression):
    w1[0] = float(expression)

def submit2(expression2):
    w2[0] = float(expression2)

def submit3(expression3):
    umbral[0] = float(expression3)

def limpiar():
    ax.plot(x, y, 'o', color='white')
    ax.cla()
    ax.set_xlim(-4, 4)
    ax.set_ylim(-4, 4)
    plt.draw()

def linea(x):
    return (-w1[0] / w2[0])*x + umbral[0]/w2[0]

def perceptron(event):
    indice = 0
    funcion = (-w1[0] / w2[0])
    limpiar()
    while(indice < len(x)):
        if x[indice] == None or y[indice] == None:
            print("no sirve")
        else:
            v = (x[indice]*w1[0] + y[indice]*w2[0]) - umbral[0]
            print(v)
            if v >= 0:
                ax.plot(x[indice], y[indice], 'o', color='yellow')
                plt.draw()
            else:
                ax.plot(x[indice], y[indice], 'o', color='blue')
                plt.draw()
            print(indice)
            indice += 1
            ax.plot(x, [linea(i) for i in x])

axbox = fig.add_axes([0.035, 0.19, 0.4, 0.075])
text_box = TextBox(axbox, "w1")
text_box.on_text_change(submit)

axbox2 = fig.add_axes([0.035, 0.10, 0.4, 0.075])
text_box2 = TextBox(axbox2, "w2")
text_box2.on_text_change(submit2)

axbox3 = fig.add_axes([0.035, 0.01, 0.4, 0.075])
text_box3 = TextBox(axbox3, "θ")
text_box3.on_text_change(submit3)

axbutton = plt.axes([0.7, 0.05, 0.1, 0.075])
bl = Button(axbutton, 'listo')
bl.on_clicked(perceptron)

fig.canvas.mpl_connect('button_press_event', onClick)
plt.show()

# matplotlib auto