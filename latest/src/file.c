#include "file.h"

void push(struct file *f, const void *element)
{
  if (f->size < MAX_SIZE_FILE) {
    f->queue[f->size] = element;
    f->size++;
  }
}

const void *top(struct file *f)
{
  if (f->size == 0)
    return NULL;
  return f->queue[0];
}

const void *pop(struct file *f)
{
  if (f->size == 0)
    return NULL;
  else {
    const void *temp = top(f);
    for (int i = 1; i < f->size; i++)
      f->queue[i-1] = f->queue[i];
    f->queue[f->size-1] = NULL;
    f->size--;
    return temp;
  }
}

void mix(struct file *f)
{
  for (int i = 0; i < f->size; i++) {
    int idx = rand() % (f->size -i) + i;
    const void *temp = f->queue[idx];
    f->queue[idx] = f->queue[i];
    f->queue[i] = temp;
  }
}

void distribute(struct file *f, struct file tab_f[], int joueurs)
{
  for (int i = 0; i < f->size / joueurs ; i++)
    for (int j = 0; j < joueurs; j++)
      push(&(tab_f[j]), pop(f));
}
