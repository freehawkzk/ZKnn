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

num_inputs = 784
num_outputs = 10
W = nd.random.normal(scale = 0.01, shape = (num_inputs, num_outputs))
b = nd.zeros(num_outputs)

W.attach_grad()
b.attach_grad()

def softmax(X):
    X_exp = X.exp()
    partition = X_exp.sum(axis = 1, keepdims = True)
    return X_exp / partition

def net(X):
    return softmax(nd.dot(X.reshape((-1,num_inputs)),W)+b)

def cross_entropy(y_hat,y):
    return -nd.pick(y_hat,y).log()

def accuacy(y_hat,y):
    return (y_hat.argmax(axis = 1) == y.astype('float32')).mean().asscalar()

def evaluate_accuracy(data_iter, net):
    acc_sum, n = 0.0 ,0
    for X, y in data_iter:
        y = y.astype('float32')
        acc_sum += (net(X).argmax(axis = 1) == y).sum().asscalar()
        n += y.size
    return acc_sum / n

def sgd(params, lr, batch_size):
    """Mini-batch stochastic gradient descent."""
    for param in params:
        param[:] = param - lr * param.grad / batch_size
        
num_epochs = 50
lr = 0.1

def train(net, train_iter, test_iter, loss, num_epochs, batch_size, params = None, lt = None, trainer = None):
    for epoch in range(num_epochs):
        train_l_sum, train_acc_sum, n = 0.0,0.0,0
        for X,y in train_iter:
            with autograd.record():
                y_hat = net(X)
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

train(net,train_iter,test_iter,cross_entropy, num_epochs, batch_size, [W,b], lr)
