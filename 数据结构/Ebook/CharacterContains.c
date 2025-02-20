#include <stdbool.h>
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
/**
 *题目描述
 *给定两个分别由字母组成的字符串A和字符串B，字符串B的长度比字符串A短。请问，如何最快地判断字符串B中所有字母是否都在字符串A里？
 *为了简单起见，我们规定输入的字符串只包含大写英文字母，请实现函数bool StringContains(string &A, string &B)
 *比如，如果是下面两个字符串：
 *String 1：ABCD
 *String 2：BAD
 *答案是true，即String2里的字母在String1里也都有，或者说String2是String1的真子集。
 *如果是下面两个字符串：
 *String 1：ABCD
 *String 2：BCE
 *答案是false，因为字符串String2里的E字母不在字符串String1里。
 *同时，如果string1：ABCD，string 2：AA，同样返回true。
 */
//第一种思路
//可以维护一个长为26的数组，然后初始化为0，只要String2有的对应ASCII码就为1，就容易判断了
/**
 * 维护一个哈希表进行处理
 * @param A 长字符串
 * @param B 短字符串
 * @return A是否包含B
 */
bool StringContains(const char *A, const char *B) {
  int letter[26] = {0};
  //得到最终的letter
  for (int i = 0; i < strlen(A); i++) {
    letter[A[i] - 'A'] = 1;
  }
  //查询letter
  for (int i = 0; i < strlen(B); i++) {
    if (letter[B[i] - 'A'] == 0) {
      return false;
    }
  }
  return true;
}

//第一种思路的优化：使用计算机中的bit代替数组
bool StringContainBetter(const char *A, const char *B){
  int hash = 0;
  for (int i = 0; i < strlen(A); ++i)
  {
    hash |= (1 << (A[i] - 'A'));
  }
  for (int i = 0; i < strlen(B); ++i)
  {
    if ((hash & (1 << (B[i] - 'A'))) == 0)
    {
      return false;
    }
  }
  return true;
}
//第二种思路
//将A、B两个字符串中的字母进行排序然后进行依次比较，但是这种方法显然是没有上面的好的
// 比较函数，用于 qsort
int compareChars(const void *a, const void *b) {
  return (*(char *)a - *(char *)b);
}
// 排序函数
void sort(char *string) {
  const size_t len = strlen(string);
  qsort(string, len, sizeof(char), compareChars);
}
bool sortStringContains(const char *A, const char *B) {
  char *sortedA = strdup(A);
  char *sortedB = strdup(B);

  if (sortedA == NULL || sortedB == NULL) {
    // 处理内存分配失败
    free(sortedA);
    free(sortedB);
    return false;
  }

  // 对字符串 A 和 B 进行排序
  sort(sortedA);
  sort(sortedB);

  // 使用两个指针进行比较
  int i = 0, j = 0;

  while (i < strlen(sortedA) && j < strlen(sortedB)) {
    if (sortedA[i] == sortedB[j]) {
      j++; // 找到 B 中的字符，移动 B 的指针
    }else {
      i++;
    }
  }

  // 如果 j 达到 sortedB 的长度，说明 B 中的所有字符都在 A 中
  const bool result = (j == strlen(sortedB));

  // 释放内存
  free(sortedA);
  free(sortedB);
  return result;
}

//第三种思路
//采用暴力破解：循环遍历每一个字符并进行判断

int main(void){
  //测试第一种思路
  const char A[] = "ABCDE";
  const char B[] = "CEF";
  printf("first thinking: ");
  if (StringContains(A, B)) {
    printf("A contains B");
  }else {
    printf("A don't contains B");
  }

  printf("\n");
  //测试第二种思路
  printf("second thinking: ");
  const char C[] = "ABCDE";
  const char D[] = "CE";
  if (sortStringContains(C, D)) {
    printf("C contains D");
  }else {
    printf("C don't contains D");
  }
  return 0;
}
