回顾:
 排序算法:冒泡、插入、选择、快速
 冒泡 是相邻元素比较，大的放后面。
 插入 是后面的无序元素依次插入到前面的有序元素中。
 选择 是找到第n小的元素和第n个元素交换。
 快速 是通过 元素的移动实现前面的都小，后面的都大，再利用递归调用完成所有的排序

  
 UC - Unix/Linux系统下C的开发
  就业方向：
   C++软件工程师
   Unix/Linux开发工程师(UC)
   Windows MFC开发工程师(C++)
 或ARM开发工程师
  
  内容：
   1 Unix/Linux的静态库和共享库
   2 C语言的错误处理
   3 环境变量和环境表
   4 Unix/Linux的内存管理
   5 Unix/Linux的文件操作
   6 Unix/Linux的目录操作
   7 Unix/Linux的进程管理
   8 Unix/Linux的信号处理
   9 IPC-进程间通信(共享内存、消息队列)
   10 Unix/Linux的网络编程
   11 Unix/Linux的多线程开发

主流开发语言都是 C语系。
 
  软件行业 分三层：规范、产品、项目。
   规范也叫标准，是 行业的准则。
   产品是具体的软件，产品 是 按照大多数用户的需要编写的软件，一般不会按照个人用户的想法 改变。产品重质量。
   项目是针对特定的客户需求，软件受到客户的制约，做项目一般比较累。
  
  Gcc编译器:
  编译器	gcc 是编译器的合集，主流语言都可以编译。
  gcc -c 只编译，不连接，生成目标文件.o
  gcc -o 改变目标文件的名称
  gcc -E 只做预处理，不编译，不连接
  gcc -S 生成汇编文件
  gcc -v 可以查看编译器的版本
  gcc -Wall 可以显示更多的警告信息

 gcc的完整过程：
  1 预处理 ，针对所有的指令(以#开头)
  2 编译，检查基本的语法错误
  3 汇编，把代码变成机器指令
  4 连接，把周边的函数链接进来。
 练习：写一个hello.c，练习gcc的用法。 

在vi中，在进入状态按G可以直接到文件尾，1G到文件头。
  gcc -E test.c -otest.i

 C语言头文件.h和源文件.c都做什么用？
  .h文件用于各种声明(变量、函数、结构)
  .c文件放各种实现。

 常用的指令：
  #include 包含一个头文件
  #define 定义宏变量/宏函数
  #if/elif/ifdef/ifndef/endif 条件编译

  #error   产生错误
  #warning 产生警告
  #pragma  增加一些额外的功能
   #pragma GCC dependency 文件名a
   会比较当前文件和a谁的时间更新，如果a的时间更新，会产生一个警告。
   #pragma GCC poison 单词
   禁止使用poison后面的单词，否则产生错误。
   #pragma pack(整数) 针对 结构的对齐和补齐，整数如果为1，取消对齐和补齐，为2就是按照2的倍数对齐和补齐。   

  环境变量和头文件
   操作系统在运行时，会把一些常用的配置放入内存中，这些叫 环境变量。比如：可执行文件 默认情况下要带路径才能执行，但 也可以使用环境变量PATH去掉路径。只要把可执行文件的路径配置到PATH(系统路径)中，就可以在执行时 省略路径。命令echo可以输出环境变量的值：
   echo $PATH 多个目录用:隔开
  在bash中，配置环境变量：
   export PATH=$PATH:.
  $PATH代表之前配置的环境变量依然有效
  : 多个目录分隔
  . 当前目录

  想要永久有效需要把export 写入启动文件中，比如：登录目录/.bashrc。
  用source .bashrc 重新加载。
  
  自定义头文件，可以用三种方式include:
  1 用 ""方式
  2 gcc -I目录 (大写i)
  3 配置环境变量CPATH
    export CPATH=目录
###################################################################################################
回顾：
  查找算法:线性和二分
  Unix/Linux的常识
  gcc 
  环境变量和配置环境变量
  如何找到自定义头文件？
  1 用 "" ，里面 使用路径
  2 gcc -I目录 
  3 配置环境变量 CPATH
   export CPATH=目录
  指令：
   #warning #error 
   #pragma 
    #pragma GCC dependency
    #pragma GCC poison
    #pragma pack(整数)

今天：
  商业开发中，代码都是连接成库文件，在使用时直接面对库文件，而不是一个一个的源文件。
  Unix/Linux的库文件有两种：静态库和共享库(动态库)。因此，商业开发需要提供的是:
  库文件和头文件 - Unix系统也是这么做的
  静态库(.a文件)是 代码的合集，在使用时直接复制代码到目标文件中。
  共享库(.so文件)是 代码的合集，在使用时把代码(函数)的地址存到目标文件中。
  静态库的优点是速度稍快，运行时不需要再访问静态库，缺点是占用空间大，费资源，不利于代码的维护和修改。
  共享库的优点是省资源，利于代码的维护和修改，缺点是速度稍慢，运行时必须连带共享库(可执行文件中没有库函数代码，只有库函数地址)。
  商业开发基本都是使用共享库。
  如何创建和调用静态库？
   1 创建
    1.1 写源程序.c，保存退出。
    1.2 编译源程序，生成目标文件.o
     gcc -c add.c
    1.3 把目标文件打包成静态库文件。
     ar -r 库文件名 add.o 
     如果有多个.o，在add.o后面继续写
     库文件名有命名规范:
      以lib开头，后缀是.a，中间写库名
     比如：libmyku.a 是库文件名，库名是 
      myku
   2 调用
    2.1 写源程序testadd.c,保存退出。
    2.2 编译源程序，生成目标文件.o
      gcc -c testadd.c
    2.3 连接testadd.o和库文件,有三种方法
     a 直接连接
      gcc testadd.o libmyku.a
     b 配置环境变量LIBRARY_PATH，把库文件所在路径配置进去，然后用命令：
      gcc testadd.o -lmyku (库名)
     c 双L配置法，用命令：
      gcc testadd.o -lmyku -L路径
 2 共享库的创建和使用
   2.1 创建
    a 写源程序，保存退出。
    b 编译源程序，生成 .o文件。
    gcc -c -fpic add.c  (-fpic不写也行)
    c 生成共享库文件(.so)
    gcc -shared add.o -olibmyku.so
   共享库命名规范：以lib开头，以.so做后缀，中间是库名。
   2.2 调用
    a 写源程序testadd.c 保存退出
    b 编译源程序，生成.o文件。
    c 连接，与静态库一样，有三种方法。
     gcc testadd.o -lmyku -L. (双L)
 注：连接成功的a.out在运行时，必须配置LD_LIBRARY_PATH=库路径 才能运行起来。
  关于库的命令：
   ldconfig 可以管理共享库
   ldd 可以查看相关的共享库。
     ldd a.out
    某些共享库后缀是 .so.整数
  系统提供了一些函数可以直接在程序中打开共享库，执行其中的函数(动态编程API)。
  API = 应用程序接口(程序对外提供的函数)
  #include <dlfcn.h>
  dlopen() - 打开共享库
  dlsym() - 从一个打开的共享库中获取一个函数
  dlclose() - 关闭打开的共享库
  dlerror() 用于处理错误。(了解)

  C语言的错误处理 - 程序员编写软件时，除了正确的分支要处理，出现意外情况(错误)时也要做相应的处理。
  后期的语言(C++/Java)都是使用 异常机制处理错误，C语言没有异常，用 返回值代表出错，出错的处理代码单独写分支。
  有4种常见的出错代表方式：
   1 如果返回值是int，并且返回的数据不可能是负数，用返回 -1 代表出错。
   2 如果返回值是int，并且返回的数据可能是负数，用 指针把数据带回，返回0 代表正确，返回-1 代表出错。
   3 如果返回值是指针类型，返回NULL代表出错。
   4 如果不需要考虑错误处理，返回值定义为void即可。
  函数返回数据的方法有两种：
   1 return 返回   2 用指针参数带出。  
  
  注：以上错误处理方式只是经验，不是绝对的。
 练习：
   写4个函数，并设计这4个函数的错误处理方式。
   1 传入2个整数，求最大值，如果相等，返回错误。(第二种)
   2 返回0-9的随机数，如果随机到5，返回错误。(第一种)
   3 传入一个字符串，如果字符是"error",返回错误，否则返回原字符串。(第三种)
   4 换行打印传入的字符串。(第四种)
  写一个main()测试。

 在C语言中，关于错误处理，也提供了支持：
  提供了一个外部的全局变量，errno用于存储错误的编号，每个错误的编号都对应一种错误信息。
 有3个函数可以依靠错误编号获取错误信息：
  strerror() - 传入一个错误编号，返回错误信息。
  perror() - 传入一个字符串(附加数据)，打印错误信息(自动去找errno)。
  printf("%m") - 打印错误信息(自动找errno)。

 man 可以查询unix命令、函数和头文件。如果重名，可以man 2 或 man 3。
  
  昨天在命令方式下 配置了环境变量，在程序中也可以获取/修改环境变量。
  在系统中，定义了一个外部全局变量存储了所有的环境变量，其实是一个字符指针数组，叫 环境表。
  只要在程序中，写上：
   extern char** environ;//字符指针数组
  environ 就是环境表的首地址，存储了所有的环境变量，以NULL结束。
  关于指针：
   int i = 5;
   int* pi = &i;
   pi 是 指针，存储的是i的地址，指向i。
   i 是 普通变量，存储的是 5 ，i自身对应一块内存区域。
  pi++ 和 pi+1 的移动效果一样。
  pi+1 的移动效果：移动到下一个元素上。因此pi+1移动的字节数 由 指向的类型决定。
  char* 移动1个字节，int* 移动4个字节。
  
 数组类型都是常指针，就是不能改变地址的指针。因此数组不能再次赋值，但数组元素可以赋值。 
   int arr[5] = {0};//初始化可以
   arr = xx;//不能对arr数组赋值
   arr[0] = 5; //对数组元素赋值 可以

###################################################################################################

回顾：
  静态库和共享库的创建和调用
  共享库的创建和调用(ldd命令)
  C程序员的错误处理方式
   1 返回int，如果返回的数据不会是负数，用-1 代表错误，数据也 return 。
   2 返回int，如果返回的数据可能是负数，用-1 代表错误，用0 代表成功，数据用指针获取。
   3 返回指针，用NULL 代表出错。
   4 不需要考虑错误处理的函数，可以用void做返回类型。
  程序员 如何获取环境变量(使用环境表)
   extern char** environ;
今天：
  系统也提供了环境变量的相关函数：
   getenv() - 按环境变量的name获取value
   putenv() - 新增/修改 环境变量
   setenv() - 新增/修改/不动 环境变量
   unsetenv() - 按name删除 环境变量
   clearenv() - 全部删除所有环境变量
  putenv()当环境变量存在时，一定修改
  setenv()当环境变量存在时，可以选择是否修改，第三个参数为1 修改，为0 就不修改。
   
 Unix/Linux内存管理
  1 相关函数
   STL    ->  自动管理
    |
   C++    ->  new/delete
    |
   C语言  ->  malloc()/free()
    |
 Unix系统函数  -> sbrk()/brk()
    |
 Unix系统函数  -> mmap()/munmap()    
    |                        (用户层)
 -------------------------------------
                             (内核层)
 Uc 讲 malloc()/free()/brk()/sbrk()/
  mmap()/munmap()

  2 一个进程的内存空间
   程序和进程
   程序是 保存在硬盘上的可执行文件。
   进程是 运行在内存中的程序。
   链接的成品 是程序，运行起来的程序叫进程。
   内存空间针对进程，一个进程包括的内存空间：
   2.1 代码区 存函数的代码，只读区，函数指针就是 函数在代码区的地址。
   2.2 全局区 存 全局变量和static的变量
   2.3 BSS段 存 未初始化的全局变量，main()函数在执行前 会自动对 BSS段清0。
   2.4 栈区 存 局部变量(包括函数的参数)，栈区的内存管理是系统自动完成。
   2.5 堆区 也叫自由区，new/delete/malloc()/free()都是在堆区分配、回收内存，程序员完全管理堆区。因此如果程序员没有及时回收内存，就 内存泄露。
   2.6 只读常量区 存字符串的字面值(" ")和const的全局变量，只读区。

  3 Unix/Linux内存的管理机制
   Unix/Linux采用 虚拟内存机制管理内存。
   每个进程都先天具备0-4G的虚拟内存地址空间，虚拟内存地址 其实就是一个整数(编号)，本身不对应任何的内存/硬盘，因此虚拟内存地址 先天存在，但先天 不能存储数据。虚拟内存地址 必须 映射物理内存/硬盘文件才能真正存储数据，这个映射的过程就是内存分配。
   程序员只能接触到 虚拟内存地址，而不能接触物理内存的真实地址。
   虚拟内存地址分为两块，用户层使用0-3G，内核层使用3G-4G，程序只能直接访问用户层，用户层不能直接访问内核层。
   内存的管理单位 是 字节，内存映射的基本单位是 内存页。1个内存页是 4096字节(	4k)，一次映射必须是内存页的整数倍。

  如果没有映射物理内存/硬盘文件就直接使用虚拟内存地址，会引发段错误。

 Linux系统中，几乎一切都被看成了文件，目录、内存、各种设备都看成了文件。
 每个进程的内存都在 /proc/进程ID/ 下，其中有maps的文件 可以查看内存页。进程ID可以用ps -aux查看。函数getpid()可以获得当前进程的PID。
  cat /proc/PID/maps
 
 进程的内存空间的从小到大的次序：
  代码区、只读常量区、全局区、BSS段、堆区、栈区。
  其中，堆区和栈区相隔很远，栈区从接近3G的位置开始，堆区挨着BSS段。堆区地址从小到大排列，栈区地址从大到小排列。
 
  关于字符串:
   字符串赋值时，指向只读区的只能用 = 改，字符数组格式的只能使用strcpy()改，指向堆区的也用 strcpy()改。
  
##########################################################################################################

回顾：
  Unix/Linux的内存管理
   Unix系统采用虚拟内存管理技术，每个进程都有0-4G的虚拟内存地址，本质就是整数，不能直接存储数据，必须先做内存映射后才能存储数据。内存映射可以映射 物理内存/硬盘文件。如果使用没有映射的虚拟内存地址，就会引发段错误。对内存进行没有权限的操作也会引发段错误(修改只读区)。程序员接触的都是 虚拟内存地址。
   虚拟内存分为用户空间和内核空间。
   虚拟内存地址的管理以字节为单位，但内存映射以 1个内存页(4096字节) 为单位。
   进程的内存分为6个部分：
   代码区、全局区、BSS段、堆区、栈区
   只读常量区
   内存分配和回收函数:
   malloc() free()
   sbrk() brk()
   mmap() munmap()

 指针和数组
  char arr[5] = {}; //arr是字符数组，也可以看成 char* (常指针)
  *(arr+2) == arr[2]
char* pc = "abc";//pc是字符串的地址，也可以用数组的方式使用
  pc[2] == *(pc+2)
区别：
 sizeof(指针) = 4
 sizeof(数组) = 数组长度*元素的大小
 当数组做参数时，形参其实是 指针类型，所以还要传数组的长度。
 指针可以返回，数组不能返回。
  int x = 5；
  int* pi = &x;
  pi相关的有两个地址：
   pi是变量，有自己的地址(自身地址&pi)。
   pi是指针，存储了x的地址(指向地址pi)。
  在有符号的整数(int)中，
   最大值是：0x7FFF FFFF
   最小值是：0x8000 0000
   近似值 是正负 21亿 之间。

 输入输出缓冲区
  程序为了提高效率，在输入输出函数中，都会设定一个缓冲区。数据先放入缓冲区，在必要时才真正的输入输出。比如：
  int i;
  for(i=0;i<10;i++) printf("%d ",i);
  while(1);
  打印不会显示，因为数据放入了输出缓冲区，不满足输出缓冲区 输出的条件。
  输出缓冲区真正输出的条件：
   1 程序正常结束
   2 遇到'\n'
   3 缓冲区满了
   4 fflush()函数可以刷新缓冲区 强行输出
今天：
 malloc()分配的是堆区的内存，malloc()分配的内存必须由free()释放，否则就等到程序结束。malloc()和free() 应该成对出现。
 malloc()其实一次映射了33个内存页。如果一次申请的内存超过 33个内存页，会分配比 申请的内存 多一点的内存页(没有具体说多几页)。
 malloc()分配内存时，会额外存储一些附加信息，比如:分配大小。这些附加信息帮助程序员实现一些功能，比如:free()。因此malloc分配的内存，地址是 不挨着。
 free()只是释放 虚拟内存地址，未必会解除内存的映射，最后33个内存页 free()不会解除映射(最后33页的虚拟地址 反复使用)。只有进程结束时才 解除 映射。
 free()其实就是把 已经使用的虚拟内存地址的状态改为未使用，不一定会解除 与物理内存/硬盘文件的映射。(最后33页不会解除)
  经验：
  1 在应用时，只需要 分配内存用 malloc(),释放内存用 free()。
  2 malloc()分配内存时，不要越界使用，否则会毁坏附加数据，影响free()。

 sbrk()和brk() - Unix的系统函数(Windows下面不能使用)
  sbrk()和brk()函数 本身都同时具备分配和回收内存的功能。sbrk()分配内存更方便，brk()回收内存更方便。
  sbrk()和brk()都是通过底层维护的一个位置进行内存的分配和回收。
  void* sbrk(int increment)
  参数increment就是内存的大小：
   正数 代表 分配increment字节内存
   负数 代表 回收-increment字节内存
   0 代表 获取当前的位置(不分配也不回收)
  返回 移动之前的位置(对负数没意义),发生了错误 返回(void*) -1。
  sbrk()/brk()映射内存都是 1页，getpagesize()可以取得当前系统的1页大小。
  sbrk()/brk()在分配内存时，以1个内存页为基本单位，超了就多一页，释放了就少一页，全释放就没有内存页，映射也随之解除。
 
  int brk(void* new)
   brk()就是把位置 移动到new，可能是分配，也可能是回收。
   成功返回0，失败返回-1。
 结论：用sbrk()分配内存，用brk()回收。
  练习：改良刚才的brk.c，用sbrk()分配，brk()只负责回收内存(重新写一个.c文件)。

 mmap()和munmap() - 用户层中最底层
  主要用于: 
  虚拟内存地址和物理内存(硬盘文件)的映射
  
  如果多个选项想拼起来，用 位或 | 。
   chmod 777 a.txt
   rwx
   r 100
   w 010
   x 001

  rw代表读写？ 位或运算
   100 | 010 = 110 == 6 

 void* mmap(void* addr,size_t size,
int prot,int flags,int fd,off_t offset)
  参数addr一般给0即可，内核选定首地址
  size是映射的大小，以内存页为基本单位
  prot是权限，一般PROT_READ|PROT_WRITE
  flags是选项，主要包括：
   MAP_PRIVATE MAP_SHARED 私有/共享，对映射物理内存没区别，二选一
   MAP_ANONYMOUS 代表映射物理内存，mmap默认映射 硬盘文件。
   fd和offset映射文件用，给0即可。
  返回 映射的首地址，失败返回 MAP_FAILED
  就是(void*)-1。

########################################################################################################

回顾：
  Unix/Linux的内存分配和回收的函数
  malloc() free() - 标C
  brk() sbrk() - Unix系统函数
  mmap() munmap() - Unix系统函数
  
今天：
  mmap()的代码
  系统调用
  文件操作: 文件描述符、Unix/Linux关于读写文件的系统函数(标C函数在Unix系统的底层支持)
  系统调用：虚拟内存地址分为用户空间和内核空间，用户空间不能直接访问内核空间，而程序又需要进入内核空间，因此，Unix/Linux系统对外提供了一种用户空间进入内核空间的方法。Unix系统提供了一系列的函数，让用户空间调用函数从而进入内核空间。这一系列的函数叫做 系统调用(System Call)，这些函数被定义在POSIX规范中。

 文件管理
  1 Linux把一切都可以看成文件，比如：目录、内存、各种设备。
  比如：/dev/tty 代表键盘和显示器
  /dev/null 代表空，可以有特殊用法
  cat /dev/null > a.txt 清空文件内容

  文件操作有5个基本函数，可以打开/读/写各种文件。
  open() - 打开文件，返回一个文件描述符
  read() - 读已经打开的文件
  write() - 写已经打开的文件
  close() - 关闭打开的文件
  ioctl() - 文件的操作(了解)

  文件描述符本质上就是一个非负整数，对应一个打开的文件，文件描述符 就是 一个打开的文件的编号。每个进程都有一个 文件描述符的总表，总表中存储已经使用的文件描述符。
  文件描述符自身不记录文件的信息，文件信息记录在 文件表 中，文件描述符 对应 文件文件表。
  open()函数会先 打开一个文件，把信息存入文件表中，再去文件描述符总表中寻找当前没有使用最小编号，与文件表对应，并把 对应关系放入 总表中。
  一个文件表 可以 被多个文件描述符对应。
  文件描述符从3开始，因为0,1,2被系统占用，代表了标准输入、标准输出和标准错误。

 open()函数可以新建/打开文件，返回文件描述符。
 int open(char* filename,int flags,...)
  参数filename就是文件名(带路径)
  flags是open的标识，主要包括：
   O_RDONLY O_WRONLY O_RDWR:打开权限,3选1
   O_CREAT:新建文件，如果文件存在就打开
   O_EXCL:一般和O_CREAT联合使用，代表如果文件存在就返回错误(-1)，不存在就新建
   O_TRUNC:一般和O_CREAT联合使用，在打开已经存在的文件时会自动清空文件。
   0_APPEND:以追加的方式 写文件
  参数 ... 代表 0-n个任意类型的参数。
  返回 文件描述符，如果 错误 返回 -1。
 注：open()在新建文件时，需要第三个参数，第三个参数 是新文件的访问权限。
  关于open()有两个权限，一个是内存中 文件描述符的权限，另一个是硬盘中 文件的权限。内存中 描述符的权限 小于等于 硬盘中文件的权限。
  读写函数：
 int read(int fd,void* buf,size_t size)
 int write(int fd,void*buf,size_t size)
  参数：fd就是打开的文件的描述符
    buf是 读/写的 内存区域的首地址
    size对于read()是buf的大小，无论是否能读满。对于write()是数据的真实长度，而不是buf的大小。比如：
   char buf[100] = {};
   read(fd,buf,sizeof(buf));
   write(fd,buf,strlen(buf));
  返回：正数代表 读到/写入的字节数
   0 代表读到文件尾/没有写入任何数据
   -1 代表出错。

 vi的特点：用x退出 不会添加东西
  用wq退出 会加上结束符，实现换行。
  但读写函数不加。

 练习1：文件拷贝
 练习2：完成一个员工信息的保存和取出。
  要求: 用scanf()输入员工的信息，包括：
   编号ID、姓名、工资(double)
  把信息存入文件 em.dat 中。
  并再写一个文件把信息从文件中读出来。

 思路：定义一个结构，把结构写入文件中。
  
 练习&作业：
  1 改变上面的写入代码，要求用vi可以查看到所有信息。
  思路：把所有员工信息拼入一个字符串，直接把字符串写入文件即可(sprintf())。

  2 实现一下 用户的注册和登录。
  1 先做用户注册，用户注册的流程：
   首先输入用户名、密码和email，存入用户结构中，把用户结构写入文件(用追加方式写入 舍O_TRUNC换O_APPEND)。
  2 再做用户的登录，用户登录流程：
   首先，输入用户名和密码，循环把所有用户信息从文件中读出来，逐一比较，如果有用户名和密码都相同的，登录成功，否则失败。
   (可以考虑使用链表，也可以使用数组。)
  数组的长度 = 文件大小 除以 结构的大小
  文件的大小标C代码：
   1 fopen() 2 fseek()文件尾 3 ftell()返回值就是文件大小。
  3 再做用户注册的增强版，两方面功能：
   a 加入密码确认，如果密码不一致，继续输入。
   b 判断用户名不能重复。

#########################################################################################################
回顾：
  文件的读写操作：
   1 理解文件描述符 - 文件表的编号
   2 open() read() write() close()
  
今天：
  文件的其它函数
  memcpy()可以复制一片内存的数据(单位:字节)。
  目前，读写文件有两套方法：
   标C 
   UC
  time a.out 可以查看程序运行的时间，包括在内核层的时间和用户层的时间。
  由于标C函数在用户层有输出缓冲区，而UC函数在用户层没有，因此如果频繁的调用读写函数时，有两种方式：
  1 使用标C函数，用标C函数的缓冲区提升效率。
  2 使用Uc函数，自定义缓冲区提升效率。

  lseek() - 设置文件的偏移量。
   在文件表中，有一个文件偏移量，记录着当前读/写的位置。文件偏移量在硬盘文件上没有做任何的标识(类似于书签)。
   偏移量一开始 在文件头，如果用了O_APPEND在文件尾。每调用read()/write()函数时，会向后移动，读/写一个字节就移动一个字节。
   函数lseek()就是用来移动偏移量，可以任意移动。当偏移量移动文件尾时，可以用lseek()的返回值获得文件的大小。
  第三个参数最好使用SEEK_SET，比较清楚。

  dup()和dup2()
   函数dup()和dup2()用于复制文件描述符，但不会复制文件表。也就是说：2个描述符对应同一张 文件表。
   dup()返回新的描述符，其值由系统自动选择未使用的最小值。
   dup2()返回新的描述符，其值由程序员指定，如果这个值已经被使用，强行关闭后依然使用传入的值。

  fcntl()函数
   int fcntl(int fd,int cmd,...)
  参数fd，一个打开的文件
  cmd是操作的命令，主要包括：
   1 F_DUPFD(long) 复制文件描述符
    和dup2()类似，也是传入新描述符的值，但区别在于 如果这个值已经被使用，将递增使用比该值大的数而不是强行关闭。
   2 F_GETFL/F_SETFL，取/设置 文件状态 
  其中，获取文件状态时，只有权限和O_APPEND可以获取，O_CREAT无法获取。
  设置文件状态时，只有O_APPEND可以。
   3 F_SETLK/F_SETLKW    (了解F_GETLK)
  使用文件锁，用于多个进程同时读写文件时，进行协调。

  经验： 与0做位与，结果为0，与1做位与，结果不变。因此，取某一位或者某几位时，通常使用位与运算。比如：取x后8位二进制，用
  x & 0xFF。
 取flag的O_APPEND位：
  flag & O_APPEND

 多个进程同时读写文件时，有可能出现互相覆盖的情况，或者读到的数据不是 有效的。
 文件锁可以实现，也可以用其它方式，比如进程同步技术。
 fcntl()函数可以设置文件锁，命令：
  F_SETLK(非阻塞，返回错误)  
  或 F_SETLKW(阻塞，会持续等待)
  文件锁定义了一个结构：
   struck flock { //锁的信息
     short l_type; //锁的类型
     short l_whence;//锁定的起始点
     int l_start;//锁定的偏移量
     int l_len;//锁定的长度
     pid_t l_pid;//上锁的进程ID,SETLK时这个参数不用，因此 -1 即可。
   };
  l_type有三个值：F_RDLCK 读锁
    F_WRLCK 写锁   F_UNLCK 释放锁
  l_whence的值为: (一般用SEEK_SET)
    SEEK_SET/SEEK_CUR/SEEK_END
  l_start 就是从起始点 开始的偏移量
  l_len 是锁定区域的长度
  比如：whence SEEK_SET start 10 len 20
   锁定的是 文件的第11个到第30个字节
  读锁是共享锁，针对读操作，允许多个进程读，但不允许任何的写操作。
  写锁是独占锁，所有其他进程都不允许任何操作，无论是读还是写。

  注：上锁是 锁定文件的某个部分，而不是整个文件，因此如果两个文件锁 互相之间没有重合区域，不会互相锁定。
  文件锁 锁定的是 其他进程，自身不受锁的限制。
  文件锁 不会锁定硬盘上的文件，也不会锁定read()/write()，只能 锁定 其他进程 对文件的上锁行为。即：两个进程 不能同时对 文件的同一区域(重合区域) 加2个锁(读读除外)。
  文件锁的正确用法应该是：
   所有进程在读文件之前加读锁，在写文件之前加写锁，读写完成以后 释放锁。

  如果其它进程不能上锁，而又必须完成对文件的读写操作，可以采用 阻塞方式上锁，用F_SETLKW 上锁即可。F_SETLKW 不能上锁时不会理解返回 -1 ，而是 一直在等待。

  函数access() - 可以获取文件的权限和判断文件是否存在(有用)。
  int access(char* filename,int mode)
   参数filename就是文件名
   mode是判断什么？
   F_OK 文件是否存在
   R_OK W_OK X_OK 判断是否有相应权限
   有权限/文件存在返回0，失败返回-1。
 作业：
  1 继续完成 用户的登录和注册。
  2 补充两个功能：
    a 用户信息的修改功能，用户名不能修改，可以改密码和email。
    b 提供删除用户的功能。
   注意：修改用户时，先要找到用户所在的位置，然后用lseek()跳到对应的位置修改数据。 
   删除数据时，后面的数据要顶上来(前移)。函数truncate()可以指定文件的大小。  

###############################################################################################

回顾：
  文件的相关函数 - 非读写函数
   lseek() - 移动文件的偏移量(重点)
   fcntl() - F_DUPFD 复制文件描述符
      F_GETFL/F_SETFL 获取/设置文件状态
      F_SETLK/F_SETLKW 上 文件锁
     文件锁针对 多个进程同时访问文件，如果不做任何的处理会导致数据出现问题。因此：在调用读函数之前上读锁，在调用写函数之前上写锁，读写完毕 立即释放锁。
   dup() dup2() - 复制文件描述符，不复制文件表
   aceess() - 可以判断权限和文件是否存在
    
   close()只是从 描述符总表中移除一个对应关系，不会真正删除文件表。只有当文件表对应的描述符个数为0时，才会真正删除文件表。

   今天：
    文件的其它函数 - stat() chmod()
    truncate() remove() rename()
    目录操作函数 - mkdir() rmdir() 
   chdir() getcwd() opendir() readdir()
    进程  
   stat() - 获取文件的其它信息
    (类似ls -l)
    open()+lseek() 可以获取文件的大小
    stat()可以不打开文件直接获得文件大小
   内存用 虚拟内存地址 代表，硬盘上的文件用 i节点(inode) 代表。i节点就是文件/目录在硬盘上的地址。ls -i 可以查看i节点。
   在C语言中，时间有两种记录方式:
    整数方式: time_t - 返回记录时间和1970年1月1日0点0分0秒的秒差
    结构方式: struct tm - 采用的 xxxx年xx月xx日 xx小时 xx分 xx秒的形式。里面有代表年、月、日、小时、分、秒、星期几的成员。
  计算机 更喜欢第一种，人 更喜欢第二种。
   C语言提供了转换函数：
     ctime() - 把整数方式转成字符串，显示成 年月日方式(按美国人的习惯显示)。
     localtime() - 可以整数方式转成结构方式，程序员自由显示。
   注意： struct tm 中，年需要+1900，月需要+1.
  
  stat()/fstat()经常用于获取文件的大小。
  chmod() - 修改文件权限
  truncate() - 指定文件大小
  remove() - 删除文件/空目录
  rename() - 文件/目录 改名
  umask() - 改变 新建文件时，系统的默认权限屏蔽。(其实不用也可以，用chmod改权限也行)

   目录的操作函数 - 部分函数和文件公用
    mkdir() - 新建目录
    rmdir() - 删除空目录，目录必须先空才能删除
    chdir() - 切换当前目录(cd)
    getcwd() - 返回当前目录的绝对路径形式(不打印的pwd) 
    读目录的子项(子目录和子文件)
     1 opendir() 打开一个目录
     2 readdir() 读一个子项，并移动 目录指针到下一个子项。
  注:想获取所有的子项需要循环，读到NULL退出。
   
  022 -> 000 010 010 (权限屏蔽字)
         111 101 101(取反)
         110 110 110(位与)
  ———————————————————
         110 100 100 (屏蔽了两个写权限)
        
 进程
  进程是运行在内存中的程序。
  在操作系统中，用pid (进程ID)代表进程。
  进程的内存空间:
   代码、全局、BSS、堆、栈、只读常量
  现在的操作系统都支持多进程并行(同时运行)。  
  如何查看进程？
   Windows调任务管理器(ctrl+alt+delete)
   Unix/Linux用命令 ps：
    ps -ef : Unix/Linux 通用
    ps -aux : Linux特有，Unix不直接支持
   ps -ef | more  分页显示
   (回车、空格 -> 翻行、翻页   q退出)
   Unix中，/usr/ucb/ps -aux 可以。
   whereis 可以查找命令在哪里

  操作系统在启动完成以后，是多进程的，但在启动过程中，是一个一个启动的。如果a进程启动了b进程，a进程叫父进程，b进程叫子进程。
  Unix/Linux先启动了进程0，进程0只负责启动进程1和进程2(有些系统只启动进程1)，其它进程都由 进程1 和进程2 直接或间接启动。
  进程1 叫init进程。
  进程的状态：每个进程都有自己的状态，常见的状态有：
   S 休眠状态，进程大多数都处于休眠状态
   O 可执行状态，但没有运行
   R 运行状态
   Z 僵尸进程(僵死进程)
   僵尸进程就是 已经结束但资源没有及时回收的进程。
   
######################################################################################################

回顾：
 文件、目录和进程
 文件操作的函数：
 stat() - 获取文件的各种信息(主要是大小)
 access() - 判断文件是否存在和权限
 chmod() - 修改文件/目录权限
 truncate() - 指定文件的大小
 umask() - 改变新建文件/目录的 权限屏蔽
 mmap() 映射文件的代码
 目录的函数:
 mkdir() - 新建目录
 rmdir() - 删除空目录
 chdir() - 改变当前目录
 getcwd() - 获取当前目录的绝对路径形式
 读目录，获得目录子项：
  1 opendir()
  2 readdir()
 进程的基本概念 - ps 、 进程的关系
 
今天：
  进程 - 父子进程，a进程启动了b进程，a是父进程，b是子进程。
  父子进程之间的关系：
   父进程启动了子进程后，父子进程同时运行，如果子进程先结束，子进程给父进程发信号，父进程收到信号后回收子进程的资源。
   父进程启动了子进程后，父子进程同时运行，如果父进程先结束，子进程变成孤儿进程， 孤儿进程会认进程1(init进程) 做新的父进程，init进程负责回收孤儿进程的资源。init进程 也叫 孤儿院。
   父进程启动了子进程后，父子进程同时运行，如果子进程先结束，子进程给父进程发信号，但父进程没有收到或者收到以后没有及时处理，子进程就变成 僵尸进程。

 关于进程的一些基本函数：
  进程ID的类型： pid_t ，非负整数
  如果获取进程的ID：
   getpid() - 取本进程的进程ID
   getppid() - 取父进程的进程ID
   getuid() - 取当前用户的ID
  
  进程ID(PID)可以重复么？
   同一时刻唯一，但支持延迟重用。
  
  创建进程的方式：
   1 fork()可以创建子进程
   2 vfork() + execl() 可以创建子进程
  区别：
   1 fork()是通过 复制父进程 创建子进程，父子进程执行相同的代码区。
   2 vfork()+execl() 不复制父进程，创建全新的子进程，父子进程执行完全不同的代码区。
   
  fork 就是 叉子，fork()函数将把程序做分叉: 父进程执行一次，子进程也执行一次。
  fork()在创建子进程时，会复制父进程的内存区域，除了代码区之外的其它区域都会被复制，代码区 父子进程共享。
  fork()创建子进程后，导致：
   fork()之前的代码执行一次(父进程)。
   fork()之后的代码执行两次(父子进程)。
   fork()函数自身 返回两次，父进程返回子进程的PID，子进程返回0.

  pid_t fork(void);
   返回值 父进程返回子进程的pid，子进程返回0，失败返回 -1 并不创建子进程。
  fork()函数执行时，如果父进程打开了文件，子进程会复制文件描述符，但不复制文件表。
  fork()创建的子进程，父子进程谁先运行不确定，由操作系统的算法决定。
  fork()在复制时，子进程与父进程的内存地址一样，但指向的物理内存不同。

  进程的结束 - 正常终止 和 非正常终止
   正常终止的情况：
    1 在主函数中执行了return。
    2 调用了exit()/_exit()/_Exit()函数
    3 最后一个线程 正常退出。
   非正常终止的情况：
    1 遇到了某些特殊的信号,比如:Ctrl+C。
    2 最后一个线程被 取消。
   
  exit() 和 _exit()/_Exit() 区别：
   _exit()和_Exit()无区别。
   exit()和_Exit()的区别主要是：exit()不是立即退出，在退出前还可以调用 用atexit()注册的其它函数；而_Exit()是立即退出，不会调用任何的东西。
   return语句的效果 类似于 exit().
   exit() 慢性子，_Exit() 急性子。

  int atexit(void (*fun) (void))
   
   函数声明 把函数名换成(*变量名) 就变成了函数指针;
   
  wait()和waitpid()可以让父进程等待子进程的结束，同时取得子进程的返回值。
  区别：
  wait()会阻塞父进程，直到有子进程结束为止。waitpid()可以选择是否阻塞。
  wait()是等待所有子进程之一结束，waitpid()可以指定等待 特定的子进程结束，也可以任意。
  wait() 和 waitpid() 可以回收 僵尸子进程的资源，得名：殓尸工。
  如果没有子进程，直接返回。
  pid_t wait(int* status)
   wait()函数返回：结束子进程PID，同时用status 获取 结束子进程的返回值和是否正常结束。 失败返回 -1。
  宏函数 WIFEXITED(status)可以判断是否正常结束，WEXITSTATUS(status)可以取 子进程的返回值。

   pid_t waitpid(pid_t pid,int* status
   ,int options)
    参数pid指定 等待 子进程的范围
     >0 就是等待 进程ID是pid的某个子进程
     -1 就是等待 任意(所有)子进程之一
      0 等待本进程组的 任意子进程之一
     <0 等待 进程组ID=|pid| 的任意子进程之一  
    options 为0 阻塞等待
            为WNOHANG 非阻塞，不等待。

####################################################################################################

回顾：
  进程 - Unix/Linux通过进程实现程序的运行。用PID代表一个进程，这个PID是 非负整数，在同一时刻唯一，但可以 延迟重用。
  进程相关函数：
fork()/vfork()/getpid()/getppid()
wait()/waitpid()/exit()/_Exit()/execl()
  fork() 是通过 复制父进程 创建子进程，复制 父进程的 除了代码区之外所有区域，代码区 父子进程共享。文件描述符子进程复制，但不复制文件表。输出缓冲区也会被复制。
  fork()创建的子进程 不确定父子进程谁先运行。但vfork() 确保 子进程先运行。
  wait()/waitpid()让 父进程等待子进程的结束，同时取得子进程的退出状态和返回值。


今天：
  vfork()+execl() 创建的子进程
  信号
  vfork()在语法上与fork()一样，但和fork()在机制上区别很大。vfork()不复制父进程的内存区域，而是 直接占用父进程的内存区域，父进程将处于阻塞状态。因此，vfork()从机制上就保证了子进程先运行。当子进程运行结束或子进程调用了execl()函数时，会把占用的资源还给父进程，父进程就可以继续运行了。
  vfork()必须和exec系列函数(比如：execl)结合使用，vfork()负责创建新的子进程，但不提供执行的代码；execl()无法创建新的进程，但可以替换当前进程的代码和数据，也就是说提供进程的代码和数据。
  vfork()必须用exit()做结束，因为：execl()函数无法启动程序时不会终止程序，此时出错 需要用exit()结束进程。

  关于进程的创建方式:
   1 vfork()和execl()必须结合使用才有意义。
   2 fork()用于 父子进程 执行相同的代码区(父子进程数据有关系)。
   3 vfork()+execl()用于 父子进程执行完全不同的代码(父子进程无关)。

 信号(signal)：
  信号 是Unix/Linux系统中用于软件中断最常用的一种方式。 
  中断 就是 中止现在的代码，转而执行其他的代码。软件中断 就是 用软件的方式中断。
  信号本质上 就是一个 非负整数，为了更好的可读性，给每个信号都起了一个宏名称，都以SIG开头。
  比如：ctrl+c 其实就是一个信号，可以中断死循环。它是信号2，宏名称：SIGINT。编码时最好都使用 宏名称，有些系统 相同信号对应的数字不同，但 宏名称一样。
  命令 kill 就是给进程发送信号，可以用
  kill -l 查看系统所有的信号。
  信号 不一定连续，中间可能有断开。
  有实际意义的信号从1开始，信号0 没有实际意义，用于测试是否有权限发信号。

  kill -9 进程PID -> 发送 信号9 给进程

  信号分为可靠信号和不可靠信号，不可靠信号就是 1-31，不支持排队，因此当有多个信号到来时，有可能会造成信号丢失。可靠信号是34-64，支持排队，无论发送多少次，都会接收多少次，不会丢失。
  常见信号：
    ctrl+C -> 信号2  SIGINT
    ctrl+\ -> 信号3  SIGQUIT
   硬件、软件错误导致的信号：
    段错误 -> 信号11 SIGSEGV
    总线错误 -> 信号7 SIGBUS
    算术运算错误 -> 信号8 SIGFPE
    杀进程 -> 信号9 SIGKILL 

  信号的处理方式：
   1 默认处理，每个信号都有默认处理方式，程序员如果不 另行设置，每个信号都采用默认处理。
   2 忽略信号，信号直接被忽略，不处理。
   3 程序员自定义处理，写一个处理函数，然后设置一下即可。
  注: 信号9 无法忽略，也无法自定义。
   信号可以在进程中自由的发送，但受到用户的限制，当前用户 只能 给 当前用户启动的进程发信号。root可以给所有用户发信号。   kill -0 进程PID 可以测试是否有发送信号的权限。 ps -aux可以查看进程

  信号处理方式在很多时候需要改变，而不是只用默认处理方式。改变信号处理方式为自定义的步骤：
   1 写一个处理函数，格式：
    void fa(int 信号)
   2 用signal() 或者 sigaction()完成设置。
  函数指针 signal(int signum,函数指针)
   其中，signum是信号，代表哪个信号被设置处理方式，而 函数指针 就是当signum来了，调用哪个函数处理。格式：
   void fa(int)
  signal()不仅能把信号处理函数和信号绑定，而且也可以设置信号的处理方式为 忽略/默认(第二个参数用宏变量)。

  信号的处理方式 在创建子进程时的效果？
   1 fork()创建的子进程的信号处理方式与父进程完全一样。父进程默认，子进程默认;父进程忽略，子进程也忽略;父进程自定义，子进程也自定义。
   2 vfork()+execl()创建的子进程，信号处理方式：如果父进程是忽略、默认的，子进程一样；如果父进程是自定义处理函数的，子进程改为默认(父进程的处理函数子进程没有)。

 练习：vfork()+execl()+signal()
  先写一个子进程的代码，打印pid，然后while(1)，编译连接成一个可执行文件a。
  然后再写一个程序，先对信号2定义处理函数，信号3忽略，然后用vfork()+execl()启动上面的进程a，父进程退出即可。
  用kill命令发信号3,2给子进程，测试情况。
 
  信号的发送方式：
   1 键盘发送 (部分)
    ctrl+C -> 信号2
    ctrl+\ -> 信号3
   2 程序出现错误产生信号(部分)
    段错误 -> 信号11
    总线错误 -> 信号7
    整数除以0 -> 信号8
   3 用kill命令发送信号(全部发送)
    kill -信号 PID
   4 信号发送的系统函数
   raise()、kill()、alarm()、sigqueue()
   kill()是重点，alarm()也有用。
    kill()函数可以给任意进程发送任意信号，但 受用户的限制。

   int kill(pid_t pid,int signo)
   参数pid就是发送的进程，signo就是要发送的信号，成功返回0，失败返回-1.
   pid的值(与waitpid()中的pid一样)：
    > 0  发送给特定的进程(PID=pid)
    -1   发送给所有能发送的进程(1除外)
    0    发给本进程组 所有的进程
   < -1  发送给指定进程组的所有进程
    
 sleep() 和 usleep()
  sleep()并不是一定休眠n秒，可以被 非忽略的信号打断，并返回休眠的剩余秒数。
  usleep()以 微秒作为休眠的时间单位，一微秒是 10的-6次方 秒。比如：
   usleep(100000) 休眠0.1秒

 作业：
  写一个 myls.c，实现ls -l的效果，用户名和组名 用ID显示就可以。
  思路：直接调用stat()函数区分显示的是目录还是文件，如果是文件，直接打印即可。
  如果是目录，用opendir()+readdir()+stat()每个子项 实现目录的效果。

  ################################################################################################
  
  回顾：
  进程的创建方式之 vfork()+execl()
  信号
 vfork()创建子进程不会复制父进程的任何的内存区域，目的是去执行execl()启动的代码和数据，vfork()确保子进程先运行。vfork()在执行execl()之后 与父进程是 同时运行。
  信号 本质上也是非负整数，用来做 软件中断。每个信号都有一个宏名称，以SIG开头，编写代码时最好使用宏名称，保持通用性。
  信号处理方式：
   1 默认处理  2 忽略处理  3 自定义处理
  自定义处理的步骤：
   1 写一个格式如void fa(int)的处理函数
   2 用signal()/sigaction()把信号的处理方式改为自定义/忽略。
  信号分为可靠信号和不可靠信号，不可靠信号在Linux中1-31，可靠信号34-64。可靠信号支持排队，不会丢失；而不可靠信号不支持排队，会造成信号的丢失。

今天：
  1 信号集和信号屏蔽。
  2 信号的应用：计时器。
  3 IPC - 进程间通信。

 信号有多个，有很多应用需要一次使用多个信号。如何存储多个信号？利用二进制位可以存储信号。
  sigset_t 类型叫信号集，信号集就是多个信号的集合，是一个超大整数，里边的每个二进制位代表一个信号，0代表没有，1代表有。
  信号集也是一个集合，需要提供函数：
   增加信号
     sigaddset() - 增加一个信号(某位置1)
     sigfillset() - 增加所有信号(全置1)
   删除信号
     sigdelset() - 删除一个信号(某位置0)
     sigemptyset()-信号全部删除(全置0)
   查询信号
     sigismember() - 查询是否有某个信号

  信号可以中断程序，去执行其他代码。如果现在正在执行非常重要的代码，很可能被信号打断，带来不好影响。
  信号不确定什么时间会来，因此在执行关键代码时信号无法确保不来。只能采用信号屏蔽技术，当信号到来时，暂时不做处理，等到关键代码执行完毕后，解除信号屏蔽再处理信号。信号屏蔽 不是 没有信号，而是 把信号的处理时间 延后。
  信号屏蔽的函数：
  int sigprocmask(int how,sigset_t
   *new,sigset_t *old)
   参数：new 是新的权限屏蔽的信号集(被屏蔽的信号放在信号集中)；old 是以前的权限屏蔽的信号集(把以前屏蔽的信号存入old并返回)；how 是信号屏蔽的方式，有3种：
   SIG_BLOCK : 在原有的基础上加入new中的信号，比如：
   A B C   +  C D E  -> A B C D E
   SIG_UNBLOCK : 在原有的基础上减去new中的信号，比如：
   A B C   -  C D E  -> A B
   SIG_SETMASK : 直接屏蔽new中的信号，与原有的无关，比如： (一般使用SIG_SETMASK)
   A B C  C D E -> C D E   
  注：1 只有关键代码才需要使用信号屏蔽
     2 在执行关键代码之前屏蔽信号，在关键代码结束后应 解除信号屏蔽，用 sigprocmask(SIG_SETMASK,old,NULL)。   
  
  函数sigpending()可以获取在信号屏蔽期间来过的信号，存入一个信号集。


  signal()的主要作用是：设置信号的处理方式；sigaction()可以实现和signal()一样的效果，但功能比signal()更强。sigaction()早期用的比较多，简化成signal()。

  信号的应用：(了解)
   alarm() - 闹钟
   计时器 - itimer，有三种，比较常用的是真实计时器，通过产生SIGALRM信号工作。
   计时器的工作方式：
    首先设定一下第一次启动的时间，然后再设定一下间隔时间，就实现了 M秒之后 每隔N秒 产生一个SIGALRM信号。
   计时器能 精确到微秒。
   函数 setitimer()可以设定计时器。

 从现在开始，UC 进入 代码为主的时期。

  IPC - 进程间通信(多个进程之间的数据交互)
  IPC 有很多种办法，包括：
   1 文件
   2 信号(signal)
   3 管道
   4 共享内存
   5 消息队列
   6 信号量集(semaphore arrays)
   7 网络 (Socket编程)
   ....
   共享内存、消息队列和信号量集 统称为XSI IPC，遵循相同的POSIX规范。
   
   管道是 Unix最古老的 IPC 方式之一，Unix/Linux把 管道的交互文件 单独做了一种文件类型 .pipe文件(管道文件)。但现在 IPC基本 不会使用管道。
   管道文件的建立要使用 专门的命令或函数：mkfifo 。管道文件 就是 用于数据交互的媒介。
   管道文件 不直接存储数据，而是作为 IPC的交互媒介，只有 读写进程都在的时候才能畅通，否则 阻塞。
   管道分为有名管道和无名管道，有名管道是程序员建立管道文件，适用于任何进程之间的交互；而无名管道是内核管理管道文件，但只能用于fork()创建的父子进程之间的交互。
   练习：

    利用 管道文件 实现进程a和进程b之间的通信。
   思路：写pipea.c，把100个整数存入管道文件，然后关闭文件。
     然后再写pipeb.c，把100个整数从管道文件中读出来，关闭文件。

   读写管道文件的步骤与读写普通文件一样

  XSI IPC - 是共享内存、消息队列和信号量集的统称，都遵循POSIX规范，因此会有很多相似的地方。
  XSI IPC的同性：
  1 创建时 都需要提供一个外部key，类型key_t(整型)。
  2 key被用来参与 XSI IPC结构(共享内存、消息队列和信号量集)的创建，创建成功后每个IPC结构都有自己唯一的标识(非负整数)ID
  3 在创建IPC结构时，都需要提供结构的访问权限。 
  4 IPC结构由内核管理，如果不手工删除，重启机器后依然占据空间。
  5 key的创建方式有三种：
   5.1 宏 IPC_PRIVATE ，但基本不用，因为私有别的进程无法获取。
   5.2 可以把所有的key定义到一个头文件中，不会发生重复。
   5.3 可以用 ftok()生成key，ftok()使用真实存在的路径 + 项目ID 生成key。
  6 IPC结构的创建/获取函数一般都是
   xxxget() 参数中都有key，新建时一般都需要写上 IPC_CREAT|权限。返回值就是ID。
  7 IPC结构一般都提供了一个控制函数：
   xxxctl()，都提供了以下功能：
  IPC_STAT - 查询
  IPC_SET  - 修改
  IPC_RMID - 删除
  8 IPC结构可以用命令查看、删除：
   ipcs - 查询当前有哪些IPC结构
   ipcrm - 删除当前的IPC结构，需要提供ID
    选项： 
      -a 所有      -m 共享内存
      -q 消息队列  -s 信号量集

  共享内存：进程之间默认情况下 物理内存应该不一样，共享内存就是进程之间共享一块物理内存。由 内核管理一块物理内存，允许其他进程 使用。 共享内存 效率 最高，但 多进程同时修改 会很麻烦。
  共享内存的编程步骤：
   1 生成一个key：
    key_t key = ftok(路径,项目ID);
   2 用key 创建/获取 共享内存ID。
    shmget(key,内存大小,标识);
    创建时的标识：IPC_CREAT|0666
   3 挂接(映射)共享内存。
    shmat(shmid,0,0)
   4 使用
   5 脱接(解除映射)共享内存
    shmdt(shmid)
   6 如果以后永不使用，可以删除共享内存
    shmctl(shmid,IPC_RMID,0)

####################################################################################################

回顾：
  信号 - 信号集sigset_t 信号屏蔽:
   sigprocmask() ：信号屏蔽/解除
   sigpending() ： 判断在信号屏蔽期间有哪些信号到来过
  进程间通信 - 文件、信号、管道、共享内存
  消息队列、信号量集、网络编程
  共享内存的编程步骤：
   1 先 生成key，也可以用头文件定义。
   2 用key 创建/获取 共享内存ID:shmid。
     shmget(key,size,flag)
   3 映射共享内存 shmat(shmid,0,0)
   4 使用内存
   5 解除映射 shmdt()
   6 如果不再使用，可以删除 
    shmctl(shmid,IPC_RMID,0)

今天：
   int shmctl(int shmid,int cmd,
     struct shmid_ds* shmds)
   参数 shmid 就是共享内存ID
    cmd 包括：IPC_STAT/IPC_SET/IPC_RMID
    shmds主要用于查询，删除时给0即可。
    很少使用IPC_SET，因为只能改用户ID/组ID和权限。
   共享内存的优点就是速度最快，但缺点是：多个进程同时写数据时，没法控制。
    
   把数据放入队列中，可以解决问题。为了更好的识别数据，需要给数据附加一些信息。因此，把数据封入消息结构中，把消息放入队列就解决问题了。这个技术已经有了，就是 消息队列。
  
  消息队列：
    系统 负责维护一个队列，每个进程都可以创建/获取队列，再把数据放入队列，其它的进程就可以取队列中的数据(有些数据先封入消息，再把消息放入队列)。
   消息队列的编程步骤：
    1 生成一个 key , ftok()。
    2 创建/获取消息队列，返回ID。
      msgget(key,0) - 获取
      msgget(key,IPC_CREAT|0666) - 新建
    3 发送、接收数据(消息)。
      msgsnd() - 发送消息
      msgrcv() - 接收消息
    4 如果确定不再用，可以使用 
      msgctl(msgid,IPC_RMID,0)删除。
    msgsnd()和msgrcv()
    int msgsnd(int msgid,void* buf,
     size_t size,int flag)
    int msgrcv(int msgid,void* buf,
     size_t size,int msgtype,int flag)
   参数：msgid 代表消息队列
        buf 是发送/接收消息的首地址
        size是消息的大小
        flag基本为0或IPC_NOWAIT
      为0: 如果队列满了再发送 或者 空了再 取出，此时会阻塞(等待消息)。
      IPC_NOWAIIT：上面的情况发生不等待，直接返回错误。
    msgtype 消息类型 - 接收消息时 可以根据消息类型 筛选消息。
   
   消息队列中，数据以 消息的形式存在。
   消息分为 无类型消息和有类型消息。
   无类型消息，就是数据本身，不带附加数据，可以是任何类型(取地址就可以用)。
   有类型消息，会在数据的基础上附加信息，格式必须是个结构:
   struct 自定义结构名{
     long mtype;//第一个成员必须消息类型
     ...//随便写，写多少个都可以。
   };
    mtype 消息类型，可以区分数据是什么，发给谁的。mtype 的值 必须大于0。
   将来进程在接收消息时，可以通过 msgtype参数 区分接收不同类型的消息。
  == 0 接收所有类型的消息
   > 0 接收对应类型的消息
   < 0 接收类型小于等于|msgtype|的消息，接收次序，从小到大。
  
  注： 发送有类型消息时，消息类型的大小可算 可不算(函数的优化)。

###################################################################################################

项目的收获：
  学到的知识如何在项目中应用(开发经验)
比如：文件读写、信号关闭服务器、消息队列
  
  项目的基本流程：
   分sever端和client端
   server的功能：
    启动时的初始化
    等待客户端的请求
    处理客户端的请求并把结果返回给客户端
   client的功能：
    写一个简单的界面
    等待用户的输入
    把用户输入的数据封在消息中提交给服务器
    等待服务器的处理结果并显示给用户

   软件公司的开发流程：
    1 需求分析(确定客户想要什么)
    2 软件分析和设计(搭建软件的基本模型)
    3 编码(程序员的活)
    4 测试(测试员)
    5 维护和部署(维护也包括部分开发)

   UC好好写点东西，是 C++/嵌入式 的就业方向。
 
   XSI IPC之 信号量集(semaphore arrays)

   信号量就是一个计数器，用来控制访问共享资源的最大的并行进程数。计数器的工作方式：
   从 最大计数 开始减少计数，到0结束。
   当有新进程访问共享资源时，计数-1，当计数到0时，会阻塞新进程不允许继续访问。
   当有进程结束访问时，计数+1，当计数从0加1时，阻塞进程中会解除对某一个进程的阻塞。
   总之，计数为0，新进程不能访问共享资源，而如果计数大于0，就可以访问。

  信号量集 就是信号量的数组(计数器数组)，IPC新建/获取的不是计数器，而是计数器的数组(信号量集)。

   信号量的最大值由创建者设定。
   信号量集的编程步骤：
    1 生成一个key  ftok();
    2 创建/获取一个信号量集，函数：
     semget()
    3 如果是新建的信号量集，需要设置最大值，用函数 semctl()
    4 可以使用信号量集，信号量集的基本操作应该是 计数+1(走了)和计数-1(新来)。使用函数 semop()可以实现计数的变化。
    5 如果不再使用，可以使用 
     semctl(semid,0,IPC_RMID) 删除。
  注： semctl(semid,semnum,SETVAL,num)
    参数semnum就是信号量的下标，SETVAL代表在设置最大值，num就是最大值的数量。


  int semop(int semid, struct sembuf 
    semoparray[],size_t nops);
   参数semoparray是一个指针，它指向一个信号量操作数组，信号量的操作由sembuf结构表示：
struct sembuf{
  unsigned short sem_num;//信号量的下标
  short sem_op; //对信号量操作方式:-1和1
  short sem_flg; //0 或 IPC_NOWAIT，如果是0 新来的进程不能访问时(计数0)会阻塞，IPC_NOWAIT 不会阻塞，而是直接返回错误
};

#################################################################################################

今天：
  综合案例 - ATM (缺网络编程)
   无网络，不应用
  网络编程(C语言版 Windows也支持)
   网络常识 - 程序员应该了解的网络相关
   网络编程(socket) - 本地socket(IPC)/网络socket(重点)
   基于TCP协议的网络编程 (套路)
   基于UDP协议的网络编程 (套路)
  网络编程基本上 都是 基于多线程的。
 
  OSI七层模型：(笔试菜题)
   物理层、数据链路层、网络层、传输层、会话层、表现层、应用层。
  TCP/IP把7层模型合并成了4层(5层)：
   把会话、表现和应用层 合并成了大 应用层，物理和数据链路 合并成了 网卡驱动(5层的说法是不合并)。
  协议的概念：制定一件事情/计算机之间的交互的规范，所有编程 都要 遵守这种规范。
  协议簇(协议族)就是多个相关协议的统称，比如：TCP/IP协议簇就是一堆协议的统称，这个协议簇的主体就是TCP协议和IP协议。
  常见协议：
    HTTP - 超文本传输协议，互联网的基础
    FTP - 文件传输协议，包括上传和下载
    TCP - 传输控制协议，传输层协议，一般不翻译
    IP - 网络协议，网络层协议
    UDP - 用户数据报协议，传输层协议
    
  telnet命令可以实现远程登录，格式：
   telnet IP地址 
  输入用户名和密码进入。
   smtp、pop3 - email的收发协议
  
  IP地址：计算机在网络中的地址，本质上是一个整数。IP地址分为IPV4和IPV6，IPV4是主流，32位二进制(4个字节)。IPV6是未来的,128位。主讲IPV4。
  IP地址有两种表示方式：
    点分十进制:每个字节(8位二进制)计算出一个整数，中间用点分开，比如：192.168.0.23 (0-255)；人类使用点分十进制表示IP，计算机底层存储的是整数，用8位十六进制表示。点分十进制和十六进制 在底层存储的都是 32位二进制。
  192.168.0.23 -> C0 A8 00 17 是代表同一个IP地址。
  查看IP地址的命令：
   Windows用ipconfig，查看所有IP地址，用-all 选项(包括物理地址)。
   Unix用ifconfig。
   /sbin/ifconfig 
  IP地址其实自身只是一个整数，它需要和网卡的地址绑定以后才能代表计算机。真正定位计算机的是网卡地址，IP地址只是网卡地址的代言。网卡地址就是物理地址(Mac地址)，每块网卡在出厂时都会配置一个唯一的地址。这种绑定是动态的，同一块网卡在 不同的网络中可以 绑定不同的IP地址。
  IP地址有分类：A类、B类、C类、D类。
  子网掩码 用来判断是否 同一网段。
   IP地址：166.111.160.1
         与166.111.161.45	
 子网掩码：255.255.254.0
  与 子网掩码做位与运算，结果相同的IP地址是同一网段。
   166.111.160.1
   255.255.254.0
-----------------
   166.111.160.0

   166.111.161.45
   255.255.254.0
-----------------
   166.111.160.0
 结果相同，所以是同一网段。

  判断网络是否畅通，用 ping IP地址。

 IP地址可以在网络中定位计算机，端口负责定位计算机中的某个进程(PID是本计算机用的，端口是网络其它的计算机用的)。

  端口：
   端口本质是一个非负整数，是short类型，占2个字节。范围：(0-65535)。
   其中：
   0-1023 不要使用，因为系统先占用。
    比如： 80 - HTTP占用
           21 - ftp占用
           23 - telnet占用
    (可以改变，但一般不改)
   1024 - 48XXX  随便使用，某些软件占用其中特定端口。
   48XXX 以后的，动态端口，不稳定。

  字节顺序：(大头和小头)
   整数在计算机中的存储方式，有两种：
    一种是从大到小，一种是从小到大，
   比如：某整数的字节是 A B C D，
    存储时，可能是ABCD,也可能是DCBA
  本机顺序是不确定的，但网络顺序是确定的，因此在网络编程时，需要把端口转换成网络顺序。
  
  网络编程(socket)的开发步骤：
   socket -> 本意插座，术语 套接字
   网络编程需要什么信息？(IP+端口)
  网络编程的常识：
   1 至少要写两个程序，一个做服务，一个做客户。
   2 一般都是服务器先启动，随时等待客户端的连接(开放服务器的某个端口)。
   3 客户端发送请求，连接服务器，提交自身的数据(包括自身的IP和端口)。
   4 服务器对客户端的请求作出响应，并把处理结果返回客户端。
   5 客户端继续请求，服务器继续响应。
   6 如果不再使用，分别在服务端和客户端关闭。

 socket编程分为 本地和网络，也分为一对一和一对多。
  网络编程的代码可以用于Unix/Windows，步骤如下：
  1 服务端
   1.1 创建一个socket，使用socket()函数
  int socket(int domain,int type,
    int protocol)
    参数 domain 域，用来选择协议簇
     AF_UNIX/AF_LOCAL/AF_FILE 本地通信
     AF_INET  网络通信
     AF_INET6 网络通信(IPV6)
    其中，AF换成PF也一样。
    参数type 选择通信类型
     SOCK_DGRAM   : 数据报 (UDP协议)
     SOCK_STREAM  : 数据流 (TCP协议)
    参数protocol代表协议，但不使用，给0即可。因为协议 已经 被前2个参数确定了。
   返回值是 整数，返回 socket描述符，类似文件描述符，可以用读写文件的方式 读写socket描述符。错误返回 -1.

   1.2 准备通信地址(IP和端口port)。
    通信地址由3个结构体搞定(历史造成)。
    struct sockaddr不真正存数据，做函数的参数。  
    struct sockaddr_un负责存储本地通信的数据，而struct sockaddr_in存储网络通信的数据。本地通信就是一种IPC，使用socket文件做媒介，而网络通信需要记录 IP+port。
 #include <sys/un.h>
 struct sockaddr_un{
   int sun_family;//协议簇,与domain一致
   char sun_path[];//socket文件名  
 };

 #include <netinet/in.h>
 struct sockaddr_in{
   int sin_family;//协议簇,与domain一致
   short sin_port;//端口号
   struct in_addr sin_addr;//IP地址   
 };
  
   1.3 绑定通信地址和socket描述符
    bind(int sockfd,addr,length);
   开放一个端口，允许客户端连接。
   1.4 通信 
    用读写文件的方式就可以通信。
   1.5 关闭socket描述符
    用关闭文件的方式关闭描述符。
  
   2 客户端
    客户端的编程步骤与服务器一样，除了第三步用connect()函数，而不是bind()。connect()的用法(语法)和bind()一样。
   注：客户端准备的通信地址记录的是 服务器端的IP和端口。

  网络编程时，端口和IP地址需要转换函数：
   端口转换函数： htons() 本机转网络
   IP转换函数: 
     inet_addr("192.168.182.14")

  商业开发之 TCP开发步骤：
   TCP 协议 - 基于连接的协议，在通信过程中全程保持连接。
   优势就是可以重发一切错误数据，保证数据的正确性和完整性。但缺点是 服务器压力太大，当客户端数量庞大时服务器很难反应。
   TCP一般是 一对多，即：一个服务器连接多个客户端。
    TCP 一对多的开发步骤：
    1 服务器端
     1.1 创建socket，使用socket()函数。
     1.2 准备通信地址，sockaddr_in
     1.3 绑定sockfd和通信地址 bind() 
     1.4 监听客户端 ，使用listen()函数
     1.5 等待客户端的连接，使用accept()函数，accept()在客户端连接上来后，将返回一个新的 socket描述符，这个新的描述符用于和客户端的交互。
     1.6 读写(使用1.5返回的描述符)
     1.7 关闭描述符
    2 客户端
     与前面1对1模型步骤完全一样。
   注意: 客户端和服务器的读写操作要保持一致性：如果一端读，另外一端必须写。
   listen(int sockfd,int backlog)
    参数sockfd就是第一步返回的描述符，backlog就是同时连接上的最大并行客户端的数量。
 int accept(int sockfd,struct sockaddr*
    addr,socklen_t* len) 
  参数 sockfd就是第一步返回的描述符，addr是sockaddr_in的指针，用于存储客户端的IP地址，len是一个传入传出参数，传入期望长度，传出实际长度。返回新的sockft描述符，用于和 客户端数据的交互。
  注意：accept()如果客户端不连接，会停住等待。 

#######################################################################################################

回顾：
  网络编程
   TCP编程的步骤：
    Server端：
     1 socket()，返回socket描述符
     2 准备通信地址，struct sockaddr_in
     3 bind() 通信地址和socket描述符，相当于服务器对外开放了端口，允许客户端连接
     4 listen() 监听
     5 accept() 等待客户端的连接，会停住，直到有客户端连接上来为止。
     6 读写交互 read() write()
     7 关闭 close()
    Client端：
     1 socket()
     2 准备通信地址(服务器的地址)
     3 connect()连接 服务器
     4 读写交互
     5 关闭
 今天：
  软件公司开发流程基本都是迭代模型，即：
   先开发核心功能，做出一个版本。
   然后在核心功能的版本基础上，一点一点的附加 非核心功能。

  练习1：把昨天的代码改良一下
   把一对一的tcpserver.c改成一对多的
  思路：
    客户端的代码不需要改变
    server端的某些代码加上while(1)
    用ctrl+C信号2退出server，关闭sockfd

  练习2：把练习1的代码再改良一下
   加入客户端的输入(scanf)，而且客户端需要多次输入，并发送给服务器端，然后客户端接收服务器发回来的数据(发回客户端的输入即可)。客户端输入bye退出。
   服务器的读写也要做相应的修改。
  思路：改变客户端和服务器关于读写的代码，加上循环和退出条件(bye)。

  经验：
   如果多个客户端同时访问，服务器并行代码必须使用 多进程或多线程，主流使用的是多线程。 
  
  基于UDP协议的开发
   
    UDP协议 - 用户数据报协议
    TCP协议 - 数据流的协议

  UDP协议是 无连接协议，不需要保持连接。发送数据时连一下，发完了就不再保持任何的连接。
  UDP的优点是：比较节省系统资源，缺点：自身不会重发错误数据，因此UDP有可能数据部完整。

  UDP发送数据时,不使用write(),而是使用：    sendto()
  在接收数据时，可以使用：
   read() - 无法获取发送方的通信地址
   recvfrom() - 可以获取发送方的通信地址

 练习： 
   使用UDP编程实现一个时间服务器。
   时间服务器的功能：就是客户端先发送一个请求，然后服务器回发 系统时间，以年月日小时分秒的格式发回去
   (2014-01-14 15:16:01)。
   思路：
    取当前时间并改格式 - 
     time()、struct tm、localtime()
     sprintf() -> 把时间拼成字符串返回
   时间服务器的代码在刚才的基础上加上while(1)，用 信号2 退出。
   
  线程 和 进程
   操作系统 启动 多进程，每个进程 的内部可以启动多线程 实现并行。
   线程是轻量级的并行，不拥有自己的独立的内存空间，而是共享进程的相关资源。线程只需要一个独立的栈。
   进程是重量级的并行，需要拥有独立的内存空间。
   网络 开发 更多的选择多线程。
   每个进程内部都可以有多个线程，其中必须有一个主线程，就是main()函数。
   如果代码需要并行(同时运行)，必须使用多线程/多进程。
   线程之间相互独立，但又互相影响。
   主线程一旦结束，进程就会结束，所有线程都结束了。
   程序运行 必备的硬件是：CPU和内存。所谓线程的并行 意味着每个线程都有自己的内存和CPU。内存是可分的，CPU是 不可分的。
   主流的操作系统都是用 CPU时间片 实现线程对CPU分享。人的感官都是有感觉时间的，比如视觉是0.1秒，计算机就有0.1秒的运行时间，即：100毫秒。把100毫秒划分成很小的时间碎片(CPU时间片)，比如1毫秒一片。然后把CPU时间片分给线程，比如有4个线程A B C D，每个线程先分1片。那么4个线程都有资格运行1毫秒，会抢占式的运行(无序)。100毫秒以后，每个线程都运行了25毫秒。
在感觉上，代码实现了并行。

   多线程对于时间点 是串行，对于时间段 是并行。
   多线程之间的代码是乱序，每个线程内部的代码是 顺序执行。
   
   如何写线程？ - POSIX规范已经定义好了
   系统有一个pthread.h定义了线程的相关函数，还有共享库libpthread.so。(ldd)
   线程 thread
   相关的变量和函数都以 pthread_ 开头。
   线程的函数：
    pthread_create() - 创建一个新的线程
    
#####################################################################################################

回顾：
  网络编程 - TCP和UDP
  线程的基本原理和概念 - CPU时间片机制
  TCP的编程有固定的步骤：
   一对多：
   server:
    1 socket() 
    2 struct sockaddr_in
    3 bind()
    4 listen()
    5 accept()
    6 read()/write()
    7 close()
   client:
    1 socket()
    2 struct sockaddr_in
    3 connect()
    4 read()/write()
    5 close()
  UDP的步骤：
   server:
    1 socket()
    2 struct sockaddr_in
    3 bind()
    4 recvfrom()/sendto()
    5 close()
   client:
    1 socket()
    2 struct sockaddr_in
    3 recvfrom()/sendto()/read()
    4 close()

今天：
  推荐书：
    UNIX环境高级编程_第二版
  int pthread_create(pthread_t* id,
   pthread_attr_t* attr,
   void* (*task)(void*),void* arg)
  参数id是传出参数，用于存储线程的ID。
  attr是线程的属性，给0 使用默认属性即可
  task是一个函数指针，将来对应一个函数，线程启动以后，执行的代码就来自于这个函数，这个函数是由系统在创建线程后自动启动，这个函数的参数必须由第四个参数arg传给系统。(函数指针只能传函数，不能传参)
  运行正确，返回0，如果出错返回错误码，线程的错误处理不能使用errno，perror()。
显示错误信息得用 strerror()。
  pthread_create()的工作流程：
   系统先创建一个线程，这个线程与其他线程(主线程)并行，这个线程执行task()中的代码。函数task() 叫做 线程体。

  task()中的参数和返回值
  task()中的参数可以由pthread_create()中的第四个参数传入，返回值由pthread_join()获取。
  pthread_join()函数可以让一个线程等待另外一个线程的结束，并取得结束线程的返回值。比如：在a线程中调用了pthread_join(b,)就是让a线程阻塞，等待b线程的结束，并且用第二个参数可以获取b线程的返回值，其类型是void**。
  
   不能返回 指向局部变量的指针，除非指向的是static的局部变量。C语言不允许返回数组，但允许返回指针。 

   线程的退出方式：
    1 在线程体中return。
    2 pthread_exit()可以退出。(与1一样)
    3 被其它线程取消。(非正常退出)
  注：exit()不是退出线程，而是退出进程。

 线程的状态：
   如果线程不做任何处理，它的资源回收不确定在何时。
   只有处于join或者detach状态的线程才会确保资源的回收。
   detach叫分离状态，detach状态的线程在线程结束的同时就回收资源，不考虑其他线程是否还需要用；被join的线程 资源回收会在pthread_join()函数返回的同时。
  因此：一个线程最好要么处于detach状态，要么处于join状态。
  detach的线程 join 没有效果。
  用 pthread_detach()就可以把线程的状态设置为分离。

  线程的取消(了解)
  一个线程可以被其它线程取消，前提是被取消线程允许其它线程取消自己。
  相关函数：
   pthread_cancel() - 取消线程
   pthread_setcancelstate() - 设置是否可以取消
   pthread_setcanceltype() - 设置取消的方式。
   
  线程同步技术
   线程之间互相独立，又互相影响。线程之间一旦访问共享数据，一定会 互相影响。

   因为线程共享进程的资源，所以多线程同时操作共享资源时需要协调，以防数据出现不正确和不完整的文件，这种线程之间的协调就是 线程同步技术。

   线程同步技术的 核心理念：把并行的线程改成 一个挨着一个的串行。

   线程同步 可以保证数据没问题，缺点是：降低了代码的执行效率。
   常见的Unix的线程同步技术包括：
  互斥量、信号量、条件变量(与互斥量结合)
   互斥量  也叫互斥锁，是POSIX规范中定义好的，与线程一起写好的官方技术。互斥量的结构、变量、函数都是在pthread.h中定义的，因此一般选用互斥量。
   互斥量的使用方式和步骤：
  1 声明一个互斥量(mutex)
   pthread_mutex_t lock;
  2 初始化互斥量
   pthread_mutex_init(&lock,0);
  或者在声明的同时赋值：
   pthread_mutex_t lock =
    PTHREAD_MUTEX_INITIALIZER;
  3 加互斥锁
   pthread_mutex_lock(&lock);
  4 执行可能造成数据冲突的代码
  5 解锁
   pthread_mutex_unlock(&lock);
  6 释放互斥量的资源(销毁)
   pthread_mutex_destroy(&lock);

  

  信号量(semaphore)
  信号量是一个计数器，用来控制 访问共享资源的 最大并行线程总数。这里的信号量也支持进程，但在Linux系统中支持还不够。
  当信号量的计数为1时,效果等价于互斥量。
  
  信号量的使用步骤：
  #include <semaphore.h>
   1 定义信号量 sem_t sem;
   2 初始化信号量 sem_init(&sem,0,5);
   第一个参数是信号量指针，第二个参数为0代表 用于线程的控制，非0 用于进程的控制，Linux系统目前不支持进程。
   第三个参数 就是计数器的最大值，减到0 就会阻塞其它线程。
   3 获取信号量(计数-1) sem_wait(&sem)
   4 访问资源
   5 释放信号量(计数+1) sem_post(&sem)
   6 回收信号量的资源 sem_destroy(&sem)

 线程同步 一定要 避免 死锁。
  线程a:
   lock(&lock1);
   ...
     lock(&lock2);//等b释放lock2
   ...
     unlock(&lock2);
   unlock(&lock1);
  线程b:
   lock(&lock2);
   ...
     lock(&lock1);//等a释放lock1
   ...
     unlock(&lock1);
   unlock(&lock2);
 避免死锁的原则：
  顺序上锁，反向解锁，不要回调。
  a->b->c->d 
  d 不能 锁 a、b、c中的任何一个。
  