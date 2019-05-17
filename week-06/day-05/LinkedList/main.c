#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_t{
    int data;
    struct linked_list_t *next;
} linked_list_t;

void append(linked_list_t *head, int data);

int main()
{
    linked_list_t *head = (linked_list_t *) malloc(sizeof(linked_list_t));
    head->data = 0;
    head->next = NULL;
    return 0;
}

void append(linked_list_t *head, int data)
{
    linked_list_t *new_node = (linked_list_t *)malloc(sizeof(linked_list_t));
    new_node->data = data;
    new_node->next = NULL;
    linked_list_t *iterator = head;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    iterator->next = new_node;
}