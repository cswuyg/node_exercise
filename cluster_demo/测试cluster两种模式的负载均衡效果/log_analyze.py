#-*-coding:utf-8-*-
# 处理日志，统计各个worker进程被掉起次数 
# cswuyg
# 2016.02.16

a = dict()
with open('a.log') as f_r:
    for line in f_r:
        line = line.strip()
        a.setdefault(line, 0)
        a[line] += 1
b = sorted(a.items(), key=lambda d: d[1]) 
for item in b:
    print item
