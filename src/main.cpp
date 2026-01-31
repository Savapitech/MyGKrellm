#include <iomanip>
#include <iostream>
#include <memory>
#include <unistd.h>
#include <vector>

#include "Metrics.hpp"
#include "display/IDisplay.hpp"
#include "display/ncurses/Ncurses.hpp"
#include "display/sfml/SFML.hpp"
#include "modules/IModule.hpp"
#include "modules/ModuleBatteryInfo.hpp"
#include "modules/ModuleCpuInfo.hpp"
#include "modules/ModuleNetworkInfo.hpp"
#include "modules/ModuleRamInfo.hpp"
#include "modules/ModuleSystemInfo.hpp"

int mainLoop(Krell::IDisplay *disp,
             std::vector<std::unique_ptr<Krell::IModule>> &modules) {
  while (disp->getState()) {
    disp->refreshWindow();

    for (auto &module : modules)
      module->update();

    for (auto &module : modules)
      module->draw(*disp);

    disp->displayWindow();
    disp->setY(1);
  }
  return 1;
}

int main(void) {
  Krell::Ncurses nc;
  Krell::SFML sf;
  Krell::IDisplay *disp = &nc;
  Krell::IDisplay *stash = &sf;
  Krell::IDisplay *tmp;

  std::vector<std::unique_ptr<Krell::IModule>> modules;
  modules.push_back(std::make_unique<Krell::ModuleBatteryInfo>());
  modules.push_back(std::make_unique<Krell::ModuleSystemInfo>());
  modules.push_back(std::make_unique<Krell::ModuleCpuInfo>());
  modules.push_back(std::make_unique<Krell::ModuleRamInfo>());
  modules.push_back(std::make_unique<Krell::ModuleNetworkInfo>());

  disp->init();
  while (mainLoop(disp, modules)) {
    disp->cleanup();
    tmp = disp;
    disp = stash;
    stash = tmp;
    disp->init();
  }
  return 0;
}