1) Team: Loe Malabanan, Deven Rood
   We have neither given nor received unauthorized assistance on this work.

2) Our VM is called "lmvm" under Loe's folder in vSphere. 
   The password for the account is 48694062.

3) 

4) Issues:
   We had an issue with Free_List() where we would get a segmentation fault after 
   trying to print a list that had been freed. This makes sense because the list
   pointer now points to an invalid location. We attempted to set the list pointer
   to NULL within the Free_List() function, but since we are only operating on a 
   copy of that pointer, the segmentation fault persisted. Eventually, we realized
   that the easiest solution was to set the list to NULL within main() where we 
   have access to the actual pointer.

5) Conversations:
