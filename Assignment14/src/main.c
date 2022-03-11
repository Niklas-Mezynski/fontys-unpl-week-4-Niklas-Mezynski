#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #include <check.h>
#include "ArrayDataStore.h"

int main()
{
    printf("Start of program\n");
    init(6);

    char string[10];
    strcpy(string, "Huuuhn");
    insert(string);
    strcpy(string, "Test");
    insert(string);
    print();

    strcpy(string, "Test2");
    insert(string);
    strcpy(string, "Test2");
    insert(string);
    strcpy(string, "Test3");
    insert(string);
    print();

    strcpy(string, "Test2");
    deleteStr(string);
    print();

    destroy();
    print();

}

// START_TEST (test_init)
// {
  
// }
// END_TEST