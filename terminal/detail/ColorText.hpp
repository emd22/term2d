#pragma once
#include <iostream>
#include <string>

#ifdef _WIN32

#define DEFAULT_COLOR 15
#define ANSI false

#include <windows.h>   // WinApi header

void ColoredText(std::string message, int color)
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
    std::cout << message;

    SetConsoleTextAttribute(hConsole, DEFAULT_COLOR);
}

#else

#define DEFAULT_COLOR 0
#define ANSI true

void ColoredText(char message, int color)
{
  std::cout << "\033[" << color << "m" << message << "\033[15m";
  std::cout << "\033[" << DEFAULT_COLOR << "m" << "\033[15m";

    //ucout << utf8_string;
}

#endif
