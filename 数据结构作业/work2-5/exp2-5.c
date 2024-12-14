#include "cdlinklist.c"

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