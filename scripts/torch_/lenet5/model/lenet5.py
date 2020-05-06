import torch

class LeNet5(torch.nn.Module):

    def __init__(self):
        super(LeNet5,self).__init__()
        self.conv1=torch.nn.Conv2d(1,6,5)
        self.pooling = torch.nn.MaxPool2d(2)
        self.relu=torch.nn.ReLU()
        self.conv2 = torch.nn.Conv2d(6,16,5)
        self.conv3 = torch.nn.Conv2d(16,120,5)
        self.fc1 = torch.nn.Linear(120,84)
        self.fc2 = torch.nn.Linear(84,10)

    def forward(self,x):
            x = self.conv1(x)
            x = self.pooling(x)
            x = self.relu(x)

            x = self.conv2(x)
            x = self.pooling(x)
            x = self.relu(x)

            x = self.conv3(x)
            x = self.relu(x)

            x = x.view(x.shape[0],-1)
            x = self.fc1(x)
            x = self.relu(x)

            x = self.fc2(x)

            return x