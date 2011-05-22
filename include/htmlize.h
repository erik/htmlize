#pragma once

#ifndef _HTML_H_
#define _HTML_H_

#define HTML_BREAK "<br />"
#define DOCTYPE_HTML5 "<!DOCTYPE html>\n<html>"
#define DOCTYPE_XHTML "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"" \
  "\n\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"          \
  "\n<html xmlns=\"http://www.w3.org/1999/xhtml\">"

typedef enum doctype { 
  DOC_HTML4,
  DOC_HTML5,
  DOC_XHTML
} doctype;

typedef enum element_flags {
  ELEMENT_SELF_CLOSE = 1 << 0,
  ELEMENT_NULL_TAG   = 1 << 1,
  ELEMENT_AUTO_FREE  = 1 << 2
} element_flags;

typedef struct HTMLElement {
  char* tag;

  char** attributes;
  unsigned num_attrs;

  char* content_str;

  struct HTMLElement* content;
  unsigned num_content;

  element_flags flags;
} HTMLElement;

typedef struct HTMLDocument {
  doctype type;
  
  unsigned num_head;
  HTMLElement* head_elems;

  unsigned num_body;
  HTMLElement* body_elems;

} HTMLDocument;


/* HTMLDocument functions */
HTMLDocument html_doc_new(doctype doc);
void html_doc_destroy(HTMLDocument* doc);
void html_doc_set_doctype(HTMLDocument* doc, doctype type);
void html_doc_set_title(HTMLDocument* doc, char* title);
void html_doc_add_head_elem(HTMLDocument* doc, HTMLElement elem);
void html_doc_add_body_elem(HTMLDocument* doc, HTMLElement elem);
char* html_doc_create(HTMLDocument* doc, unsigned* sizeptr);

/* HTMLElement functions */
HTMLElement html_elem_new(char* tag, element_flags flags);
void html_elem_destroy(HTMLElement* elem);
void html_elem_add_attr(HTMLElement* elem, char* attr);
void html_elem_add_elem(HTMLElement* elem, HTMLElement inner);
void html_elem_add_content(HTMLElement* elem, char* content);
void html_elem_set_content(HTMLElement* elem, char* content);
char* html_elem_create(HTMLElement* elem, unsigned* sizeptr);

/**
 * Returns an HTML-escaped representation of a given char* of text.
 */
char* html_escape(char* raw, unsigned* sizeptr);

#endif /* _HTML_H_ */
