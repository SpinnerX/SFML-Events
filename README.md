```
____  _____ __  __ _          _____                 _       
/ ___||  ___|  \/  | |        | ____|_   _____ _ __ | |_ ___ 
\___ \| |_  | |\/| | |   _____|  _| \ \ / / _ \ '_ \| __/ __|
 ___) |  _| | |  | | |__|_____| |___ \ V /  __/ | | | |_\__ \
|____/|_|   |_|  |_|_____|    |_____| \_/ \___|_| |_|\__|___/
```

Description

This simply allows SFML-Events to become its own framework (this is to get an idea on how I may want to handle other kinds of events systems) The goal is to also be able
to handle events by creating one instance focused on one class instance that can be accessed throughout an entire SFML application without the use of cuntion calls

Features (Things that SFML-Events is able to handle)
- Key Events
- Mouse Events

Comparison the code base

Without SFML-Events
```C++
int main(){
    sf::RenderWindow window(sf::VideoMode(680, 480), "Window");

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
             if(event.type == sf::Event::Closed) window.close();
             if(event.key.code == sf::Keyboard::Escape) window.close();
        }
    }
}
```

With SFML-Events
```C++

// Events would be able to be used and call in other functions as long it has been initialized.
// Allows for reliability in use-cases throughout the project this is included in.
void movements(){
   if(Events::keys() == "W") { /* player movements */ }|
}

int main(){
    sf::RenderWindow window(sf::VideoMode(680, 480), "Window");
    Events::Initialize(&window);
    Events::insert(sf::Keyboard::Escape, "Escape");
    Events::insert(sf::Keyboard::Space, "Space");

    while(window.isOpen()){
        Events::listener();

        if(Events::keys() == "Escape") window.close();
        if(Events::keys() == "Space") { /* do something */ }

        movements();
    }
}
```

Allowing mouse events to be repeatedly clicked (when holding on the mouse button)
```C++
// This allows mouse clicks to be repeated.
Events::setMouseRepeatEnabled(false);
```
