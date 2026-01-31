#include "../ADisplay.hpp"
#include "ncurses.h"

class Ncurses : public ADisplay {
  public:
    Ncurses();
    virtual ~Ncurses();
    virtual void init() override;
    virtual void display_window() override; 
    virtual void refresh() override;
    virtual void draw_box(int x, int y, int width, int height) override;
    virtual void draw_text(int x, int y, std::string text) override; 
  private:
    WINDOW *_window;
};
