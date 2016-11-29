#pragma once

#include <utility>
#include <math.h>
#include <cassert>

struct CircleInfo {
  int x = 0;
  int y = 0;
  int radius = 10;

  std::pair<double, double> threshold = { 0.9, 1.1 };
};

void DrawCircle(ScreenSpace &ss,
  CircleInfo circle)
{
  assert(circle.threshold.first < circle.threshold.second);

  const float consoleRatio = 4.0/3.0;
  const float a = consoleRatio * circle.radius;
  const float b = circle.radius;

  for (int y = -b; y <= b; y++) {
    for (int x = -a; x <= a; x++) {
      float d = (x / a)*(x / a) + (y/b)*(y/b);
      if (d >= circle.threshold.first && d < circle.threshold.second) {
        ss.Edit((x)+circle.radius*2, (y)+circle.radius*2, '@', WARN_COLOR);
      }
    }
  }
}
