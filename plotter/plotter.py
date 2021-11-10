import matplotlib.pyplot as plt
import numpy as np

leftOriginal = open('leftOriginal.txt')
rightOriginal = open('rightOriginal.txt')
leftRaw = open('leftRaw.txt')
rightRaw = open('rightRaw.txt')


originalValLeft = []
originalValRight = []
rawValLeft = []
rawValRight = []

for x in leftOriginal:
    originalValLeft.append(x)
for x in rightOriginal:
    originalValRight.append(x)

for x in leftRaw:
    rawValLeft.append(x)
for x in rightRaw:
    rawValRight.append(x)
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
