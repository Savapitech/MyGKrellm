#pragma once

#include "AModule.hpp"
#include "../display/IDisplay.hpp"

class ModuleRamInfo : public AModule {
  public:
    ModuleRamInfo() = default;
    ~ModuleRamInfo() = default;
    virtual void draw(IDisplay &display) override;
    virtual void update() override;
  private:
    std::deque<uint8_t> _queue;
};
