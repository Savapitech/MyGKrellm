#include <iomanip>
#include <iostream>
#include <unistd.h>

#include "Metrics.hpp"
#include "display/IDisplay.hpp"
#include "display/ncurses/Ncurses.hpp"
#include "display/sfml/SFML.hpp"
#include "modules/IModule.hpp"
#include "modules/ModuleSystemInfo.hpp"
#include "modules/ModuleCpuInfo.hpp"

int mainLoop(IDisplay *disp, IModule *sy, IModule *cpu)
{
    while (disp->getState()) {
      disp->refreshWindow();
      sy->update();
      cpu->update();
      sy->draw(*disp);
      cpu->draw(*disp);
      disp->displayWindow();
      sleep(1);
    }
    return 1;
}

int main(void) {
  Ncurses nc;
  SFML sf;
  IDisplay *disp = &sf;
  IModule *sy = new ModuleSystemInfo();
  IModule *cpu = new ModuleCpuInfo();


  disp->init();
  while (mainLoop(disp, sy, cpu)) {
    disp->cleanup();
    disp = &nc;
    disp->init();
  }
  return 0;
}
