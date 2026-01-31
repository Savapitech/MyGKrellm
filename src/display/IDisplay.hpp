#pragma once

class IDisplay {
  public:
    virtual ~IDisplay() = default;
    virtual void init() = 0;
    virtual void display_window() = 0;
    virtual void destroy() = 0;
    virtual void refresh() = 0;
    virtual void draw_box() = 0;
    virtual void draw_text() = 0;
};
