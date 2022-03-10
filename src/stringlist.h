// stringlist.h
// api for adding strings to a list and deleting strings.

#ifndef _STRING_LIST_H_
#define _STRING_LIST_H_

typedef struct node {
    char * content;
    struct node * next;
} s_node;

/* pre : -
   post: return value points to the head and head points to the tail, 
         head and tail have content NULL, both act as dummy
*/
s_node * init();

/* pre : head points to the beginning of the list
   post: a copy of newContent (design decision) has been added at 
         the end of the list
*/
void add(s_node *head, char *newContent);

void print(s_node *head);

/* pre : head points to the beginning of the list
   post: all allocated memory has been deallocated and head==NULL
*/
void clear(s_node *head);

s_node * search(s_node *head, char *searchTerm);

void delete(s_node *head, char *searchTerm);

#endif