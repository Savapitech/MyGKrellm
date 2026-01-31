#pragma once

#include "../Metrics.hpp"
#include "AModule.hpp"

class ModuleNetworkInfo : public AModule {
public:
  ModuleNetworkInfo() = default;
  ~ModuleNetworkInfo() = default;
  virtual void draw(IDisplay &display) override;
  virtual void update() override;
};
