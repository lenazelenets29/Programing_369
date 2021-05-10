#include "list.h"
#include "data.h"
#include "string.h"
#include "stdbool.h"

DblLinkedList* createDblLinkedList(){
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}

void deleteDblLinkedList(DblLinkedList **list){
    Node *tmp = (*list)->head;
    Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}


void pushFront(DblLinkedList *list, void *data){
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;
 
    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void* popFront(DblLinkedList *list){
    Node *prev;
    void *tmp;
    if (list->head == NULL) {
        exit(2);
    }
 
    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);
 
    list->size--;
    return tmp;
}

void pushBack(DblLinkedList *list, train *value){
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

void* popBack(DblLinkedList *list){
    Node *next;
    void *tmp;
    if (list->tail == NULL) {
        exit(4);
    }
 
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);
 
    list->size--;
    return tmp;
}

Node* getNth(DblLinkedList *list, size_t index) {
    Node *tmp = NULL;
    size_t i;
     
    if (index < list->size/2) {
        i = 0;
        tmp = list->head;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }
    } else {
        i = list->size - 1;
        tmp = list->tail;
        while (tmp && i > index) {
            tmp = tmp->prev;
            i--;
        }
    }
 
    return tmp;
}

bool test_insert(){
    bool result = true;
    int N_act = getStrNum("t_insert.out");
    train * data_act = (train *) malloc(N_act * sizeof(train));
    data_act = readStr("t_insert.out");
    DblLinkedList * act = fromArray(data_act, N_act, sizeof(train));
    int N_exp = getStrNum("t_insert.in");
    train * data_exp = (train *) malloc(N_exp * sizeof(train));
    data_exp = readStr("t_insert.in");
    DblLinkedList * exp = fromArray(data_exp, N_exp, sizeof(train));
    way w1 = {"Russia", "Ukraine"};
    train data = {"B1111", 'n', 45, w1, "heat"};
    insert(exp, 6, &data);

    Node *node_act = act->head;
    Node *node_exp = exp->head;

    while(node_act && node_exp){
        if(strcmp(node_act->value->number, node_exp->value->number) != 0 || node_act->value->repairs != node_exp->value->repairs || node_act->value->carts != node_exp->value->carts || strcmp(node_act->value->move.start, node_exp->value->move.start) != 0 || strcmp(node_act->value->move.finish, node_exp->value->move.finish) != 0 || strcmp(node_act->value->type, node_exp->value->type) != 0){
            result = false;
            break;
        }
        node_exp = node_exp->next;
        node_act = node_act->next;
    }
    if(result){
        printf("Test '%s' passed.\n ... ... ... \n", "test_insert");
    }else{
        printf("Function `%s` failed: Actual data: %s, expected: %s\n", "test_insert", node_act->value->number, node_exp->value->number);
    }
    free(data_act);
    free(data_exp);
    deleteDblLinkedList(&exp);
    deleteDblLinkedList(&act);
    return result;
}

void insert(DblLinkedList *list, size_t index, train *value){
    Node *elm = NULL;
    Node *ins = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;
 
    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }
 
    list->size++;
}

bool test_delete_nth(){
    bool result = true;
    int N_act = getStrNum("t_delete.out");
    train * data_act = (train *) malloc(N_act * sizeof(train));
    data_act = readStr("t_delete.out");
    DblLinkedList * act = fromArray(data_act, N_act, sizeof(train));
    int N_exp = getStrNum("t_delete.in");
    train * data_exp = (train *) malloc(N_exp * sizeof(train));
    data_exp = readStr("t_delete.in");
    DblLinkedList * exp = fromArray(data_exp, N_exp, sizeof(train));
    deleteNth(exp, 2);

    Node *node_act = act->head;
    Node *node_exp = exp->head;

    while(node_act && node_exp){
        if(strcmp(node_act->value->number, node_exp->value->number) != 0 || node_act->value->repairs != node_exp->value->repairs || node_act->value->carts != node_exp->value->carts || strcmp(node_act->value->move.start, node_exp->value->move.start) != 0 || strcmp(node_act->value->move.finish, node_exp->value->move.finish) != 0 || strcmp(node_act->value->type, node_exp->value->type) != 0){
            result = false;
            break;
        }
        node_exp = node_exp->next;
        node_act = node_act->next;
    }
    if(result){
        printf("Test '%s' passed.\n ... ... ... \n", "test_delete_nth");
    }else{
        printf("Function `%s` failed: Actual data: %s, expected: %s\n", "test_delete_nth", node_act->value->number, node_exp->value->number);
    }
    free(data_act);
    free(data_exp);
    deleteDblLinkedList(&exp);
    deleteDblLinkedList(&act);
    return result;
}

void* deleteNth(DblLinkedList *list, size_t index){
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;
 
    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }
 
    free(elm);
 
    list->size--;
 
    return tmp;
}

void printTrain(train *value){
    printf("%s %c %i %s %s %s\n", value->number, value->repairs, value->carts, value->move.start, value->move.finish, value->type);
}

