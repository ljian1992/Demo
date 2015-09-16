__author__ = 'ljian1992'

import os

if __name__ == '__main__':
    BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

    # __file__ 脚步的相对路径
    print(__file__)

    # 绝对路径
    print(os.path.abspath(__file__))