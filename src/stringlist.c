// stringlist.c, compiles and runs without error, but valgrind still
// shows errors
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stringlist.h"

s_node *init()
{
    s_node *head = (s_node *)malloc(sizeof(s_node));
    head->next = (s_node *)malloc(sizeof(s_node));
    head->content = NULL;
    head->next->next = NULL;
    head->next->content = NULL;
    return head;
}

void add(s_node *head, char *newContent)
{
    // find last but one node
    s_node *runner = head;
    while (runner->next->next != NULL)
    {
        runner = runner->next;
    }
    s_node *tail = runner->next;
    runner->next = (s_node *)malloc(sizeof(s_node));
    runner = runner->next;
    runner->next = tail;
    runner->content = (char *)malloc(sizeof(char) * (strlen(newContent) + 1));
    strcpy(runner->content, newContent);
}

void print(s_node *head)
{
    printf("content of list is:\n");
    s_node *runner;
    runner = head->next;
    int i = 1;
    while (runner->next != NULL)
    {
        printf("%d: %s\n", i, runner->content);
        i++;
        runner = runner->next;
    }
}

void clear(s_node *head)
{
    s_node *runner;
    runner = head->next;
    while (runner->next != NULL)
    {
        s_node *temp = runner;
        free(runner->content);
        free(runner);
        runner = temp->next;
    }
    free(head);
    free(runner);
}

s_node *search(s_node *head, char *searchTerm)
{
    s_node *runner;
    runner = head;
    while (runner->next->next != NULL)
    {
        if (strcmp(searchTerm, runner->next->content) == 0)
        {
            return runner;
        }
        runner = runner->next;
    }
    return runner;
}

void delete (s_node *head, char *searchTerm)
{
    s_node *runner;
    runner = head;
    while (runner->next->next != NULL)
    {
        if (strcmp(searchTerm, runner->next->content) == 0)
        {
            s_node *toDelete = runner->next;
            runner->next = runner->next->next;
            free(toDelete->content);
            free(toDelete);
            
        }
        runner = runner->next;
    }
}
