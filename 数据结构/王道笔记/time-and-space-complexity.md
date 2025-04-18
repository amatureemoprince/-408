---
title: 评判算法好坏的标准
icon: "bugs"
categories:
  - "408"
  - "数据结构"
tags:
  - "O(n)~"
---
## 算法的好坏评价标准
我们说这是一个优秀的算法，那是一个糟糕的算法，不是看是谁写的，也不是看是谁先提出来的，而是根据该算法的**时间复杂度**和**空间复杂度**来决定的。

那怎样进行判断呢？

我们就不搞数学那一套了，直接使用更为简单易懂的形式进行理解。

## 时间复杂度
第一眼看到这个名词的时候还以为是让一段程序在电脑上运行一下同时统计运行使用的时间嘞，但回头一想，这样好像不太科学吧！

是的，如果只是简单的采用在电脑上运行的时间作为评判，那就滑天下之大稽了。思考一下，你的20000元的电脑和我的3000元的电脑玩原神的流畅度，肯定是不能比的。在这里也是同理，不同的电脑对于同一段程序跑出来的时耗也是不同的，甚至是天差地别！

再退一步说，如果不论什么算法都让它跑一下，对于计算机资源也是一种浪费呀。我们可是**勤俭节约**的人呀！可不能这样干。

那这个问题怎样解决呢？

既然在不同的物理机上是存在差别的，那我们就将其统一嘛，认为每行代码执行的时间是相同的，这样对于输入规模为n的真实时间与使用时间复杂度估计的时间只会相差一个常量系数，而在n很大时这个值是可以忽略的。

此时记T(n) = O(f(n))，这个f(n)是每行代码执行之和，于是我们就用这个方法来表示算法的时间复杂度（也叫大O表示法）
### 各种时间复杂度
我们可以来举几个例子，举例子是最容易让人明白的手段：
- 时间复杂度为O(1) 
```c
int sum(int n){
    return n;
}
```
可以看到这个函数无论n为多少，函数内的代码只会执行与n无关的次数，也就是$O(n^0)$，故其时间复杂度为O(1)
:::tip 请注意
不要认为里面的代码行数只有一行其时间复杂度为O(1)。就算里面有100000000....行，只要其与n无关都是O(1)的时间复杂度。
:::
- 时间复杂度为O(n)
```c
int sum(int n){
    int result = 0;
    for(int i = 0; i < n; i++){
        result += i;
    }
    return n;
}
```
此时总的执行次数为for循环中的n次加上开头和结尾分别一次，共n + 2次，T(n) = O(n + 2)。此时需要注意：我们在写这个T(n)时只需要保留n的最高次就行。

故T(n) = O(n)

:::tip 请注意
上面说的保留最高次的意思是不管最高次前的系数，统一为1。
比如：所有代码运行了5n + 20次，此时的T(n)仍为O(n)
:::
- 时间复杂度为$O(n^2)$
```c
int double(int n){
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result += j;
        }
    }
    return result;
} 
```
显然的，此时代码运行次数为$n ^ 2 + 2$，使用大O表示法可知时间复杂度为：$O(n^2)$。现在看来就简单了吧！
- 时间复杂度为O($\log_2 n$)
```c
int logarithmic(int n) {
    int count = 0;
    while (n > 1) {
        n = n / 2;
        count++;
    }
    return count;
} 
```
我们还是进行分析代码运行的次数，显然有必然的两次（在以后的分析中就不用再考虑这些“无关紧要的次数了”），重要的中间的while循环。

进入循环时是n，经过一次之后为$\frac{n}{2}$，经历2次是$\frac{n}{2^2}$，依次类推，设运行了t次，那么有$\frac{n}{2^t} = 1$，显然得t=$\log_2 n$。此时时间复杂度T(n) = O($\log_2 n$)。

- 时间复杂度为O($n \log_2 n$)
```c
int linearLogRecur(int n) {
    if (n <= 1)
        return 1;
    int count = linearLogRecur(n / 2) + linearLogRecur(n / 2);
    for (int i = 0; i < n; i++) {
        count++;
    }
    return count;
} 
```
这个采用了递归，一共拆分为了$\log_2 n$层，每层下面有一个for循环则时间复杂度就为O(n$\log_2 n$)。
- 时间复杂度为O($2^n$)
```c
int exponential(int n) {
    int count = 0;
    int bas = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bas; j++) {
            count++;
        }
        bas *= 2;
    }
    // count = 1 + 2 + 4 + 8 + .. + 2^(n-1) = 2^n - 1
    return count;
} 
```
和之前的思考方式一样，去算一算代码总共的运行的次数吧！
- 时间复杂度为O(n!)
```c
int factorialRecur(int n) {
    if (n == 0)
        return 1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += factorialRecur(n - 1);
    }
    return count;
} 
```
可以看到for循环中套了一个递归，最外层运行n次，进入之后为n-1，类推下去直到n = 0。容易看出运行的次数需要将每层循环的次数乘起来，故时间复杂度为O(n!)。
### 最好时间复杂度、最坏时间复杂度、平均时间复杂度
在一个算法中运行的时间可能并入我们所料的那么长，也可能没有我们预想的那么短。

举个例子：
在一个数组中查找置为12的索引，该数组为:[12, 23, 34, 22]，显然第一个就是它，此时的最佳复杂度为Ω(1)。
如果我们要查找的不是12而是22，那么此时需要在最后一次才能找到它，也就是最坏的情况，此时的最坏时间复杂度为O(n)。
通常来说，有最佳，有最坏，那么肯定有个折中的，在这里就是平均时间复杂度，显然是O($\frac{n}{2}$)，也就是O(n)。

值得说明的是：在使用时间复杂度时总是使用最坏的或者平均的，而不会使用最好的，因为我们总要把**最坏**的情况考虑到而不会是最好的情况，这样才能知道自己是否能接受这个结果从而进行取舍。
### 常见时间复杂度排序
我们来给常见的时间复杂度从小到大排个序：
**O(1) < O($\log_2 n$) < O(n) < O(n * $\log_2 n$) < O($2^n$) < O(n!)** 
:::tip 注意
O($2^n$) < O(n!)是n在大于4的情况下！
:::
## 空间复杂度
空间复杂度，顾名思义是在程序运行时需要额外空间与输入规模之间的关系，这个概念是和时间复杂度非常类似。

- 常数阶O(1)
```c
int func() {
    return 0;
}
void constant(int n) {
    const int a = 0;
    int b = 0;
    int nums[1000];
    ListNode *node = newListNode(0);
    free(node);
    for (int i = 0; i < n; i++) {
        int c = 0;
    }
    for (int i = 0; i < n; i++) {
        func();
    }
} 
```
可以看到这个使用的空间与n的输入大小无关，故空间复杂度为O(1)。

其余的就不在这里举例了。如果有想了解其他空间复杂度的同学可以访问[hello算法](https://www.hello-algo.com/chapter_computational_complexity/space_complexity/#3-on2)

## 总结
在计算时间复杂度时要紧紧抓住运算代码的次数，这是最重要的地方！


