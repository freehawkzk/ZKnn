#coding: utf-8
import os
import cv2
import tensorflow as tf
import numpy as np
import sys

data_dir = 'E:/XiongDi/ZKnn/data/cifar-10/cifar-10-batches-bin/'
dstdir = 'E:/XiongDi/ZKnn/data/cifar-10/images/'
imgchannels = 3
imgwidth = 32
imgheight = 32
labellen = 1
imglen = imgchannels * imgwidth * imgheight
recodelen = labellen + imglen

class IMGObj(object):
    pass

label=0
key=0
def ExtractBins(datadir):
    filenames = [os.path.join(datadir, 'data_batch_%d.bin' % i) for i in range(1, 6)]
    print(filenames)
    filename_queue = tf.compat.v1.train.string_input_producer(filenames,shuffle=False,num_epochs=1)
    reader = tf.FixedLengthRecordReader(record_bytes=recodelen)
    imgObj = IMGObj()

    key, value =  reader.read(filename_queue)
    print(key)
    record_bytes = tf.decode_raw(value, tf.uint8)
    label = tf.cast(tf.strided_slice(record_bytes, [0], [labellen]), tf.int32)
    print(label)
    depth_major = tf.reshape(tf.strided_slice(record_bytes, [labellen],[labellen + imglen]),[imgchannels, imgheight, imgwidth])
    imgObj.imgdata = tf.transpose(depth_major, [1, 2, 0])
    reshaped_image = tf.cast(imgObj.imgdata, tf.float32)
    return reshaped_image

if __name__ == '__main__':

    with tf.Session() as sess:
        imgobj = ExtractBins(data_dir)
        tf.local_variables_initializer().run()
        threads = tf.compat.v1.train.start_queue_runners(sess=sess)

        i = 0

        while True:
            i += 1
            img = sess.run(imgobj)
            labeldir = dstdir + '/'+str(label)
            if os.path.exists(labeldir) is False:
                os.makedirs(labeldir)
            fn = labeldir + '/'+str(i)+'.jpg'
            cv2.imwrite(fn,img)