void printDblLinkedList(DblLinkedList *list){
    Node *tmp = list->head;
    while (tmp) {
        printTrain(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void fprintTrain(train *value, char *fname){
    FILE *out_t;
    if((out_t = fopen(fname, "a")) == NULL) {
        printf("Cannot open file.\n");
        return;
    }
    fprintf(out_t, "%s %c %i %s %s %s\n", value->number, value->repairs, value->carts, value->move.start, value->move.finish, value->type);
    fclose(out_t);
}

void fprintDblLinkedList(DblLinkedList *list, char *fname){
    FILE *out_t;
    if((out_t = fopen(fname, "w")) == NULL) {
        printf("Cannot open file.\n");
        return;
    }
    fclose(out_t);
    Node *tmp = list->head;
    while (tmp) {
        fprintTrain(tmp->value, fname);
        tmp = tmp->next;
    }
}

DblLinkedList* fromArray(train *arr, size_t n, size_t size) {
    DblLinkedList *tmp = NULL;
    size_t i = 0;
    if (arr == NULL) {
        exit(7);
    }
 
    tmp = createDblLinkedList();
    while (i < n) {
        pushBack(tmp, (arr + i));
        i++;
    }
 
    return tmp;
}

bool test_filter_dblinked_list(){
    bool result = true;
    int N_act = getStrNum("t_filter.out");
    train * data_act = (train *) malloc(N_act * sizeof(train));
    data_act = readStr("t_filter.out");
    DblLinkedList * act = fromArray(data_act, N_act, sizeof(train));
    int N_exp = getStrNum("t_filter.in");
    train * data_exp = (train *) malloc(N_exp * sizeof(train));
    data_exp = readStr("t_filter.in");
    DblLinkedList * exp = fromArray(data_exp, N_exp, sizeof(train));
    exp = FilterDblLinkedList(exp, 't', "electro");

    Node *node_act = act->head;
    Node *node_exp = exp->head;

    while(node_act && node_exp){
        if(strcmp(node_act->value->number, node_exp->value->number) != 0 || node_act->value->repairs != node_exp->value->repairs || node_act->value->carts != node_exp->value->carts || strcmp(node_act->value->move.start, node_exp->value->move.start) != 0 || strcmp(node_act->value->move.finish, node_exp->value->move.finish) != 0 || strcmp(node_act->value->type, node_exp->value->type) != 0){
            result = false;
            break;
        }
        node_exp = node_exp->next;
        node_act = node_act->next;
    }
    if(result){
        printf("Test '%s' passed.\n ... ... ... \n", "test_filter_dblinked_list");
    }else{
        printf("Function `%s` failed: Actual data: %s, expected: %s\n", "test_filter_dblinked_list", node_act->value->number, node_exp->value->number);
    }
    free(data_act);
    free(data_exp);
    deleteDblLinkedList(&exp);
    deleteDblLinkedList(&act);
    return result;
}

DblLinkedList* FilterDblLinkedList(DblLinkedList *list, char criterion, char *filter){
    Node *tmp_node = list->head;
    DblLinkedList *temp = createDblLinkedList();
    if(criterion == 'n'){
        while(tmp_node){
            if(strcmp(tmp_node->value->number, filter) == 0){
                pushBack(temp, tmp_node->value);
            }
            tmp_node = tmp_node->next;
        }
    }
    if(criterion == 'r'){
        while(tmp_node){
            if(tmp_node->value->repairs == filter[0]){
                pushBack(temp, tmp_node->value);
            }
            tmp_node = tmp_node->next;
        }
    }
    if(criterion == 'c'){
        while(tmp_node){
            if(tmp_node->value->carts == atoi(filter)){
                pushBack(temp, tmp_node->value);
            }
            tmp_node = tmp_node->next;
        }
    }
    if(criterion == 's'){
       while(tmp_node){
            if(strcmp(tmp_node->value->move.start, filter) == 0){
                pushBack(temp, tmp_node->value);
            }
            tmp_node = tmp_node->next;
        }
    }
    if(criterion == 'f'){
        while(tmp_node){
            if(strcmp(tmp_node->value->move.finish, filter) == 0){
                pushBack(temp, tmp_node->value);
            }
            tmp_node = tmp_node->next;
        }
    }
    if(criterion == 't'){
        while(tmp_node){
            if(strcmp(tmp_node->value->type, filter) == 0){
                pushBack(temp, tmp_node->value);
            }
            tmp_node = tmp_node->next;
        }
    }

    return temp;
}

int sortChar(char * current, char * next, int poz, int len){
    int r = 0;
    if(current[poz] > next[poz]){
        return 1;
    }
    if(current[poz] < next[poz]){
        return 0;
    }else{
        poz++;
        if(poz != len){
            r = sortChar(current, next, poz, len);
        }
        return r;
    }
}

void insertBeforeElement(DblLinkedList *list, Node* elm, void *value){
    Node *ins = NULL;
    if (elm == NULL) {
        exit(6);
    }
     
    if (!elm->prev) {
        pushFront(list, value);
        return;
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm->prev;
    elm->prev->next = ins;
    ins->next = elm;
    elm->prev = ins;
 
    list->size++;
}

bool test_insertion_sort(){
    bool result = true;
    int N_act = getStrNum("t_sort.out");
    train * data_act = (train *) malloc(N_act * sizeof(train));
    data_act = readStr("t_sort.out");
    DblLinkedList * act = fromArray(data_act, N_act, sizeof(train));
    int N_exp = getStrNum("t_sort.in");
    train * data_exp = (train *) malloc(N_exp * sizeof(train));
    data_exp = readStr("t_sort.in");
    DblLinkedList * exp = fromArray(data_exp, N_exp, sizeof(train));
    insertionSort(&exp, 'n');

    Node *node_act = act->head;
    Node *node_exp = exp->head;

    while(node_act && node_exp){
        if(strcmp(node_act->value->number, node_exp->value->number) != 0 || node_act->value->repairs != node_exp->value->repairs || node_act->value->carts != node_exp->value->carts || strcmp(node_act->value->move.start, node_exp->value->move.start) != 0 || strcmp(node_act->value->move.finish, node_exp->value->move.finish) != 0 || strcmp(node_act->value->type, node_exp->value->type) != 0){
            result = false;
            break;
        }
        node_exp = node_exp->next;
        node_act = node_act->next;
    }
    if(result){
        printf("Test '%s' passed.\n ... ... ... \n", "test_insertion_sort");
    }else{
        printf("Function `%s` failed: Actual data: %s, expected: %s\n", "test_insertion_sort", node_act->value->number, node_exp->value->number);
    }
    free(data_act);
    free(data_exp);
    deleteDblLinkedList(&exp);
    deleteDblLinkedList(&act);
    return result;
}

void insertionSort(DblLinkedList **list, char criterion){
    DblLinkedList *out = createDblLinkedList();
    Node *sorted = NULL;
    Node *unsorted = NULL;
     
    pushFront(out, popFront(*list));
 
    unsorted = (*list)->head;
    int len;
    if(criterion == 'n'){
        while (unsorted) {
            sorted = out->head;
            if(len = strlen(unsorted->value->number) < strlen(sorted->value->number)){
                len = strlen(sorted->value->number);
            }      
            while (sorted && sortChar(unsorted->value->number, sorted->value->number, 0, len)) {
                sorted = sorted->next;
            }
            if (sorted) {
                insertBeforeElement(out, sorted, unsorted->value);
            } else {
                pushBack(out, unsorted->value);
            }
            unsorted = unsorted->next;
        }
    }
    if(criterion == 'r'){
        while (unsorted) {
            sorted = out->head;      
            while (sorted && (unsorted->value->repairs > sorted->value->repairs)) {
                sorted = sorted->next;
            }
            if (sorted) {
                insertBeforeElement(out, sorted, unsorted->value);
            } else {
                pushBack(out, unsorted->value);
            }
            unsorted = unsorted->next;
        }
    }
    if(criterion == 'c'){
        while (unsorted) {
            sorted = out->head;      
            while (sorted && (unsorted->value->carts > sorted->value->carts)) {
                sorted = sorted->next;
            }
            if (sorted) {
                insertBeforeElement(out, sorted, unsorted->value);
            } else {
                pushBack(out, unsorted->value);
            }
            unsorted = unsorted->next;
        }
    }
    if(criterion == 's'){
        while (unsorted) {
            sorted = out->head;
            if(len = strlen(unsorted->value->move.start) < strlen(sorted->value->move.start)){
                len = strlen(sorted->value->move.start);
            }      
            while (sorted && sortChar(unsorted->value->move.start, sorted->value->move.start, 0, len)) {
                sorted = sorted->next;
            }
            if (sorted) {
                insertBeforeElement(out, sorted, unsorted->value);
            } else {
                pushBack(out, unsorted->value);
            }
            unsorted = unsorted->next;
        }
    }
    if(criterion == 'f'){
        while (unsorted) {
            sorted = out->head;
            if(len = strlen(unsorted->value->move.finish) < strlen(sorted->value->move.finish)){
                len = strlen(sorted->value->move.finish);
            }      
            while (sorted && sortChar(unsorted->value->move.finish, sorted->value->move.finish, 0, len)) {
                sorted = sorted->next;
            }
            if (sorted) {
                insertBeforeElement(out, sorted, unsorted->value);
            } else {
                pushBack(out, unsorted->value);
            }
            unsorted = unsorted->next;
        }
    }
    if(criterion == 't'){
        while (unsorted) {
            sorted = out->head;
            if(len = strlen(unsorted->value->type) < strlen(sorted->value->type)){
                len = strlen(sorted->value->type);
            }      
            while (sorted && sortChar(unsorted->value->type, sorted->value->type, 0, len)) {
                sorted = sorted->next;
            }
            if (sorted) {
                insertBeforeElement(out, sorted, unsorted->value);
            } else {
                pushBack(out, unsorted->value);
            }
            unsorted = unsorted->next;
        }
    }
    
    free(*list);
    *list = out;
}