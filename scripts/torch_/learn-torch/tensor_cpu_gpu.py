import torch
import numpy as np


data = [[1,2,3],[2,3,4]] # data in python list object

arr = np.array(data) # create numpy array object use the python list object

x_cpu = torch.from_numpy(arr) # create a cpu tensor use the numpy array object

x_gpu = x_cpu.cuda(device="cuda:0") # create a gpu tensor by the cpu tensor

x_cpu2 = x_gpu.cpu()
print("python list object: ",data)
print("numpy array object: ",arr)
print("cpu tensor: ",x_cpu," device: ",x_cpu.get_device())
print("gpu tensor: ",x_gpu," device: ",x_gpu.get_device())
print("cpu tensor2: ",x_cpu2," device: ",x_cpu2.get_device())
data[0]=3
print("after change data: ")
print("python list object: ",data)
print("numpy array object: ",arr)
print("cpu tensor: ",x_cpu," device: ",x_cpu.get_device())
print("gpu tensor: ",x_gpu," device: ",x_gpu.get_device())
print("cpu tensor2: ",x_cpu2," device: ",x_cpu2.get_device())

# python list object:  [[1, 2, 3], [2, 3, 4]]
# numpy array object:  [[1 2 3]
#  [2 3 4]]
# cpu tensor:  tensor([[1, 2, 3],
#         [2, 3, 4]])  device:  -1
# gpu tensor:  tensor([[1, 2, 3],
#         [2, 3, 4]], device='cuda:0')  device:  0
# cpu tensor2:  tensor([[1, 2, 3],
#         [2, 3, 4]])  device:  -1
# after change data: 
# python list object:  [3, [2, 3, 4]]
# numpy array object:  [[1 2 3]
#  [2 3 4]]
# cpu tensor:  tensor([[1, 2, 3],
#         [2, 3, 4]])  device:  -1
# gpu tensor:  tensor([[1, 2, 3],
#         [2, 3, 4]], device='cuda:0')  device:  0
# cpu tensor2:  tensor([[1, 2, 3],
#         [2, 3, 4]])  device:  -1