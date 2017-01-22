/*
 *
 * LibParseURL just another C URL extractor library
 * author: Antonio "Cooler_"
 * read LICENSE.txt please...
 * contact: coolerlair@gmail.com
 * date:29/11/2014
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include "libParseURL.h"

/*
enum {
  ACTION,SRC,HREF, END
};
*/

int char_type_counter(char *string,char type)
{
	int counter=0;
 
	while(*string != '\0')
	{
		if(*string==type) 
			counter++;
		string++;
	}
  
	return counter;
}

// to remove blank
char *init_response_parse(char* input)                                                  
{
	int i=0,j=0,len=strlen(input),buf=len-char_type_counter(input,' ');
	char *output=NULL;
	output = malloc(buf*sizeof(char)+1);

	while (i!=len)                       
	{
		if (input[i]!=' ')                                                  
			output[j]=input[i];                                            
		else
			j--;   
		i++;
		j++;                                                      
	}

	output[j] ='\0';

	return output;                                                     
}

// My DFA URL Parser
int parse_urls(char** p, char** lex)
{
    char* marker;

    for (;;) {
    *lex = *p;
    
	{
		char yych;

		yych = (char)**p;
		switch (yych) {
		case 0x00:	goto yy6;
		case 'a':	goto yy2;
		case 'h':	goto yy5;
		case 's':	goto yy4;
		default:	goto yy8;
		}
yy2:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'c':	goto yy25;
		default:	goto yy3;
		}
yy3:
		{ continue; }
yy4:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'r':	goto yy18;
		default:	goto yy3;
		}
yy5:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'r':	goto yy9;
		default:	goto yy3;
		}
yy6:
		++*p;
		{ return END; }
yy8:
		yych = (char)*++*p;
		goto yy3;
yy9:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy11;
		default:	goto yy10;
		}
yy10:
		*p = marker;
		goto yy3;
yy11:
		yych = (char)*++*p;
		switch (yych) {
		case 'f':	goto yy12;
		default:	goto yy10;
		}
yy12:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy13;
		default:	goto yy10;
		}
yy13:
		yych = (char)*++*p;
		switch (yych) {
		case '>':	goto yy10;
		default:	goto yy14;
		}
yy14:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '>':	goto yy16;
		default:	goto yy14;
		}
yy16:
		++*p;
		{ return HREF; }
yy18:
		yych = (char)*++*p;
		switch (yych) {
		case 'c':	goto yy19;
		default:	goto yy10;
		}
yy19:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy20;
		default:	goto yy10;
		}
yy20:
		yych = (char)*++*p;
		switch (yych) {
		case '>':	goto yy10;
		default:	goto yy21;
		}
yy21:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '>':	goto yy23;
		default:	goto yy21;
		}
yy23:
		++*p;
		{ return SRC; }
yy25:
		yych = (char)*++*p;
		switch (yych) {
		case 't':	goto yy26;
		default:	goto yy10;
		}
yy26:
		yych = (char)*++*p;
		switch (yych) {
		case 'i':	goto yy27;
		default:	goto yy10;
		}
yy27:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy28;
		default:	goto yy10;
		}
yy28:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy29;
		default:	goto yy10;
		}
yy29:
		yych = (char)*++*p;
		switch (yych) {
		case '=':	goto yy30;
		default:	goto yy10;
		}
yy30:
		yych = (char)*++*p;
		switch (yych) {
		case '>':	goto yy10;
		default:	goto yy31;
		}
yy31:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '>':	goto yy33;
		default:	goto yy31;
		}
yy33:
		++*p;
		{ return ACTION; }
	}
    }
}
