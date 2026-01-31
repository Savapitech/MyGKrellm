#pragma once

#include <cstdint>
#include <string>
#include <stdint.h>

class IDisplay {
  public:
    virtual ~IDisplay() = default;
    virtual void init() = 0;
    virtual void displayWindow() = 0;
    virtual void refreshWindow() = 0;
    virtual void drawBox(int x, int y, int width, int height) = 0;
    virtual void drawText(int x, int y, std::string text) = 0;
    virtual void drawBar(int x, int y, int height, int width, uint8_t percentage, std::string text) = 0;
    virtual void cleanup() = 0;
    virtual bool getState() const = 0;
    virtual int getY() const = 0;
    virtual void setY(int y) = 0;
};
