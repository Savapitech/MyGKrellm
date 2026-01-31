#pragma once

#include "AModule.hpp"
#include "../display/IDisplay.hpp"

class ModuleCpuInfo : public AModule {
  public:
    ModuleCpuInfo() = default;
    ~ModuleCpuInfo() = default;
    virtual void draw(IDisplay &display) override;
    virtual void update() override;
};
