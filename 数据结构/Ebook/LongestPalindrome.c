#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * 最长回文子串
 * 题目描述
 * 给定一个字符串，求它的最长回文子串的长度。
 *
 */

//思路一：一个回文串的前缀和后缀都是一致的，所以进行枚举中心点并更新最大长度则可
int longestPalindrome(const char *string, const int len) {
    //需要合法的输入数据
    if (string == 0 || len < 0)
        return 0;
    int max = 0;
    for (int i = 0; i < len; i++) {
        //该字符串个数为奇数时：adada
        for (int j = 0; i < )
    }

    return 1;
}
int main(){

  return 0;
}