#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 插入操作
 * @param arr 要插入的数组
 * @param index 插入的索引
 * @param val 插入的值
 * @param len 数组的长度
 */
void insert(int **arr, int *len, const int index, const int val) {
  // 判断数据是否合理
  if (arr == NULL || *arr == NULL || index < 0 || index > *len) {
    printf("invalid parameters\n");
    return;
  }
  // 扩展数组的长度
  (*len)++;
  *arr = realloc(*arr, (*len) * sizeof(int));
  if (*arr == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  // 移动元素
  for (int i = *len - 1; i > index; i--) {
    (*arr)[i] = (*arr)[i - 1];
  }
  (*arr)[index] = val;
}

/**
 *
 * @param arr 要删除的数组
 * @param index 删除元素的索引
 * @param len 数组长度
 * @return 是否成功删除
 */
bool removeIndex(int *arr, const int index, int *len) {
  if (arr == NULL || index < 0 || index >= *len) {
    printf("invalid parameters\n");
    return false;
  }
  for (int i = index; i < *len - 1; i++) {
    arr[i] = arr[i + 1];
  }
  // 更新长度，这样就不用处理剩余那个元素了，因为已经不会再遍历到它了
  (*len)--;
  return true;
}

/**
 *
 * @param arr 数组
 * @param num 要查找的元素
 * @param len 数组长度
 * @return 元素索引
 */
int findElement(const int *arr, const int num, const int len) {
  if (arr == NULL) {
    printf("the array is the null");
    return -1;
  }
  for (int i = 0; i < len; i++) {
    if (arr[i] == num) {
      return i;
    }
  }
  return -1;
}

/**
 * 冒泡排序
 * @param arr 要排序的数组
 * @param len 数组长度
 */
void bubbleSort(int *arr, const int len) {
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        const int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

/**
 * 折半查找（二分查找）
 * @param arr 折半排序的数组
 * @param len 数组长度
 * @param num 要查找的元素
 */
int halfFoldFind(int *arr, const int len, const int num) {
  //先将其排序
  bubbleSort(arr, len);
  int start = 0;
  int end = len - 1;
  //使用双指针，每查找一次就会缩短一半
  while (start <= end) {
    const int mid = start + (end - start) / 2;
    if (num == arr[mid]) {
      return mid;
    }else {
      if (num < arr[mid]) {
        end = mid - 1;
      }
      else {
        start = mid + 1;
      }
    }
  }
  return -1;
}

/**
 * 反转数组
 * @param arr 要反转的数组
 * @param len 数组长度
 */
void reverse(int *arr, const int len) {
  // 1  2  3  4  5
  // 1  2  3  4
  // 最前面的和最后面的元素进行交换则可
  for (int i = 0; i < len / 2; i++) {
    const int temp = arr[i];
    arr[i] = arr[len - i - 1];
    arr[len - i - 1] = temp;
  }
}

/**
 * 给定一个含n(n>=1)
 * 个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。例如，数组{−5,3,2,3}
 * 中未出现的最小正整数是1；数组{1,2,3}
 * 中未出现的最小正整数是4
 */
int findMinPositive(int *arr, const int len) {
  //进行排序
  bubbleSort(arr, len);
  int index = 1;
  for (int i = 0; i < len; i++) {
    if (arr[i] <= 0) {
      continue;
    }
    if (arr[i] != index) {
      return index;
    }
    index++;
  }
  return 0;
}

/**
 * 2010年考题
 * 设将n(n>1)
 * 个整数存放到一维数组R中。设计一个在时间和空间两方面都尽可能高效的算法，将R中保存的序列循环左移p(0<p<n)
 * 个位置，即将R中的数据由(X0,X1,...,Xn−1)
 * 变换为(Xp,Xp+1,...,Xn−1,X0,X1,...,Xp−1)。
 */
//随便写一个数组观察就可以得出规律
//    1 2 3 4  移动位数p
//    2 3 4 1    1
//    3 4 1 2    2
//    4 1 2 3    3
void moveLeft(int arr[], const int p, const int len) {
  int *brr = (int *) malloc(sizeof(int) * p);
  //取出前p个元素
  printf("\nbrr: ");
  for (int i = 0; i < p; i++) {
    brr[i] = arr[i];
    printf("%d ", brr[i]);
  }
  printf("\narr: ");
  //移动后面的到前面
  for (int i = p; i < len; i++) {
    arr[i - p] = arr[i];
    printf("%d ", arr[i - p]);
  }
  //将之前取出来的元素放入arr
  for (int i = 0; i < p; i++) {
    arr[len - p + i] = brr[i];
  }
  printf("\n");
  free(brr);
}

/**
 * 2011统考真题
 *一个长度为L（L>=1）的升序序列S，处在第[L/2]个位置的数称为S的中位数。例如，若序列S1=(11,13,15,17,19)则S1的中位数是15
 *，两个序列的中位数是它们所有元素的升序序列的中位数。例如，若S2=(2,4,6,8,20)
 *，则S1和S2的中位数是11。现在有两个等长升序序列A和B，设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。
 */
//肯定需要将两个数组进行排序，然后找到L/2位置的元素
int findMidNumber(const int *arr, const int *brr, const int len) {
  //声明两个指针，用于两个数组元素的比较大小
  int a = 0;
  int b = 0;
  int *crr = (int *)malloc(sizeof(int) * (len + len));
  while (a < len || b < len) {
    if (arr[a] <= brr[b] && a < len) {
      crr[a + b] = arr[a];
      a++;
    }else if (arr[a] > brr[b] && b < len) {
      crr[a + b] = brr[b];
      b++;
    }
  }
  const int result = crr[(len + len) / 2];
  printf("traversal the array: ");
  for (int i = 0; i < 2 * len; i++) {
    printf("%d ", crr[i]);
  }
  free(crr);
  return result;
}

int main(void) {
  // 动态分配数组
  int *arr = (int *)malloc(5 * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  arr[0] = 13;
  arr[1] = 32;
  arr[2] = 133;
  arr[3] = 83;
  arr[4] = 21;
  int len = 5; // 当前数组长度

  // TODO: 测试插入操作
  insert(&arr, &len, 3, 5);
  printf("New length after insertion: %d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // TODO: 测试移除操作
  removeIndex(arr, 3, &len);
  printf("New length after removal: %d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  printf("traversal find 133, it's index is: %d", findElement(arr, 133, len));
  printf("\n");
  // TODO: 测试冒泡排序
  printf("bubble sort result: ");
  bubbleSort(arr, len);
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  // TODO: 测试折半查找
  printf("half fold sort 133 index: %d", halfFoldFind(arr, len, 133));
  printf("\n");
  // TODO: 测试反转数组
  reverse(arr, len);
  printf("reserver the array: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  // 释放内存
  free(arr);
  printf("\n");
  // TODO: 测试2018年考试题
  int brr[]  = {-1, 1, 2, 4, 12, 23};
  printf("the positive min is %d \n", findMinPositive(brr, 6));
  // TODO: 测试2011年考题
  const int crr[5] = {11,13,15,17,19};
  const int drr[5] = {2,4,6,8,20};
  printf("\nthe 2011 year's result is %d\n", findMidNumber(crr, drr, 5));
  // TODO: 测试2010年考试题
  int err[6] = {12, 34, 44, 54, 67, 99};
  moveLeft(err, 3, 6);
  printf("test 2010's result: ");
  for (int i = 0; i < 6; i++) {
    printf("%d ", err[i]);
  }
  return 0;
}