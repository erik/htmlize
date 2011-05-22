#include <stdio.h>
#include <stdlib.h>
#include "htmlize.h"

int main(int argc, char** argv) {
  HTMLDocument doc = html_doc_new(DOC_HTML5);
  html_doc_set_title(&doc, "This is a webpage");


  HTMLElement e = html_elem_new("p", 0);
  html_elem_add_attr(&e, "class=myclass");
  html_elem_add_attr(&e, "id=myid");
  html_elem_set_content(&e, "this is a paragraph");

  html_doc_add_body_elem(&doc, e);

  unsigned size;
  char* html = html_doc_create(&doc, &size);
  
  printf("%d\n", size);
  puts(html);

  free(html);

  html_elem_destroy(&e);
  html_doc_destroy(&doc);
  return 0;
}
