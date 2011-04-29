#pragma once

#ifndef _HTML_H_
#define _HTML_H_

#include "str.h"

#define ATTRIBUTES(...) (char*[]){__VA_ARGS__, NULL}
#define CONTENT(...)    (char*[]){__VA_ARGS__, NULL}

#define HEAD(...)       (string_t*[]){__VA_ARGS__, NULL}
#define BODY(...)       (string_t*[]){__VA_ARGS__, NULL}

#define ID(name) ("id=" #name )
#define CLASS(name) ("class=" #name)

#define HTML_BREAK "<br />"

#define DOCTYPE_XHTML "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\n\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"

char* html_escape(char* text);
char* htmlize(char* doctype, string_t* head[], string_t* body[]);

struct string* html_tag(char* tagname, char* attrs[], char* content[]);

#endif /* _HTML_H_ */
