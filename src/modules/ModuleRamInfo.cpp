#include "ModuleRamInfo.hpp"
#include "../Metrics.hpp"
#include <cstdint>
#include <string>
#include <sys/types.h>

void ModuleRamInfo::update() {
  return;
}

void ModuleRamInfo::draw(IDisplay &display) {
  std::uint64_t total = Metrics::getRamTotalKb() / 1000;
  std::uint64_t used = Metrics::getRamUsedKb() / 1000;
  std::uint64_t free = total - used;
  int x = 1;
  int y = 17 + Metrics::getCpusUsage().size() * 2 + 11;

  display.drawBox(x, y, 50, 11);
  display.drawText(x + 1, y, "Ram Info");
  y += 4;
  x += 1;
  display.drawBar(x + 1, y, 1, 48, (used * 100/ total), "");
  display.drawText(x + 1, y += 2, "RAM Usage: " + std::to_string(used) + " / " + std::to_string(total) + ", " + std::to_string(free) + " free.");
}
