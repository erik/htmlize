#include <stdio.h>
#include "htmlize.h"
#include "str.h"

int main(int argc, char** argv) {  
  string_t* tag = html_tag("p",
                           ATTRIBUTES( 
                                      ID("myid, myotherid"),
                                      CLASS("myclass, myotherclass")),
                           CONTENT(
                                   "wat is this",
                                   HTML_BREAK,
                                   "I don't know!"));

  printf("%s\n", tag->str);

  string_del(tag);
  return 0;
}
