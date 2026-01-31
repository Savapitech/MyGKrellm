#include "ModuleCpuInfo.hpp"
#include "../Metrics.hpp"
#include <cstdint>
#include <string>

void ModuleCpuInfo::update() {
  return;
}

void ModuleCpuInfo::draw(IDisplay &display) {
  std::vector<uint8_t> cpus = Metrics::getCpusUsage();
  std::uint16_t physics = Metrics::getPCpuCount();
  std::uint16_t virtuals = Metrics::getVCpuCount();
  int x = 1;
  int y = 13;

  display.drawBox(x, y, 50, cpus.size() * 2 + 12);
  display.drawText(x + 1, y, "CPU Info");
  y += 2;
  x += 1;
  //drawbar
  y += 6;
  display.drawText(x + 1, y, "Physical: " + std::to_string(physics) + ", " + "Virtual: " + std::to_string(virtuals));
  y += 4;
  for (size_t i = 0; i < cpus.size(); ++i) { 
    display.drawBar(x, y + i * 2, 1, 50, cpus[i], "Core " + std::to_string(i));
  }
}
