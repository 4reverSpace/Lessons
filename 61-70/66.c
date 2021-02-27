#include "malloc.h"
#include "stdio.h"

typedef struct list list;
struct list {
    list *next;
    int value;
};

list *create(int value) {
    list *new = (list *) malloc(sizeof(list));
    new->value = value;
    new->next = 0;
    return (new);
}

list *addElement(list *head, int value, int typeOfAdding) {
    if (typeOfAdding == 0) {
        list *new = create(value);
        new->next = head;
        return new;
    }
    if (typeOfAdding == -1) {
        list *next = head;
        while (next->next)
            next = next->next;
        list *new = create(value);
        new->next = 0;
        next->next = new;
        return head;
    }
    list *next = head;
    while (typeOfAdding) {
        next = next->next;
        typeOfAdding--;
    }
    list *new = create(value);
    new->next = next->next;
    next->next = new;
    return head;

}

void deleteElement(list *head, int value) {
    list *now = head;
    if (now->next == 0)
        return;
    while (now->next->value != value) {
        if (now->next == 0)
            return;
        now = now->next;
    }
    now->next = now->next->next;
    free(now->next);
    return;
}

void printList(list *head) {
    list *now = head;
    while (now->next) {
        printf("%d", now->value);
        now = now->next;
    }
    return;
}

void freeList(list *head) {
    while (head) {
        list *next = head->next;
        free(head);
        head = next;
    }
}

int isCycled(list *head) {
    list *now = head;
    while (now->next) {
        if (now->next == head)
            return 1;
        now = now->next;
    }
    return 0;
}

int lenght(list *head) {
    int i = 0;
    while (head) {
        head = head->next;
        i++;
    }
    return i;
}

list *sort(list *head) {
    int a = lenght(head);
    head = mergesort(head, a);
    return head;
}

list *mergesort(list *head, int len) {
    if (len == 1) {
        return head;
    }
    list *tail = head;
    list *left = mergesort(tail, len / 2);
    for (int i = 0; i < len / 2; i++) {
        tail = tail->next;
    }
    list *right = mergesort(tail, (len + 1) / 2);
    int left_num = 0, right_num = 0;
    list* buf = 0;
    while (left_num < len / 2 || right_num < (len + 1) / 2) {
        if (left_num == len / 2) {
            buf = addElement(buf, right->value, -1);
            right = right->next;
            right_num++;
        } else if (right_num == (len + 1) / 2) {
            buf = addElement(buf, left->value, -1);
            left = left->next;
            left_num++;
        } else if (left->value <= right->value) {
            buf = addElement(buf, left->value, -1);
            left = left->next;
            left_num++;
        } else {
            buf = addElement(buf, right->value, -1);
            right = right->next;
            right_num++;
        }
    }
    return buf;
}
