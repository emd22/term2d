#include "terminal/terminal.hpp"
#include <iostream>

int main() {
  int selected = 0;
  bool clicked = false;
  char style = '&';
  bool visible = true;

  std::vector<std::string> buttons = {"Yes", "No", "Remind me in a minute"};
  int b_len = buttons.size();

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
    if (key == '\n') {
      clicked = true;
    }

    MODAL_GUARD(b_len);

    ModalOptions mo;
    mo.x = 10;
    mo.y = 10;
    mo.width = 25;
    mo.height = 15;
    mo.buttons = buttons;
    mo.visible = visible;
    mo.selected = selected;
    mo.clicked = clicked;
    mo.style = style;
    mo.message = "click yes to change the background";

    std::string clicked_button = Modal(ss, mo);


    if (clicked_button == "Yes") {
      if (style < 100) {
        style++;
      }
      if (style == 100) {
        style = 32;
      }
    }
    if (clicked_button == "No") {
      visible = false;
    }

    HideTermCaret();
    SetTermCursorPos(0, 0);
    ss.Print();
    TimeDelay("ms", 20);
    ss.ClearObjs();
    clicked = false;
  }

  EnableKeyPrint();
}
