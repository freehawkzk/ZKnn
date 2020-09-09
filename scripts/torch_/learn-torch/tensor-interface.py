import torch
import numpy as np

data = [1,0,0.5]

x = torch.from_numpy(np.array(data))
print(x)

print(x.acos())