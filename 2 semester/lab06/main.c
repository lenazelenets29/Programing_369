#include "stdio.h"
#include "src/list.h"
#include "src/data.h"

DblLinkedList *run_command(DblLinkedList *list);

int main(){
    regex_t regex;
	int reti;
	reti = regcomp(&regex, "^[A-ZА-Я]((\\w|\\d|[А-Яа-я])+(\\s?[.,?:;!]?))+", REG_EXTENDED);
	if (reti) {
   		fprintf(stderr, "Could not compile regex\n");
    	exit(1);
	}

    int N = getStrNum("in.txt")/3+1;
    train * data = (train *) malloc(N * sizeof(train)); 
    data = readStr("in.txt", N, regex, reti);
    DblLinkedList *list = fromArray(data, N, sizeof(train)); 

    reti = regcomp(&regex, ".+\\s.+", REG_EXTENDED);
	if (reti) {
   		fprintf(stderr, "Could not compile regex\n");
    	exit(1);
	}
    printDblLinkedList(list, regex, reti);

    free(data);
    deleteDblLinkedList(&list);
    return 0;
}
