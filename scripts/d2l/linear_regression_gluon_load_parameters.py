from mxnet import autograd, nd
from mxnet import gluon
from mxnet.gluon import data as gdata
from mxnet.gluon import nn
from mxnet import init
from mxnet.gluon import loss as gloss

net = nn.Sequential()
net.add(nn.Dense(1))
net.load_parameters('test')
num_inputs = 2
x = nd.random.normal(scale=1,shape=(1, num_inputs))
print(x)
x[0][0]=1.0
x[0][1]=1.0
y_hat = net(x)
print(y_hat)