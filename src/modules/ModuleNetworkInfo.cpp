#include "ModuleNetworkInfo.hpp"
#include "../Metrics.hpp"
#include <string>
#include <vector>

void ModuleNetworkInfo::update() {
  return;
}

void ModuleNetworkInfo::draw(IDisplay &display) {
  std::vector<Metrics::Inet> inets = Metrics::getInets();
  int x = 1;
  int y = display.getY() + 6;
  display.drawBox(x, y, 50, 12 * inets.size());

  for (auto &inet : inets) {
    display.drawText(x + 1, y += 2, inet.getName() + ":");
    display.drawText(x + 1, y += 2, "\tReceive: " + std::to_string(inet.getRBits()/1000) + " Kb, " + std::to_string(inet.getRPackets()) + " packet(s),");
    display.drawText(x + 1, y += 2, "\t\t" + std::to_string(inet.getRError()) + " error(s), " + std::to_string(inet.getRDrop()) + " drop(s).");
    display.drawText(x + 1, y += 2, "\tTransmit: " + std::to_string(inet.getTBits()/1000) + " Kb, " + std::to_string(inet.getTPackets()) + " packet(s),");
    display.drawText(x + 1, y += 2, "\t\t" + std::to_string(inet.getTError()) + " error(s), " + std::to_string(inet.getTDrop()) + " drop(s).");
 }
  display.setY(0);
}
