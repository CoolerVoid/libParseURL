#include <stdio.h>
#include <stdlib.h>

#ifndef __LIBPARSEURL_H__
#define __LIBPARSEURL_H__

enum {
  ACTION,SRC,HREF, END
};

int char_type_counter(char *string,char type);
char *init_response_parse(char* input);  
// My DFA URL Parser
int parse_urls(char** p, char** lex);
#endif
