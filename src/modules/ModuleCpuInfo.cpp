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

  display.drawBox(x, y, 50, cpus.size() * 2 + 2);
  display.drawText(x + 1, y, "CPU Info");
  y += 2;
  x += 1;

  for (size_t i = 0; i < cpus.size(); ++i) { 
    display.drawText(x, y + i *2, "Core " + std::to_string(i) + "\t" + std::to_string(cpus[i]) + "%");
  }
}
