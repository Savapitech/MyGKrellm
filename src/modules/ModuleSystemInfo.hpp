#pragma once

#include "AModule.hpp"
#include <string>
#include "../display/IDisplay.hpp"

class ModuleSystemInfo : public AModule {
  public:
    ModuleSystemInfo();
    ~ModuleSystemInfo();
    virtual void draw(IDisplay &display) override;
    virtual void update() override;
  private:
    std::string _hostname;
    std::string _username;
    std::string _kernel;
    std::string _os;
    std::string _time;
    std::string _date;
};
