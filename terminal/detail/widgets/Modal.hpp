#pragma once

#include <vector>
#include "../Space.hpp"

#define MODAL_GUARD(b_len)  if (selected >= b_len) { \
                        selected = 0;          \
                      }                        \
                      else if (selected < 0) { \
                        selected = b_len-1;    \
                      }                        \

std::string Modal(
  ScreenSpace &ss,
  int x,
  int y,
  int width,
  int height,
  char style = '@',
  std::vector<std::string> buttons = {},
  int selected = 0,
  bool clicked = false,
  std::string message = "",
  bool visible = true,
  int bodycolor = 35,
  int buttoncolor = 36,
  int paddingx = 1,
  int paddingy = 1,
  int buttonspacing = 1,
  int highlight_color = 46,
  int message_color = 45
  ){
  if (visible) {
    int addspace = 0;

    for (int j = 0; j < buttons.size(); j++) {
      addspace += buttons[j].length();
    }
    if (addspace >= width-(buttonspacing*buttons.size())) {
      width = addspace+4;
    }

    if (selected >= buttons.size()) {
      selected = 0;
    }
    else if (selected < 0) {
      selected = buttons.size();
    }

    int bx = x+paddingx;

    if (message.length() >= width) {
      int start = 0;
      int end = width;
      for (int i = 0; i < message.length()/(width)+1; i++) {
        ss.TextEdit(x+paddingx, y+paddingy+(i+1), message.substr(start, end-2), message_color);
        start += width-2;
        end += width+2;
        if (end >= width) {
          end = width;
        }
      }
    }

    for (int i = 0; i < buttons.size(); i++) {
      if (selected == i) {
        ss.TextEdit(bx, y+height-paddingy, buttons[i], highlight_color);
      } else {
        ss.TextEdit(bx, y+height-paddingy, buttons[i], buttoncolor);
      }

      bx += buttons[i].length()+buttonspacing;
    }

    ss.RectLine(x, y, width, height, style, bodycolor);
    if (clicked == true) {
      return buttons[selected];
    }
    else {
      return "";
    }
  }
}
