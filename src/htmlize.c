#include "htmlize.h"
#include "str.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

char* htmlize(char* doctype, string_t* head[], string_t* body[]) {
  string_t* string = string_new2(doctype);

  return string->str;
}

string_t* html_tag(char* tag, char* attrs[], char* content[]) { 
  string_t* tag_string = string_new2("<");
  tag_string = string_append_str(tag_string, tag);

  char* attr;
  while((attr = *attrs++)) {
    tag_string = string_append_str(tag_string, " ");
    tag_string = string_append_str(tag_string, attr);
  }

  tag_string = string_append_str(tag_string, ">");    

  char* elem;
  while((elem = *content++)) {
    tag_string = string_append_str(tag_string, elem);
  }

  tag_string = string_append_str(tag_string, "</");
  tag_string = string_append_str(tag_string, tag);
  tag_string = string_append_str(tag_string, ">");
  
  return tag_string;
}
