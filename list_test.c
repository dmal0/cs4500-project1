l#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main()
{
    /* Create list and strings;
     * Strings must be one character longer than
     * the actual text to include \0 at the end. */
    list *testList = create_list();
    char str[5] = "test";
    char str2[7] = "test 2";
    char str3[7] = "test 3";

    // Add the first string to the linked list
    add_to_list(testList, str);
    
    // Check if the head is still NULL
    if (testList->head != NULL)
    {
        printf("Head is NOT null\n");
    }
    
    // Peek at head item
    node *listHead = testList->head;
    char *headItem = listHead->item;
    printf("%s\n", headItem);

    // Add another node and peek
    add_to_list(testList, str2);
    node *nextFromHead = listHead->next;
    char *nextItem = nextFromHead->item;
    printf("%s\n", nextItem);

    // Add a third node
    add_to_list(testList, str3);

    // Try printing the list
    printf("Printing the linked list...\n");
    print_list(testList);

    // Remove head
    char *oldHead = remove_from_list(testList);
    printf("Old head item: %s\n",oldHead);

    // Try printing the list - Segmentation fault
    printf("Printing the linked list...\n");
    print_list(testList);

    free_list(testList);
    print_list(testList);

    return 0;
}
