#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* Allocate space for a new list and set its head to NULL.
 * Returns the created list if successful, NULL otherwise. */
list* create_list()
{
    // Create the list
    list *llist = malloc(sizeof(list));
    
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
        return oldHeadItem;
    }
}

/* Prints every string in each node of the list ll, with a new line
 * character at the end of each string */
void print_list(list *ll)
{
    if(ll == NULL)
    {
        printf("The list is NULL.\n");
    }
    else
    {
        if(ll->head == NULL)
        {
            printf("The list is empty.\n");
        }
    
        // Head pointer
        node *ptr = ll->head;
    
        // Print and traverse
        while(ptr != NULL)
        {
            printf("%s\n", ptr->item);
            ptr = ptr->next;
        }
    }
}

/* Flushes (clears) the entire list and re-initializes the list. The passed 
 * pointer ll should still point to a valid, empty list when this function
 * returns. Any memory allocated to store nodes in the list should be freed. */
void flush_list(list* ll)
{
    free_list(ll);
    ll = create_list();
    
}

/* De-allocates all data for the list. Ensure all memory allocated for list
 * ll is freed, including any allocated strings and list ll itself. */
void free_list(list *ll)
{
    node* tmp;
    
    // Traverse, free, and set to NULL
    while (ll->head != NULL)
    {
        tmp = ll->head;
        ll->head = ll->head->next;
        free(tmp);
        tmp=NULL;
    }
    
    free(ll);
    ll=NULL;
}
