#include <stdio.h>
#include <string.h>

#define COLOR_NUMBER 3

struct color{
  char *ANSI;
  char *name;
};

struct color red = {"\e[0;31mrouge\033[0m","rouge"};
struct color blue = {"\e[0;34mbleu\033[0m","bleu"};
struct color green = {"\e[0;32mvert\033[0m","vert"};

struct color* colors[COLOR_NUMBER] = {&red, &blue, &green};

const char* color_name(struct color* t)
{
	if (t == NULL)
		return NULL;
	return t->name;
	
}

const char* color_cstring(struct color* t)
{
	if (t == NULL)
		return NULL;
	return t->ANSI;
}

struct color* color_from_name(const char* name)
{
  for (int i = 0; i < COLOR_NUMBER; ++i) {
    if (strcmp(colors[i]->name,name) == 0)
      return colors[i];
  }
  return NULL;
}

