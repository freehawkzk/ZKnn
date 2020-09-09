import torch
import numpy as np
import matplotlib.pyplot as plt
import cv2

# create a black image on gpu. w: 128, h: 128, c: 3
t_img_gpu = torch.zeros([1,3,128,128],dtype=torch.float32,device=0)

# pixle format: b-g-r
t_img_gpu[:,0,0:64,0:64]=1.0
t_img_gpu[:,1,64:,0:64]=1.0
t_img_gpu[:,2,0:64,64:]=1.0

t_img_cpu = t_img_gpu.cpu() # download image from gpu to cpu

np_img = t_img_cpu.numpy() # convert tensor to numpy array
np_img = np.reshape(np_img,[3,128,128]) # remove N dim

np_img = np.array(np_img*255).astype(np.uint8) # convert image from float to uint8

np_img = np.swapaxes(np_img,0,2) # change data from CWH to HWC
cv2.imshow("1",np_img)
cv2.waitKey(10000)
