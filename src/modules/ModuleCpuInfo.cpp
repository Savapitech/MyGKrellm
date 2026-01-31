#include "ModuleCpuInfo.hpp"
#include "../Metrics.hpp"
#include <string>

void ModuleCpuInfo::update() {
  return;
}

void ModuleCpuInfo::draw(IDisplay &display) {
  std::vector<uint8_t> cpus = Metrics::getCpusUsage();
  int x = 1;
  int y = 17;

  display.drawBox(x, y, 50, 35);
  y += 2;
  x += 1;

  for (size_t i = 0; i < cpus.size(); ++i) { 
    display.drawText(x, y + i *2, std::to_string(cpus[i]) + "%" + "\t\tCore\t" + std::to_string(i));
  }
}
