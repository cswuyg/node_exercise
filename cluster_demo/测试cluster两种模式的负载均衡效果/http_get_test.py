#-*-coding:utf-8-*-
# 测试并发访问web服务
# cswuyg
# 2016.02.16

import requests
import multiprocessing

def test_func():
    url = 'http://xxx.com:8678/'  # your host
    ret = requests.get(url)                                                                                                    
    print(ret)

def main():
    pool = multiprocessing.Pool(processes=12)
    for i in xrange(1, 1000):
        pool.apply_async(test_func);

    #pool.terminate()
    pool.close()
    pool.join()
main()
