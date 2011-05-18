#include <stdio.h>
#include "htmlize.h"
#include "str.h"

int main(int argc, char** argv) {
  html_auto_free = 1;
  string_t* html = 
    htmlize(DOCTYPE_XHTML,
            HEAD(
                 html_tag("meta",
                          ATTRIBUTES("http-equiv=\"Content-type\"",
                                     "content=\"text/html"              \
                                     ";charset=UTF-8\""),
                          CONTENT(NULL),
                          1),
                 
                 html_tag("meta",
                          ATTRIBUTES("name=\"keywords\"",
                                     "content=\"notspam\""),
                          CONTENT(NULL),
                          1),
                 html_tag("title",
                          ATTRIBUTES(NULL),
                          CONTENT("TITLE"),
                          0)),
            BODY(
                 html_tag("p",
                          ATTRIBUTES(NULL),
                          CONTENT("PARAGRAPH"),
                          0)));
  
  printf("%s\n", html->str);

  string_del(html);
  return 0;
}
