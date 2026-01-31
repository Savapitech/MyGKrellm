#pragma once

#include "AModule.hpp"
#include "../Metrics.hpp"

class ModuleNetworkInfo : public AModule {
  public:
    ModuleNetworkInfo() = default;
    ~ModuleNetworkInfo() = default;
    virtual void draw(IDisplay &display) override;
    virtual void update() override;
};
