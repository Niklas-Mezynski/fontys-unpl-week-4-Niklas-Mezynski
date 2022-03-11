#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ArrayDataStore.h"

char **stringArray;
int arraySize = 0;

void init(int n)
{
    if (n < 1)
    {
        printf("Size needs to be > 0\n");
        return;
    }
    if (stringArray != NULL)
    {
        printf("Storage is already initialized\n");
        return;
    }
    stringArray = (char **)malloc(n * sizeof(char *));
    arraySize = n;
    for (int i = 0; i < arraySize; i++)
    {
        stringArray[i] = NULL;
    }
}

void destroy()
{
    if (stringArray == NULL)
    {
        printf("Storage must be initialized first\n");
        return;
    }
    for (int i = 0; i < arraySize; i++)
    {
        free(stringArray[i]);
    }
    free(stringArray);
    arraySize = 0;
}

bool insert(char *str)
{
    if (stringArray == NULL)
    {
        printf("Storage must be initialized first\n");
        return false;
    }
    if (str == NULL)
    {
        printf("Parameter is not allowed to be null\n");
        return false;
    }

    for (int i = 0; i < arraySize; i++)
    {

        if (stringArray[i] == NULL)
        {
            stringArray[i] = (char *)malloc(strlen(str) + 1);
            strcpy(stringArray[i], str);
            return true;
        }
    }
    return false;
}

void deleteStr(char *str)
{
    if (stringArray == NULL)
    {
        printf("Storage must be initialized first\n");
        return;
    }
    if (str == NULL)
    {
        printf("Parameter is not allowed to be null\n");
        return;
    }
    for (int i = 0; i < arraySize; i++)
    {
        if (stringArray[i] != NULL)
        {
            if (strcmp(stringArray[i], str) == 0)
            {
                free(stringArray[i]);
                stringArray[i] = NULL;
            }
        }
    }
}

void print()
{
    if (stringArray == NULL)
    {
        printf("Storage must be initialized first\n");
        return;
    }
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d: %s\n", i + 1, stringArray[i]);
    }
    printf("\n");
}