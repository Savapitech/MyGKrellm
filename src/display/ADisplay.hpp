#pragma once

#include "IDisplay.hpp"
#include <string>

class ADisplay : public IDisplay {
  public:
    virtual ~ADisplay() = default;
    virtual void init();
    virtual void display_window(); 
    virtual void refresh();
    virtual void draw_box();
    virtual void draw_text();
    virtual std::string get_name() const {
      return _name;
    };
  
  protected:
    std::string _name;
};
