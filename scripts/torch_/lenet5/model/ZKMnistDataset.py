import torch
import numpy as np
from torch.utils.data import Dataset
import pickle
import gzip

class ZKMnistTrainDataset(Dataset):
    
    def __init__(self,filepath):
        super(ZKMnistTrainDataset,self).__init__()
        with gzip.open(filepath, "rb") as f:
            ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
        x_train, y_train, x_valid, y_valid = map(torch.tensor, (x_train, y_train, x_valid, y_valid))
        print(x_train.shape)
        self.trainx = x_train
        self.trainy = y_train
        self.len = self.trainx.shape[0]

    def __getitem__(self, index):
        return self.trainx[index],self.trainy[index]
    
    def __len__(self):
        return self.len

class ZKMnistTestDataset(Dataset):

    def __init__(self,filepath):
        super(ZKMnistTestDataset,self).__init__()
        with gzip.open(filepath, "rb") as f:
            ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")
        x_train, y_train, x_valid, y_valid = map(torch.tensor, (x_train, y_train, x_valid, y_valid))
        print(x_train.shape)
        self.trainx = x_valid
        self.trainy = y_valid
        self.len = self.trainx.shape[0]

    def __getitem__(self, index):
        return self.trainx[index],self.trainy[index]
    
    def __len__(self):
        return self.len