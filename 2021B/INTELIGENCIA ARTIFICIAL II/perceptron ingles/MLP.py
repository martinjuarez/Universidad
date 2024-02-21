import tkinter
from tkinter import Entry, Label, Frame, Button
from matplotlib.backends.backend_tkagg import (
    FigureCanvasTkAgg, NavigationToolbar2Tk)
from matplotlib.backend_bases import key_press_handler
from matplotlib.backend_bases import MouseButton
from matplotlib.widgets import Cursor
from itertools import cycle
import matplotlib.pyplot as plt
import numpy as np
from numpy import asarray

plt.rcParams["figure.figsize"] = [20, 10]

a =[]
b =[]

#train_data =
"""
train_data = np.array(
    [
        [0, 0],
        [0, 1],
        [1, 0],
        [1, 1]])

target_xor = np.array(
    [
        [0],
        [1],
        [1],
        [0]])
"""
#target_xor =

class MLP:


    def __init__(self, train_data, target, fi, li, lr=0.001, num_epochs=50000, num_input=2, num_hidden=4, num_output=1):
        self.train_data = train_data
        self.target = target
        self.lr = lr
        self.num_epochs = num_epochs

        self.weights_01 = np.random.uniform(size=(num_input, num_hidden))
        self.weights_12 = np.random.uniform(size=(num_hidden, num_output))

        self.b01 = np.random.uniform(size=(1, num_hidden))
        self.b12 = np.random.uniform(size=(1, num_output))

        self.losses = []
        
        self.ax = fi
        self.fig = li
    def update_weights(self):

        loss = 0.5 * (self.target - self.output_final) ** 2
        self.losses.append(np.sum(loss))

        error_term = (self.target - self.output_final)

        grad01 = self.train_data.T @ (((error_term * self._delsigmoid(
            self.output_final)) * self.weights_12.T) * self._delsigmoid(self.hidden_out))

        grad12 = self.hidden_out.T @ (error_term *
                                      self._delsigmoid(self.output_final))

        self.weights_01 += self.lr * grad01
        self.weights_12 += self.lr * grad12

        self.b01 += np.sum(self.lr * ((error_term * self._delsigmoid(self.output_final))
                           * self.weights_12.T) * self._delsigmoid(self.hidden_out), axis=0)
        self.b12 += np.sum(self.lr * error_term *
                           self._delsigmoid(self.output_final), axis=0)

    def _sigmoid(self, x):

        return 1 / (1 + np.exp(-x))

    def _delsigmoid(self, x):

        return x * (1 - x)

    def forward(self, batch):

        self.hidden_ = np.dot(batch, self.weights_01) + self.b01
        self.hidden_out = self._sigmoid(self.hidden_)

        self.output_ = np.dot(self.hidden_out, self.weights_12) + self.b12
        self.output_final = self._sigmoid(self.output_)

        return self.output_final

    def classify(self, datapoint):

        datapoint = np.transpose(datapoint)
        if self.forward(datapoint) >= 0.5:
            return 1

        return 0

    def plot(self, h=0.01):

        colors = {
            0: "ro",
            1: "go"
        }

        for i in range(len(self.train_data)):
            ax.plot(colors[self.target[i][0]],markersize=20)
        
        x_range = np.arange(-0.1, 1.1,h)
        y_range = np.arange(-0.1, 1.1,h)

        xx, yy = np.meshgrid(x_range, y_range, indexing='ij')
        Z = np.array([[self.classify([x, y]) for x in x_range]
                     for y in y_range])

        plt.contourf(xx, yy, Z, colors=[
                     'red', 'green', 'green', 'blue'], alpha=0.4)
        plt.draw()

    def train(self):

        for epoch in range(self.num_epochs):

            self.forward(self.train_data)
            self.update_weights()

            if epoch % 500 == 0:
                print("Loss: ", self.losses[epoch])

def on_click(event):
    """Esta funcion sirve para graficar los puntos y guardar las coordenadas"""
    x_1 = event.xdata
    y_1 = event.ydata
    if event.button is MouseButton.LEFT:
        a.append([x_1, y_1])
        b.append([1])
        ax.plot(a[-1][0], a[-1][1], 'o', color='green')
        plt.draw()
    elif event.button is MouseButton.RIGHT:
        a.append([x_1, y_1])
        b.append([0])
        ax.plot(a[-1][0], a[-1][1], 'o', color='red')
        plt.draw()

x_axis_x = [-10, 10]
x_axis_y = [0, 0]
y_axis_x = [0, 0]
y_axis_y = [-10, 10]

root = tkinter.Tk()
root.wm_title("MLP")

n1 = tkinter.StringVar()
n2 = tkinter.StringVar()
n3 = tkinter.StringVar()

frame2 = Frame(root,)
frame2.pack(side="right")

"""
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
"""


fig = plt.figure(figsize=(5, 4), dpi=100)
ax = fig.add_subplot()
ax.set_xlim(-0.1, 1.1)
ax.set_ylim(-0.1, 1.1)
ax.plot(x_axis_x, x_axis_y, color='black')
ax.plot(y_axis_x, y_axis_y, color='black')

fig.suptitle('Perceptron', fontsize=14, fontweight='bold')
ax.set_title('x2')
ax.set_ylabel('x1')

n1.set(0)
n2.set(0)
n3.set(1)

def iniciar():
    train = asarray(a)
    target = asarray(b)
    mlp = MLP(train, target, ax, fig, 0.2, 8000)
    mlp.train()
    #_ = plt.plot(mlp.losses)
    mlp.plot()

boton1 = Button(frame2, text="Listo", command=iniciar)
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
