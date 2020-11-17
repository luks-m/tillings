#include "file.h"

void push(struct file *f, void *element)
{
  f->queue[f->size] = element;
  (f->size)++;
}

void *top(struct file *f)
{
  return f->queue[0];
}

void *pop(struct file *f)
{
  void *temp = top(f);
  for (int i = 1; i < f->size; i++)
    f->queue[i-1] = f->queue[i];
  f->queue[(f->size)-1] = NULL;
  (f->size)--;
  return temp;
}

void mix(struct file *f)
{
  for (int i = 0; i < f->size; i++) {
    int idx = rand() % (f->size -i) + i;
    void *temp = f->queue[idx];
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
