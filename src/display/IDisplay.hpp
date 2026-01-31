#pragma once

#include <string>

class IDisplay {
  public:
    virtual ~IDisplay() = default;
    virtual void init() = 0;
    virtual void displayWindow() = 0;
    virtual void refreshWindow() = 0;
    virtual void drawBox(int x, int y, int width, int height) = 0;
    virtual void drawText(int x, int y, std::string text) = 0;
};
