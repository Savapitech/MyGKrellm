#pragma once

#include <string>

class IDisplay {
  public:
    virtual ~IDisplay() = default;
    virtual void init() = 0;
    virtual void display_window() = 0;
    virtual void refresh_window() = 0;
    virtual void draw_box(int x, int y, int width, int height) = 0;
    virtual void draw_text(int x, int y, std::string text) = 0;
};
