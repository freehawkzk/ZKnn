from mxnet import autograd, nd
from mxnet import gluon
from mxnet.gluon import data as gdata
from mxnet.gluon import nn
from mxnet import init
from mxnet.gluon import loss as gloss


num_inputs = 2
num_examples = 1000
true_w = [2,-34]
true_b = 4.2
features = nd.random.normal(scale=1,shape=(num_examples, num_inputs))
labels = true_w[0]*features[:,0]+true_w[1]*features[:,1]+true_b
labels += nd.random.normal(scale=1,shape=labels.shape)

batch_size = 10
dataset = gdata.ArrayDataset(features,labels)
data_iter = gdata.DataLoader(dataset=dataset,batch_size=batch_size,shuffle=True)

net = nn.Sequential()
net.add(nn.Dense(1))

net.initialize(init.Normal(sigma=0.01))
# net.summary(features)
loss = gloss.L2Loss()

trainer = gluon.Trainer(net.collect_params(),'sgd',{'learning_rate':0.03})

# print(net.collect_params())
num_epochs = 30

for epoch in range(1,num_epochs+1):
    for X,y in data_iter:
        with autograd.record():
            l = loss(net(X),y)
        l.backward()
        trainer.step(batch_size=batch_size)
    l = loss(net(features),labels)
    print('epoch %d loss %f' % (epoch, l.mean().asnumpy()))

net.save_parameters('test')
print('w',net[0].weight.data())
print('b',net[0].bias.data())

