#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
};

struct node *stack_top;

void pop();

bool push(int d);

bool is_empty();

void display_top();


int main() {
    int ar, sel;
    stack_top = NULL;
    while (1) {
        printf("epiloges menu\n");
        printf("------------\n");
        printf("0. exit\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. display_top\n");


        printf("enter choice : ");
        scanf("%d", &sel);

        switch (sel) {
            case 0:
                exit(0);
            case 1:
                printf("dwse moy arithmo : ");
                scanf("%d", &ar);
                if (push(ar) == false) {
                    puts("not available memory\n");
                }
                break;
            case 2:
                pop();
                break;
            case 3:
                display_top();
                break;
            default:
                puts("wrong key\n");
        }
    }
    return 0;
}


bool push(int d) {
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        return false;
    }
    new->data = d;
    new->next = stack_top;
    stack_top = new;
    return true;
}

void pop() {
    struct node *temp;
    int d;
    if (is_empty()) {
        printf("empty list\n");
        return;
    }
    printf("number %d popped out of stack\n", stack_top->data);
    temp = stack_top->next;
    free(stack_top);
    stack_top = temp;
}

bool is_empty() {
    return (stack_top == NULL);
}

void display_top() {
    if (is_empty()) {
        printf("empty stack");
    } else {
        printf("stack_top:%d\n", stack_top->data);
    }
}
