from pathlib import Path
import requests
import pickle
import gzip
from matplotlib import pyplot
import numpy as np
import torch
import math
import model.ZKMnistModel
import model.ZKMnistDataset
from torch.utils.data import DataLoader


PATH = "/home/zk/e/XiongDi/ZKnn/scripts/torch_/data/mnist/mnist.pkl.gz"
ds_train = model.ZKMnistDataset.ZKMnistTrainDataset(PATH)
ds_test = model.ZKMnistDataset.ZKMnistTestDataset(PATH)
trainloader = DataLoader(dataset = ds_train, batch_size= 1024, shuffle=True,num_workers=2)
testloader = DataLoader(dataset = ds_test, batch_size= 1024, shuffle=False,num_workers=2)

model_ = model.ZKMnistModel.ZKMnistModel()

device = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
model_.to(device)

criterion = torch.nn.CrossEntropyLoss()
optim = torch.optim.Adam(model_.parameters(),lr=0.005)



for epoch in range(10):
    loss_total = 0
    for i,data in enumerate(trainloader,0):
        x,y=data
        x = x.view([-1,1,28,28])
        x,y = x.to(device),y.to(device)
        y_ = model_(x)
        loss = criterion(y_,y)
        loss_total += loss.item()
        optim.zero_grad()
        loss.backward()
        optim.step()
    
    if epoch % 1 == 0:
        correct = 0
        total = 0
        with torch.no_grad():
            for testdata in testloader:
                x,y=testdata
                x = x.view([-1,1,28,28])
                x,y = x.to(device),y.to(device)
                output = model_(x)
                _,predicted = torch.max(output.data,dim =1)
                total += y.size(0)
                correct += (predicted == y).sum().item()
        print(epoch,"acc: ",100*correct / total,correct, total)


    
device = torch.device("cpu")
model_.to(device)
model_.eval()

torch.save(model_,"../../../model/mnist-cnn.pkl")
correct = 0
total = 0
with torch.no_grad():
    for testdata in testloader:
        x,y=testdata
        x = x.view([-1,1,28,28])
        x,y = x.to(device),y.to(device)
        output = model_(x)
        _,predicted = torch.max(output.data,dim =1)
        total += y.size(0)
        correct += (predicted == y).sum().item()
print("cpu model acc: ",100*correct / total,correct, total)

x = torch.randn([1,1,28,28])
torch_out = torch.onnx._export(model_, x, "../../../model/mnist-cnn.onnx",export_params=True)