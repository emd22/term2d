#pragma once
#include <string>
#include <iostream>
#include "Other.hpp"
#include "Time.hpp"

class ScreenSpace {
public:
  void Create(int x_size = TermWidth(), int y_size = TermHeight()) {
    stored_xsize = x_size;
    stored_ysize = y_size;
    for (int y = 0; y < y_size; y++) {
      for (int x = 0; x < x_size; x++) {
        temp_screen_space.push_back(' ');
      }
      screen_space.push_back(temp_screen_space);
      temp_screen_space.clear();
    }
  }
  void Edit(int x, int y, char change) {
    if (x != stored_xsize && y != stored_ysize) {
      screen_space[y][x] = change;
    }
  }
  void TextEdit(int x, int y, std::string change) {
    for (int x2 = 0; x2 < change.length(); x2++) {
      if (y != stored_ysize) {
        if (x+x2 >= stored_xsize) {
          screen_space[y][x+x2-1] = '.';
          screen_space[y][x+x2-2] = '.';
          screen_space[y][x+x2-3] = '.';
          break;
        }
        screen_space[y][x+x2] = change[x2];
      }
    }
  }

  void RectLine(int sx, int sy, int width, int height, char style) {
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        screen_space[sy+y][sx+x] = style;
      }
    }
  }

  void Print() {
    for (int y = 0; y < stored_ysize; y++) {
      for (int x = 0; x < screen_space[y].size(); x++) {
        std::cout << screen_space[y][x];
      }
      std::cout << "\n";
    }
    std::cout << "\r";
  }

private:
  int stored_xsize = 0;
  int stored_ysize = 0;
};

/*
void CreateScreenSpace(int xsize = 0, int ysize = 0) {
  _xsize = xsize;
  _ysize = ysize;
  for (int y = 0; y < ysize; y++) {
    for (int x = 0; x < xsize; x++) {
      temp_screen_space.push_back(' ');
    }
    screen_space.push_back(temp_screen_space);
    temp_screen_space.clear();
  }
}
void EditScreenSpace(int x, int y, char change) {
  screen_space[y][x] = change;
}
void SEditScreenSpace(int sx, int sy, std::string change) {
  for (int x = 0; x < change.length(); x++) {
    screen_space[sy][sx+x] = change[x];
  }
}

void CreateGameSpace(int xg1 = 0, int yg1 = 0, char back1 = 'e', int xsize = 0, int ysize = 0) {
  _xsizeg = xsize;
  _ysizeg = ysize;

  xg = xg1;
  yg = yg1;

  back = back1;
  for (int y = 0; y < ysize; y++) {
    for (int x = 0; x < xsize; x++) {
      temp_game_space.push_back(back1);
    }
    game_space.push_back(temp_game_space);
  }
}
void EditGameSpace(int x, int y, char change) {
  EditScreenSpace(xg+x, yg+y, change)
}

//Print out screenspace
void Print() {
  for (int y = 0; y < _ysizeg; y++) {
    for (int x = 0; x < _xsizeg; x++) {
      EditScreenSpace(x, y, back);
    }
  }
  for (int i = 0; i < entities.size(); i++) {
    screen_space[entities[i].y][entities[i].x] = entities[i].style;
  }

  for (int y2 = 0; y2 < _ysize; y2++) {
    for (int x2 = 0; x2 < screen_space[y2].size(); x2++) {
      std::cout << screen_space[y2][x2];
    }
    std::cout << "\n";
  }
  std::cout << "\r";
  SetTermCursorPos(0,0);
}
//Reset screenspace
void Reset(char background) {
  screen_space.clear();
  for (int y = 0; y < _ysize; y++) {
    for (int x = 0; x < _xsize; x++) {
      temp_screen_space.push_back(background);
    }
    screen_space.push_back(temp_screen_space);
    temp_screen_space.clear();
  }
}
//add entity
void AddEntity(Entity entity) {
  entities.push_back(entity);
}
//add all entities to screenspace
*/
