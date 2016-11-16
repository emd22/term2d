#pragma once

struct Entity {
  int x = 0;
  int y = 0;
  char style = '?';

  Entity() {

  }
  Entity(int x, int y, char style) {
    this->x = x;
    this->y = y;
    this->style = style;
  }
};
