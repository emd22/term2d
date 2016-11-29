#pragma once
#include <string>

std::string AddCharToString(char c, int amt) {
  std::string line = "";
  for (int i = 0; i < amt; i++) {
    line += c;
  }
  return line;
}

std::string Progress(int start, int length, char style = '%', char change_style = '@') {
  std::string bar = AddCharToString(change_style, start);
  bar += AddCharToString(style, length-start);
  return bar;
}
