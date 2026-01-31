#pragma once

#include "../display/IDisplay.hpp"

class IModule {
  public: 
    virtual std::string get_name() const = 0;
    virtual bool get_state() const = 0;
    virtual void draw(IDisplay &display) = 0;
    virtual void update() = 0;
};
