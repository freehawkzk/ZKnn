import torch
    r"""this is a script to test the linear model trained by w*x+b """
    
# define model
class LinearModel(torch.nn.Module):
    def __init__(self):
        super(LinearModel,self).__init__()
        self.linear=torch.nn.Linear(1,1,)
    
    def forward(self,x):
        y_pred = self.linear(x)
        return y_pred

# load model object from the model file.
model = torch.load("./linearmodel.pkl")

# do a test for the trained model.
x_test = torch.Tensor([[4.0]])
y_test = model(x_test)
print("y_pred = ",y_test.data.item())
