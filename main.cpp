#include "terminal/terminal.hpp"
#include <iostream>

int main() {
  ClearScreen();
  CreateScreenSpace(20, 20);
  DisableKeyPrint();
  HideTermCaret();
  while (true) {
    EditScreenSpace(10, 10, CurKey());
    Print();
    TimeDelay("ms", 500);
  }

}
