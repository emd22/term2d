#pragma once
#include "Entity.hpp"

std::vector<std::vector<char> > screen_space;
std::vector<char> temp_screen_space;

std::vector<std::vector<char> > game_space;
std::vector<char> temp_game_space;
char back = '?';

int _xsize = 0;
int _ysize = 0;

int _xsizeg = 0;
int _ysizeg = 0;

//Simple collision things
bool simple_collisions = false;

std::vector<Entity> entities;
