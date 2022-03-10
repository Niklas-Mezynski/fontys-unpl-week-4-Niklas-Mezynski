#include <stdio.h>
#include <string.h>
#include "stringlist.h"

int main(int argc, char* argv[]) {
    s_node *list = init();
    printf("size of snode: %lu\n", sizeof(s_node));
    add(list, "Hello");
    add(list, " ");
    add(list, "world");
    print(list);

    char searchTerm[10];
    strcpy(searchTerm, "Hello");
    s_node *result;
    result = search(list, searchTerm);
    printf("Search result 1: [%s]\n", result->next->content);

    strcpy(searchTerm, "HUUHN");
    result = search(list, searchTerm);
    printf("Search result 2: [%s]\n", result->content);

    strcpy(searchTerm, "Hello");
    delete(list, searchTerm);
    print(list);

    clear(list);
    printf("End\n");
    return 0;
}
