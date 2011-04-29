#include "htmlize.h"
#include "str.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

char html_auto_free = 0;

string_t* htmlize(char* doctype, string_t* head[], string_t* body[]) {
  string_t* string = string_new2(doctype);
  
  string_t* tag = NULL;

  string = string_append_str(string, "\n\t<head>\n");
  while((tag = *head++)) {
    string = string_append_str(string, "\t\t");
    string = string_append(string, tag);

    if(html_auto_free) { 
      string_del(tag);
    }

    string = string_append_str(string, "\n");
  }
  string = string_append_str(string, "\t</head>");
  string = string_append_str(string, "\n\t<body>\n");

  while((tag = *body++)) {
    string = string_append_str(string, "\t\t");
    string = string_append(string, tag);
    if(html_auto_free) {
      string_del(tag);
    }
    string = string_append_str(string, "\n");
  }
  string = string_append_str(string, "\t</body>\n");
  string = string_append_str(string, "</html>");
  return string;
}

string_t* html_tag(char* tag, char* attrs[], char* content[]) { 
  string_t* tag_string = string_new2("<");
  tag_string = string_append_str(tag_string, tag);

  char* attr;
  while(*attrs && (attr = *attrs++)) {
    tag_string = string_append_str(tag_string, " ");
    tag_string = string_append_str(tag_string, attr);
  }

  tag_string = string_append_str(tag_string, ">");    

  char* elem;
  while(*content && (elem = *content++)) {
    tag_string = string_append_str(tag_string, elem);
  }

  tag_string = string_append_str(tag_string, "</");
  tag_string = string_append_str(tag_string, tag);
  tag_string = string_append_str(tag_string, ">");
  
  return tag_string;
}
