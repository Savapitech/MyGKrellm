#pragma once

#include "IDisplay.hpp"
#include <string>

class ADisplay : public IDisplay {
  public:
    virtual ~ADisplay() = default;
    virtual void init();
    virtual void display_window(); 
    virtual void refresh();
    virtual void draw_box(int x, int y, int width, int height);
    virtual void draw_text(int x, int y, std::string text);
    virtual std::string get_name() const {
      return _name;
    };
  
  protected:
    std::string _name;
};
