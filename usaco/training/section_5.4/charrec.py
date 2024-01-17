"""
ID: huangch7
LANG: PYTHON3
TASK: bigbrn
"""
import math

task_name = "bigbrn"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

chars = ' abcdefghijklmnopqrstuvwxyz'


fout.close()
