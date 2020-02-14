import os
import tensorflow as tf
import cv2
from tensorflow.examples.tutorials.mnist import input_data
from tensorflow.python.framework import graph_util
MNISTDir = 'E:/XiongDi/ZKnn/mnist/'
mnist = input_data.read_data_sets(MNISTDir,one_hot=True)

savepath = './model/mnist_train/'
if os.path.exists(savepath) is False:
    os.makedirs(savepath)

x = tf.placeholder(tf.float32,[None,784],name='x')
y_ = tf.placeholder(tf.float32,[None,10])

w = tf.Variable(tf.zeros([784,10],tf.float32),name='w')
b = tf.Variable(tf.zeros([10],tf.float32),name='b')
y = tf.nn.softmax(tf.matmul(x,w)+b,name='op_out')

cross_entropy = tf.reduce_mean(-tf.reduce_sum(y_*tf.log(y)))

train_step = tf.train.GradientDescentOptimizer(0.01).minimize(cross_entropy)

sess = tf.InteractiveSession()

tf.global_variables_initializer().run()
constgraph = graph_util.convert_variables_to_constants(sess,sess.graph_def,['op_out'])

modelsaver = tf.train.Saver()
for i in range(1000):
    bx,by = mnist.train.next_batch(100)
    sess.run(train_step,feed_dict={x:bx,y_:by})
    if i % 100 == 0:
        modelsaver.save(sess,savepath+'mnist',global_step=i)
        with tf.gfile.FastGFile(savepath+'mnist-'+str(i)+'.pb',mode='wb') as f:
            f.write(constgraph.SerializeToString())

correct_prediction = tf.equal(tf.argmax(y,1),tf.argmax(y_,1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction,tf.float32))
print(sess.run(accuracy,feed_dict={x:mnist.test.images,y_:mnist.test.labels}))