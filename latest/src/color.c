#include <stdio.h>
#include <string.h>

enum color_enum {ROUGE, BLEU, VERT, MAX_COLOR};

const char *ANSI[] = {"\e[0;31m", "\e[0;34m", "\e[0;32m"};

const char *name_color[] = {"rouge", "bleu", "vert"}; 

struct color{
	enum color_enum c;
};

const char* color_name(struct color* t){
	return name_color[t->c];
}

const char* color_cstring(struct color* t) {
	return ANSI[t->c];
}

struct color* color_from_name(const char* name){
	
	for (int i = 0 ; i < MAX_COLOR ; ++i){
		if (strcmp(name_color[i], name)){
			struct color result = {i};
		}
		i++;
	}
	return NULL;
};enum color { RED, BLUE, GREEN };
