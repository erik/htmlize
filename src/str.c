#include "str.h"

#include <stdlib.h>
#include <string.h>

string_t* string_new(char* str, unsigned length) {
  string_t* string = malloc(sizeof(string_t) + length);
  
  string->allocated = length;

  unsigned size = 0;

  while ( str && ( string->str[size] = str[size] )
          && size++ < length ) ;

  string->size = size;

  return string;  
}

string_t* string_new2(char* str) {
  return string_new(str, strlen(str));
}

void string_del(string_t* string) {
  free(string);
}

string_t* string_resize(string_t* string, unsigned size) {
  string_t* new = string_new(string->str, size);

  string_del(string);

  return new;
}

string_t* string_concat(string_t* a, string_t* b) {
  unsigned newsize  = a->size + b->size;

  string_t* string = string_new(NULL, newsize);
  string->size = newsize;

  unsigned i = 0;
  while( (string->str[i] = a->str[i]) && i++ < a->size);
  i = 0;
  while( (string->str[i + a->size] = b->str[i]) && i++ < b->size);

  return string;
}

string_t* string_concat_str(string_t* base, char* str) {
  string_t* cat_str = string_new2(str);
  string_t* concat = string_concat(base, cat_str);

  string_del(cat_str);
  
  return concat;
}

string_t* string_append_str(string_t* base, char* string) {
  unsigned len = strlen(string);
  
  if(len + base->size >= base->allocated) {
    base = string_resize(base, len + base->size);
  }

  strncpy(base->str + base->size, string, len);
  base->size = base->allocated;

  return base;
}
