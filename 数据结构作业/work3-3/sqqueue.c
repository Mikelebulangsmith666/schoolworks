// sqqueue.cpp

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10 // 定义队列的最大长度（可以适当调整）

// 环形队列的结构定义
typedef struct {
    char data[MAXSIZE];
    int front; // 队头指针
    int rear;  // 队尾指针
} SqQueue;

// 初始化队列
void InitQueue(SqQueue *q) {
    q->front = q->rear = 0; // 初始化队头和队尾指针
}

// 判断队列是否为空
bool QueueEmpty(SqQueue *q) {
    return q->front == q->rear;
}

// 判断队列是否已满
bool QueueFull(SqQueue *q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

// 入队操作
bool EnQueue(SqQueue *q, char e) {
    if (QueueFull(q)) {
        printf("Queue Overflow\n");
        return false;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE; // 更新队尾指针
    return true;
}

// 出队操作
bool DeQueue(SqQueue *q, char *e) {
    if (QueueEmpty(q)) {
        printf("Queue Underflow\n");
        return false;
    }
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE; // 更新队头指针
    return true;
}

// 输出出队序列，同时清空队列
void PrintQueueSequence(SqQueue *q) {
    while (!QueueEmpty(q)) {
        char e;
        DeQueue(q, &e);
        printf("%c ", e);
    }
    printf("\n");
}

// 释放队列（对于顺序队列，实际上不需要做特殊操作，这里仅做示例）
void FreeQueue(SqQueue *q) {
    // 对于顺序队列，队列是静态分配的，不需要释放
}