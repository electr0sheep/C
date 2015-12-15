#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(int argc, const char * argv[]){
	int i;
	struct list_node *list;

	list = NULL;
	for (i = 0; i < 10; i++){
		list = append(list, i);
		fprint_list(stdout, list, "->");
		printf("\n");
	}

	return 0;
}

