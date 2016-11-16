#pragma once
#include <string>

std::string StringLower(std::string str) {
  for (int i=0; str[i]; i++) str[i] = tolower(str[i]);
  return str;
}
std::string StringUpper(std::string str) {
  for (int i=0; str[i]; i++) str[i] = toupper(str[i]);
  return str;
}
