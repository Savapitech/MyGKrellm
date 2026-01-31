#include "SFML.hpp"

SFML::SFML() :
    _name("SFML"), _window(sf::VideoMode().getDesktopMode(), "hello")
{
    this->_window.setFramerateLimit(60);
    this->_font.loadFromFile(FONT_PATH);
}

SFML::~SFML()
{
    this->_window.close();
}

void SFML::init()
{
    return;
}

void SFML::display_window()
{
    this->_window.display();
}

void SFML::refresh_window()
{
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
           this->_window.close();
    }
    this->_window.clear();
}

void SFML::draw_box(int x, int y, int width, int height)
{
    sf::RectangleShape rec(sf::Vector2f(height, width));
    rec.setPosition(sf::Vector2f(x, y));
    rec.setFillColor(sf::Color::Cyan);
    this->_window.draw(rec);
}

void SFML::draw_text(int x, int y, std::string text)
{
    sf::Text tex(text, this->_font, 16);
    tex.setPosition(sf::Vector2f(x, y));
    tex.setFillColor(sf::Color::Red);
    tex.setOutlineColor(sf::Color::Black);
    this->_window.draw(tex);
}

const sf::RenderWindow &SFML::getWindow() const
{
    return this->_window;
}
