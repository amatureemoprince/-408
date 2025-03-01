/**
 * 王道课后习题
 *第二章:线性表
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * 第一题
 */
int findMin(int* arr, int *len) {
    if (arr == NULL) {
        fprintf(stderr, "arr is the NULL");
        exit(1);
    }
    int min = arr[0];
    int index = 0;
    for (int i = 0; i < *len; i++) {
        if (arr[i] < min) {
            index = i;
            min = arr[i];
        }
    }
    for (int i = index; i < *len; i++) {
        arr[i] = arr[i + 1];
    }
    (*len)--;
    return min;
}
void minePrintf(const char *info) {
    printf(info);
    printf("==========================================================");
    printf("\n");
}

/**
 * 第二题
 */
void reserver(int *arr, const int len) {
    int first = 0;
    int end = len - 1;
    while (first < end) {
        const int temp = arr[first];
        arr[first] = arr[end];
        arr[end] = temp;
        first++;
        end--;
    }
}

/**
 * 第三题
 */
void deleteSample(int *arr, int *len, const int x) {
    int k = 0;
    for (int i = 0; i < *len; i++) {
        if (arr[i] != x) {
            arr[k++] = arr[i];
        }
    }
    (*len) = k;
}

/**
 * 第四题
 */
void deleteRange(int *arr, const int t, const int s, int *len) {
    if (arr == NULL) {
        fprintf(stderr, "arr is the NULL");
        exit(1);
    }
    if (t >= s) {
        fprintf(stderr, "s must bigger than t");
        exit(1);
    }
    int k = 0;
    for (int i = 0; i < (*len); i++) {
        if (arr[i] > s || arr[i] < t) {
            arr[k++] = arr[i];
        }
    }
    (*len) = k;
}
int main(void){
    //第一题测试
    int arr[5] = {3, 1, 4, 5, 7};
    int len = 5;
    minePrintf("fist test:");
    printf("the min number is %d\nthe arr is :", findMin(arr, &len));
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //第二题测试
    minePrintf("second test:");
    int brr[5] = {3, 1, 4, 5, 7};
    printf("the origin brr is : 3, 1, 4, 5, 7\n");
    reserver(brr, 5);
    printf("the result brr is : ");
    for (int i = 0; i < 5; i++) {
        printf("%d, ", brr[i]);
    }
    printf("\n");
    minePrintf("third test: ");
    int crr[5] = {12, 4 , 4, 21, 4};
    int len2 = 5;
    printf("the origin crr is : 12, 4 , 4, 21, 4\n");
    deleteSample(crr, &len2, 4);
    printf("the result brr is : ");
    for (int i = 0; i < len2; i++) {
        printf("%d, ", crr[i]);
    }
    printf("\n");
    minePrintf("fourth test: ");
    int drr[5] = {12, 22, 23, 44, 56};
    int len3 = 5;
    printf("the origin drr is : 12, 22, 23, 44, 56\n");
    deleteRange(drr, 22, 44, &len3);
    printf("the result is : ");
    for (int i = 0; i < len3; i++) {
        printf("%d, ", drr[i]);
    }
    printf("\n");
    return 0;
}