#include <stdio.h>
#include "htmlize.h"
#include "str.h"

int main(int argc, char** argv) {
  html_auto_free = 1;
  string_t* html = htmlize(DOCTYPE_XHTML,
                           HEAD(
                                html_tag("title",
                                         ATTRIBUTES(NULL),
                                         CONTENT("TITLE"))),
                           BODY(
                                html_tag("p",
                                         ATTRIBUTES(NULL),
                                         CONTENT("PARAGRAPH")),
                                html_tag("p",
                                         ATTRIBUTES(NULL),
                                         CONTENT("PARAGRAPH2"))));


  printf("%s\n", html->str);

  string_del(html);
  return 0;
}
