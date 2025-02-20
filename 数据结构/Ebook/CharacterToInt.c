#include <ctype.h>
#include<stdio.h>
#include<string.h>

/**
 * 
 * @param num 幂数
 * @return 10的幂指数结果
 */
int powerIndex(const int num) {
  int result = 1;
  for (int i = 0; i < num; i++) {
    result *= 10;
  }
  return result;
}

/**
 * 
 * @param str 需要转换的字符串
 * @return 转换后的整数
 */
//此时的代码健壮性不好，需要重构一下
int strToInt(const char *str) {
  //  1234
  int num = 0;
  const int len = (int)strlen(str);
  for (int i = 0; i < len; i++) {
    num = num * 10 + str[i] - '0';
  }
  return num;
  // const int len = (int) strlen(str);
  // int num = 0;
  // for (int i = 0; i < len; i++) {
  //   num += (str[i] - '1' + 1) * powerIndex(len - 1 - i);
  // }
  // return num;
}

/**
 * 优化重构后的实现
 * @param str 需要转换的字符串
 * @return 转换后的整数
 */
int betterStrToInt(const char *str) {
  static const int MAX_INT = (int)((unsigned)~0 >> 1);
  static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
  int n = 0;
  //判断是否输入为空
  if (str == 0)
  {
    return 0;
  }

  //处理空格
  while (isspace(*str))
    ++str;

  //处理正负
  int sign = 1;
  if (*str == '+' || *str == '-')
  {
    if (*str == '-')
      sign = -1;
    ++str;
  }
  //确定是数字后才执行循环
  while (isdigit(*str))
  {
    //处理溢出
    int c = *str - '0';
    if (sign > 0 && (n > MAX_INT / 10 || (n == MAX_INT / 10 && c > MAX_INT % 10)))
    {
      n = MAX_INT;
      break;
    }
    else if (sign < 0 && (n >(unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
    {
      n = MIN_INT;
      break;
    }
    //把之前得到的数字乘以10，再加上当前字符表示的数字。
    n = n * 10 + c;
    ++str;
  }
  return sign > 0 ?  n :  -n;
}
int main(void){
  printf("%d", strToInt("4922"));
  return 0;
}
