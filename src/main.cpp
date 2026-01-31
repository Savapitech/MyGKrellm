#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "Metrics.hpp"
#include "display/IDisplay.hpp"
#include "display/ncurses/Ncurses.hpp"
#include "display/sfml/SFML.hpp"
#include "modules/IModule.hpp"
#include "modules/ModuleCpuInfo.hpp"
#include "modules/ModuleSystemInfo.hpp"
#include "modules/ModuleRamInfo.hpp"

int mainLoop(IDisplay *disp, IModule *sy, IModule *cpu, IModule *ram)
{
    while (disp->getState()) {
      disp->refreshWindow();
      sy->update();
      cpu->update();
      ram->update();
      sy->draw(*disp);
      cpu->draw(*disp);
      ram->draw(*disp);
      disp->displayWindow();
    }
    return 1;
}

int main(void) {
  Ncurses nc;
  //SFML sf;
  IDisplay *disp = &nc;
  IModule *sy = new ModuleSystemInfo();
  IModule *cpu = new ModuleCpuInfo();
  IModule *ram = new ModuleRamInfo();

  disp->init();
  while (mainLoop(disp, sy, cpu, ram)) {
    disp->cleanup();
    disp = &nc;
    disp->init();
  }
  return 0;
}
