#include "ModuleSystemInfo.hpp"
#include "../Metrics.hpp"


ModuleSystemInfo::ModuleSystemInfo() {
  _hostname = Metrics::getHostname();
  _username = Metrics::getUsername();
  _os = Metrics::getOs();
  _kernel = Metrics::getKernel();
  _time = Metrics::getTime();
  _date = Metrics::getDate();
}

void ModuleSystemInfo::update() {
  _time = Metrics::getTime();
  _date = Metrics::getDate();
}

void ModuleSystemInfo::draw(IDisplay &display)
{
  std::string user = "Username:  " + _username;
  std::string host = "Hostname:  " + _hostname;
  std::string os = "Op. sys.:  " + _os;
  std::string kernel = "Kernel:  " + _kernel;
  display.drawBox(1, 1, 30, 10);
  display.drawText(2, 1, "System Info");
  display.drawText(2, 2, user);
  display.drawText(2, 3, host);
  display.drawText(2, 4, os);
  display.drawText(2, 5, kernel);
}
