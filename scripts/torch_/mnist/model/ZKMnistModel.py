import torch
import numpy as np

class ZKMnistModel(torch.nn.Module):
    
    def __init__(self):
        super(ZKMnistModel,self).__init__()
        self.conv1 = torch.nn.Conv2d(1,512,3,stride=1)
        self.conv2 = torch.nn.Conv2d(512,256,3,stride=1)
        self.conv3 = torch.nn.Conv2d(256,128,3,stride=1)
        self.maxpool = torch.nn.MaxPool2d(2)
        self.relu = torch.nn.ReLU(inplace=True)
        self.softmax = torch.nn.Softmax(dim=1)
        self.linear1 = torch.nn.Linear(128*3*3,512)
        self.linear2 = torch.nn.Linear(512,128)
        self.linear3 = torch.nn.Linear(128,10)


    def forward(self,x):
        # x = x.view([-1,1,28,28]) # out: N*1*28*28

        x = self.conv1(x) # out: N*512*26*26
        x = self.maxpool(x) # out: N*512*13*13
        x = self.relu(x) # out: N*512*13*13

        x = self.conv2(x) # out: N*256*11*11
        x = self.maxpool(x) # out: N*256*5*5
        x = self.relu(x) # out: N*256*5*5

        x = self.conv3(x) # out: N*128*3*3
        x = self.relu(x) # out: N*128*3*3

        shape_ = x.shape
        x = x.view(shape_[0],-1) # make tensor to be a line

        x = self.linear1(x) # out: 512
        x = self.relu(x) # out: 512

        x = self.linear2(x) # out: 128
        x = self.relu(x) # out: 128

        x = self.linear3(x) # out: 10

        return x