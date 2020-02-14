#coding: utf-8
"""
this file is used to convert tensorflow's mnist dataset data to 
images formated as jpg.
"""
import os
import cv2
import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
import numpy as np

MNISTDir = 'E:/XiongDi/ZKnn/mnist/'
mnist = input_data.read_data_sets(MNISTDir,one_hot=True)

savedir = MNISTDir + 'images/'
if os.path.exists(savedir) is False:
    os.makedirs(savedir)

traindir = savedir + '/train/'
if os.path.exists(traindir) is False:
    os.makedirs(traindir)

for i in range(10):
    dir = traindir+str(i)+'/'
    if os.path.exists(dir) is False:
        os.makedirs(dir)

valdir = savedir + 'validation/'
if os.path.exists(valdir) is False:
    os.makedirs(valdir)

for i in range(10):
    dir = valdir+str(i)+'/'
    if os.path.exists(dir) is False:
        os.makedirs(dir)

testdir = savedir + 'test/'
if os.path.exists(testdir) is False:
    os.makedirs(testdir)

for i in range(10):
    dir = testdir+str(i)+'/'
    if os.path.exists(dir) is False:
        os.makedirs(dir)

nTrainImg,nImgSize = mnist.train.images.shape
_,nLabelSize=mnist.train.labels.shape
nValImg,_ = mnist.validation.images.shape
nTestImg,_ = mnist.test.images.shape
print('..........start decode train images..........')
for i in range(nTrainImg):
    imgdata = mnist.train.images[i,:]
    labeldata = mnist.train.labels[i,:]

    imgdata = imgdata.reshape(28,28)#imgdata type is float, need to convert to uint8
    imgdata = imgdata*255
    imgdata = imgdata.astype(np.uint8)
    label=0
    for j in range(nLabelSize):
        if labeldata[j] == 1:
            label =j
            break
    fn = traindir+str(label)+'/'+str(i)+'.jpg'
    cv2.imwrite(fn,imgdata)#save image by opencv
    if i % 100 == 0:
        print(' decode '+str(i)+' train images')
print('..........finish decode train images..........')

print('..........start decode validation images..........')
for i in range(nValImg):
    imgdata = mnist.validation.images[i,:]
    labeldata = mnist.validation.labels[i,:]

    imgdata = imgdata.reshape(28,28)
    imgdata = imgdata*255
    imgdata = imgdata.astype(np.uint8)
    label=0
    for j in range(nLabelSize):
        if labeldata[j] == 1:
            label =j
            break
    fn = valdir+str(label)+'/'+str(i)+'.jpg'
    cv2.imwrite(fn,imgdata)
    if i % 100 == 0:
        print(' decode '+str(i)+' validation images')
print('..........finish decode validation images..........')

print('..........start decode test images..........')
for i in range(nTestImg):
    imgdata = mnist.test.images[i,:]
    labeldata = mnist.test.labels[i,:]

    imgdata = imgdata.reshape(28,28)
    imgdata = imgdata*255
    imgdata = imgdata.astype(np.uint8)
    label=0
    for j in range(nLabelSize):
        if labeldata[j] == 1:
            label =j
            break
    fn = testdir+str(label)+'/'+str(i)+'.jpg'
    cv2.imwrite(fn,imgdata)
    if i % 100 == 0:
        print(' decode '+str(i)+' test images')
print('..........finish decode test images..........')