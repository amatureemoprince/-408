---
title: 排序算法
icon: sort
categories:
  - "408"
  - "算法"
  - "排序算法"
---
默认以下的排序代码中元素都是整数数值且目的是进行升序排序。

------

## 排序的概念

排序：重新排列表中的元素，使表中的元素满足按关键字有序的过程。

也就是说对应表中输入 n 个不管是否有序的记录（每个记录表示用于排序的标志称为关键字），在输出时表中为 n 个有序的记录。

在讨论排序算法时，有一个很重要的性质：该算法是否稳定！

那么满足什么条件才能说改算法是稳定的呢？

若待排序表中有两个元素 Ri 和 Rj，其对应的关键字相同，且 Ri 排在 Rj 的前面，若在使用了某个排序算法后，Ri 仍然排在 Rj 的前面，那么就称该排序算法是稳定的，否则不稳定。

------

排序算法大多都是基于比较的，但是并不是所有排序算法都是基于比较的！比如：基数排序（这是一种十分有意思的排序算法）

我们要清晰地意识到：每种排序算法都有各自的优点，不是哪种排序算法就一定强于另一种排序算法，我们要具体情况具体分析！在实际解决问题也是这样，所以才提出了那么多种技术和框架，我们的世界是一个巨大的权衡！

## 插入排序

插入排序十分的直观，是一种“耿直”的排序算法。

其基本的思想是：每次将一个待排序的记录按照关键字大小插入到前面已经排好序的子序列中，直到所有的记录全部插入完成。

------

### 直接插入排序

顾名思义，就是“直接”，不管那么多弯弯绕绕。

每次从待排序记录中选取第一个关键字插入到前面排好序的序列中！从遍历过程中找到合适的位置。

重点就是找到要插入的位置！

```c
void direct_insert(int *arr, int len){
    int i, j, temp;
    //默认第一个位置是有序的
    for(i = 1; i < len; i++){
        temp = arr[i];
        //确定插入的位置
        for(j = i - 1; j >= 0; j--){
            if(arr[j] > arr[i]){
                arr[j + 1] = arr[j];
            }else{
                break;
            }
        }
        //处理原本的arr[i]
        arr[j + 1] = temp;
    }
}
```

核心是寻找插入的位置，在这里是通过遍历寻找的，可以进行优化，使用折半查找进行寻找适合插入的位置。

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为只需要常数个辅助单元，故**空间复杂度为**![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg)**。**
- 时间复杂度：若整个数组都是有序的再进行直接插入排序，由于从左至右遍历的 n 个元素都只需要比较一次，故此时为**最好的时间复杂度** ![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)；若是一个从大到小的数组（反序）进行直接插入排序，此时就是最坏的时间复杂度![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg)。故平均复杂度为![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg)。

1. 分析该算法的稳定性：每次插入都是从后往前比较，故不会让相同元素的相对位置发生变化，因此直接插入算法是一种**稳定**的算法！
2. 适用性：直接插入算法适用于**顺序存储和线性存储**的线性表！

------

### 折半插入排序

