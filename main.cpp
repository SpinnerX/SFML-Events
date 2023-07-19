#include <SFML/Graphics.hpp>
#include "SFML-Events/Events.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(680, 480), "Window");
    Events::Initialize(&window);
    Events::insert(sf::Keyboard::Escape, "Escape");

    while(window.isOpen()){
        Events::listener();

        if(Events::keys() == "Escape") window.close();
    }
}