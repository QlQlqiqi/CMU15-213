docker 环境见 [github](https://github.com/Yansongsongsong/CSAPP-Experiments/tree/master) 和 [知乎](https://zhuanlan.zhihu.com/p/82529114)

[labs frame](https://github.com/XieGuochao/csapp)

[official labs](http://csapp.cs.cmu.edu/3e/labs.html)

[video(github)](https://github.com/EugeneLiu/translationCSAPP)

[shedule](https://www.cs.cmu.edu/afs/cs/academic/class/15213-f15/www/schedule.html)

[CSAPP 解读](https://fengmuzi2003.gitbook.io/csapp3e/)



### datalab

参考 [知乎](https://zhuanlan.zhihu.com/p/59534845)

<img src="https://article.biliimg.com/bfs/article/5447c8b8c02ab4dec6c44aa25914cb3afd94ae51.png" alt="image-20230618184447518" style="zoom: 80%;" />

<img src="https://article.biliimg.com/bfs/article/d832592f03fbe96c4c90548781f404846bc9fcb7.png" alt="image-20230618184506596" style="zoom: 67%;" />



### bomblab

这个主要是学习了 gdb 调试、看反汇编代码。

我是跟着这个 [博客](https://earthaa.github.io/2020/01/12/CSAPP-Bomblab/) 学习的，最后一个太长了（hard for the best student），没写，其他的难度比较递增。

下面是我 copy 上面博客中的部分参考：

|         命令          |                         功能                         |
| :-------------------: | :--------------------------------------------------: |
|     gdb filename      |                       开始调试                       |
|          run          |                       开始运行                       |
|       run 1 2 3       |            开始运行，并且传入参数 1，2，3            |
|         kill          |                       停止运行                       |
|         quit          |                       退出 gdb                       |
|       break sum       |              在 sum 函数的开头设置断点               |
|    break *0x8048c3    |             在 0x8048c3 的地址处设置断点             |
|       delete 1        |                      删除断点 1                      |
|       clear sum       |              删除在 sum 函数入口的断点               |
|         stepi         |                     运行一条指令                     |
|        stepi 4        |                    运行 4 条指令                     |
|       continue        |                   运行到下一个断点                   |
|       disas sum       |                   反汇编 sum 函数                    |
|     disas 0X12345     |             反汇编入口在 0x12345 的函数              |
|  print /x /d /t $rax  | 将 rax 里的内容以 16 进制，10 进制，2 进制的形式输出 |
|      print 0x888      |               输出 0x888 的十进制形式                |
| print *(int*)0x123456 |      将 0x123456 地址所存储的内容以数字形式输出      |
| print (char*)0x123456 |             输出存储在 0x123456 的字符串             |
|       x/w $rsp        |             解析在 rsp 所指向位置的 word             |
|       x/2w $rsp       |           解析在 rsp 所指向位置的两个 word           |
|      x/2wd $rsp       |    解析在 rsp 所指向位置的 word，以十进制形式输出    |
|    info registers     |                      寄存器信息                      |
|    info functions     |                       函数信息                       |
|      info stack       |                        栈信息                        |

![1_4ipwUzIWd4eqUvcEmZ5tMQ](https://article.biliimg.com/bfs/article/167c03900b7d1d7b5768567d4cf9e9c2b30fcba7.png)



### attacklab

> 没做最后一个

参考 [blob1](https://earthaa.github.io/2020/02/11/CSAPP-Attacklab/) [blob2](https://zhuanlan.zhihu.com/p/60724948)

- 了解基本的程序攻击/防护方式；
- 了解 stack frame 大致组成；

