#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

struct list_node *
append(struct list_node *list, int x){
	if (is_empty(list)){
		list = (struct list_node *) malloc(sizeof(struct list_node));
		list->datum = x;
		list->next = NULL
	} else {
		list->next = append(list->next, x);
	}

	return list;
}

struct list_node *
prepend(struct list_node *list, int x){
	struct list_node *nlist;

	nlist = (struct list_node*) malloc(sizeof(struct list_node));
	nlist-> datum = x;
	nlist->next = list;

	return nlist;
}

int
is_empty(struct list_node *list, int x){
	return list == NULL;
}

struct list_node *
delete(struct list_node *list, int x){
	if (is_empty(list)){
		return list;
	}

	if (list->datum == x){
		struct list_node *nlist = list->next;
		list->next = NULL;
		free(list);
		return nlist;
	} else {
		list->next = delete(list->next, x);
		return list;
	}
}

struct list_node *
delete_all(struct list_node *list, int x){
	if (is_empty(list)){
		return list;
	}

	if (list->datum == x){
		struct list_node *nlist = list->next;
		list->next = NULL;
		free(list);
		nlist = delete_all(nlist, x);
		return nlist;
	} else {
		list->next = delete_all(list->next, x);
		return list;
	}
}

void
fprint_list(FILE *output, struct list_node *list, char *delim){
	if (is_empty(list)){
		fprintf(output, "NULL");
	} else {
		fprintf(output, "%d%s", list->datum, delim);
		fprint_list(output, list->next, delim);
	}
}

