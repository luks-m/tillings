#include <stdlib.h>

#define MAX_SIZE_FILE 2000

struct file {
  void *queue[MAX_SIZE_FILE]; //file
  int size; //number of useful elements in the file
};

/* 
 * queue[0] is the first element of the file, return with function pop and top
 * queue[n] is the last element of the file, where we push others elements
 */

void push(struct file *f, void *element);

void *top(struct file *f);

void *pop(struct file *f);

void mix(struct file*f);

void distribute(struct file *f, struct file tab_f[], int joueurs);
