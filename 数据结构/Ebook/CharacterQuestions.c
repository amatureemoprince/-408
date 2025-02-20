#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
* 题目描述:
* 给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，
* 如把字符串“abcdef”前面的2个字符'a'和'b'移动到字符串的尾部，
* 使得原字符串变成字符串“cdefab”。请写一个函数完成此功能，
* 要求对长度为n的字符串操作的时间复杂度为 O(n)，空间复杂度为 O(1)。
*
*/

//第一种思路
//根据其有的性质进行移动

/**
 * 第一种思路解
 * @param string 字符串
 * @param num 反转的字符个数
 */
void moveTargetNumToRight(char *string, const int num){
    const unsigned int len = strlen(string);
    // 分配一个temp，存放更改后的字符串
    char *temp = malloc(sizeof(char) * num);
    // 将前num个字符移动temp后面
    for(int i = 0; i < num; i++){
      temp[len - num + i] = string[i];
    }
    for (int i = 0; i < len - num; i++) {
        temp[i] = string[num + i];
    }
    // 将temp中的数据移到string中
    for (int i = 0; i < len; i++) {
        string[i] = temp[i];
    }
    free(temp);
}

//第二种思路
//反转：将整个字符串分为两个部分，各自反转后再整体反转就可以实现要求
/**
 * 反转字符串
 * @param string 需要反转的字符串
 * @param start 开始的索引
 * @param end 结束的索引
 */
void reverse(char *string, unsigned int start, unsigned int end) {
    while (start < end) {
        const char temp = string[start];
        string[start] = string[end];
        string[end] = temp;
        start++;
        end--;
    }
}

/**
 * 使用reverse函数进行实现
 * @param string 修改的字符串
 * @param num 移动的个数
 */
void leftNumToRight(char *string, const int num) {
    const unsigned int len =  strlen(string);
    reverse(string, 0, num - 1);
    reverse(string, num, len - 1);
    reverse(string, 0, len - 1);
}

//第三种思路
//暴力解法
/**
 * 将字符串的第一个字符移动到末尾
 * @param string 字符串
 * @param len 字符串长度
 */
void removeToRight(char *string, unsigned const int len) {
    const char temp = string[0];
    for (int i = 0; i < len - 1; i++) {
        string[i] = string[i + 1];
    }
    string[len - 1] = temp;
}

/**
 * 使用removeToRight实现
 * @param string 需要修改的字符串
 * @param num 移动的个数
 */
void violenceMove(char *string, int num) {
    while (num--) {
        removeToRight(string, strlen(string));
    }
}
int main(void){
    //测试第一种思路
    char arr[] = "abcde";
    moveTargetNumToRight(arr, 2);
    printf("first thinking: ");
    for (int i = 0; i < strlen(arr); i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
    //测试第二种思路
    char brr[] = "abcdefg";
    printf("second thinking: ");
    leftNumToRight(brr, 2);
    for (int i = 0; i < strlen(brr); i++) {
        printf("%c", brr[i]);
    }
    //测试第三种思路
    printf("\n");
    printf("third thinking: ");
    char crr[] = "abcdefgh";
    violenceMove(crr, 5);
    for (int i = 0; i < strlen(crr); i++) {
        printf("%c", crr[i]);
    }
	return 0;
}
