#pragma once

#include "IModule.hpp"

class AModule : public IModule {
public:
  virtual std::string get_name() const override;
  virtual bool get_state() const override;

protected:
  std::string _name;
  bool _state;
};
