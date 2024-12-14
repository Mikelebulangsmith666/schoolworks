// dlinklist.cpp

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义双链表节点结构
typedef struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
} DNode;

// 双链表类型定义
typedef struct {
    DNode *head;
    int length;
} DLinkList;

// 初始化双链表
void InitDLinkList(DLinkList *L) {
    L->head = (DNode *)malloc(sizeof(DNode));
    if (!L->head) exit(-1); // 内存分配失败
    L->head->prev = NULL;
    L->head->next = NULL;
    L->length = 0;
}

// 销毁双链表
void DestroyDLinkList(DLinkList *L) {
    DNode *p = L->head, *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L->head = NULL;
    L->length = 0;
}

// 尾插法插入元素
bool InsertTail(DLinkList *L, char e) {
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    if (!newNode) return false; // 内存分配失败

    newNode->data = e;
    newNode->next = NULL;

    if (L->head->next == NULL) { // 如果是空链表
        newNode->prev = L->head;
        L->head->next = newNode;
    } else {
        DNode *tail = L->head;
        while (tail->next != NULL) tail = tail->next;
        tail->next = newNode;
        newNode->prev = tail;
    }

    L->length++;
    return true;
}

// 输出双链表
void PrintDLinkList(DLinkList *L) {
    DNode *p = L->head->next;
    printf("DLinkList: ");
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 获取双链表长度
int GetLength(DLinkList *L) {
    return L->length;
}

// 判断双链表是否为空
bool IsEmpty(DLinkList *L) {
    return L->head->next == NULL;
}

// 获取第i个元素
bool GetElem(DLinkList *L, int i, char *e) {
    if (i < 1 || i > L->length) return false;
    DNode *p = L->head->next;
    for (int j = 1; j < i; ++j) {
        p = p->next;
    }
    *e = p->data;
    return true;
}

// 查找元素的位置
int LocateElem(DLinkList *L, char e) {
    DNode *p = L->head->next;
    int pos = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        pos++;
    }
    if (p == NULL) return -1; // 元素不存在
    return pos;
}

// 在第i个位置插入元素
bool InsertElem(DLinkList *L, int i, char e) {
    if (i < 1 || i > L->length + 1) return false;
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    if (!newNode) return false; // 内存分配失败

    DNode *p = L->head;
    for (int j = 1; j < i; ++j) {
        p = p->next;
    }

    newNode->data = e;
    newNode->next = p->next;
    newNode->prev = p;
    if (p->next != NULL) p->next->prev = newNode;
    p->next = newNode;

    L->length++;
    return true;
}

// 删除第i个元素
bool DeleteElem(DLinkList *L, int i, char *e) {
    if (i < 1 || i > L->length) return false;
    DNode *p = L->head->next;
    for (int j = 1; j < i; ++j) {
        p = p->next;
    }

    *e = p->data;
    p->prev->next = p->next;
    if (p->next != NULL) p->next->prev = p->prev;
    free(p);

    L->length--;
    return true;
}