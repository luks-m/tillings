#include <stdio.h>
#include <string.h>

#define COLOR_NUMBER 3

struct color{
  char *ANSI;
  char *name;
};

struct color red = {"\e[0;31m","rouge"};
struct color blue = {"\e[0;34m","bleu"};
struct color green = {"\e[0;32m","vert"};

struct color* colors[COLOR_NUMBER] = {&red, &blue, &green};

const char* color_name(struct color* t){
	for (int i = 0 ; i < COLOR_NUMBER ; ++i){
		if (colors[i]->name == t->name)
			return t->name;
	}
	return NULL;
}

const char* color_cstring(struct color* t) {
	for (int i = 0 ; i < COLOR_NUMBER ; ++i){
		if (colors[i]->ANSI == t->ANSI)
			return t->ANSI;
	}
	return NULL;
}

struct color* color_from_name(const char* name)
{
  for (int i = 0; i < COLOR_NUMBER; ++i) {
    if (strcmp(colors[i]->name,name) == 0)
      return colors[i];
  }
  return NULL;
}

