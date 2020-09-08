"""
@brief: execise convert between numpy ndarray and pytorch tensor.
@author: freehawkzk@126.com
"""

import numpy as np
import torch as t

## 1 convert a numpy to pytorch tensor
x_array = np.ones([2,3],dtype=np.float)
print(x_array)
print(x_array.type())