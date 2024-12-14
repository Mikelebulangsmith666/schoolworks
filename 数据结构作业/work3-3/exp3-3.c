// exp3-3.cpp

#include "sqqueue.c" // 包含环形队列的定义和基本运算

int main() {
    SqQueue q;
    
    // （1）初始化队列q
    InitQueue(&q);
    
    // （2）判断队列q是否非空
    if (!QueueEmpty(&q)) {
        printf("Queue is not empty\n");
    } else {
        printf("Queue is empty\n");
    }
    
    // （3）依次进队元素a、b、c
    EnQueue(&q, 'a');
    EnQueue(&q, 'b');
    EnQueue(&q, 'c');
    
    // （4）出队一个元素，输出该元素
    char e;
    if (DeQueue(&q, &e)) {
        printf("Dequeued element: %c\n", e);
    }
    
    // （5）依次进队元素d、e、f
    EnQueue(&q, 'd');
    EnQueue(&q, 'e');
    EnQueue(&q, 'f');
    
    // （6）输出出队序列
    printf("Popping elements from queue: ");
    PrintQueueSequence(&q);
    
    // （7）释放队列
    FreeQueue(&q); // 对于顺序队列，这一步通常不是必需的
    
    return 0;
}