#include "terminal/terminal.hpp"
#include <iostream>

#define plot(x, y, color) ss.Edit(x, y, '@', color)

/*void raster_circle(
        ScreenSpace &ss,
        unsigned int x0,
        unsigned int y0,
        unsigned int radius) {
  int f = 1 - radius;
  int ddF_x = 0;
  int ddF_y = -2 * radius;
  int x = 0;
  int y = radius;

  plot(x0, y0 + radius, 45);
  plot(x0, y0 - radius, 45);
  plot(x0 + radius, y0, 46);
  plot(x0 - radius, y0, 46);

  while(x < y) {
    if(f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x + 1;
    plot(x0 + x, y0 + y, 46);
    plot(x0 - x, y0 + y, 46);
    plot(x0 + x, y0 - y, 46);
    plot(x0 - x, y0 - y, 46);
    plot(x0 + y, y0 + x, 46);
    plot(x0 - y, y0 + x, 46);
    plot(x0 + y, y0 - x, 46);
    plot(x0 - y, y0 - x, 46);
  }
}*/

int main() {
  ScreenSpace ss;
  //HideTermCaret();
  ss.Create('!');
  ss.Edit(4, 4, 'K', 46);
  ss.Edit(5, 4, 'F', 45);
  ss.AddObjsToSpace();
  SetTermCursorPos(0, 0);
  ss.Print();
  ss.ClearObjs();

}
