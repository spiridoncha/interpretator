#include "String.h"
String::String(const String &other) {
  if (other.str != nullptr) {
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
  } else {
    str = other.str;
    size = other.size;
  }
}

String::String(const char *other) {
  if (other != nullptr) {
    size = strlen(other);
    str = new char[size + 1];
    strcpy(str, other);
  } else {
    str = nullptr;
    size = 0;
  }
}

String String::int_to_str(const int n) {
  int i = n;
  int mod;
  String tmp("");
  if (n == 0) {
    tmp += String("0");
    return tmp;
  }
  while (i) {
    mod = i % 10;
    mod += '0';
    char *p = new char[2];
    p[0] = mod;
    p[1] = '\0';
    tmp = String(p) + tmp;
    delete[] p;
    i /= 10;
  }
  return tmp;
}

String &String::operator=(const String &other) {
  if (other.str != nullptr) {
    if (this == &other) {
      return *this;
    }
    delete[] str;
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
    return *this;
  } else {
    if (this == &other) {
      return *this;
    }
    delete[] str;
    size = other.size;
    str = other.str;
    return *this;
  }
}

String &String::operator+=(const String &other) {
  size += other.size;
  char *p_new = new char[size + 1];
  strcpy(p_new, str);
  strcat(p_new, other.str);
  delete[] str;
  str = p_new;
  return *this;
}

String String::operator+(const String &other) {
  String tmp("");
  tmp += *this;
  tmp += other;
  return tmp;
}

std::ostream &operator<<(std::ostream &out, const String &st) {
  if (st.str != nullptr) {
    out << st.str;
  }
  return out;
}

bool String::operator==(const String &other_str) {
  return strcmp(str, other_str.str) == 0 ? true : false;
}
bool String::operator!=(const String &other_str) {
  return not this->operator==(other_str);
}
bool String::operator<(const String &other_str) {
  return strcmp(str, other_str.str) < 0 ? true : false;
}
bool String::operator>(const String &other_str) {
  return strcmp(str, other_str.str) > 0 ? true : false;
}
