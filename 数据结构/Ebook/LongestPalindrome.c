#include <stdio.h>

/**
 * 最长回文子串
 * 题目描述
 * 给定一个字符串，求它的最长回文子串的长度。
 *
 */

int getLongByOdd(const char * str, const int len) {
    int max = 0, c = 0;
    for (int i = 0; i < len; i++) {
        //该字符串个数为奇数时：adada
        for (int j = 0; (i - j) >= 0 && (i + j < len); j++) {
            if (str[i - j] != str[i + j])
                break;
            c = j * 2 + 1;
        }
        if (c > max)
            max  = c;
    }
    return max;
}

int getLongByEven(const char * str, const int len) {
    int max = 0, c = 0;
    for (int i = 0; i < len; i++) {
        //该字符串个数为偶数时：abaaba
        for (int j = 0; (i - j) >= 0 && (i + j + 1 < len); j++) {
            if (str[i - j] != str[i + j + 1])
                break;
            c = j * 2 + 2;
            if (c > max)
                max = c;
        }
    }
    return max;
}

//思路一：一个回文串的前缀和后缀都是一致的，所以进行枚举中心点并更新最大长度则可
//因为奇数和偶数的中心点在不同位置，所以需要进行不同的处理
int longestPalindrome(const char *string, const int len) {
    //需要合法的输入数据
    if (string == 0 || len < 0)
        return 0;
    int max = 0;
    if (len % 2 == 1){
        max = getLongByOdd(string, len);
    }else {
        max = getLongByEven(string, len);
    }
    return max;
}
int main(){
    printf("%d", longestPalindrome("aaddaa", 6));
    return 0;
}