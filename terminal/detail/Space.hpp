#pragma once
#include <string>
#include <iostream>
#include <cmath>
#include "Time.hpp"
#include "Caret.hpp"
#include "ColorText.hpp"

struct Char {
  char message = '?';
  int color = DEFAULT_COLOR;
  int x = 0;
  int y = 0;
};

class ScreenSpace {
public:
  void Create(char style = ' ',
                     int xsize = Size::Width(),
                     int ysize = Size::Height()) {
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
    if (x <= stored_xsize && y <= stored_ysize-1 && y >= 0 && x >= 0) {
      Char c;
      c.message = change;
      c.color = color;
      c.x = x;
      c.y = y;
      charobjs.push_back(c);
    //std::cout << charobjs.size() << "\n";
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
        Edit(sx+x, sy+y+1, style, color);
      }
    }
  }

  void BetterLine(int x1, int y1, int x2, int y2, char style, int color) {
    if (x1 == x2 && y1 == y2) {
      Edit(x1, y1+1, style, color);
    }
    else if (x1 == x2) {
      if (y1 > y2) {
        RectLine(x1, y2, 1, y1-y2, style, color);
      }
      else if (y2 > y1) {
        RectLine(x1, y1, 1, y2-y1, style, color);
      }
    }
    else if (y1 == y2) {
      if (x1 > x2) {
        RectLine(x2, y1, x1-x2, 1, style, color);
      }
      else if (x2 > x1) {
        RectLine(x1, y1, x2-x1, 1, style, color);
      }
    }
    else {
      const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
      if(steep)
      {
        std::swap(x1, y1);
        std::swap(x2, y2);
      }
      if(x1 > x2)
      {
        std::swap(x1, x2);
        std::swap(y1, y2);
      }

      const float dx = x2 - x1;
      const float dy = fabs(y2 - y1);

      float error = dx / 2.0f;
      const int ystep = (y1 < y2) ? 1 : -1;
      int y = (int)y1;

      const int maxX = (int)x2;

      for(int x=(int)x1; x<maxX; x++)
      {
        if(steep)
        {
            Edit(y, x, style, color);
        }
        else
        {
            Edit(x, y, style, color);
        }

        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
      }
    }
  }

  int FindCharObjsAtPos(int x, int y) {
    for (int i = 0; i < charobjs.size(); i++) {
      if (charobjs[i].x == x && charobjs[i].y == y) {
        return i;  //Text exists
      }
    }
    return -1; //Text does not exist
  }
  void ClearObjs() {
    charobjs.clear();
  }
  void Print() {
    //std::cout << "\n";
    for (int y = 0; y < stored_ysize; y++) {
      //std::cout << "\n";
      for (int x = 0; x < screen_space[y].size(); x++) {
        int pos = FindCharObjsAtPos(x, y);
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

  int test() {
    i++;
    return i;
  }

private:
  int stored_xsize = 0;
  int stored_ysize = 0;

  int lines = 0;
  int i = 0;
  char background = '?';

  std::vector<std::vector<char> > screen_space;
  std::vector<char> temp_screen_space;

  std::vector<Char> charobjs;
};
