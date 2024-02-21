
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider, Button

x = np.array([[1,0,0],[1,0,1],[1,1,0],[1,1,1]])
print(x)
x.size
x.shape
x = x.T
print(x)
w = np.array([-1.5,1,1])
print(w)
v = np.dot(w,x)
print(v)