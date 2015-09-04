# -*- coding: utf-8 -*-
__author__ = 'Ljian'
import os


# 获取操作系统的类型，nt--window, posix--Linux, Unix, Max OS X
systytpe = os.name
print(systytpe)
if os.name == 'nt':
    print('window')
else:
    print('Linux, Unix, Max OS X')

# 获取操作系统的详细信息，windows平台不提供
#os.uname()


# 获取环境变量,
env_value = os.environ
print(env_value)
print(env_value.get('PATH'))

# 获取当前目录
cwd = os.getcwd()
print(cwd)


# 查看清单目录的绝对路径:
abs_path = os.path.abspath('.')
print(abs_path)

# 返回指定目录所有的文件名和目录名，非递归获取
dirs = os.listdir('.')
print(dirs)

# 判断路径是否存在
path = "F:sdf"

if os.path.exists(path):
    print("exit %r" % path)
else:
    print("not exit: %r" % path)


# 删除文件
path = './test'
if os.path.exists(path):
    os.remove(path)
    print('remove %s succeeded.' % path)
else:
    print("not exit: ", path)

# 重命名
try:
    os.rename('./tifa.jpg', 'ttifa.jpg')
except FileNotFoundError as e:
    print('FileNotFoundError', e)

# 创建，删除目录， removedirs()在目录有文件的情况下，不会被删除

if os.path.exists('./testdir'):
    os.removedirs('./testdir')
    print('remove %s succeeded.' % './testdir')
else:
    os.mkdir('./testdir')
    os.removedirs('./testdir')

# 返回文件大小
filesize = os.path.getsize('./The_Zen_of_Python')
print(filesize)


# 判断是否是文件
print(os.path.isfile('./with_as.py'))

# 判断是否是目录
print(os.path.isdir('./with_as.py'))
print(os.path.isdir('../File'))

# 判断是否是绝对路径
print(os.path.isabs('./with_as.py'))

# 判断是否是链接
print(os.path.islink('http://www.baidu.com'))


# 路径合成
path = os.path.join(os.getcwd(), 'testdir')
print(path)

# 路径拆分，最后一个级别的目录和文件名
path_split = os.path.split(os.path.abspath('.'))
print(path_split)

# 扩展名的拆分
path_splitext = os.path.splitext('./use_StringIO_BytesIO.py')
print(path_splitext)


list = [x for x in os.listdir('.') if os.path.isfile(x) and os.path.splitext(x)[1] == '.py']
print(list)