这就是上述的优化方案，因为插入时寻找合适的位置采用折半查找，故命名为折半插入排序，理想情况下可以将遍历用的![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)优化成![img](https://cdn.nlark.com/yuque/__latex/65c54415e21b8b592c65dc4cd43cbd33.svg)。

算法核心是：遍历每个元素，在前面已经排好序的子序列中使用折半查找来寻找合适的插入位置，找到后通过一次循环将插入位置及以后的元素后移一位，最后插入待插入的元素。

```c
void insert_half_sort(int *arr, int len) {
    int i, j, cur;
    int start, end;
    int middle;
    for (i = 1; i < len; i++) {
        cur = arr[i];
        start = 0;
        int val = cur;
        end = i - 1;
        //总是在start位置插入
        while (start <= end) {
            middle = start + (end - start) / 2;
            if (val < arr[middle]) {
                end = middle - 1;
            }else{
                start = middle + 1;
            }
        }
        for (int z = i - 1; z >= start; z--) {
            arr[z + 1] = arr[z];
        }
        arr[start] = cur;
    }
}
```

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为只需要常数个辅助单元，故**空间复杂度为**![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg)**。**
- 时间复杂度：由于将寻找合适插入位置优化为折半查找，故最佳时间复杂度约为![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg)，该算法的平均时间复杂度和最坏时间复杂度都为![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg)**。**

1. 分析该算法的稳定性：折半插入排序是一种**稳定**的算法！
2. 适用性：仅仅适用于**顺序存储**的线性表！
3. 该算法在数据量不是很大的情况下有着很好的性能。

------

### 希尔排序

希尔排序是对直接插入排序的优化，又称“缩小增量排序”。

由上面的分析可知：只要在数组是有序的，则时间复杂度是可以降低的，希尔排序的思路就是通过将数据尽量变得有序，这样就可以在一定程度上降低时间复杂度了。

算法核心是：使用一个增量 d，将待排序表分割为多个子待排表，形如 [i, i + d, i + 2d, ..., i + kd]，把相隔 d 的记录组成一个子表，分别对子待排表进行直接插入排序，然后再整体进行一次直接插入排序。

```c
void shell_sort(int *arr, int len, int d) {
    // 需要分成不同的组进行排序
    for (d; d >= 1; d = d / 2) {
        // 每组的排序的插入排序
        for (int i = d; i < len; i++) {
            int temp = arr[i];
            int j;
            // 插入排序
            for (j = i; j >= d && arr[j - d] > temp; j -= d) {
                arr[j] = arr[j - d];
            }
            arr[j] = temp;
        }
    }
}
```

希尔算法中“增量”值的取法有许多的学问，可以说直接关系着整体算法的时间复杂度。有兴趣的同学可以去学习一下课外知识，一般我们取值就为数组长度的一半则可。

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为只需要常数个辅助单元，故**空间复杂度为**![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg)**。**
- 时间复杂度：希尔排序的时间复杂度取决于增量 d 的取值，这在数学上还没有解决，但是我们可以知道的是当 n 在某个特定范围内时，希尔排序的时间复杂度约为![img](https://cdn.nlark.com/yuque/__latex/057b59460eee88aad289b71782d747e2.svg)，最坏的时间复杂度为![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg)**。**

1. 分析该算法的稳定性：希尔排序是一种**不稳定**的算法！
2. 适用性：仅仅适用于**顺序存储**的线性表！

------

## 交换排序

交换：根据序列中两个元素关键字的比较结果来对换这两个记录在序列中的位置。

举个例子：有个序列 1,2；我们要从大到小进行排序，所以需要比较这个序列中的元素，显然 1 < 2 = true，故两者对换，得到序列 2,1；即成功的得到了想要的从大到下的排序，这就是上面的定义所说内容。

------

### 冒泡排序

这个排序算法是学习 C 语言必学算法了吧！泪目了，勾起了我懵懂的大一时光记忆😭

这个算法在排序的过程中，元素会像水里的气泡一样“飘”向一侧，故称为冒泡排序！

算法核心是：比较相邻两个元素，一趟冒泡会将大的元素交换到最右侧。

```c
void bubbling(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            int temp;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

这个代码还可以进行优化，在一次冒泡中若没有出现交换元素的操作，说明已经是有序的了，可以提前结束！

```c
void bubbling_with_flag(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int flag = 0;
        for (int j = 0; j < len - 1 - i; j++) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            flag = 1;
        }
        //没有交换则直接退出
        if (flag == 0) {
            break;
        }
    }
}
```

------

对优化后的冒泡排序进行分析：

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为只需要常数个辅助单元，故**空间复杂度为**![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg)**。**
- 时间复杂度：最好的时间复杂度就是遍历一次后都没有交换，显然为![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)，平均和最坏的时间复杂度都为![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg)**。**

1. 分析该算法的稳定性：冒泡排序是一种**稳定**的算法！
2. 适用性：冒泡排序适用于**顺序存储和链式存储**的线性表！

**冒泡算法在一趟排序后，必有一个元素位于全局合适的位置！**

------

### 快速排序

快排讲究的就是快！基于分治的思想。

算法核心是：在一个待排序表中任取一个元素作为“枢轴”（pivot），通过一趟排序将待排序表分为两部分，分别为小于 pivot 和大于等于 pivot 的，左侧全部小于 pivot，右侧全部大于等于 pivot。递归地对子表使用，直到每个部分的元素个数为 1。

```c
int partition(int *nums, int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        //移动hight指针
        while (low < high && nums[high] >= pivot) {
            high--;
        }
        //填坑
        if (low < high) nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) {
            low++;
        }
        //填坑
        if (low < high) nums[high] = nums[low];
    }
    //基准数放到合适的位置
    nums[low] = pivot;
    return low;
}
//快速排序
void quick_sort(int *nums, int low, int high){
    if (low < high) {
        int index = partition(nums, low, high);
        quick_sort(nums, low, index-1);
        quick_sort(nums, index+1, high);
    }
}
```

一般而言取得 pivot 就为第一个元素。

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为需要一个递归栈，故空间复杂度与递归的层数有关。最好的空间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/f057422a218236bfa4d1ff132c1e8be8.svg)，最坏的空间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)，平均的空间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/65c54415e21b8b592c65dc4cd43cbd33.svg)。
- 时间复杂度：快速排序的时间复杂度与划分是否对称有关，最坏的情况就是 pivot 两侧数据量分别为 0 和 剩余所有数据量，这样的划分是最“不对称”的，此时时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg)；故只要我们的 pivot 元素随机取，则可以避免这种情况，此时为理想的时间复杂度：![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg)。

1. 分析该算法的稳定性：快速排序是一种**不稳定**的算法！
2. 适用性：快速排序适用于**顺序存储**的线性表！
3. **快速排序是所有内部排序算法中平均性能最优的排序算法！**

------

## 选择排序

选择排序的基本思想是：每趟从后面的待排序元素中选取关键字最小的元素加入到排好序的元素中，遍历完则所有元素就都有序了。

------

### 简单选择排序

十分的简单，就像这个算法的名字一样，朴实无华！

```c
void select_sort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int min = INT_MAX;
        int index;
        //寻找后面最小的值
        for (int j = i; j < len; j++) {
            if (arr[j] < min) {
                min = arr[j];
                index = j;
            }
        }
        //处理最小值
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
}
```

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为只需要常数个辅助单元，故**空间复杂度为**![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg)**。**
- 时间复杂度：不管待排元素是否有序都需要进行双层遍历，故时间复杂度始终为：![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg)。

1. 分析该算法的稳定性：简单选择排序是一种**不稳定**的算法！
2. 适用性：简单选择排序适用于**顺序存储和链式存储**的线性表！还适用于关键字较少的情况。

------

### 堆排序

堆可视为一颗完全二叉树。

可分为大根堆和小根堆，前者是树的根结点元素大于孩子结点的，其树的每颗子树同样满足这个条件；后者和大根堆满足的条件相反。

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743407772688-c54f5d5e-4f5a-4675-8e74-c71bdb1815bf.jpeg)

那么想要进行从小到大的排序就可以使用小根堆，取出根结点就是最小元素，如果破坏了堆的性质，将其调整为一个新的堆后又取出第二个根结点，依次类推就可以得到排好序的元素序列。

想要进行上面的步骤，首先要初始化一个堆，然后要将剩余的元素调整为一个新的堆。

这两个操作就是堆排序的核心问题！

堆是在顺序表中进行维护的，也就是说这个完全二叉树是以顺序表存储的。

------

初始化堆（采用大根堆）：

需要从后往前检查所有的**分支节点**，看分支结点的孩子是否满足大根堆的性质，若不满足，则对以该分支结点为根的子树进行调整。因为在调整一个子树时可能会导致另一个子树出现不满足的性质的情况出现，所以在调整一个根结点时需要将下面所有的结点进行调整，直到所有结点都满足大根堆的性质！

初始化堆之后会将根结点元素弹出（这里的弹出就是和最后一个元素交换位置），然后就需要调整堆以满足大根堆的性质：

在弹出根结点后，会将最后一个元素和根结点元素交换位置，然后对根结点元素向下调整，直到满足性质为止。在最后的元素必是最大的，所以需要向下调整。

在这里，弹出就是交换根结点和最后一个元素有个好处，就是节省了空间！

试想一下，如果不是这样，我们需要将数组中的元素以从小到大的顺序排序，就需要一个小根堆，然后每次用一个数组接收到小根堆的根结点元素。

而在这里使用大根堆进行“交换”，默认的就将数组按从小到大进行排好序了！

```c
void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void head_adjust(int *arr, int k, int len) {
    //保留根结点元素值
    int root_val = arr[k];
    for (int i = 2 * k + 1; i < len; i = 2 * k + 1) { 
        // 检查右孩子是否存在且是否更大
        if (i + 1 < len && arr[i] < arr[i + 1]) {
            i++;
        }
        // 若根节点大于等于子节点，调整完成
        if (root_val >= arr[i]) {
            break;
        } else {
            // 否则将子节点值上移，并继续向下调整
            arr[k] = arr[i];
            k = i;
        }
    }
    arr[k] = root_val;
}

