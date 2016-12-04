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

    std::string clicked_button = Modal(
          ss,
          10,            //x
          10,            //y
          30,            //width
          15,            //height
          style,         //style
          buttons,       //buttons
          selected,
          clicked,
          "Want to change the background of this modal?saddvasgdasdgashdghausidgsagdduiasog",
          visible
    );
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
    if (clicked_button == "Remind me in a minute") {
      visible = false;
      TimeDelay("s", 60);
      visible = true;
    }

    HideTermCaret();
    SetTermCursorPos(0, 0);
    ss.Print();
    //TimeDelay("ms", 200);
    ss.ClearObjs();
    clicked = false;
  }

  EnableKeyPrint();
}
