#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_t {
    int data;
    struct linked_list_t *next;
} linked_list_t;

void append(linked_list_t *head, int data);

void prepend1(linked_list_t *head, int data);

linked_list_t *prepend2(linked_list_t *head, int data);

void prepend3(linked_list_t **head, int data);

int size(linked_list_t *node);

int isEmpty(linked_list_t *head);

linked_list_t *delete(linked_list_t *head);

linked_list_t *deleteFirst(linked_list_t *head);

int deleteElements(linked_list_t *node, int value);

void printElements(linked_list_t *node);

linked_list_t *searchValue(linked_list_t *head, int value);

linked_list_t *bubbleSort(linked_list_t *head);

linked_list_t *insertionSort(linked_list_t *head);

int main()
{
    linked_list_t *head = (linked_list_t *) malloc(sizeof(linked_list_t));
    head->data = 0;
    head->next = NULL;
    append(head, 3);
    //printf("%d\n", head->next->data);
    append(head, 2);
    append(head, 1);
    //printf("%d\n", head->next->next->data);
    prepend1(head, -1);
    //printf("%d\n", head->next->data);
    head = prepend2(head, -2);
    //printf("%d\n", head->data);
    prepend3(&head, -3);
    //printf("%d\n", head->next->data);
    //printf("%d\n", size(head));
    head = delete(head);
    //printf("%d\n", size(head));
    head = deleteFirst(head);
    //printf("%d\n", size(head));
    //printf("%d\n", deleteElements(head, 2));
    //printElements(head);
    head = bubbleSort(head);
    printElements(head);
    return 0;
}

void append(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->data = data;
    new_node->next = NULL;
    linked_list_t *iterator = head;
    while (iterator->next != NULL) {
        iterator = iterator->next;
    }
    iterator->next = new_node;
}

void prepend1(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->data = data;
    new_node->next = head->next;
    head->next = new_node;
}

linked_list_t *prepend2(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->data = 0;
    new_node->next = head;
    head->data = data;
    return new_node;
}

void prepend3(linked_list_t **head, int data)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->data = 0;
    new_node->next = *head;
    (*head)->data = data;
    *head = new_node;
}

int size(linked_list_t *node)
{
    int counter = 0;
    while (node->next != NULL) {
        counter++;
        node = node->next;
    }
    return counter;
}

int isEmpty(linked_list_t *head)
{
    if (head->next == NULL)
        return 1;
    else
        return 0;
}

linked_list_t *delete(linked_list_t *head) // delete actual head!
{
    head->next->data = 0;
    linked_list_t *temp = head->next;
    free(head);
    return temp;
}

linked_list_t *deleteFirst(linked_list_t *head)
{
    linked_list_t *temp = head->next;
    head->next = head->next->next;
    free(temp);
    return head;
}

int deleteElements(linked_list_t *node, int value)
{
    int counter = 0;
    while (node->next != NULL) {
        if (node->next->data == value) {
            linked_list_t *temp = node->next;
            node->next = node->next->next;
            free(temp);
            counter++;
        }
        node = node->next;
    }
    return counter;
}

void printElements(linked_list_t *node)
{
    int a = size(node);
    for (int i = 0; i < a + 1; ++i) {
        printf("%d, ", node->data);
        node = node->next;
    }
}

linked_list_t *searchValue(linked_list_t *node, int value)
{
    while (node->next != NULL) {
        if (node->data == value)
            return node;
        else
            node = node->next;
    }
    return 0;
}

linked_list_t *bubbleSort(linked_list_t *node)
{
    int swapped = 1;
    linked_list_t *head = node;
    linked_list_t *temp = (linked_list_t *) malloc(sizeof(linked_list_t));
    while (swapped) {
        swapped = 0;
        while (node->next != NULL) {
            if (node->data > node->next->data) {
                swapped = 1;
                temp->data = node->data;
                node->data = node->next->data;
                node->next->data = temp->data;
            }
            node = node->next;
        }
        node = head;
    }
    free(temp);
    return head;
}

linked_list_t *insertionSort(linked_list_t *head)
{
    linked_list_t *sorted = head;
    linked_list_t *prev = head;
    linked_list_t *temp;
    linked_list_t *temp2;
    while (prev->next != NULL) {
        temp = sorted;
        while (prev->next != NULL && temp != prev->next && temp->data < prev->next->data)
            temp = temp->next;
        if (prev->next != temp) {
            temp2 = prev->next;
            prev->next = prev->next->next;
            sorted = prepend1(sorted,temp2->data);
        }
    }


    free(temp);
    return head;
}