void build_max_heap(int *arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        head_adjust(arr, i, len);
    }
}

void heap_sort(int *arr, int len) {
    //构建大根堆
    build_max_heap(arr, len);
    // 只需交换 len-1 次
    for (int i = 0; i < len - 1; i++) {
        swap(arr, 0, len - i - 1);  // 将最大值交换到末尾
        head_adjust(arr, 0, len - i - 1); // 调整剩余堆
    }
}
```

------

**堆的插入和删除：**

插入：插入的位置是堆的末端，再对该结点进行向上的调整操作。

删除：就是上面所说的将根节点存放到末尾，进行调整操作。

------

**堆的应用：**

在海量的数据中得到最大的 100 个值，可以取前 100 个元素构造一个小根堆，然后让剩余元素插入小根堆（小于根节点元素的数据不考虑），直到最后小根堆中剩余的 100 个元素就是最大的 100 个值！

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为只需要常数个辅助单元，故**空间复杂度为**![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg)**。**
- 时间复杂度：建堆的时间复杂度为![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)，每次向下调整的时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/3f1ee1ee2af181570be289f01ed4a4c0.svg)，这个高度 h 是二叉树的高，故所有的时间复杂度都为：![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg)。

1. 分析该算法的稳定性：堆排序是一种**不稳定**的算法！
2. 适用性：堆排序仅仅适用于**顺序存储**的线性表！还适用于关键字较多的情况。

------

## 归并排序

归并排序是基于两个或两个以上有序表，其可以将多个有序表合并为一个有序表。

设：有 n 个有序表，使用二路归并排序。

则在一次二路归并排序后会得到![img](https://cdn.nlark.com/yuque/__latex/21d72a1f1e7cf0f7f306f39fa9c7abf7.svg)个有序表，依次类推，直到只有一个有序表为止，就算排完序了。

算法核心是：将一个数组递归地进行划分，直到子数组分别只有两个元素，然后再进行递归地进行归并排序，得到两端有序数据，再对左右两侧进行一次归并算法则可。

```c
// 合并函数（新增临时数组参数）
void merge(int *arr, int low, int mid, int high) {
    // 创建临时数组
    int *temp = malloc((high - low + 1) * sizeof(int));
    int i = low;        // 左子数组起点
    int j = mid + 1;    // 右子数组起点
    int k = 0;          // 临时数组索引
    // 合并两个有序子数组
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    // 处理剩余元素
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    // 将排序结果拷贝回原数组
    for (int m = 0; m < k; m++) {
        arr[low + m] = temp[m];
    }
    free(temp);
}

