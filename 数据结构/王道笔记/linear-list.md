---
title: 线性表
icon: water
categories:
  - "408"
  - "数据结构"
  - "线性结构"
---
## 线性表的定义
> 线性表是具有**相同数据类型**的n（n >= 0）个数据元素的**有限序列**，其中n为表长，当n = 0时线性表是一个空表。若使用L命名线性表，则表示为：
> **L = (a1, a2, ..., an)**
 
重要的是有限个且类型相同。我们可以知道线性表有以下的特性：
- 元素类型相同。
- 个数有限。
- 除了第一个元素，其余每个元素都有一个直接前驱。
- 除了最后一个元素，其余每个元素都有一个直接后继。

线性表只是一种**逻辑结构**，表示的是元素之间是“挨着”的关系，它可以有不同的物理实现方式（顺序表、链表）。

## 基本操作
一般来说，学习了一个数据结构的结构后，就需要学习在这个结构上我们可以进行的操作。在这里学习的线性表具有的操作有：
- 初始化：initList()
- 求表长：length()
- 按位插入：listInsert(Element *head, int val, int location)
- 按位删除：delete(Element *head, int location)
- 查找值：findVal(Element *head, int val)
- 销毁：destroyList()

## 顺序表
在上面我们进行了定义线性表，我们知道其是一种逻辑结构，具体的实现有两种。

这里的顺序表就是其中一种。**顺序表是采用顺序存储的，也就是分配了一块连续的物理地址用于存储线性表中的数据元素。使其不仅在逻辑上连续，在物理层面上仍然连续。**

由此我们可以看出，如果知道一个顺序表的起始地址和要找的次序，我们可以直接找出该次序上的元素。这就是C语言中的数组呀！

如：一个数组arr = [12, 34, 13, 43]，我们要求这个数组上第2个元素，可以直接`printf("%d", arr[1]);`。
:::tip 有点不对劲
上面求的不是第二个元素吗？为什么使用的是`printf("%d", arr[1]);`呀？

这里就需要说明一下：数组上元素对应的位置称为索引，而索引是从0开始的，故求的是第二个元素，采用的却是`printf("%d", arr[1]);`。
:::

### 顺序表的优点和缺点
我们为什么会采用顺序表实现线性表呢？肯定是需要它给我们带来的优势撒！那么它有什么优势呢？如下：
 - 随机访问：一个数组，无论我们想访问第1个元素还是10000个元素，访问的时间复杂度都是O(1)。
 - 存储密度高：除了要存储的数据没有其他的无用信息。
**除了优点，还有以下缺点：**
 - 插入、删除需要移动大量元素：在一个具有n个元素的数组中删除第一个元素需要将后面的n - 1个元素都向前移动，十分的不方便。平均也要移动$\frac{n}{2}个元素$
 - 分配不方便：因为需要一段连续的地址，如果计算机中没有的话，就不会进行分配，非常难受。

## 链表
这是线性表的另一种实现方式，采用一个一个的节点表示并通过指针连接。

**(单链表)节点的表示为：
+-------+------+
| data  | next |
+-------+------+**
使用C语言表示的结构体为（类型指明为具体的int）：
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```
next为指向下一个Node的指针，通过这个指针就可以找到与其紧挨着的元素了。就像一群人，两两之间使用一条绳子进行联系，这里的指针也起到相同的作用。
### 链表的优点和缺点
使用链表的好处在哪里呢？显而易见这个和顺序表是互补的。
- 便于插入和删除：想要插入一个node的话，我们直接改变next的指向就行了，不用再移动大量的元素。
- 不再需要连续的地址块：此时的联系不是通过物理上的“挨着”实现的，而是采用“绳子”的形式。
**那缺点呢？**
- 不再能随机存储：因为我们是不知道每个node的详细地址的，所以只能通过next去找寻。
- 存储密度低：一个node除了要存储data之外还要额外存储一个next。

## 顺序表和链表之间的差别
根据上面顺序表和链表的意义可以知道：

链表更加灵活不需要分配一段连续的地址块并且在插入和删除时很方便但也会导致访问元素很困难（只能一次一次的遍历）；顺序表因为是连续的所以可以轻松的访问任意一个元素但这也导致灵活度的缺失。

所以在一些插入、删除行为非常频繁的场景下可以使用链表，而在访问元素次数多的场景下可以使用顺序表！

## 额外的补充
在真实的场景中链表真的常用吗？我们可以思考一个问题，如果一个数组在移动大量的元素的情况下使用的时间比链表修改指针的时间更少的话，我们为什么要使用链表呢？

因为数组的每个元素我们都要随机访问，所以在插入时可以直接开始移动元素。而链表想要插入元素首先得遍历到要插入位置的前一个节点。在这里的操作中，遍历需花费的时间是占大头的，反而多次的修改所需的时间是更少的。

就连Java中创造LinkList的作者都明确地说了“他自己从不使用LinkList”。

![图片为证](https://camo.githubusercontent.com/fbc58d844d97136609b9d64c7cf809a0761e57a4516b3274e457148096c8475b/68747470733a2f2f63646e2e6e6c61726b2e636f6d2f79757175652f302f323032352f706e672f34383037333733302f313734313136313131323435372d61623439363739622d306538342d343237302d626239612d3532633736663566636534662e706e67)

ok，我们来做一个实验：
分别使用一个数组和一个链表随机插入10000个元素，看看那个使用的时间更久。

```java
package com.lj.blog.main;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;

