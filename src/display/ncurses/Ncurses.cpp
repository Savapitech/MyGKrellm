#include "Ncurses.hpp"

Ncurses::Ncurses() {
  _name = "Ncurses";
}

Ncurses::~Ncurses() {
  endwin();

}

void Ncurses::init() {
    _window = initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    cbreak();
    noecho();
    this->setState(true);
}


void Ncurses::drawBox(int x, int y, int width, int heigth) {
  attron(COLOR_PAIR(1));
  heigth /= 2;
  y /= 2;

  mvhline(y, x + 1, ACS_HLINE, width - 1);
  mvvline(y + 1, x, ACS_VLINE, heigth - 1);
  mvvline(y + 1, x + width, ACS_VLINE, heigth - 1);
  mvhline(y + heigth, x + 1, ACS_HLINE, width - 1);

  mvaddch(y + heigth, x, ACS_LLCORNER);
  mvaddch(y + heigth, x + width, ACS_LRCORNER);
  mvaddch(y, x, ACS_ULCORNER);
  mvaddch(y, x + width, ACS_URCORNER);
}

void Ncurses::drawText(int x, int y, std::string text) {
  y /= 2;
  attron(COLOR_PAIR(2));
  mvprintw(y, x, " %s ", text.c_str());
}


void Ncurses::displayWindow() {
  refresh();
}

void Ncurses::refreshWindow() {
  return;
}

void Ncurses::cleanup() {
  endwin();
}