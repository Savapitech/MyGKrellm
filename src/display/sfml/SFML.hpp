#pragma once

#include "../ADisplay.hpp"
#include <string>
#include <SFML/Graphics.hpp>

#define FONT_PATH "src/assets/Radiant Regular/Radiant.ttf"


class SFML : public ADisplay {
  public:
    SFML();
    ~SFML();
    virtual void init() override;
    virtual void displayWindow() override;
    virtual void refreshWindow() override;
    virtual void drawBox(int x, int y, int width, int height) override;
    virtual void drawText(int x, int y, std::string text, bool header = false) override;
    virtual void drawBar(int x, int y, int height, int width, uint8_t percentage, std::string text, bool reverse_color = false) override;
    virtual void cleanup() override;

    const sf::RenderWindow &getWindow() const;

  private:
    std::string _name;
    sf::RenderWindow _window;
    sf::Font _font;
    sf::Event _event;
};
