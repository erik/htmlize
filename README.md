# htmlize
You're sitting there, minding your own business writing some C,
 and find yourself needing to generate valid HTML. How often does this
 happen to you? _*Far too often.*_

Worry no more! With htmlize, you can generate perfectly awesome HTML, right
from C!

## building
htmlize is rather easy to build, it's just plain C. Run `make` to build it, and
you can test it by running the generated executable, `./htmlize`

## usage
To use htmlize, make sure to #include the `htmlize.h` header. `src/test.c` 
contains a usage example which shows the basic idea, and `include/htmlize.h` has
the actual documentation for the library. Using it is pretty straight-forward
however:

```c
/* create a new HTML <div> element */
unsigned flags = 0;
HTMLElement div = html_elem_new("div", flags);
/* set attributes of the element */
html_elem_add_attr(&div, "class=sidebar");

/* create an <a> element.
 * The ELEMENT_AUTO_FREE flag sets the object to be automatically
 * destroyed after its HTML is generated
*/
HTMLElement a = html_elem_new("a", ELEMENT_AUTO_FREE);
html_elem_add_attr(&a, "href=/index.html");

/* add some content inside of the tag */
html_elem_add_content(&a, "Go home");

/* add the anchor to the div */
html_elem_add_elem(&div, a);

/* create a new empty HTML5 document */
HTMLDocument doc = html_doc_new(DOC_HTML5);

/* add the div to the <body> of the document */
html_doc_add_body_elem(&doc, div);

unsigned size;
/* generate the html */
char* html = html_doc_create(&doc, &size);

printf("Generated HTML (%u bytes):\n%s\n", size, html);

free(html);

html_elem_destroy(&div);
html_doc_destroy(&doc);
```

This will output:

```html
<!doctype html>
<html>
	<head>
	</head>
	<body>
		<div class=sidebar><a href=/index.html>Go home</a></div>
	</body>
</html>
```

## license
    Copyright (c) 2011 Erik Price
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
