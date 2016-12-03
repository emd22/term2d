#pragma once

#include <vector>
#include "../Space.hpp"

void Modal(
  ScreenSpace &ss,
  int x,
  int y,
  int width,
  int height,
  char style = '@',
  std::vector<std::string> buttons = {},
  int bodycolor = DEFAULT_COLOR,
  int buttoncolor = DEFAULT_COLOR,
  int paddingx = 1,
  int paddingy = 1,
  int buttonspacing = 2,
  int highlight_color = 46,
  int selected = 0,
  bool bold = false) {

  if (ANSI == true && bold == true) {
    buttoncolor = 1;
  }

  if (selected >= buttons.size()) {
    selected = 0;
  }
  else if (selected < 0) {
    selected = buttons.size();
  }

  int bx = x+paddingx;
  for (int i = 0; i < buttons.size(); i++) {
    if (selected == i) {
      ss.TextEdit(bx, y+height-paddingy, buttons[i], highlight_color);
    } else {
      ss.TextEdit(bx, y+height-paddingy, buttons[i], buttoncolor);
    }

    bx += buttons[i].length()+buttonspacing;
  }

  ss.RectLine(x, y, width, height, style, bodycolor);
}
