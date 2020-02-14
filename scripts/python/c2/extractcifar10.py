#coding: utf-8
import os
import sys
import tarfile

srcdir = 'E:/XiongDi/ZKnn/data/cifar-10/'
srcfile = srcdir + 'cifar-10-binary.tar.gz'
dstdir = srcdir

def cifar10_extract():
  """Extract the tarball from Alex's website."""
  if not os.path.exists(srcdir):
    os.makedirs(srcdir)
  extracted_dir_path = os.path.join(dstdir, 'cifar-10-batches-bin')
  if not os.path.exists(extracted_dir_path):
    tarfile.open(srcfile, 'r:gz').extractall(extracted_dir_path)

if __name__ == '__main__':
    cifar10_extract()