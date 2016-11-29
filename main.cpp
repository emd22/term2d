#include "terminal/terminal.hpp"
#include <iostream>

int main() {
  std::cout << "test\n";
  ScreenSpace ss;
  ss.Create(' ');

  //ss.TextEdit(15, 15, Progress(6, 12));
  DrawCircle(ss, {
    0, 0, 10, {
      0.5, 1.0
    }
  });

  ss.AddObjsToSpace();
  SetTermCursorPos(0, 0);
  ss.Print();
  ss.ClearObjs();

}
