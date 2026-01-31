#pragma once

#include "IDisplay.hpp"
#include <string>

namespace Krell {

class ADisplay : public IDisplay {
  int _y = 1;

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
    virtual int getY() const override {
      return _y;
    };
    virtual void setY(int y) override {
      _y = y;
    }

  protected:
    std::string _name;
    bool _state = false;
};

} // namespace Krell
