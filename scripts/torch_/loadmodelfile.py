import torch

# prepare datasets
x_data = torch.Tensor([[1.0],[2.0],[3.0]])
y_data = torch.Tensor([[2.0],[4.0],[6.0]])


# define model
class LinearModel(torch.nn.Module):
    def __init__(self):
        super(LinearModel,self).__init__()
        self.linear=torch.nn.Linear(1,1,)
    
    def forward(self,x):
        y_pred = self.linear(x)
        return y_pred

# create a Model instance, model is callable object
# model = LinearModel()
model = torch.load("./linearmodel.pkl")
# # define an object of MSE loss function.
# criterioc = torch.nn.MSELoss(size_average=False)

# # define an object of optimizer.
# optim = torch.optim.SGD(model.parameters(),lr=0.01)

# # this is the train cycle, want to train 1000 cycles.
# for epoch in range(1000):
#     y_pred = model(x_data) # forward
#     loss = criterioc(y_pred,y_data)# loss
#     print(epoch,loss.item())

#     optim.zero_grad()# clear all parameters' grade, because pytorch never clear them automatic.
#     loss.backward()# calculate weights' grad
#     optim.step()# do wight update

# print("w = ",model.linear.weight.item())
# print("b = ",model.linear.bias.item())

# do a test for the trained model.
x_test = torch.Tensor([[4.0]])
y_test = model(x_test)
print("y_pred = ",y_test.data)

# model.eval()
# torch.save(model,"./linearmodel.pkl")