/**
 * @ClassName ArrayMain
 * @Description
 * @Author Dark Chocolate 2069057986@qq.com
 * @Date 2025/3/5 16:09
 * @Version JDK 17
 */
public class ArrayMain {

        private static final int COUNT = 10000;

        static List<Integer> fillList(List<Integer> list) {
            for (int i = 0; i < COUNT; i++) {
                list.add(i);
            }
            return list;
        }

        static void randomAdd(List<Integer> list, String listType) {
            long t1 = System.currentTimeMillis();
            for (int i = 0; i < COUNT; i++) {
                list.add(ThreadLocalRandom.current().nextInt(0,COUNT), i);
            }
            long t2 = System.currentTimeMillis();
            System.out.println(listType + "随机位置插入" + COUNT + "次耗时：" + (t2-t1));
        }

        public static void main(String[] args) {

            randomAdd(fillList(new ArrayList<>(COUNT)), "数组");

            randomAdd(fillList(new LinkedList<>()), "链表");

        }

}
```

此时运行的结果为：
![COUNT为10000](https://camo.githubusercontent.com/0ec24c070b4f187b3c5c85bab0c1bb1d18f36fe98d31ddf3aa5ef873ddeea0c5/68747470733a2f2f63646e2e6e6c61726b2e636f6d2f79757175652f302f323032352f706e672f34383037333733302f313734313136323630323232312d35643135333539342d353031382d343337372d383466312d6438303735376537323961352e706e67)

效果还不是很明显，我们将COUNT提升到100000，此时结果为：
![COUNT为100000](https://camo.githubusercontent.com/fddedb5e67a3330123d5b289f2064193716b6de9fac6f56de67bfe4397467151/68747470733a2f2f63646e2e6e6c61726b2e636f6d2f79757175652f302f323032352f706e672f34383037333733302f313734313136323639313030362d63613766616134352d316436342d346635302d383661652d3830643834666266666531612e706e67)

可以得出为什么在实际开发中几乎不会使用LinkList。所以说呀，理想总是丰满的，现实总是骨感的😅。

## 顺序表的各种操作
现在是较为有趣的部分，在搞懂上面顺序表的定义后，我们开始对其进行操作了。
### 插入
顺序表中的插入会将该位置及其以后的元素都向后移动一位。
```c
void insertList(int *arr, int location, int val, int *len){
    for(int i = *len; i > location - 1; i++){
        arr[i] = arr[i - 1];
    }
    arr[location - 1] = val;
    (*len)++;
}
```
### 删除
顺序表中删除会将删除位置以及后面所有元素向前移动一位。
```c
void delete(int *arr, int location, int *len){
    for(int i = location; i < *len; i++){
        arr[i - 1] = arr[i];
    }
    (*len)--;
}
```
### 按值查找
通过遍历查找符合条件元素的索引，存在则返回对应索引，否则返回-1。
```c
int findVal(int *arr, int val, int len){
    for(int i = 0; i < len; i++){
        if(arr[i] = val){
            return i;
        }
    }
    return -1;
}
```
## 各种链表
在这里值得说明一下 头结点、头指针在有与没有头结点的表示含义。（使用head表示头指针）
头结点是一个特殊的节点，它其中的data属性一般不存放数据，如果要存放可以存放节点的个数，这里的个数是不包含的头结点的，因为头结点只是一个工具而已便于我们对元素进行操作。在没有特殊说明的情况下都是存在头结点的。

- 在有头结点的情况下：头指针指向头结点，判空条件为`head->next == NULL`。
- 在没有头结点的情况下：头指针指向链表的第一个元素，判空条件为`head == NULL`。

看来头指针总是指向链表中的第一个节点，存在头结点则指向头结点；不存在头结点时由于没有其他节点所以指向NULL。

在有头结点的情况是更合理的。因为有头结点的话不管是在首部插入、删除或是在中间部分插入、删除，其代码都是统一的。而没有头结点的话则需要额外的判断，因为可能需要修改头指针。
### 单链表
在上面已经提到过了，这里给出详细定义。
> 定义：通过一组任意的存储单元来存储线性表中的数据元素。为了建立数据元素之间的线性关系，对每个链表节点，除元素自身的信息外，还需要存储一个指向下一个节点的指针。

**节点结构为：
+-------+------+
| data  | next |
+-------+------+**
C语言表示的结构体为：
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```
#### 初始化
我们进行初始化并返回该链表的头结点指针。
```c
Node *init(){
    Node *head = (Node *)malloc(sizeof(Node));
    if(head == NULL){
        fprintf(stderr, "没有分配到相应的内存地址");
        exit(1);
    }
    head->data = 0;
    head->next = NULL;
    return head;
}
```
#### 头插法
每次插入都是在头节点后面进行插入，插入顺序和真实排序是相反的。如：插入顺序为：1 2 3 4 5；遍历输出结果为：5 4 3 2 1。
```c
void insertHead(Node *head, int data){
    if(head == NULL){
        return;
    }
    Node *node = createNode(data);
    node->next = head->next;
    head->next = node;
}
```
这里的createNode(int data)是一个通过传入的data创建节点的函数。除了头插法还有尾插法，通过遍历到表尾再进行插入。
#### 按位删除
```c
void deleteByLocation(Node **head, int location) {
    if (*head == NULL) {
        return; // 链表为空
    }

    Node *p = *head;

    // 特殊情况：删除头节点
    if (location == 0) {
        *head = p->next; // 更新头指针
        free(p); // 释放头节点
        return;
    }

    // 遍历到删除元素的前一位
    for (int i = 0; i < location - 1; i++) {
        if (p != NULL) {
            p = p->next;
        } else {
            return; // 位置超出链表长度
        }
    }

    // 如果 p 为空，说明位置超出链表长度
    if (p == NULL || p->next == NULL) {
        return; // 位置超出链表长度
    }

    Node *q = p->next; // q 是要删除的节点
    p->next = q->next; // 将前一个节点的 next 指向要删除节点的下一个节点
    free(q); // 释放要删除的节点
}
```
其他的一些基础操作和这些类似就不再赘述了。
### 双链表
这个在单链表的基础上又添加了一个指向前一个节点的指针，这样可以使得链表更加灵活但与之对应的就是存储密度的下降和更加复杂。
双链表的结构如下：
**+-------+-------+------+    
 | prev  | data  | next |
