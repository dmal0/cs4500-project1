NAME OF PROJECT:
================
Project 1 Linked List

MEMBERS:
========
Loe Malabanan, Deven Rood

STATEMENT:
==========
We have neither given nor received unauthorized assistance on this work.

VIRTUAL MACHINE (VM) INFORMATION:
=================================
NAME OF VIRTUAL MACHINE (VM): lmvm
USERNAME: The virtual machine does not ask for a username when we log in.
PASSWORD: 48694062

The project files can be found on the desktop, in the folder "Project 1," 
in the subfolder "Project 1 (with Makefile)."

Files:
    list.h      - Function prototypes from the instructions
    list.c      - Implementation for the functions in list.h
    list_test.c - Code for testing functionality
    list        - Executable file
    makefile    - The makefile for the program
    README.txt  - This file

All other files were created when the command "make list" was run.

ROOT PASSWORD:
==============
48694062

PROBLEM DESCRIPTION AND REMEDIATION:
====================================

    PART 0: SET UP
    ==============
    No significant problems were encountered during this part.

    PART 1: LINKED LIST
    ===================
        We had an issue with free_list() where we would get a segmentation fault 
    after trying to print a list that had been freed. This makes sense because the 
    list pointer now points to an invalid location. We attempted to set the list 
    pointer to NULL within the Free_List() function, but since we are only operating 
    on a copy of that pointer, the segmentation fault persisted. Eventually, we 
    realized that the easiest solution was to set the list to NULL within main() where 
    we have access to the actual pointer.

    I reached out to Riley Daughton on Discord asking for advice on how to deal with
    the segmentation fault. He informed me that he had run into the same issue and
    that setting the list to NULL in main() solved the problem. We discussed why
    setting the list to NULL within Free_List() wouldn't work and the ways that
    Free_List() and Flush_List() were distinct from each other.

    PART 2: WRITING A MAKE FILE
    ===========================
    No significant problems were encountered during this part.
