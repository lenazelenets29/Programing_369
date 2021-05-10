/* File file.h */
#ifndef LIST_H
#define LIST_H

#include "stdio.h"
#include "data.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "time.h"

typedef struct _Node{
    train *value;
    struct _Node *next;
    struct _Node *prev; 
} Node;

typedef struct _DblLinkedList{
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;


DblLinkedList* createDblLinkedList();
void deleteDblLinkedList(DblLinkedList **list);
void pushFront(DblLinkedList *list, void *data);
void* popFront(DblLinkedList *list);
void pushBack(DblLinkedList *list, train *value);
void* popBack(DblLinkedList *list);
Node* getNth(DblLinkedList *list, size_t index);
void insert(DblLinkedList *list, size_t index, train *value);
void* deleteNth(DblLinkedList *list, size_t index);
void printDblLinkedList(DblLinkedList *list);
void printTrain(train *value);
void fprintDblLinkedList(DblLinkedList *list, char *fname);
DblLinkedList* fromArray(train *arr, size_t n, size_t size);
DblLinkedList* FilterDblLinkedList(DblLinkedList *list, char criterion, char *filter);
void insertionSort(DblLinkedList **list, char criterion);
int sortChar(char * current, char * next, int poz, int len);
void insertBeforeElement(DblLinkedList *list, Node* elm, void *value);
long currentTimeMillis();

#endif /* LIST_H */