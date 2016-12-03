#include "terminal/terminal.hpp"
#include <iostream>

int main() {
  int selected = 0;
  ScreenSpace ss;
  ss.Create(' ');
  DisableKeyPrint();

  while (true) {
    int key = CurKey();
    if (key == 'a') {
      selected--;
    }
    if (key == 'd') {
      selected++;
    }

    if (selected >= 2) {
      selected = 0;
    }
    else if (selected < 0) {
      selected = 2;
    }

    Modal(ss,
          10,            //x
          10,            //y
          10,            //width
          10,            //height
          '.',           //style
          {"Ok", "Nope"},//buttons
          35,            //body/background color
          36,            //button color
          1,             //padding x
          1,             //padding y
          1,             //spaces between buttons
          45,            //highlighted color
          selected);     //selection
    ss.Print();
    //TimeDelay("ms", 200);
    ss.ClearObjs();
  }

  EnableKeyPrint();
}
