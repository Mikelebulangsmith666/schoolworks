// sqstack.cpp

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100 // 定义栈的最大长度

// 顺序栈的结构定义
typedef struct {
    char data[MAXSIZE];
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack *s) {
    s->top = -1; // 栈顶初始化为-1，表示栈为空
}

// 判断栈是否非空
bool StackEmpty(SqStack *s) {
    return s->top == -1;
}

// 进栈操作
bool Push(SqStack *s, char e) {
    if (s->top == MAXSIZE - 1) {
        printf("Stack Overflow\n");
        return false;
    }
    s->data[++s->top] = e; // 将元素e放入栈顶，并更新栈顶指针
    return true;
}

// 出栈操作
bool Pop(SqStack *s, char *e) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return false;
    }
    *e = s->data[s->top--]; // 取出栈顶元素，并更新栈顶指针
    return true;
}

// 获取栈顶元素（不弹出）
bool GetTop(SqStack *s, char *e) {
    if (s->top == -1) {
        return false;
    }
    *e = s->data[s->top];
    return true;
}

// 输出出栈序列，同时清空栈
void PrintStackSequence(SqStack *s) {
    char e;
    while (!StackEmpty(s)) {
        Pop(s, &e);
        printf("%c ", e);
    }
    printf("\n");
}

// 释放栈（对于顺序栈，实际上不需要做特殊操作，这里仅做示例）
void FreeStack(SqStack *s) {
    // 对于顺序栈，栈是静态分配的，不需要释放
}