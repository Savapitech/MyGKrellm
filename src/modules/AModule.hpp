#pragma once

#include "IModule.hpp"

class AModule : public IModule {
  public: 
    virtual std::string get_name() const override;
    virtual std::string get_data() const override;
    virtual bool get_state() const override;
    virtual void draw(IDisplay &display) override;
    virtual void update() override;

  protected:
    std::string _name;
    bool _state;
};
