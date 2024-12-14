// exp2-3.cpp

#include "dlinklist.cpp" // 包含双链表的定义和基本运算

int main() {
    DLinkList h;
    
    // （1）初始化双链表h
    InitDLinkList(&h);
    
    // （2）依次采用尾插法插入a、b、c、d、e元素
    InsertTail(&h, 'a');
    InsertTail(&h, 'b');
    InsertTail(&h, 'c');
    InsertTail(&h, 'd');
    InsertTail(&h, 'e');
    
    // （3）输出双链表h
    PrintDLinkList(&h);
    
    // （4）输出双链表h的长度
    printf("Length of DLinkList: %d\n", GetLength(&h));
    
    // （5）判断双链表是否为空
    if (!IsEmpty(&h)) {
        printf("DLinkList is not empty\n");
    } else {
        printf("DLinkList is empty\n");
    }
    
    // （6）输出双链表的第3个元素
    char e;
    if (GetElem(&h, 3, &e)) {
        printf("The 3rd element is: %c\n", e);
    }
    
    // （7）输出元素a的位置
    int pos = LocateElem(&h, 'a');
    if (pos != -1) {
        printf("Element 'a' is at position: %d\n", pos);
    } else {
        printf("Element 'a' not found\n");
    }
    
    // （8）在第4个元素位置上插入新元素
    char newElem = 'z';
    if (InsertElem(&h, 4, newElem)) {
        printf("Inserted '%c' at position 4\n", newElem);
    }
    
    // （9）输出双链表h
    PrintDLinkList(&h);
    
    // （10）删除双链表h的第3个元素
    if (DeleteElem(&h, 3, &e)) {
        printf("Deleted element: %c\n", e);
    }
    
    // （11）输出双链表h
    PrintDLinkList(&h);
    
    // （12）释放双链表h
    DestroyDLinkList(&h);
    
    return 0;
}