## This Python script is used to plot our motion profiles for better visualization

import matplotlib.pyplot as plt
import numpy as np

leftOriginal = open('leftOriginal.txt')
rightOriginal = open('rightOriginal.txt')

raw = open('raw.txt')

rawList = raw.readlines()


originalValLeft = []
originalValRight = []
rawValLeft = []
rawValRight = []

for x in leftOriginal:
    originalValLeft.append(x)
for x in rightOriginal:
    originalValRight.append(x)

for x in range (len(rawList)-1):
    rawValLeft.append(rawList[x])
    rawValRight.append(rawList[x+1])


print(rawValLeft)
print('--------------------------------------')
print(rawValRight)

# print(originalValLeft)

fig, (ax1, ax2) = plt.subplots(2)
ax1.plot(originalValLeft)
ax1.plot(rawValLeft, 'r')
ax1.axes.xaxis.set_visible(False)
ax1.axes.yaxis.set_visible(False)

ax2.plot(originalValRight)
ax2.plot(rawValRight, 'r')
ax2.axes.xaxis.set_visible(False)
ax2.axes.yaxis.set_visible(False)

plt.show()