+-------+-------+------+**  
C语言的结构体定义为：
```c
typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}Node;
```
#### 双链表的插入
我们指定在p指针指向的节点后面插入节点*s，下面是对应的代码片段。（值得注意的是一个节点存在两个指针，记得都要修改）
```c
s->next = p->next;
p->next-prev = s;
s->prev = p;
p->next = s;
```
让我们进行思考，一定只能是这样进行操作吗？当然不是的，我们需要保证在插入s之前，p之后的指针不能丢失，不然就不能修改原本p之后结点的prev指针了！

若出现这种选择操作的题目只需要自己手动试一下就明晰了。
### 循环链表
见名知义，这种链表是**循环**的。

这里又分为单向循环链表和双向循环链表，前者是单链表的循环，表尾节点的指针指向头结点。后者是双链表的循环，表尾节点的next指向头结点，头结点的prev指向表尾节点。

若单链表中只存在一个头结点，那么它的next指针是指向头结点的；若双链表中只存在一个头结点，那么它的prev、next指针都是指向头结点的。
### 静态链表
这是一种十分巧妙的设计方案，常在不支持指针的语言中出现，采用数组来实现线性表的链式存储。它同样拥有一个data和next，不过这里的next是指向的下一个节点在数组中的索引，如果next为-1则表示其为最后一个节点。（和链表中的NULL一致）

下面是对于静态链表的C语言结构体：
```c
#define MAX_SIZE 100
typedef struct{
    int data;
    int next;
}SLinkList[MAX_SIZE];
```
#### 初始化并在main函数调用
```c
void initList(SLinkList list) {
    for (int i = 0; i < MAX_SIZE; i++) {
        list[i].data = 0;  // 初始化数据为 0
        list[i].next = -1; // 初始化 next 为 -1，表示没有指向下一个节点
    }
}
int main() {
    SLinkList list; 
    initList(list); 
    list[0].data = 1;
    list[0].next = 1; 
    list[1].data = 2;
    list[1].next = -1;
    for (int i = 0; i < 2; i++) {
        printf("Node %d: data = %d, next = %d\n", i, list[i].data, list[i].next);
    }
    return 0;
}
```
## 常见题目

