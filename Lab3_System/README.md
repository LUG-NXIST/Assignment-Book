# Lab3 矩阵相乘

改自：[第二期傲来操作系统(EulixOS)训练营，进阶阶段题目](https://opencamp.cn/EulixOS/camp/202501/stage/2)，欢迎大家加入`RISC-V`的建设中来

## 题目：

### 1. 完善矩阵乘法函数

矩阵相乘是线性代数中一个基本操作，广泛应用于图像处理、机器学习、物理模拟等领域。在这个任务中，我们需要实现矩阵相乘的操作，并将结果矩阵输出。

你需要实现一个函数 `multiply`，该函数用于计算两个矩阵的乘积。

矩阵的定义由以下结构表示：

```c
int **multiply(int **A, int ASize, int *AColSize, int **B, int BSize, int *BColSize, int *returnSize, int **returnColumnSizes);
```

#### 矩阵乘法

来自[百度百科，矩阵乘法](https://baike.baidu.com/item/%E7%9F%A9%E9%98%B5%E4%B9%98%E6%B3%95/5446029)

矩阵乘法常常指的是一般矩阵乘法。设矩阵$$A=(a_{ij})_{m * n}$$和$$B=((b_{ij})_{n *s})$$，令$$C=(c_{ij})_{m*s}$$。其中$$c_{ij}={\sum^{n}_{k=1}}a_{ik}b_{kj}(1{\leq}i{\leq}m,1{\leq}j{\leq}s)$$，那么矩阵$$C$$称为矩阵$$A$$与$$B$$的乘积，记为$$C=AB$$或$$C=A{\cdot}B$$。为方便，称被乘数$$A$$为左矩阵，乘数$$B$$为右矩阵。

注意事项： 

- 只有左矩阵的列数与右矩阵的行数相同的两个矩阵才能相乘。
- 乘积矩阵第`i`行第`j`列处的元素等于左矩阵的第`i`行与右矩阵的第`j`列对应元素乘积之和，即$$(AB)_{ij}={\sum^{n}_{k=1}}a_{ik}b_{k}$$。
- 乘积矩阵的行数等于左矩阵的行数，列数等于右矩阵的列数。

 计算示例：

![img](https://bkimg.cdn.bcebos.com/formula/ad4ea357c420a84f2ae7db21e87f5a58.svg)

#### 例子

假设我们有两个矩阵：

矩阵 A：
```
1 2 3
4 5 6
7 8 9
```

矩阵 B：
```
9 8 7
6 5 4
3 2 1
```

调用 `multiply(A, 3, AColSize, B, 3, BColSize, &returnSize, &returnColumnSizes)` 后，返回的新矩阵应该是：

```
30 24 18
84 69 54
138 114 90
```

### 2. 完善MakeFile文件

`Makefile` 是一个用于自动化编译程序的脚本文件。当你写了一个 C 程序，可能包含多个 `.c` 和 `.h` 文件，每次修改后都要手动输入很长的 `gcc` 命令来编译，非常麻烦。而 `make` 工具配合 `Makefile` 可以自动判断哪些文件被修改过，并只重新编译需要的部分，大大提高开发效率。

你需要完善`Makefile`中的语句，使程序能够正常连接并编译运行

参考：[廖雪峰的官方网站-MakeFile教程](https://liaoxuefeng.com/books/makefile/makefile-basic/index.html)

#### Makefile 的基本结构

Makefile 由若干 **规则（rules）** 组成，每条规则格式如下：

```makefile
目标（target）: 依赖（prerequisites）
	命令（command）
```

- **目标（target）**：通常是你要生成的文件名（如可执行文件或 .o 文件）。
- **依赖（prerequisites）**：生成目标所需要的文件（如源代码）。
- **命令（command）**：如何从依赖生成目标（必须用 Tab 缩进）。

 `make` 会检查依赖文件是否比目标新，如果是，就执行命令。

## 运行：

打开终端，输入`bash ./test_matrix.sh`进行测试

- 测试通过示例：
  <img src="/home/liyifei/.config/Typora/typora-user-images/image-20251123001346102.png" alt="image-20251123001346102" style="zoom:50%;" />

- 测试失败示例：

  ![image-20251123001716017](/home/liyifei/.config/Typora/typora-user-images/image-20251123001716017.png)

  如果目标文件未删除可以手动执行`make clean`命令

## 输入

两个矩阵 A 和 B，每个矩阵由逗号分隔的数值表示。例如：

矩阵 A：`1,2,3,4,5,6,7,8,9`
矩阵 B：`9,8,7,6,5,4,3,2,1`


## 输出

打印相乘后的矩阵

Result:
`30 24 18`
`84 69 54`
`138 114 90`
