#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Training / Test Log Regression
"""

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
from sklearn.metrics import classification_report
from sklearn.metrics import roc_curve
from sklearn.metrics import auc as calc_auc
import sklearn

Data = pd.read_csv('../data/Titanic_Cleaned_Data.csv')

#remove NAN and sex catergorical variable (already made dummy variable)
Data = Data[(Data['age'] > 0)]
Data = Data.drop("sex", axis=1)


# exploratory plots
#sns.countplot(x='survived', hue='sex_i', data=Data)
#sns.countplot(x='survived', hue='pclass', data=Data)


#split into explanatory v response
split = .3

X = Data.drop("survived",axis=1)
y = Data["survived"]

#split to test and training

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = split, random_state = 101)


# Fit model
from sklearn.linear_model import LogisticRegression
logmodel = LogisticRegression()
logmodel.fit(X_train,y_train)

predval = logmodel.predict_proba(X_test)
predval = predval[:, 1]

FalsePositive, TruePositive, thresholds = roc_curve(y_test, predval)
roc_auc = sklearn.metrics.roc_auc_score(y_test, predval)


# plot ROC curve
plt.plot(FalsePositive, TruePositive, label='ROC curve area = %0.3f' % roc_auc)
plt.plot([0, 1], [0, 1], 'k--')  # random predictions curve
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.0])
plt.xlabel('False Positive Rate or (1 - Specificity)')
plt.ylabel('True Positive Rate or (Sensitivity/Recall)')
plt.title('Titanic: ROC')
#plt.annotate('FalsePositive = 0.146\nTruePositive = 0.681', (0.08,0.85))
#plt.arrow(0.12, 0.81, 0.02, -0.09, length_includes_head=True,
          #head_width=0.02, head_length=0.02)
plt.legend(loc="lower right")
plt.show()

print("Area under the curve:", roc_auc)



#apply specified threshold value - beware of overfitting
newlogmodel = LogisticRegression(class_weight="balanced")
newlogmodel.fit(X_train, y_train)
THRESHOLD = 0.6
newpredval = np.where(newlogmodel.predict_proba(X_test)[:,1] > THRESHOLD, 1, 0)
tempdict = {'Actual':y_test, 'Predicted':newpredval}


# combine output into a confusion matrix
ActualVPredicted = pd.DataFrame(tempdict)
ConfusionMatrix = pd.crosstab(ActualVPredicted['Actual'], ActualVPredicted['Predicted'],
                     rownames=['Actual'], colnames=['Predicted'],
                     margins=True)

print(ConfusionMatrix)
print('\n', classification_report(y_test, newpredval))
