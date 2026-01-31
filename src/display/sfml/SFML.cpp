#include "SFML.hpp"

SFML::SFML() :
    _name("SFML")
{
    this->_window.setFramerateLimit(1);
    this->_font.loadFromFile(FONT_PATH);
}

SFML::~SFML()
{
    this->_window.close();
}

void SFML::init()
{
    this->_window.create(sf::VideoMode().getDesktopMode(), "hello", sf::Style::None);
    this->setState(true);
    return;
}

void SFML::displayWindow()
{
    this->_window.display();
}

void SFML::refreshWindow()
{
    while (this->_window.pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::KeyPressed && this->_event.key.code == sf::Keyboard::E) {
            this->setState(false);
        }
    }
    this->_window.clear();
}

void SFML::drawBox(int x, int y, int width, int height)
{
    sf::RectangleShape rec(sf::Vector2f(width * 8, height * 16));
    rec.setPosition(sf::Vector2f(x * 8, y * 16));
    rec.setFillColor(sf::Color::Black);
    rec.setOutlineColor(sf::Color::Black);
    rec.setOutlineThickness(2);
    this->_window.draw(rec);
}

void SFML::drawText(int x, int y, std::string text)
{
    sf::Text tex(text, this->_font, 20);
    tex.setPosition(sf::Vector2f(x * 8, y * 16));
    tex.setFillColor(sf::Color::Red);
    tex.setOutlineColor(sf::Color::Black);
    this->_window.draw(tex);
}

const sf::RenderWindow &SFML::getWindow() const
{
    return this->_window;
}

void SFML::cleanup()
{
    this->_window.close();
}