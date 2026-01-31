#pragma once

#include "IDisplay.hpp"
#include <string>

class ADisplay : public IDisplay {
  public:
    virtual ~ADisplay() = default;
    virtual void init() = 0;
    virtual void displayWindow() = 0; 
    virtual void refreshWindow() = 0;
    virtual void drawBox(int x, int y, int width, int height) = 0;
    virtual void drawText(int x, int y, std::string text) = 0;
    virtual std::string getName() const {
      return _name;
    };
  
  protected:
    std::string _name;
};
