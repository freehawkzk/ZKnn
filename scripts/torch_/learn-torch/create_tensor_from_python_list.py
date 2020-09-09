import torch
import numpy as np

data = [1,0,0.5] # this is a python list object
print("python list data: ",data)
arr = np.array(data) # convert python list object to numpy array object
print("numpy array: ",arr)
x_tensor = torch.from_numpy(arr) # convert numpy array object to torch tensor
print("tensor: ",x_tensor)


# python list data:  [1, 0, 0.5]
# numpy array:  [1.  0.  0.5]
# tensor:  tensor([1.0000, 0.0000, 0.5000], dtype=torch.float64)
