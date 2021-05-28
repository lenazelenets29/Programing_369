#include "stdio.h"
#include "time.h"
#include "test.h"
#include "list.h"

DblLinkedList *run_command(DblLinkedList *list);

int main(){/// this is main
    #ifdef DEBUG
		printf("Debug enabled\n");
        const time_t timer = time(NULL);
        printf("%s", ctime(&timer));
        long begin = currentTimeMillis();
	#endif
    int N = getStrNum("in.txt");
    train * data = (train *) malloc(N * sizeof(train)); 
    data = readStr("in.txt");
    DblLinkedList *list = fromArray(data, N, sizeof(train)); 
    list = run_command(list);
    free(data);
    deleteDblLinkedList(&list);
    #ifdef DEBUG
		long end = currentTimeMillis();
        printf("Spent time: %d sec\n", (end - begin) / 1000);
	#endif
    return 0;
}

DblLinkedList *run_command(DblLinkedList *list){
    char type_com[15];
    printf("Set command:> ");
    scanf("%s", type_com);
    if(type_com[0] == 'c'){
        return list;
    }
    if(type_com[0] == 'p'){
        printDblLinkedList(list);
    }
    if(type_com[0] == 'r'){
        deleteDblLinkedList(&list);
        char fname[15];
        printf("Enter filename:> ");
        scanf("%s", fname);
        int N = getStrNum(fname);
        train * data = (train *) malloc(N * sizeof(train)); 
        data = readStr(fname);
        list = fromArray(data, N, sizeof(train));
    }
    if(type_com[0] == 'w'){
        char fname[15];
        printf("Enter filename:> ");
        scanf("%s", fname);
        fprintDblLinkedList(list, fname);
    }
    if(type_com[0] == 'n'){
        train temp;
        int index;
        printf("Enter number:> ");
        scanf("%s", temp.number);
        printf("Enter repairs:> ");
        scanf("\n%c", &temp.repairs);
        printf("Enter carts:> ");
        scanf("%i", &temp.carts);
        printf("Enter start:> ");
        scanf("%s", temp.move.start);
        printf("Enter finish:> ");
        scanf("%s",temp.move.finish);
        printf("Enter type:> ");
        scanf("%s", temp.type);
        printf("Enter index:> ");
        scanf("%i", &index);
        insert(list, index, &temp);
    }
    if(type_com[0] == 'd'){
        int index;
        printf("Enter index:> ");
        scanf("%i", &index);
        deleteNth(list, index);
    }
    if(type_com[0] == 'f'){
        char criterion, filter[15];
        printf("Enter criterion:> ");
        scanf("\n%c", &criterion);
        printf("Enter filter:> ");
        scanf("%s", filter);
        DblLinkedList * temp = FilterDblLinkedList(list, criterion, filter);
        printDblLinkedList(temp);
        deleteDblLinkedList(&temp);
    }
    if(type_com[0] == 's'){
        char criterion, filter;
        printf("Enter criterion:> ");
        scanf("\n%c", &criterion);
        insertionSort(&list, criterion);
        printDblLinkedList(list);
    }
    if(type_com[0] == 't'){
        #ifdef DEBUG
		    printf("Testing\n");
            const time_t timer = time(NULL);
            printf("%s\n", ctime(&timer));
            long begin = currentTimeMillis();
	    #endif
        bool result = true;
        result &= test_filter_dblinked_list();
        result &= test_insert();
        result &= test_insertion_sort();
        result &= test_delete_nth();
        if(result){
            printf("All test passed.\n");
        }
        #ifdef DEBUG
		    long end = currentTimeMillis();
            printf("Spent time for testing: %d msec\n", (end - begin));
	    #endif
    }
    run_command(list);
}