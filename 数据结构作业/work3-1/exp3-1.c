// exp3-1.cpp

#include "sqstack.c" // 包含顺序栈的定义和基本运算

int main() {
    SqStack s;
    
    // （1）初始化栈
    InitStack(&s);
    
    // （2）判断栈是否非空
    if (!StackEmpty(&s)) {
        printf("Stack is not empty\n");
    } else {
        printf("Stack is empty\n");
    }
    
    // （3）依次进栈元素a、b、c、d、e
    Push(&s, 'a');
    Push(&s, 'b');
    Push(&s, 'c');
    Push(&s, 'd');
    Push(&s, 'e');
    
    // （4）判断栈是否非空
    if (!StackEmpty(&s)) {
        printf("Stack is not empty\n");
    } else {
        printf("Stack is empty\n");
    }
    
    // （5）输出出栈序列
    printf("Popping elements from stack: ");
    PrintStackSequence(&s);
    
    // （6）判断栈是否非空
    if (!StackEmpty(&s)) {
        printf("Stack is not empty\n");
    } else {
        printf("Stack is empty\n");
    }
    
    // （7）释放栈
    FreeStack(&s); // 对于顺序栈，这一步通常不是必需的
    
    return 0;
}