#ifndef _FILE_H_
#define _FILE_H_

#include <stdlib.h>
#define MAX_SIZE_FILE 200

struct file {
  const void *queue[MAX_SIZE_FILE]; //file
  int size; //number of useful elements in the file
};

/* 
 * queue[0] is the first element of the file, return with function pop and top
 * queue[n] is the last element of the file, where we push others elements
 */

//insert an element at the end of the file
void push(struct file *f, const void *element); 

//return a pointer to the element at the top of the file if the file is not empty
const void *top(struct file *f); 

//remove and return the element at the top of the file if the file is not empty
const void *pop(struct file *f); 

//mix the elements of the file with randomness
void mix(struct file*f); 

//distribute the elements of the file f to several players
void distribute(struct file *f, struct file tab_f[], int joueurs); 

#endif // _FILE_H_
