#include "test.h"
#include "list.h"
#include "data.h"

bool test_insert(){ /// За допомогою функції `getStrNum` отримуємо номер поїзду, який був вставлений, за допомогою функції `readStr` зчитуємо його та за допомогою функції `fromArray` переводимо з масиву в список. В дані записуємо потяг, який ми очікуємо отримати в результаті. Порівнюємо його з результатом виконання функції `insert`.
    #ifdef DEBUG
		printf("Function test_insert -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
        long begin = currentTimeMillis();
	#endif
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
    #ifdef DEBUG
		long end = currentTimeMillis();
        printf("Spent time: %d msec\n", (end - begin));
	#endif
    return result;
}


bool test_delete_nth(){ /// За допомогою функції `getStrNum` отримуємо номер поїзду, який повинен видалитися, за допомогою функції `readStr` зчитуємо його та за допомогою функції `fromArray` переводимо з масиву в список. В дані записуємо потяг, який ми очікуємо, що видалимо в результаті. Порівнюємо його з результатом виконання функції  `deleteNth `.
    #ifdef DEBUG
		printf("Function test_delete_nth -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
        long begin = currentTimeMillis();
	#endif
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
    #ifdef DEBUG
		long end = currentTimeMillis();
        printf("Spent time: %d msec\n", (end - begin));
	#endif
    return result;
}


bool test_filter_dblinked_list(){ /// За допомогою функції `getStrNum` отримуємо номер поїзду, значення якого будемо шукати, за допомогою функції `readStr` зчитуємо його та за допомогою функції `fromArray` переводимо з масиву в список. Далі записуємо дані, які ми очікуємо отримати в результаті пошуку. Порівнюємо його з результатом виконання функції  `FilterDblLinkedList`.
    #ifdef DEBUG
		printf("Function test_filter_dblinked_list -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
        long begin = currentTimeMillis();
	#endif
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
    #ifdef DEBUG
		long end = currentTimeMillis();
        printf("Spent time: %d msec\n", (end - begin));
	#endif
    return result;
}


bool test_insertion_sort(){ /// За допомогою функції `getStrNum` отримуємо номери потягів з файлу `t_sort.out`, значення якого відсортовані, за допомогою функції `readStr` зчитуємо та за допомогою функції `fromArray` переводимо з масиву в список. Далі таким же чином зчитуємо дані з файлу `t_sort.in`, які ми очікуємо отримати в результаті сортування. Порівнюємо ці дані з результатом виконання функції  `insertionSort `.
    #ifdef DEBUG
		printf("Function test_insertion_sort -----\n");
        const time_t timer = time(NULL);
        printf("%s\n", ctime(&timer));
        long begin = currentTimeMillis();
	#endif
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
    #ifdef DEBUG
		long end = currentTimeMillis();
        printf("Spent time: %d msec\n", (end - begin));
	#endif
    return result;
}