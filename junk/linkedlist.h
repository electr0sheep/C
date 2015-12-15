#include <stdio.h>

#ifndef michaellinkedlist
#define michaellinkedlist

struct list_node{
  int datum;
  struct list_node *next;
};

struct list_node *
append(struct list_node *, int);

struct list_node *
prepend(struct list_node *, int);

int
is_empty(struct list_node *);

struct list_node *
delete(struct list_node *, int);

struct list_node *
delete_all(struct list_node *, int);

void
fprint_list(FILE *, struct list_node, char *delim);

#endif