#pragma once
#include <string>

std::string AddCharToString(char c, int amt) {
  std::string line = "";
  for (int i = 0; i < amt; i++) {
    line += c;
  }
  return line;
}

std::string Progress(int start, int max, int length, char style = '%', char change_style = '@') {
  int perc = start/max * 100;
  std::string bar = AddCharToString(change_style, perc/10);
  bar += AddCharToString(style, length-perc/10);
  return bar;
}
