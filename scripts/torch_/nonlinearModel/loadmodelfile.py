import torch
    
# define model
class LinearModel(torch.nn.Module):
    def __init__(self):
        super(LinearModel,self).__init__()
        self.linear1=torch.nn.Linear(1,1,)
        self.linear2=torch.nn.Linear(1,1,)
        self.linear3=torch.nn.Linear(1,1,)
        self.Sig1 = torch.nn.Sigmoid()
        self.Sig2 = torch.nn.Sigmoid()

    
    def forward(self,x):
        x = self.linear1(x)
        x = self.Sig1(x)
        x = self.linear2(x)
        x = self.Sig2(x)
        y_pred = self.linear3(x)
        return y_pred

# load model object from the model file.
model = torch.load("../../../model/nonlinear.onnx")

# do a test for the trained model.
x_test = torch.Tensor([[6.0]])
y_test = model(x_test)
print("y_pred = ",y_test.data.item())
