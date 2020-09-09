# -*- coding: utf-8 -*-
import torch
import numpy

# dev = torch.device("cuda",2) # 使用设备类型+序号，设备类型支持"cuda"或"CPU"，cuda序号不能超过系统GPU数量-1,CPU序号只能是-1或0
# dev = torch.device("cuda:2")
dev = torch.device(2) # 在不指定设备类型时，默认使用cuda设备。
print(dev)

x = torch.tensor([2,3])

print(x.get_device())

print(x.is_cuda) #用于标志该tensor是不是在gpu上，在gpu上时=True,否则=False