#pragma once

#include "AModule.hpp"
#include "../display/IDisplay.hpp"

class ModuleBatteryInfo : public AModule {
  public:
    ModuleBatteryInfo() = default;
    ~ModuleBatteryInfo() = default;
    virtual void draw(IDisplay &display) override;
    virtual void update() override;
};
