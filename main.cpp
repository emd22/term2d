#include "terminal/terminal.hpp"
#include <iostream>

int main() {
  ScreenSpace ss;
  ss.Create();
  ss.RectLine(0, 1, 1, TermHeight()-1, '-');
  ss.Print();

}
