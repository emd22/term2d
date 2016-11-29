#pragma once
#include <iostream>


//Set caret position and remove caret
#ifdef _WIN32
inline void SetTermCursorPos(int x, int y)
{
    COORD cur;
    cur.X = x;
    cur.Y = y;vec
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

inline void HideTermCaret()
{
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO structCursorInfo;
    structCursorInfo.dwSize = 1;
    structCursorInfo.bVisible = FALSE;

    SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
}

void ClearScreen(bool movecur = false) {
  for (int i = 0; i < Size::Height(); i++) {
    std::cout << "\n";
  }
  if (movecur == true) {
    SetTermCursorPos(0, 0);
  }
}

#else
//LINUX/UNIX
#include <cstdio>

inline void SetTermCursorPos(int x, int y)
{
    std::printf("\033[%d;%dH", y, x);
}

inline void HideTermCaret()
{
    std::fputs("\e[?25l", stdout);
}
#endif
//A quick way to clear screen using newlines
void ClearScreen(bool movecur = false) {
  for (int i = 0; i < Size::Height(); i++) {
    std::cout << "\n";
  }
  if (movecur == true) {
    SetTermCursorPos(0, 0);
  }
}
