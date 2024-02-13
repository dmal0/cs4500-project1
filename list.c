#include <stdio.h>
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
    remove_from_list(testList);

    // Try printing the list - Segmentation fault
    printf("Printing the linked list...\n");
    print_list(testList);

    return 0;
}

/* Allocate space for a new list and set its head to NULL.
 * Returns the created list if successful, NULL otherwise. */
list* create_list()
{
    // Create the list
    list *llist = malloc(sizeof(node));
    
    // Set the head to NULL
    llist->head = NULL;

    // Verify that the head is NULL
    if (llist->head == NULL)
    {
        return llist;
    }
    else 
    {
        return NULL;
    }
}

/* Allocates a new node and copies the string from item to this node 
 * (use malloc, strlen, and strcpy; or try strdup). Adds this new node
 * to end of the list ll. Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item)
{
    // Add the first node to the list
    if (ll->head == NULL)
    {       
        node *newNode = malloc(sizeof(node)); // Allocate node space
        ll->head = newNode; // Set head
        
        newNode->item = strdup(item); // Copy the string
        newNode->next = NULL; // There is no next list item yet
        return 0;

        // Verify input copied
        if (newNode->item == item)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    // If not the first, go to end of list to add
    else
    {
        // Head
        node *hd = ll->head;

        // Go to end
        while (hd->next != NULL)
        {
            hd = hd->next;
        }

        // New node
        node *newNode = malloc(sizeof(node));
        hd->next = newNode;
        newNode->item = strdup(item);
        newNode->next = NULL;
        return 0;

        // Verify input copied
        if (newNode->item == item)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

/* Removes the head of the list ll, extracts the string stored in the head,
 * and returns a pointer to this string. Also frees the removed head node. */
char* remove_from_list(list* ll)
{
    if (ll->head == NULL)
        return NULL;
    
    else
    {
        // Save the old head node
        node *oldHead = ll->head;

        // Set the original head to the new head,
        // unlinking the old head
        ll->head = oldHead->next;

        // Save the string from the old head
        char* oldHeadItem = (char*)malloc(sizeof(oldHead->item));
        strcpy(oldHeadItem,oldHead->item);

        // Free the old head
        free(oldHead);

        // Return the old head's string
        return 0;
    }
}

/* Prints every string in each node of the list ll, with a new line
 * character at the end of each string */
void print_list(list *ll)
{
    if(ll->head == NULL)
    {
        printf("The list is empty.\n");
    }

    // Head pointer
    node *ptr = ll->head;

    while(ptr != NULL)
    {
        printf("%s\n", ptr->item);
        ptr = ptr->next;
    }
}