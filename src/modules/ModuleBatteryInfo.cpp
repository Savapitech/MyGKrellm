#include <string>
#include <sys/types.h>

#include "ModuleBatteryInfo.hpp"
#include "../Metrics.hpp"

void ModuleBatteryInfo::update() {
  return;
}

void ModuleBatteryInfo::draw(IDisplay &display) {
  int x = 1;
  int y = display.getY();

  display.drawBox(x, y, 50, 9);
  display.drawText(x + 2, y, "Battery Info");
  y += 4;
  x += 1;
  display.drawBar(x + 1, y, 1, 48, Metrics::getBatteryPercentage(), "Battery");
  display.setY(y);
}
