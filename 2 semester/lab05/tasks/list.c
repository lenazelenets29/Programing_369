#include "list.h"

DblLinkedList* createDblLinkedList(){ /// Ця функція створює екземпляр структури DblLinkedList. Тобто виділяє пам’ять на список, оголошує змінну його розміру, а також оголошує, що `head` та `tail` вказують на NULL, бо поки що наш список є пустим.
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
 
    return tmp;
}

void deleteDblLinkedList(DblLinkedList **list){ /// Дана функція реалізовує видалення двонапрямленого списку.
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


void pushFront(DblLinkedList *list, void *data){ /// Дана функція реалізовує вставку в початок двонапрямленого списку.
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

void* popFront(DblLinkedList *list){ /// Дана функція реалізовує видалення з початку двонапрямленого списку.
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

void pushBack(DblLinkedList *list, train *value){ /// Дана функція реалізовує вставку в кінець двонапрямленого списку.
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

void* popBack(DblLinkedList *list){ /// Дана функція реалізовує видалення з кінця двонапрямленого списку.
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

Node* getNth(DblLinkedList *list, size_t index) { /// Дана функція реалізовує отримання n-го елементу. У залежності від індекса можемо проходитися по списку або з початку в кінець, або з кінця на початок. Це дозволяє використовувати в половину менше проходів по списку.
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

void insert(DblLinkedList *list, size_t index, train *value){ /// Дана функція реалізовує вставку вузла в список.
    #ifdef DEBUG
		printf("Function insert -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
	#endif
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

void* deleteNth(DblLinkedList *list, size_t index){ /// Дана функція реалізовує видалення вузла із списку.
    #ifdef DEBUG
		printf("Function deleteNth -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
	#endif
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

void printDblLinkedList(DblLinkedList *list){ /// Дана функція виводить двонаправлений список потягів на екран. Виведення здійснюється шляхом друку поелементно.
    #ifdef DEBUG
		printf("Function printDbLinkedList -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
	#endif
    Node *tmp = list->head;
    while (tmp) {
        printTrain(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void fprintTrain(train *value, char *fname){ /// Дана функція реалізовує відкриття файлу в режимі читання та запису. Виведення в файл структур за допомогою функції `fprintf`.
    FILE *out_t;
    if((out_t = fopen(fname, "a")) == NULL) {
        printf("Cannot open file.\n");
        return;
    }
    fprintf(out_t, "%s %c %i %s %s %s\n", value->number, value->repairs, value->carts, value->move.start, value->move.finish, value->type);
    fclose(out_t);
}

void fprintDblLinkedList(DblLinkedList *list, char *fname){ /// Дана функція реалізовує відкриття файлу в режимі запису. І якщо список існує(тобто він не пустий), то проходиться по всьому списку і виводиться за допомогою функції `fprintTrain`.
    #ifdef DEBUG
		printf("Function fprintDbLinkedList -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
	#endif
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

DblLinkedList* fromArray(train *arr, size_t n, size_t size) { /// Дана функція створює список з масиву. Спочатку йде перевірка чи не є пустим масив, і потім з цього масиву утворюється список за допомогою функції `createDblLinkedList`.
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

DblLinkedList* FilterDblLinkedList(DblLinkedList *list, char criterion, char *filter){ /// Дана функція реалізовує пошук за певним вказаним нами критерієм.
    #ifdef DEBUG
		printf("Function FilterDbLinkedList-----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
	#endif
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

int sortChar(char * current, char * next, int poz, int len){ /// Дана функція реалізовує сортування.
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

void insertBeforeElement(DblLinkedList *list, Node* elm, void *value){ /// Дана функція реалізовує вставку до вказаного нами елемента.
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

void insertionSort(DblLinkedList **list, char criterion){ /// Дана функція реалізовує сортування вставками за певним вказаним критерієм.
    #ifdef DEBUG 
		printf("Function insertionSort -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
	#endif
    DblLinkedList *out = createDblLinkedList();
    Node *sorted = NULL;
    Node *unsorted = NULL;
     
    pushFront(out, popFront(*list));
 
    unsorted = (*list)->head;
    int len;
    if(criterion == 'n'){
        while (unsorted) {
            sorted = out->head;
            if((len = strlen(unsorted->value->number)) < strlen(sorted->value->number)){
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
            if((len = strlen(unsorted->value->move.start)) < strlen(sorted->value->move.start)){
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
            if((len = strlen(unsorted->value->move.finish)) < strlen(sorted->value->move.finish)){
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
            if((len = strlen(unsorted->value->type)) < strlen(sorted->value->type)){
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

long currentTimeMillis() {  /// Переведення часу в мілісекунди.  
    struct timeval time;
    mingw_gettimeofday(&time, NULL); //note: how c functions returns structures !
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}