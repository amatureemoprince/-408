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
int halfFoldSort(int *arr, const int len, const int num) {
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
  printf("half fold sort 133 index: %d", halfFoldSort(arr, len, 133));
  printf("\n");
  // TODO: 测试反转数组
  reverse(arr, len);
  printf("reserver the array: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  // 释放内存
  free(arr);
  return 0;
}