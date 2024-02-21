# -*- coding: utf-8 -*-
"""
Created on Mon Mar  7 09:39:01 2022

@author: marti
"""

import numpy as np
import pandas as pd

from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report
from sklearn.metrics import plot_confusion_matrix
import matplotlib.pyplot as plt

#leer el archivo
dataFilePath = '../Datasets/breastCancer.csv'
dataFrame = pd.read_csv(dataFilePath)
#revisamos el tipo de dato, para que vean que es un objeto de tipo datafreme de pandas
print(type(dataFrame))
#un vistazo a los datos con los que trabajaremos
print(dataFrame.head())
#revisamos que no haya nulos
print(dataFrame.isnull().sum())
#Ploteamos la cantidad de personas con problemas del corazon (1) y los que no tienen (0)
ax = dataFrame['diagnosis'].value_counts().plot(kind='bar');

#preparar la entrada y la posible salida
dataFrame.diagnosis.replace(to_replace = dict(M = 1, B = 0), inplace = True)

y = dataFrame["diagnosis"].values

x = dataFrame.drop(["diagnosis","Unnamed: 32", "id"], axis = 1)

#escalar los valores de entradas


#SPlitting into train and test
xtrain, xtest, ytrain, ytest = train_test_split(x, y, test_size = 0.3)

#creamos el modelo de un Perceptron multicapa
model=MLPClassifier(alpha=1, max_iter=2000)
#a entrenar
model.fit(xtrain, ytrain)

#revisar el score de los modelos en entrenamiento y en test
print('Train: ', model.score(xtrain, ytrain))
print('Test: ', model.score(xtest, ytest))

#sacar la prediccion en la parte del test
ytestpred = model.predict(xtest)

#sacar el reporte de clasificacion 
print('Classification report: \n', classification_report(ytest, ytestpred))
class_names=["no sano"," sano"]
disp =plot_confusion_matrix(model,xtest, ytest,display_labels=class_names,
                                 cmap=plt.cm.Blues,)
disp.ax_.set_title("Confusion matrix, without normalization")
plt.show()


confusion_matrix(ytest,ytestpred)
print(pd.crosstab(ytest, ytestpred, rownames = ['Actual'], colnames =['Predicted'], margins = True))