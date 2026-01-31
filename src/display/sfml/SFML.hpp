#pragma once

#include "../ADisplay.hpp"
#include <string>
#include <SFML/Graphics.hpp>

#define FONT_PATH "src/assets/VMV Sega Genesis/VMVSegaGenesis-Regular.otf"

class SFML : public ADisplay {
  public:
    SFML();
    ~SFML();
    void init();
    void display_window();
    void refresh_window();
    void draw_box(int x, int y, int width, int height);
    void draw_text(int x, int y, std::string text);

    const sf::RenderWindow &getWindow() const;

  private:
    std::string _name;
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Event _event;
};
