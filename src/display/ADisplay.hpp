#pragma once

#include "IDisplay.hpp"
#include <string>

class ADisplay : public IDisplay {
  public:
    virtual ~ADisplay() = default;
    virtual std::string getName() const {
      return _name;
    };
    virtual bool getState() const override {
      return _state;
    };
    virtual void setState(bool state) {
      this->_state = state;
    };

  protected:
    std::string _name;
    bool _state = false;
};
