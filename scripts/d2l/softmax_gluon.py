import mxnet as mx
from mxnet import autograd, nd
from mxnet import gluon
from mxnet.gluon import data as gdata
from mxnet.gluon import nn
from mxnet import init
from mxnet.gluon import loss as gloss
import os
import sys

def load_data_fashion_mnist(batch_size, resize=None, root=os.path.join(
        '~', '.mxnet', 'datasets', 'fashion-mnist')):
    """Download the fashion mnist dataset and then load into memory."""
    root = os.path.expanduser(root)
    transformer = []
    if resize:
        transformer += [gdata.vision.transforms.Resize(resize)]
    transformer += [gdata.vision.transforms.ToTensor()]
    transformer = gdata.vision.transforms.Compose(transformer)

    mnist_train = gdata.vision.FashionMNIST(root=root, train=True)
    mnist_test = gdata.vision.FashionMNIST(root=root, train=False)
    num_workers = 0 if sys.platform.startswith('win32') else 4

    train_iter = gdata.DataLoader(mnist_train.transform_first(transformer),
                                  batch_size, shuffle=True,
                                  num_workers=num_workers)
    test_iter = gdata.DataLoader(mnist_test.transform_first(transformer),
                                 batch_size, shuffle=False,
                                 num_workers=num_workers)
    return train_iter, test_iter

batch_size = 256
train_iter, test_iter = load_data_fashion_mnist(batch_size)

net = nn.Sequential()
net.add(nn.Dense(10))
net.initialize(init.Normal(sigma = 0.01),ctx = mx.gpu())

loss = gloss.SoftmaxCrossEntropyLoss()

trainer = gluon.Trainer(net.collect_params(),'sgd',{'learning_rate':0.1})

num_epochs = 50

def evaluate_accuracy(data_iter, net):
    acc_sum, n = 0.0 ,0
    for X, y in data_iter:
        # print(X)
        y = y.astype('float32')
        X = X.copyto(mx.gpu())
        y_hat = net(X)
        y_hat = y_hat.copyto(mx.cpu())
        acc_sum += (y_hat.argmax(axis = 1) == y).sum().asscalar()
        n += y.size
    return acc_sum / n

def train(net, train_iter, test_iter, loss, num_epochs, batch_size, params = None, lt = None, trainer = None):
    for epoch in range(num_epochs):
        train_l_sum, train_acc_sum, n = 0.0,0.0,0
        for X,y in train_iter:
            # print(X)
            with autograd.record():
                X = X.copyto(mx.gpu())
                y_hat = net(X)
                y_hat = y_hat.copyto(mx.cpu())
                l = loss(y_hat,y).sum()
            l.backward()
            if trainer is None:
                sgd(params , lr , batch_size)
            else:
                trainer.step(batch_size)
            y = y.astype('float32')
            train_l_sum += l.asscalar()
            train_acc_sum += (y_hat.argmax(axis = 1)== y).sum().asscalar()
            n += y.size
        test_acc = evaluate_accuracy(test_iter, net)
        print('epoch %d, loss %f, train acc %f, test acc %f'%(epoch+1, train_l_sum/n,train_acc_sum/n, test_acc))

train(net,train_iter,test_iter,loss, num_epochs, batch_size,None, None, trainer)
