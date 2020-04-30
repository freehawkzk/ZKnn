from pathlib import Path
from matplotlib import pyplot
import numpy as np
import torch
import math
import model.ZKMnistModel
import model.ZKMnistDataset
from torch.utils.data import DataLoader
import cv2

PATH = "/home/zk/e/XiongDi/ZKnn/scripts/torch_/data/mnist/mnist.pkl.gz"
ds_test = model.ZKMnistDataset.ZKMnistTestDataset(PATH)
testloader = DataLoader(dataset = ds_test, batch_size= 1024, shuffle=False,num_workers=2)

# model_ = model.ZKMnistModel.ZKMnistModel()

model_ = torch.load("/home/zk/src/ZKnn/model/mnist-cnn.pkl")

device = torch.device("cpu")
model_.to(device)

for data in testloader:
    x,y = data
    x = x.view([-1,1,28,28])
    x = x[0]
    y_ = model_(x)
    print(y_)
    x = x.numpy()
    print(x.shape)
    cv2.imshow("1",x[0])
    cv2.waitKey()

    img = x[0]*255
    img = img.astype('uint8')
    cv2.imshow('2',img)
    cv2.waitKey()
    cv2.imwrite("3.jpg",img)
    break