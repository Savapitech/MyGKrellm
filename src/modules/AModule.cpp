#include "AModule.hpp"
#include <ncurses.h>

std::string AModule::get_name() const { return _name; }

bool AModule::get_state() const { return _state; }
