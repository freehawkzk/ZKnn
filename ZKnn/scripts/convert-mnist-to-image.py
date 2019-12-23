from tensorflow.examples.tutorials.mnist import input_data
from scipy import misc
import numpy as np
import os
import cv2

mnist = input_data.read_data_sets('E:/XiongDi/ZKnn/ZKnn/x64/Release/scripts/',one_hot=True)

result_path ='E:/XiongDi/ZKnn/ZKnn/x64/Release/scripts/img2/'

def onehot2id(labels):
    return list(labels).index(1)

if not os.path.exists(result_path):
    os.mkdir(result_path)

labels_txt = open('train_labs.txt','w')
for i in range(len(mnist.train.images)):
    img_vec = mnist.train.images[i,:]
    img_vec = np.array(img_vec)
    img_arr = np.reshape(img_vec,[28,28])
    img_lab = mnist.train.labels[i,:]
    img_id = onehot2id(img_lab)
    labels_txt.write(str(i)+'    '+str(img_id)+'\n')
    img_path = os.path.join(result_path,str(i)+'.png')
    #misc.imsave(img_path,img_arr)
    cv2.imwrite(img_path,img_arr)