#pragma once

#include "../display/IDisplay.hpp"
#include "AModule.hpp"
#include <string>

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
