"""
@brief: execise convert between numpy ndarray and pytorch tensor.
@author: freehawkzk@126.com
"""

import numpy as np
import torch as t

## 1 convert a numpy to pytorch tensor
x_array = np.ones([2,3],dtype=np.float)
print(x_array)
#[[1. 1. 1.]
# [1. 1. 1.]]

"""
Creates a Tensor from a numpy.ndarray.

The returned tensor and ndarray share the same memory. 
Modifications to the tensor will be reflected in the ndarray and vice versa. 
The returned tensor is not resizable.

It currently accepts ndarray with dtypes of numpy.float64, numpy.float32, numpy.float16, 
numpy.complex64, numpy.complex128, 
numpy.int64, numpy.int32, numpy.int16, numpy.int8, numpy.uint8, 
and numpy.bool.
"""
x_tensor1 = t.from_numpy(x_array)
print(x_tensor1)
#tensor([[1., 1., 1.],
#        [1., 1., 1.]], dtype=torch.float64)

x_array[0,1]=100
print("x_array: ",x_array)
print("x_tensor1: ",x_tensor1)
#x_array:  [[  1. 100.   1.]
# [  1.   1.   1.]]
#x_tensor1:  tensor([[  1., 100.,   1.],
#        [  1.,   1.,   1.]], dtype=torch.float64)

"""
Convert the data into a torch.Tensor. 
If the data is already a Tensor with the same dtype and device, no copy will be performed, 
otherwise a new Tensor will be returned with computational graph retained if data Tensor has requires_grad=True. 
Similarly, if the data is an ndarray of the corresponding dtype and the device is the cpu, no copy will be performed.

Parameters

        data (array_like) – Initial data for the tensor. Can be a list, tuple, NumPy ndarray, scalar, and other types.

        dtype (torch.dtype, optional) – the desired data type of returned tensor. Default: if None, infers data type from data.

        device (torch.device, optional) – the desired device of returned tensor. 
        Default: if None, uses the current device for the default tensor type (see torch.set_default_tensor_type()). 
        device will be the CPU for CPU tensor types and the current CUDA device for CUDA tensor types.

"""
x_tensor2 = t.as_tensor(x_array,dtype=t.uint8)
x_tensor3 = t.as_tensor(x_array,dtype=t.float32)
x_tensor4 = t.as_tensor(x_array,dtype=t.float64)
print("x_tensor2: ",x_tensor2)
print("x_tensor3: ",x_tensor3)
print("x_tensor4: ",x_tensor4)
#x_tensor2:  tensor([[  1, 100,   1],
#        [  1,   1,   1]], dtype=torch.uint8)
#x_tensor3:  tensor([[  1., 100.,   1.],
#        [  1.,   1.,   1.]])
#x_tensor4:  tensor([[  1., 100.,   1.],
#        [  1.,   1.,   1.]], dtype=torch.float64)

x_tensor2[0,0]=2
print("x_array: ",x_array)
print("x_tensor2: ",x_tensor2)
print("x_tensor3: ",x_tensor3)
print("x_tensor4: ",x_tensor4)
# x_array:  [[  1. 100.   1.]
#  [  1.   1.   1.]]
# x_tensor2:  tensor([[  2, 100,   1],
#         [  1,   1,   1]], dtype=torch.uint8)
# x_tensor3:  tensor([[  1., 100.,   1.],
#         [  1.,   1.,   1.]])
# x_tensor4:  tensor([[  1., 100.,   1.],
#         [  1.,   1.,   1.]], dtype=torch.float64)


x_tensor3[0,0]=3
print("x_array: ",x_array)
print("x_tensor2: ",x_tensor2)
print("x_tensor3: ",x_tensor3)
print("x_tensor4: ",x_tensor4)
# x_array:  [[  1. 100.   1.]
#  [  1.   1.   1.]]
# x_tensor2:  tensor([[  2, 100,   1],
#         [  1,   1,   1]], dtype=torch.uint8)
# x_tensor3:  tensor([[  3., 100.,   1.],
#         [  1.,   1.,   1.]])
# x_tensor4:  tensor([[  1., 100.,   1.],
#         [  1.,   1.,   1.]], dtype=torch.float64)

