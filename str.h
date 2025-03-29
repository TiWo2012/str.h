#ifndef _str_h_
#define _str_h_

#include <cstddef>
#include <cstdlib>

struct String {
  char *data;
  size_t size;
};

String* newString(size_t size) {
  String* s = (String*) malloc(sizeof(String));

  s->data = new char[size];
  s->size = size;

  return s;
}

inline void freeString(String* s) {
  free(s);
}

String* appendString(String* str, String append) {
  char *tmp = str->data;

  str = (String*) realloc(str, sizeof(String) * (str->size + append.size));

  str->data = tmp;
  str->size += append.size;

  return str;
}

#endif
