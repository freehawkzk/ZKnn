# -*- coding: utf-8 -*-


from torchvision import transforms
from PIL import Image
import warnings
warnings.filterwarnings("ignore")



img = Image.open('/home/zk/src/images/1.jpg')

print(type(img))
print(img.size)

# 将输入的PIL.Image重新改变大小成给定的size,size是最小边的边长。
crop = transforms.Scale(300)
croped_img=crop(img)
print(type(croped_img))
print(croped_img.size)

croped_img.show()

img_tensor = transforms.ToTensor()(croped_img) # 转换成tensor
print("img_tensor",img_tensor)

# 图像转换，
croped_img_1=transforms.ToPILImage(img_tensor)
print("croped_img_1",croped_img_1)

# 图像缩放，将原是PIL图像重新调整到指定形状。
croped_img_2=transforms.functional.resize(croped_img_1, [300,578], interpolation=2)
print("croped_img_2",croped_img_2)
croped_img_2.show()

