#include "Buffer.h"
void Buffer::re_size() {
  if (real_size + 1 == size) {
    char *buf_new = new char[2 * size];
    for (int i = 0; i < size; ++i) {
      buf_new[i] = buf[i];
    }
    for (int i = size; i < 2 * size; ++i) {
      buf_new[i] = '\0';
    }
    size *= 2;
    delete[] buf;
    buf = buf_new;
  }
}

void Buffer::clear() {
  real_size = 0;
  for (int i = 0; i < size; ++i) {
    buf[i] = '\0';
  }
}

void Buffer::add(int ch) {
  re_size();
  buf[real_size++] = ch;
}
