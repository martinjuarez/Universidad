# -*- coding: utf-8 -*-
"""
Created on Wed Feb  9 15:17:25 2022

@author: marti
"""

import numpy as np
import numpy.random as rnd
import matplotlib.pyplot as plt
import random as rd
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression, Ridge
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline

np.random.seed(42)
m = 10
X = 6 * np.random.rand(30, 1)-2
#X=np.random.uniform(-3,3,(m,1))
y = 2 + 0.5 * X + np.random.randn(30, 1) / 1.5
#y=np.exp(X) + np.random.randn(m, 1)+1
#y=np.exp(X)


plt.plot(X, y, "b.")
plt.xlabel("$x_1$", fontsize=18)
plt.ylabel("$y$", rotation=0, fontsize=18)
plt.axis([-3, 3, -2, 20])
plt.show()


poly_features = PolynomialFeatures(degree=11, include_bias=False)
X_poly = poly_features.fit_transform(X)
print(X[0])
alpha = 1e-05



lin_reg = LinearRegression()
lin_reg.fit(X_poly , y)


print(lin_reg.intercept_, lin_reg.coef_)


X_new=np.linspace(-3, 3, 100).reshape(100, 1)
X_new_poly = poly_features.transform(X_new)
y_new = lin_reg.predict(X_new_poly)



plt.plot(X_new, y_new , "r-", linewidth=1, label="Predictions")
plt.xlabel("$x_1$", fontsize=18)
plt.ylabel("$y$", rotation=0, fontsize=18)
plt.legend(loc="upper left", fontsize=14)
plt.axis([-3, 3, -2, 20])
plt.show()




for style , width , degree in (("y-", 5, 20), ("b--", 5, 11), ("r--", 2, 1)):
    polybig_features = PolynomialFeatures(degree=degree , include_bias=False)
    std_scaler = StandardScaler()
    lin_reg = LinearRegression()
    polynomial_regression = Pipeline([("poly_features", polybig_features),("std_scaler", std_scaler),("lin_reg", lin_reg)]) 
    polynomial_regression.fit(X, y)
    y_newbig = polynomial_regression.predict(X_new)
    plt.plot(X_new , y_newbig , style , label=str(degree), linewidth=width)


plt.plot(X, y, "b.", linewidth=3)
plt.legend(loc="upper left")
plt.xlabel("$x_{1}$")
plt.ylabel("$y$")
plt.axis([-3, 3, -2, 20])
plt.show()