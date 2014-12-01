/*
 * libParseURL
 * test.c
 * 29/11/2014
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include "libParseURL.h"

int main() 
{
    char *p ="sdfsaaaa<img src = 'ratimbum.png' >  aaaaaa\n  sdfsdfsd<img src='senhor_madruga .png'>fsdfsdfsdf <a href='/page/site.jsp'> sdfsdfsdfsdfi    <ahref=\"blah.jsp\"> \n  <form action='majin_boo.php'>  sdf<a> <a href='boo.php'>\n sdhfh sdfhshdfhsf";
    int sz;
    int result=0;

    puts("Test to Parse");
    puts(p);
    puts("--------------- extract...");
	

    p=init_response_parse(p);

    char *last = p;
    puts(p);

    while(!result )
  	  switch (parse_urls(&p, &last)) 
  	  {
// you can use SRC,ACTION too...
 	       case HREF:
	            sz = p - last - 1;
      		    printf("url with href is : '%.*s'\n", sz, last);
       		    break;

 	       case ACTION:
	            sz = p - last - 1;
      		    printf("url with action is : '%.*s'\n", sz, last);
       		    break;

 	       case SRC:
	            sz = p - last - 1;
      		    printf("url with src is : '%.*s'\n", sz, last);
       		    break;

	       case END:
		    printf("no url\n");
		    result=1;	
                    break;
	  }

    return 0;
}
