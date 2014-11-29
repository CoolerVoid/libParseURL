#include <stdio.h>
#include <stdlib.h>

#ifndef __LIBPARSEURL_H__
#define __LIBPARSEURL_H__

enum {
  ACTION,SRC,HREF, END
};


// My DFA URL Parser
int parse_urls(char** p, char** lex);
#endif
