#include <stdio.h>
#include <stdlib.h>

/**
 * 定义链表节点
 */
typedef struct Node {
  int data;
  struct Node *next;
} Node;

/**
 * 创建一个链表头结点
 * @return 头节点
 */
Node *createHead() {
  Node *head = (Node *) malloc(sizeof(Node));
  if (head == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  head->data = 0;
  head->next = NULL;
  return head;
}

/**
 * 获取链表长度
 * @param head 链表头
 * @return 链表长度
 */
int getLinkLen(const Node *head) {
  return head->data;
}

/**
 * 创建一个节点
 * @param data 节点的值
 * @return 新节点
 */
Node *createNode(const int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  node->data = data;
  node->next = NULL;
  return node;
}

/**
 * 头插法
 * @param head 插入的链表头结点地址
 * @param data 插入的数据
 */
void insertHead(Node *head, const int data) {
  if (head == NULL) {
    printf("the head is the NULL\n");
    return;
  }
  Node *newNode = createNode(data);
  newNode->next = head->next;
  head->next = newNode;
  head->data++;
}

/**
 *
 * @param head 链表头
 * @param data 元素值
 * @param location 插入的位置
 */
void insertLocation(Node *head, const int data, const int location) {
  if (head == NULL) {
    return;
  }
  head->data++;
  Node *node = createNode(data);
  Node *p = head;
  for (int i  = 0; i < location - 1; i++) {
    p = p->next;
  }
  const Node *q = p->next;
  p->next = node;
  node->next = q->next;
}

/**
 * 尾差法
 * @param head 链表头
 * @param data 插入数值
 */
void insetEnd(Node *head, const int data) {
  if (head == NULL) {
    return;
  }
  head->data++;
  Node *p = head;
  //遍历到最后一个节点
  while (p->next) {
    p = p->next;
  }
  Node * node = createNode(data);
  p->next = node;
}

/**
 * 遍历链表
 * @param head 需要遍历的头节点
 */
void traversalLinkList(const Node *head){
  if (head == NULL || head->next == NULL) {
    printf("the head is the NULL or empty list\n");
    return;
  }
  const Node *node = head->next;
  printf("linkList has %d nodes: ", head->data);
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

/**
 *
 * @param head 查询链表头节点
 * @param num 查找的数值
 * @return 数值的位置
 */
int findElement(const Node *head, const int num) {
  if (head == NULL) {
    return -1;
  }
  int index = 1;
  for (const Node *node = head->next; node; node = node->next) {
    if (node->data == num) {
      return index;
    }
    index++;
  }
  return index;
}

/**
 *
 * @param head 链表的头节点
 * @param index 删除的位置
 */
void deletedElement(Node *head, const int index) {
  if (head == NULL || head->next == NULL) {
    return;
  }
  head->data--;
  Node *p = head;
  //遍历到要删除的节点之前
  for (int i = 0; i < index - 1; i++) {
     p = p->next;
  }
  //删除并释放节点
  Node *q = p->next;
  p->next = q->next;
  free(q);
}

/**
 * 释放链表节点
 * @param head 需要释放的头节点
 */
void freeNode(Node *head) {
  if (head == NULL) {
    return;
  }
  Node *p = head;
  while (p) {
    Node *q = p->next;
    free(p);
    p = q;
  }
}

int main(void){
  Node *head = createHead();
  for (int i = 0; i < 10; i++) {
    insertHead(head, i);
  }
  traversalLinkList(head);
  printf("the index of 5 is %d \n", findElement(head, 5));
  printf("delete 5 location from the linkList .\n");
  deletedElement(head, 5);
  traversalLinkList(head);
  printf("insert 10 in the linkList .\n");
  insertHead(head, 10);
  traversalLinkList(head);
  freeNode(head);
  return 0;
}
