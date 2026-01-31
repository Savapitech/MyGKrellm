#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "Metrics.hpp"
#include "display/IDisplay.hpp"
#include "display/ncurses/Ncurses.hpp"
#include "display/sfml/SFML.hpp"
#include "modules/IModule.hpp"
#include "modules/ModuleCpuInfo.hpp"
#include "modules/ModuleNetworkInfo.hpp"
#include "modules/ModuleSystemInfo.hpp"
#include "modules/ModuleRamInfo.hpp"
#include "modules/ModuleBatteryInfo.hpp"

int mainLoop(IDisplay *disp, IModule *sy, IModule *cpu, IModule *ram, IModule *net, IModule *battery)
{
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
    }
    return 1;
}

int main(void) {
  Ncurses nc;
  //SFML sf;
  IDisplay *disp = &nc;
  IDisplay *stash = &nc;
  IDisplay *tmp;
  IModule *battery = new ModuleBatteryInfo();
  IModule *sy = new ModuleSystemInfo();
  IModule *cpu = new ModuleCpuInfo();
  IModule *ram = new ModuleRamInfo();
  IModule *net = new ModuleNetworkInfo();

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
