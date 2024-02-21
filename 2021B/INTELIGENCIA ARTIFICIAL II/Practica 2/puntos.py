from matplotlib.widgets import *
from matplotlib.backend_bases import MouseButton
from numpy import asarray
import numpy as np
import matplotlib.pyplot as plt
import random
import time

fig, ax = plt.subplots(figsize=(9, 7))
fig.subplots_adjust(bottom=0.3)
t = np.arange(-2.0, 2.0, 0.001)
ax.set_xlim(-4, 4)
ax.set_ylim(-4, 4)
a = []
b = []
w = asarray([[random.random(),random.random()]])
t = random.random()
r = 0.5

cursor = Cursor(ax, useblit=True, color='red', linewidth=2)
def onClick(event):
    x1, y1 = event.xdata, event.ydata
    if x1 != None and y1 != None:
        if event.button is MouseButton.LEFT:
            a.append([x1,y1])
            b.append([-1])
            ax.plot(a[-1][0], a[-1][1], 'o', color='blue')
            plt.draw()
        elif event.button is MouseButton.RIGHT:
            a.append([x1,y1])
            b.append([1])
            ax.plot(a[-1][0], a[-1][1], 'o', color='yellow')
            plt.draw()
            
def submit(expression):
    w[0][0] = float(expression)

def submit2(expression2):
    w[0][1] = float(expression2)

def submit3(expression3):
    w0 = float(expression3)

def limpiar():
    ax.cla()
    ax.set_xlim(-4, 4)
    ax.set_ylim(-4, 4)
    plt.draw()
        
def linea(x):
    return (-w[0][0] / w[0][1])*x + t/w[0][1]

def perceptron(event):
    global t
    x = asarray(a)
    z = asarray(b)
    k=0
    n=0
    l=1
    i=1
    errores = len(x)
    line = ax.plot(x, [linea(i) for i in x], color = 'green')
    plt.draw()
    while k < len(x):
        print("Epoca=",i)
        print("Iteracion=",l)
        print("-----------------------------------------------------------------------------------------")
        y =  w[0][0]*x[k][0]+w[0][1]*x[k][1]-t
        print("y = w[0][0]*x[",k,"][0]+w[0][1]*x[",k,"][1]")
        print(w[0][0],"*",x[k][0],"+",w[0][1],"*",x[k][1])
        print("y =",y)
        if y >= 0:
            n = 1
            print("n->",n)
            ax.plot(x[k][0], x[k][1], 'o', color='yellow')
            plt.draw()
        else:
            n = -1
            print("n->",n)
            ax.plot(x[k][0], x[k][1], 'o', color='blue')
            plt.draw()
        if n == z[k]:
            print("✔")
            errores= errores - 1
            plt.draw()
            print("errores=",errores)
        else:
            print("_________________________________________________________________________________________")
            print("✘")
            print("e =",z[k][0],"-", n)
            e = z[k][0] - n
            print("e =",e)
            d = r * e
            print("d =", r, "*", e)
            print("d =", d)
            print("w[0] =",w[0], "+", d, "*", x[k])
            w[0] = w[0] + d * x[k]
            print("w[0] =",w[0])
            t = t + d * -1
            print("θ=", t)
            text_box.set_val(w[0][0])
            text_box2.set_val(w[0][1])
            text_box3.set_val(t)
            print("errores=",errores)
            
            line.set_ydata([linea(i) for i in x])
            fig.canvas.draw()
            fig.canvas.flush_events()
        print("-----------------------------------------------------------------------------------------")
        k= k + 1
        l= l + 1
        if k == len(x):
            if errores > 0:
                print("Iteracion=",l)
                print("Epoca=",i+1)
                k=0
                errores = len(x)
            i= i + 1

axbox = fig.add_axes([0.035, 0.19, 0.4, 0.075])
text_box = TextBox(axbox, "w1")
text_box.on_text_change(submit)
text_box.set_val(w[0][0])

axbox2 = fig.add_axes([0.035, 0.10, 0.4, 0.075])
text_box2 = TextBox(axbox2, "w2")
text_box2.on_text_change(submit2)
text_box2.set_val(w[0][1])

axbox3 = fig.add_axes([0.035, 0.01, 0.4, 0.075])
text_box3 = TextBox(axbox3, "θ")
text_box3.on_text_change(submit3)
text_box3.set_val(t)

axbutton = plt.axes([0.7, 0.05, 0.1, 0.075])
bl = Button(axbutton, 'listo')
bl.on_clicked(perceptron)

fig.canvas.mpl_connect('button_press_event', onClick)
plt.show()

# matplotlib auto