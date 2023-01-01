#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
}Node;

void print_list(Node const* head);

Node* allocate_node(int value, Node* next);

Node* push(int value, Node* head);

void free_list(Node* head);

Node* mirror(Node* head);

int main()
{
    Node* head = NULL;

    int number_imput = 0;

    printf("Original Linked list:\n");
    scanf("%d", &number_imput);
    while (number_imput >= 0)
    {
        head = push(number_imput, head);
        scanf("%d", &number_imput);
    }

    head = mirror(head);

    printf("Mirror Linked list:\n");
    print_list(head);
    free_list(head);


    return 0;
}


void print_list(Node const* head)
{
    for (; head; head = head->next)
        printf("%d ", head->value);
    printf("\n");
}

Node* allocate_node(int value, Node* next)
{
    Node* n = malloc(sizeof * n);
    if (!n) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->value = value;
    n->next = next;
    return n;
}

Node* push(int value, Node* head)
{
    return allocate_node(value, head);
}

void free_list(Node* head)
{
    while (head) {
        Node* old = head;
        head = head->next;
        free(old);
    }
}

Node* mirror(Node* head)
{   
    Node* ordered_head= head;
    Node* reverse_head = NULL;
    Node* tmp_node = NULL;

    while (head != NULL)
    {   

        reverse_head = push(head -> value , tmp_node);
        tmp_node = reverse_head;
        head = head -> next;

    }
    
    Node* reverse_list = reverse_head;
    while(1){
        if (reverse_head -> next == NULL){
            reverse_head -> next = ordered_head;
            break;
        }
        reverse_head = reverse_head -> next;
    }

    return reverse_list;

}
