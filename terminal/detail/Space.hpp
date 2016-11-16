#pragma once
#include <string>
#include "Other.hpp"
#include "Entity.hpp"

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

void CreateGameSpace(char back1 = 'e', int xsize2 = 0, int ysize2 = 0) {
  _xsizeg = xsize2;
  _ysizeg = ysize2;
  back = back1;
  for (int y = 0; y < ysize2; y++) {
    for (int x = 0; x < xsize2; x++) {
      temp_game_space.push_back(back1);
    }
    game_space.push_back(temp_game_space);
    temp_screen_space.clear();
  }
}
void EditGameSpace(int x, int y, char change) {
  game_space[y][x] = change;
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
void AddEntsToSpace() {
  for (int i = 0; i < entities.size(); i++) {
    game_space[entities[i].y-1][entities[i].x-1] = entities[i].style;
  }
}
