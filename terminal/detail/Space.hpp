#pragma once
#include <string>
#include <iostream>
#include "Time.hpp"
#include "Caret.hpp"
#include "Text.hpp"

class ScreenSpace {
public:
  void Create(char style = ' ', int xsize = TermWidth(), int ysize = TermHeight()) {
    stored_ysize = ysize;
    stored_xsize = xsize;
    background = style;
    for (int y = 0; y < stored_ysize; y++) {
      for (int x = 0; x < stored_xsize; x++) {
        temp_screen_space.push_back(style);
      }
      screen_space.push_back(temp_screen_space);
      temp_screen_space.clear();
    }
  }
  void Edit(int x, int y, char change, int color = DEFAULT_COLOR) {
    if (x <= stored_xsize && y <= stored_ysize-1 && y >= 0) {
      Char c;
      c.message = change;
      c.color = color;
      c.x = x;
      c.y = y;
      charobjs.push_back(c);
      std::cout << charobjs.size() << "\n";
    }
  }
  void TextEdit(int x, int y, std::string change, int color = DEFAULT_COLOR) {
    for (int x2 = 0; x2 < change.length(); x2++) {
      if (y <= stored_ysize) {
        if (x+x2 >= stored_xsize) {
          Edit(x+x2-1, y, '.', color);
          Edit(x+x2-2, y, '.', color);
          Edit(x+x2-3, y, '.', color);
          break;
        }
        Edit(x+x2, y, change[x2], color);
      }
    }
  }

  void RectLine(int sx, int sy, int width, int height, char style, int color) {
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        Edit(sx+x, sy+y, style, color);
      }
    }
  }

  int FindAtPos(int x, int y) {
    for (int i = 0; i < charobjs.size(); i++) {
      if (charobjs[i].x == x && charobjs[i].y == y) {
        return i;  //Text exists
        break;
      } else {
        return -1; //Text does not exist
      }
    }
  }
  void AddObjsToSpace() {
    for (int i = 0; i < charobjs.size(); i++) {
      screen_space[charobjs[i].y][charobjs[i].x] = charobjs[i].message;
    }
  }
  void ClearObjs() {
    charobjs.clear();
  }
  void Print() {
    std::cout << "\n";
    for (int y = 0; y < stored_ysize; y++) {
      std::cout << "\n";
      for (int x = 0; x < screen_space[y].size(); x++) {
        int pos = FindAtPos(x, y);
        if (pos > -1) {
          ColoredText(charobjs[pos].message, charobjs[pos].color);
        } else {
          std::cout << screen_space[y][x];
        }
      }
    }
    std::cout << "\r";
    SetTermCursorPos(0, 0);
  }

  void Reset() {
    screen_space.clear();
    for (int y = 0; y < stored_ysize; y++) {
      for (int x = 0; x < stored_xsize; x++) {
        temp_screen_space.push_back(background);
      }
      screen_space.push_back(temp_screen_space);
      temp_screen_space.clear();
    }
  }
  void UpdateScreenSpaceSize(int width, int height) {
    stored_xsize = width;
    stored_ysize = height;
  }

private:
  int stored_xsize = 0;
  int stored_ysize = 0;

  int lines = 0;
  char background = '?';

  std::vector<std::vector<char> > screen_space;
  std::vector<char> temp_screen_space;

  std::vector<std::vector<char> > game_space;
  std::vector<char> temp_game_space;

  std::vector<Char> charobjs;
};
