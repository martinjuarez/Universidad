"""Este modulo une Tkinter con una figura de matplotlib"""
import tkinter
from tkinter import Entry, Label, Frame, Button
import random
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (
    FigureCanvasTkAgg, NavigationToolbar2Tk)
from matplotlib.backend_bases import key_press_handler
from matplotlib.backend_bases import MouseButton
from matplotlib.widgets import Cursor
from numpy import asarray


a = []
b = []
xy = []
x_axis_x = [-10, 10]
x_axis_y = [0, 0]
y_axis_x = [0, 0]
y_axis_y = [-10, 10]

w = asarray([[random.random(), random.random()]])
T = random.random()
R = 0.5

root = tkinter.Tk()
root.wm_title("Correccion del error")

n1 = tkinter.StringVar()
n2 = tkinter.StringVar()
n3 = tkinter.StringVar()

frame2 = Frame(root,)
frame2.pack(side="right")

label = Label(frame2, text="w1")
label.pack()
entry = Entry(frame2, textvariable=n1)
entry.pack()

label2 = Label(frame2, text="w2")
label2.pack()
entry2 = Entry(frame2, textvariable=n2)
entry2.pack()

label3 = Label(frame2, text="θ")
label3.pack()
entry3 = Entry(frame2, textvariable=n3)
entry3.pack()

fig = plt.figure(figsize=(5, 4), dpi=100)
ax = fig.add_subplot()
ax.set_xlim(-3.1, 3.1)
ax.set_ylim(-2.1, 2.1)
ax.plot(x_axis_x, x_axis_y, color='black')
ax.plot(y_axis_x, y_axis_y, color='black')

fig.suptitle('Perceptron', fontsize=14, fontweight='bold')
ax.set_title('x2')
ax.set_ylabel('x1')

n1.set(w[0][0])
n2.set(w[0][1])
n3.set(T)


def on_click(event):
    """Esta funcion sirve para graficar los puntos y guardar las coordenadas"""
    x_1 = event.xdata
    y_1 = event.ydata
    if event.button is MouseButton.LEFT:
        xy.append(x_1)
        a.append([x_1, y_1])
        b.append([-1])
        ax.plot(a[-1][0], a[-1][1], 'o', color='blue')
        plt.draw()
    elif event.button is MouseButton.RIGHT:
        a.append([x_1, y_1])
        b.append([1])
        ax.plot(a[-1][0], a[-1][1], 'o', color='yellow')
        plt.draw()


def linea(ex):
    """Esta funcion sirve retornar los valores que graficara"""
    return (-w[0][0] / w[0][1])*ex + T/w[0][1]


def limpiar():
    """Esta funcion sirve para limpiar los puntos de la figura"""
    ax.cla()
    ax.set_xlim(-3.1, 3.1)
    ax.set_ylim(-2.1, 2.1)
    ax.plot(x_axis_x, x_axis_y, color='black')
    ax.plot(y_axis_x, y_axis_y, color='black')
    plt.draw()


def pesos():
    """Esta funcion sirve actualizar los pesos"""
    n1.set(w[0][0])
    n2.set(w[0][1])
    n3.set(T)
    plt.draw()
    fig.canvas.draw_idle()


def perceptron():
    """Esta funcion sirve para realizar las labores de clasificacion lo que es
    el perceptron"""
    global T
    w[0][0] = float(n1.get())
    w[0][1] = float(n2.get())
    T = float(n3.get())
    ex = asarray(a)
    z_1 = asarray(b)
    k = 0
    e_1 = 0
    e_2 = 1
    i = 1
    errores = len(ex)
    ax.plot(ex, [linea(i) for i in ex], color="green")
    plt.draw()
    while k < len(ex):
        print("Epoca=", i)
        print("Iteracion=", e_2)
        print("--------------------------------------------------------------")
        y_1 = w[0][0]*ex[k][0]+w[0][1]*ex[k][1]-T
        print("y = w[0][0]*x[", k, "][0]+w[0][1]*x[", k, "][1]")
        print(w[0][0], "*", ex[k][0], "+", w[0][1], "*", ex[k][1])
        print("y =", y_1)
        if y_1 >= 0:
            e_1 = 1
            print("n->", e_1)
            ax.plot(ex[k][0], ex[k][1], 'o', color='yellow')
            plt.draw()
        else:
            e_1 = -1
            print("n->", e_1)
            ax.plot(ex[k][0], ex[k][1], 'o', color='blue')
            plt.draw()
        if e_1 == z_1[k]:
            print("✔")
            errores = errores - 1
            plt.draw()
            print("errores=", errores)
        else:
            print(
                "____________________________________________________________")
            print("✘")
            print("e =", z_1[k][0], "-", e_1)
            e = z_1[k][0] - e_1
            print("e =", e)
            d = R * e
            print("d =", R, "*", e)
            print("d =", d)
            print("w[0] =", w[0], "+", d, "*", ex[k])
            w[0] = w[0] + d * ex[k]
            print("w[0] =", w[0])
            T = T + d * -1
            print("θ=", T)
            pesos()
            print("errores=", errores)
        print("--------------------------------------------------------------")
        k = k + 1
        e_2 = e_2 + 1
        if k == len(ex):
            i = i + 1
            if errores > 0:
                print("Iteracion=", e_2)
                print("Epoca=", i+1)
                k = 0
                errores = len(ex)
            i = i + 1
        ax.cla()
        ax.set_xlim(-3.1, 3.1)
        ax.set_ylim(-2.1, 2.1)
        ax.plot(x_axis_x, x_axis_y, color='black')
        ax.plot(y_axis_x, y_axis_y, color='black')
        plt.draw()
        indice = 0
        while indice < len(ex):
            y_1 = w[0][0]*ex[indice][0]+w[0][1]*ex[indice][1]-T
            if y_1 >= 0:
                ax.plot(ex[indice][0], ex[indice][1], 'o', color='yellow')
                plt.draw()
            else:
                ax.plot(ex[indice][0], ex[indice][1], 'o', color='blue')
                plt.draw()
            indice = indice + 1
        ax.plot(ex, [linea(i) for i in ex], color="green")
        plt.draw()


boton1 = Button(frame2, text="Listo", command=perceptron)
boton1.pack()

canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()

toolbar = NavigationToolbar2Tk(canvas, root, pack_toolbar=False)
toolbar.update()

canvas.mpl_connect("key_press_event", lambda event: print(
    f"you pressed {event.key}"))
canvas.mpl_connect("key_press_event", key_press_handler)

toolbar.pack(side=tkinter.BOTTOM, fill=tkinter.X)
canvas.get_tk_widget().pack(side=tkinter.TOP, fill=tkinter.BOTH, expand=1)

cursor = Cursor(ax, useblit=True, color='red', linewidth=2)
fig.canvas.mpl_connect('button_press_event', on_click)
tkinter.mainloop()
input()
