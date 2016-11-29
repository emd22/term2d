#pragma once
#include <sys/ioctl.h>

struct Size {
  static int Height() {
    struct winsize size;
    ioctl(1/*STDOUT_FILENO*/, TIOCGWINSZ, &size);
    return size.ws_row;
  }
  static int Width() {
    struct winsize size;
    ioctl(1/*STDOUT_FILENO*/, TIOCGWINSZ, &size);
    return size.ws_col;
  }
};
