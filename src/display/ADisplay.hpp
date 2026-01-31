#pragma once

#include "IDisplay.hpp"
#include <string>

class ADisplay : public IDisplay {
  public:
    virtual ~ADisplay() = default;
    virtual void init() = 0;
    virtual void display_window() = 0; 
    virtual void refresh_window() = 0;
    virtual void draw_box(int x, int y, int width, int height) = 0;
    virtual void draw_text(int x, int y, std::string text) = 0;
    virtual std::string get_name() const {
      return _name;
    };
  
  protected:
    std::string _name;
};
