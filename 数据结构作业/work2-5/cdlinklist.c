#include <stdio.h>
#include <stdlib.h>

// 定义循环双链表的节点结构
typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

// 定义循环双链表结构
typedef struct {
    Node* head;
    int length;
} CircularDoublyLinkedList;

// 初始化循环双链表
void initList(CircularDoublyLinkedList* list) {
    list->head = (Node*)malloc(sizeof(Node));
    if (list->head == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    list->head->prev = list->head->next = list->head;
    list->length = 0;
}

// 尾插法插入元素
void append(CircularDoublyLinkedList* list, char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    
    if (list->length == 0) {
        list->head->next = list->head->prev = newNode;
        newNode->prev = newNode->next = list->head;
    } else {
        Node* lastNode = list->head->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = list->head;
        list->head->prev = newNode;
    }
    list->length++;
}

// 打印循环双链表
void printList(const CircularDoublyLinkedList* list) {
    if (list->length == 0) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = list->head->next;
    do {
        printf("%c ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("\n");
}

// 获取循环双链表长度
int getListLength(const CircularDoublyLinkedList* list) {
    return list->length;
}

// 判断循环双链表是否为空
int isEmpty(const CircularDoublyLinkedList* list) {
    return list->length == 0;
}

// 获取第index个元素
char getElementAt(const CircularDoublyLinkedList* list, int index) {
    if (index < 1 || index > list->length) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }

    Node* temp = list->head->next;
    for (int i = 1; i < index; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

// 查找元素位置
int findElement(const CircularDoublyLinkedList* list, char val) {
    Node* temp = list->head->next;
    int index = 1;
    do {
        if (temp->data == val) {
            return index;
        }
        temp = temp->next;
        ++index;
    } while (temp != list->head);

    return -1;
}

// 在第index个位置插入元素
void insertAt(CircularDoublyLinkedList* list, int index, char val) {
    if (index < 1 || index > list->length + 1) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;

    if (index == 1) {
        Node* lastNode = list->head->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = list->head->next;
        list->head->next->prev = newNode;
        list->head->next = newNode;
    } else {
        Node* temp = list->head->next;
        for (int i = 1; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    list->length++;
}

// 删除第index个元素
void deleteAt(CircularDoublyLinkedList* list, int index) {
    if (index < 1 || index > list->length) {
        fprintf(stderr, "Index out of bounds\n");
        exit(1);
    }

    Node* toDelete;
    if (index == 1) {
        toDelete = list->head->next;
        list->head->next = toDelete->next;
        toDelete->next->prev = list->head;
    } else {
        Node* temp = list->head->next;
        for (int i = 1; i < index; ++i) {
            temp = temp->next;
        }
        toDelete = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(toDelete);
    list->length--;
}

// 释放循环双链表
void clearList(CircularDoublyLinkedList* list) {
    if (list->length == 0) return;

    Node* current = list->head->next;
    Node* nextNode;
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != list->head);
    free(list->head);
    list->head = NULL;
    list->length = 0;
}

// 测试函数
/*h
int main() {
    CircularDoublyLinkedList h;
    initList(&h);

    // (2) Tail insert elements a, b, c, d, e.
    append(&h, 'a');
    append(&h, 'b');
    append(&h, 'c');
    append(&h, 'd');
    append(&h, 'e');

    // (3) Print the list.
    printList(&h);

    // (4) Print the list length.
    printf("List length: %d\n", getListLength(&h));

    // (5) Check if the list is empty.
    printf("Is list empty? %s\n", isEmpty(&h) ? "Yes" : "No");

    // (6) Print the 3rd element.
    printf("The 3rd element is: %c\n", getElementAt(&h, 3));

    // (7) Print the position of element 'a'.
    printf("Position of element 'a': %d\n", findElement(&h, 'a'));

    // (8) Insert an element at the 4th position.
    insertAt(&h, 4, 'x');

    // (9) Print the updated list.
    printList(&h);

    // (10) Delete the 3rd element.
    deleteAt(&h, 3);

    // (11) Print the updated list after deletion.
    printList(&h);

    // (12) Free the list.
    clearList(&h);

    return 0;
}
*/