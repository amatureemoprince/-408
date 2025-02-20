#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * 题目描述
 * 回文，英文palindrome，指一个顺着读和反过来读都一样的字符串，比如madam、我爱我，这样的短句在智力性、
 * 趣味性和艺术性上都颇有特色，中国历史上还有很多有趣的回文诗。
 * 那么，我们的第一个问题就是：判断一个字串是否是回文？
 */

//思路一：从两边向中间进行判断
/***
 * @param string 需要判断的字符串
 * @return 是否为回文数
 */
bool palindrome(const char *string) {
  if (string == NULL) {
    return false;
  }
  int end = (int) strlen(string) - 1;
  int start = 0;
  while (start < end) {
    if (string[start] != string[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}
//思路二：可以从中间向两边进行判断
bool palindromeFromMid(const char *string, const int len) {
  //获取中间值：采用位运算获取
  /***
   *   偶数个数： a  b  b  a
   *               ^  ^
   *   奇数个数： a  b  c  d  e
   *               ^     ^
   *   箭头就是需要指向的位置，然后从这个位置向两侧进行判断则可
   */
  const int mid = ((len >> 1) - 1) >= 0 ? len - 1 : 0;
  //从左侧加了一个mid与之对称的是从右侧加一个mid，这样就是关于中心对称了
  const char *left = string + mid;
  const char *right = string + len - 1 - mid;
  while (left >= string) {
    if (*left != *right) {
      return false;
    }
    left--;
    right++;
  }
  return true;
}
int main(){
  const char arr[1000];
  printf("please input a string :");
  // &取地址符
  scanf("%s", &arr);
  printf("first thinking: ");
  if (palindrome(arr)) {
    printf("is a palindrome");
  }else {
    printf("isn't a palindrome");
  }
  printf("\n");

  printf("second thinking: ");
  if (palindromeFromMid(arr, (int)strlen(arr))) {
    printf("is a palindrome");
  }else {
    printf("isn't a palindrome");
  }
  return 0;
}