#include "../ADisplay.hpp"
#include <ncurses.h>

class Ncurses : public ADisplay {
  public:
    Ncurses();
    virtual ~Ncurses();
    virtual void init() override;
    virtual void displayWindow() override; 
    virtual void refreshWindow() override;
    virtual void drawBox(int x, int y, int width, int height) override;
    virtual void drawText(int x, int y, std::string text) override;
    virtual void drawBar(int x, int y, int height, int width, uint8_t percentage, std::string text) override;
    virtual void cleanup() override;
  private:
    WINDOW *_window;
    int _ch;
};
