#include <iomanip>
#include <iostream>
#include <unistd.h>

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

int mainLoop(Krell::IDisplay *disp, Krell::IModule *sy, Krell::IModule *cpu,
             Krell::IModule *ram, Krell::IModule *net,
             Krell::IModule *battery) {
  while (disp->getState()) {
    disp->refreshWindow();
    sy->update();
    cpu->update();
    ram->update();
    net->update();
    battery->draw(*disp);
    sy->draw(*disp);
    cpu->draw(*disp);
    ram->draw(*disp);
    net->draw(*disp);
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
  Krell::IModule *battery = new Krell::ModuleBatteryInfo();
  Krell::IModule *sy = new Krell::ModuleSystemInfo();
  Krell::IModule *cpu = new Krell::ModuleCpuInfo();
  Krell::IModule *ram = new Krell::ModuleRamInfo();
  Krell::IModule *net = new Krell::ModuleNetworkInfo();

  disp->init();
  while (mainLoop(disp, sy, cpu, ram, net, battery)) {
    disp->cleanup();
    tmp = disp;
    disp = stash;
    stash = tmp;
    disp->init();
  }
  return 0;
}