x_tensor4[0,0]=4
print("x_array: ",x_array)
print("x_tensor2: ",x_tensor2)
print("x_tensor3: ",x_tensor3)
print("x_tensor4: ",x_tensor4)
# x_array:  [[  4. 100.   1.]
#  [  1.   1.   1.]]
# x_tensor2:  tensor([[  2, 100,   1],
#         [  1,   1,   1]], dtype=torch.uint8)
# x_tensor3:  tensor([[  3., 100.,   1.],
#         [  1.,   1.,   1.]])
# x_tensor4:  tensor([[  4., 100.,   1.],
#         [  1.,   1.,   1.]], dtype=torch.float64)

x_tensor5 = t.as_tensor(x_array,device=t.device('cuda'))
print(x_tensor5)
x_tensor5[0,0] = 5
print("x_array: ",x_array)
print(x_tensor5)
# tensor([[  4., 100.,   1.],
#         [  1.,   1.,   1.]], device='cuda:0', dtype=torch.float64)
# x_array:  [[  4. 100.   1.]
#  [  1.   1.   1.]]
# tensor([[  5., 100.,   1.],
#         [  1.,   1.,   1.]], device='cuda:0', dtype=torch.float64)

### NOTE: from_numpy(),will not copy data, tensor and numpy array use the same memory.
### torch.as_tensor() will copy memroy when the copy is necessary. 
### If numpy array and tensor have different data type or device, will copy memory.

## 2 from tensor to numpy array

"""
Returns self tensor as a NumPy ndarray. 
This tensor and the returned ndarray share the same underlying storage. 
Changes to self tensor will be reflected in the ndarray and vice versa.
"""

x = t.randn([2,3],dtype=t.float32)
print("x : ",x)
x1 = x.numpy()
print("x1: ",x1)
# x :  tensor([[ 0.2259, -0.8085,  1.1210],
#         [-0.4707,  1.3111,  0.9475]])
# x1:  [[ 0.22594252 -0.80854577  1.1210223 ]
#  [-0.47068182  1.3110596   0.9474761 ]]

x[0,0] = 10
print("x : ",x)
print("x1: ",x1)
# x :  tensor([[10.0000, -0.8085,  1.1210],
#         [-0.4707,  1.3111,  0.9475]])
# x1:  [[10.         -0.80854577  1.1210223 ]
#  [-0.47068182  1.3110596   0.9474761 ]]

x1[1,1] = 15
print("x : ",x)
print("x1: ",x1)
# x :  tensor([[10.0000, -0.8085,  1.1210],
#         [-0.4707, 15.0000,  0.9475]])
# x1:  [[10.         -0.80854577  1.1210223 ]
#  [-0.47068182 15.          0.9474761 ]]

x2 = t.randn([2,3],device=t.device("cuda"))
x3 = x2.cpu().numpy()
print("x2 : ",x2)
print("x3 : ",x3)
# x2 :  tensor([[ 1.9357, -0.3691,  1.6468],
#         [-0.1487,  2.2522, -0.8448]], device='cuda:0')
# x3 :  [[ 1.9356828  -0.36911824  1.6467508 ]
#  [-0.14868717  2.252174   -0.8447822 ]]

x2[0,0] = 10
print("x2 : ",x2)
print("x3 : ",x3)
# x2 :  tensor([[10.0000, -0.3691,  1.6468],
#         [-0.1487,  2.2522, -0.8448]], device='cuda:0')
# x3 :  [[ 1.9356828  -0.36911824  1.6467508 ]
#  [-0.14868717  2.252174   -0.8447822 ]]

x3[1,1] = 15
print("x2 : ",x2)
print("x3 : ",x3)
# x2 :  tensor([[10.0000, -0.3691,  1.6468],
#         [-0.1487,  2.2522, -0.8448]], device='cuda:0')
# x3 :  [[ 1.9356828  -0.36911824  1.6467508 ]
#  [-0.14868717 15.         -0.8447822 ]]