void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2; // 避免整数溢出
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
```

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：因为需要分配 n 个单元，故**空间复杂度为**![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)**。**
- 时间复杂度：每趟归并的时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)，一共需要![img](https://cdn.nlark.com/yuque/__latex/65c54415e21b8b592c65dc4cd43cbd33.svg)次归并，故时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg)

1. 分析该算法的稳定性：归并排序是一种**稳定**的算法！
2. 适用性：归并排序适用于**顺序存储和线性存储**的线性表！

------

## 基数排序

这是一种十分有意思的排序算法，设计者真的强！其不基于比较和移动进行排序，而是基于关键字各位的大小进行排序。**基数排序是一种借助多关键字排序的思想对单逻辑关键词进行排序的方法**。

算法核心是：

将结点中元素的关键字 ![img](https://cdn.nlark.com/yuque/__latex/5d496a3b872073b90e3b920cacfc3dc6.svg)划分为 d 元组。如：一个元素的关键字为：354，则将其按从地位到高位分为 4、5、3。

根据上述例子，在实现多关键字排序时，通常有两种做法：

- 一是：最高位优先（MSD），先排高位的分组，再排低位的分组。
- 二是：最低位优先（LSD），和上面的相反。

------

举个例子：采用链式基数排序 LSD 对{123，120，194，184，110，111，214，253，171}进行排序。

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743471743612-56ddf8c7-b3f4-4eef-9238-7f42f5887b2b.jpeg)

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：一趟排序需要的辅助空间为 r（r 个队列：r 个头指针和 r 个队尾指针），循环利用的，故空间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/76c87bdcdbb3dbe867d829ff2a95017b.svg)。
- 时间复杂度：基数排序需要进行 d 趟分配和收集的操作，一趟分配需要遍历所有的关键字，时间复杂度为![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)，一趟收集需要合并 r 个队列，时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/76c87bdcdbb3dbe867d829ff2a95017b.svg)，故总的时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/f96b90b4e660ba19902c37579e2c0992.svg)。

1. 分析该算法的稳定性：基数排序是一种**稳定**的算法！
2. 适用性：基数排序适用于**顺序存储和线性存储**的线性表！

------

## 计数排序（*）

这就是之前说的那种不基于比较的排序算法！

该算法的思想是：对每个待排序元素 x，统计小于 x 的元素个数，利用该信息就可以确定 x 的最终位置了。但是如果在有几个相同元素的情况下，就需要额外的优化。

这个不在考点之中，但是这种思想在考试之中出现多次！

```c
void counting_sort(int *arr, int len) {
    if (len <= 1) return;
    // 1. 找出最大值和最小值
    int max = arr[0], min = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    // 2. 创建计数数组（优化空间：范围是[min, max]）
    int count_size = max - min + 1;
    int *count = (int *)calloc(count_size, sizeof(int));
    // 3. 统计元素出现次数
    for (int i = 0; i < len; i++) {
        count[arr[i] - min]++; // 将数值映射到[0, count_size)区间
    }
    // 4. 累加计数（计算最终位置）
    for (int i = 1; i < count_size; i++) {
        count[i] += count[i - 1];
    }
    // 5. 反向填充结果数组（保证稳定性）
    int *output = (int *)malloc(len * sizeof(int));
    for (int i = len - 1; i >= 0; i--) {
        int val = arr[i];
        int pos = --count[val - min]; // 先减再取，对应下标从0开始
        output[pos] = val;
    }
    // 6. 拷贝回原数组
    for (int i = 0; i < len; i++) {
        arr[i] = output[i];
    }
    free(count);
    free(output);
}
```

------

1. 分析该算法的时间和空间复杂度：

- 空间复杂度：输出的数组长度为 n，辅助数组的长度为 k，则空间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/0546cf9a3ce1a0886decec99f94f7a12.svg)。
- 时间复杂度：循环次数和 n 和 k 都有关，总的时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/0546cf9a3ce1a0886decec99f94f7a12.svg)，若 k=n 时 ，其复杂度为![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg)，但是若 k>![img](https://cdn.nlark.com/yuque/__latex/a61bd8427817a96bc59a25d5351035d2.svg)的话，其时间复杂度还不如一些基于比较的排序算法（如：快排、堆排等）。

1. 适用性：计数排序更适用于**顺序存储**的线性表！
2. 稳定性：计数排序是一种**稳定**的排序算法。

------

## 外部排序

### 定义

之前学习的排序算法，都是基于内存的（在内存里面进行的），外部排序算法是将外存中的数据进行排序！

由于我们知道存储在外存的数据量通常是很大的，所以不可能像内部排序一样将数据全部放入内存再进行排序。

引入外部排序的定义：

外部排序：将待排序的记录存储在外存上，排序时再把数据一部分一部分地调入内存中进行排序，在排序过长中需要多次进行内存和外存之间的交换。

我们知道内存的运行速度是非常快的，所以在外部排序中，影响整体的排序时间是进行 **IO 操作**。就是从外存读入到内存，再从内存写入到外存。

------

### 具体操作

如何对外存的大文件进行排序呢？下面来解答：

第一：需要根据内存的缓冲区大小，将外存中的大文件分成 n 份长度为 l 的子文件，依次读入读入内存，然后使用内部排序算法对其进行排序，并将排完序的有序子文件写入到外存，这些有序子文件成为**归并段或顺串**。

第二：对归并段进行归并，这样就可以将多个归并段合为一个归并段了，直到整个文件有序。

------

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743304375277-fd2674f2-b7e4-439e-a791-29e51e4a06a6.jpeg)

根据内存中的输入缓存区大小将外存的文件划分为 n 块，这里采用的是二路归并，所以有两个输入缓存区，然后读入外存文件的两个块，分别为：块 1（4、1、6）和块 2（3、2、7），分别在输入缓存 1、2 中等待排序。根据归并排序将这两个块内部进行排序，再写入外存，这样外存中的每个块都是有序的了。

选择两个块进行排序合为一个有序的块，整体变为 n/2 个归并段，以此类推，就可以将整个外部文件变为有序的了。

------

因为分配的内存大小有限，故不能将两个有序段和归并结果一同存储在内存中，所以是需要不断地读入、写出数据，而大量的 IO 操作会带来大量的时间消耗。结合上面的其他时间消耗可得：

**外部排序时间 = 内部排序时间 + 外部数据读入/写出 时间 + 内部归并时** 

**显然的，外部数据 IO 操作是最消耗时间的，故应该着手降低 IO 次数，才能改善外部排序时间。**

思考一下，怎样可以减少 IO 操作次数呢？

设：有一个含有 2000 个记录的文件，每个块可以存放 125 个记录。（每个块中都是有序的了）

采用二路归并算法

因为读入写入的操作是以“块”为单位的，所以需要 16 次写入排好序后再进行 16 次写出。

也就是依次归并操作就需要 32 次 IO 操作，不管是归并段为多大，都是一样的，因为每次归并操作都会将每个块进行读入和写出。

根据这个可以画出一个二叉树：

------

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743307005556-61468bfd-9c69-46c2-b750-f5a95a57dba6.jpeg)

R1、R2...表示的是有序块，R1'表示通过 R1、R2 归并后得到的有序段，其余的以此类推则可。

显然是需要内部排序+归并 3 次才能有序。故需要 32 + 32 x 3 次 IO 操作。每层到每层之间需要一次归并。

------

如何优化呢？显然只要该树的层数变少了则可以减少归并操作，怎样变少呢？因为块数是一样的（叶子结点数一样）故只要树的阶数变大则可以将层数变小！

换句话说就是改 2 路归并为更多路归并，如 4 路归并。

这样树的高度变为 3，则只需要 32 + 32 x 2 次 IO 操作了，如下：

------

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743307596785-0f48049d-12b5-4280-aa5e-15921b4a575a.jpeg)

------

由此可知：若有 r 个初始归并段（排好序），采用 k 路归并则有：

**树的高度 - 1 =** ![img](https://cdn.nlark.com/yuque/__latex/03c090e28f82e8b72b728c5f64fe7379.svg)**= 归并次数 = S**

但是我们需要注意：如果分配的内存大小是一定的，采用的 k 路归并，k 越大，则在内部进行 k 路归并排序的时间就需要更多，所以需要平衡这两者之间的关系。

推导：

采用 k 路归并，需要比较 k - 1 次才能得到一个最小的元素，而在每次归并的元素个数为 n，所以每趟需要做(n - 1)(k - 1)次比较。

则总的比较次数为：S(n - 1)(k - 1)

![img](https://cdn.nlark.com/yuque/__latex/57f229bd2f35683a87153b11490119f8.svg)

------

严谨地推论可以得知在 k 增大到一定时候，会将因 k 增大而减少外部访问次数的收益抵消掉。因此，我们不能使用普通的内部排序算法！

在这里引入**败者树。**

### 败者树

其实这个数据结构在日常生活中十分常见，在比赛时，先进行一轮 PK，在有额外的选手参与进来时，不再重新 PK，而是安排从胜者的位置中进行 PK。这样在这后面比较的效率会大大提升。

败者树是树形选择排序的一种变体，可视为一颗完全二叉树，内部节点中保留失败者。

这里的外部排序规定的是：数值大的为失败者，小的为胜利者。因为我们需要的从小到大排序！最后的胜利者就作为最小值写到输出缓存区中，直到输出缓存区中满了一个块的大小就写入到外存的一个块中。

举个例子：

------

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743320652772-a8b12d56-9e76-45d7-b59c-ef74667e5e09.jpeg)

如上：败者树的叶子结点个数 k，就为 k 路归并。

显然的，采用 k 路归并的败者树深度为：![img](https://cdn.nlark.com/yuque/__latex/de4f9ee6bc2132d029693cadd9a312fa.svg)（不包含胜者结点），进行的比较的次数为⌈log_2k⌉

故进行的比较的总次数为：S(n - 1)⌈log_2k⌉

化简为：![img](https://cdn.nlark.com/yuque/__latex/e3d969e49d4aa2e8aff7099a91db18a6.svg)

------

接着上面说的增加 k 就可以减少 IO 操作，引入败者树后比较次数就和 k 无关了，只要内存空间允许，增大归并路数 k，就可以有效地减少 IO 操作，从而提高外部排序的速度！

但是这是基于内存空间足够大的情况，如果内存空间一定，增加 k，则每块的大小会减少，从而每次归并需要的 IO 操作又会增多，唉，有够麻烦的呀！！！（计算机是这样的😋）

------

根据上面的公式

S = ![img](https://cdn.nlark.com/yuque/__latex/741c36d5d19ac7c970b06d343cee2e47.svg)

知道：减少外部排序的时间除了增加 k，还可以减少 r 吧！好像发现新大陆。

根据这个思路就引出了一个新的解决方案：置换-选择排序

### 置换-选择排序

之前分配的归并段每一段都是相等的，初始归并段总数 r 为![img](https://cdn.nlark.com/yuque/__latex/691870d5e9fb14918fd8a2e6ccf7749e.svg)

l 依赖于内部排序时可用的内存工作区（WA）大小，为了减少 r，所以使用新的方法来产生更长的归并段！

令其使用原本大小的 WA 可以构造更长的初始归并段（越长当然个数越小咯）

------

其实方法非常的简单：

假设 WA 可以存储 3 个记录，然后外部待排序存储文件分别为：4,6,9,7,13,11,16,14,10。

还有一个变量 MINIMAX 用于存储 3 个记录中的最小值

首先进入 3 个：4,6,9

找出最小的 4 加入归并段 1 并令 MINIMAX 为 4 再进入 7

此时 WA 中的最小值为 6 且大于 MINIMAX 故可以加入到归并段 1 再进入 13

找出最小的 7，大于 MINIMAX 故可以加入归并段 1 并令 MINIMAX 为 7 再进入 11

......

此时 WA 中为 14,16，MINIMAX 为 13，进入 10

因为 10 小于 MINIMAX 故不能进入归并段 1，只能再开一个归并段 2，此时归并段 1 就已经处理完了。

依次类推，直到所有外部文件都处理完毕。

在选择 MINIMAX 时是采用的**败者树**实现的

https://player.bilibili.com/player.html?bvid=BV1b7411N798&p=103&page=103&autoplay=0

------

### 最佳归并树

归并树：各叶结点表示一个初始归并段，上面的权值表示该归并段的长度，叶结点到根节点的路径长度表示参与归并的趟数，各非叶子结点代表归并成的新归并段。

使用置换-选择排序后，得到的初始归并段长度是不一致的。

而这个最佳归并树就是为了解决**怎样组织长度不一致的初始归并段的归并顺序，使其 IO 次数最少**。

在归并树中该树的 WPL 乘以 2 就为对应初始段的 IO 操作次数

------

要使得归并树为一个最佳归并树，就要使的 WPL 最小，显然的，此时的最佳归并树也就是一个**哈夫曼树！**

那就要构造一个哈夫曼树，大体和之前构造方法一致，但是需要注意一下地方。

- 因为该“哈夫曼树”的阶数是有采用的 k 路归并决定的，所以可以是 k 阶
- 如果在某次归并中不是使用的 k 路归并则出错

最后一个需要注意的地方进行说明：

**由归并树构成的哈夫曼树一定要是一个严格 k 叉树。**

之所以会出现某次归并不是 k 路归并，就是因为该归并树的结点数不够形成一颗完全 k 叉树。为了解决这个问题就需要添加“虚段”，也就是权值为 0 的初始段！

如何添加“虚段”呢？如下：

------

设：度为 0 的结点有![img](https://cdn.nlark.com/yuque/__latex/fae17384674b5ec0640c50049ea43076.svg)个，度为 k 的结点有![img](https://cdn.nlark.com/yuque/__latex/d150ef9da5e420d7b49c1459bdc3bfe2.svg)个，归并树的结点数总共有![img](https://cdn.nlark.com/yuque/__latex/53bd15bd9229cd48a311be75b1a51db2.svg)个，则有：

![img](https://cdn.nlark.com/yuque/__latex/a0cabecbbf69c007f2545a9bf3237c19.svg)

![img](https://cdn.nlark.com/yuque/__latex/a0e8bf6b5d4c27d4152e404a663f6f3c.svg)

由此可知：对于严格 k 叉树有：![img](https://cdn.nlark.com/yuque/__latex/128ae40dda374b9e9b796365c3b811fd.svg)

故有![img](https://cdn.nlark.com/yuque/__latex/a39427813efc38060687d7a733dee9df.svg)

若 ![img](https://cdn.nlark.com/yuque/__latex/ae2d1e7c624621f31fa05d0a62fd5897.svg)= 0 则表示 ![img](https://cdn.nlark.com/yuque/__latex/6a856162e54b4148ca4a773f3b2ec9e0.svg)个叶子结点可以构成一颗 k 叉归并树，此时内部结点有![img](https://cdn.nlark.com/yuque/__latex/d150ef9da5e420d7b49c1459bdc3bfe2.svg)个。

若![img](https://cdn.nlark.com/yuque/__latex/ae2d1e7c624621f31fa05d0a62fd5897.svg) = u 则表示 ![img](https://cdn.nlark.com/yuque/__latex/6a856162e54b4148ca4a773f3b2ec9e0.svg)个叶子结点不能构成一颗 k 叉归并树，其中有 u 个多余，不能包含在 k 叉归并树中。为了构造包含所有叶子结点的 k 叉归并树，需要在添加  ![img](https://cdn.nlark.com/yuque/__latex/cb5a760ed9273fe4190f6ef40702aa88.svg)个“虚段”，再进行构造。

------

举个例子：

如果有初始归并段为：2、3、6、9、12、17、18、24 对其进行 3 路归并

1. 不采用“虚段”

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743328407349-8c9b255a-9e96-40e5-9b90-4ceba5a05677.jpeg)

这样做法在 32 和 59 这一层就不是采用的 3 路归并，就是错误的！

此时的 WPL 为 193

1. 采用“虚段”

![img](https://cdn.nlark.com/yuque/0/2025/jpeg/48073730/1743328553303-f2205cf1-cf6d-45e7-bfb0-038895772daa.jpeg)

因为总的初始归并段数为 8，采用 3 路归并，根据上面的公式得余数为 1

故需要添加 3 - 1 - 1 个“虚段”

此时 WPL 为 139

显然比上面不添加“虚段”的 WPL 小！

## 排序算法的比较和应用

对各个内部排序的性质做一个表格。

| 算法种类     |                                                              | 时间复杂度                                                   |                                                              | 空间复杂度                                                   | 稳定性 |
| ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------ |
|              | 最好情况                                                     | 最坏情况                                                     | 平均情况                                                     |                                                              |        |
| 直接插入排序 | ![img](https://cdn.nlark.com/yuque/__latex/d76f5cf3fcea4956dc2914d44e6cd5e6.svg) | ![img](https://cdn.nlark.com/yuque/__latex/2a1f5db7ab84c7a1ad631960ee8647e9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg) | 稳定   |
| 冒泡排序     | ![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg) | 稳定   |
| 简单选择排序 | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg) | 不稳定 |
| 希尔排序     | ![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/057b59460eee88aad289b71782d747e2.svg) | ![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg) | 不稳定 |
| 快速排序     | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f2d5f588234eb61a559ff90c41511b85.svg) | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/65c54415e21b8b592c65dc4cd43cbd33.svg) | 不稳定 |
| 堆排序       | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/a2006f1ac61cb1902beacb3e29fff089.svg) | 不稳定 |
| 二路归并排序 | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg) | ![img](https://cdn.nlark.com/yuque/__latex/e65a67ac353abeeff44c359310d05c02.svg) | 稳定   |
| 基数排序     | ![img](https://cdn.nlark.com/yuque/__latex/f96b90b4e660ba19902c37579e2c0992.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f96b90b4e660ba19902c37579e2c0992.svg) | ![img](https://cdn.nlark.com/yuque/__latex/f96b90b4e660ba19902c37579e2c0992.svg) | ![img](https://cdn.nlark.com/yuque/__latex/76c87bdcdbb3dbe867d829ff2a95017b.svg) | 稳定   |

上面快排空间复杂度有可能降为 n！写的都是平均大小，具体的数据到对应位置查看。



------

在对一组数据选择排序算法时，要多方面考虑，如：

- 待排序元素的个数 n
- 待排序元素的初始状态
- 关键字的结构及分布情况
- 稳定性的要求
- 存储结构及辅助空间的大小限制

若 n 较小，则可采用**直接插入排序或简单选择排序**，其中直接插入排序所需要的记录移动次数比简单选择排序多，因此在记录的信息较大时，应采用简单选择排序！

若 n 较大，则应该采用平均时间复杂度为：![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg)的排序算法，也就是**快排、堆排、归并排序**。它们各有优点，快排被认为是目前基于比较的内部算法中最好的算法。堆排使用的辅助空间较少，且不会出现快排的最坏情况，但这两者都是不稳定的。若需要又快又稳定则可以选择归并算法。

若数据在初始态就已经基本有序了，则可以选择直接插入算法和冒泡算法。

若 n 很大，记录的关键字位数较少且可以分解时，采用基数排序算法。

当记录信息量很大时，为了避免消耗大量的时间来移动，故可以采用链表作为存储结构。

只要是基于“比较”的排序算法，在关键字比较后仅有两种转移可能，故可以使用一颗二叉树来描述比较的过程。由此可知，只要是 n 个随机的关键字使用基于“比较”的排序算法排序，则至少需要![img](https://cdn.nlark.com/yuque/__latex/648f3680e061da44160a6d658847c5d9.svg)的时间复杂度。