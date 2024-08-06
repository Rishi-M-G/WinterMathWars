// include important libraries here

#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

// Make code easier to type by using "using namespace"
using namespace sf;

int main()
{
    //Creating a video mode object
    VideoMode vm(960, 540);

    //Creating and opening a window for the game
    RenderWindow window(vm, "Winter Math Wars..!!!");
    View view(sf::FloatRect(0, 0, 1920, 1080));
    window.setView(view);

    /*
    * Background
    */

    //Create a texture to hold a graphic on the GPU
    Texture textureBackground;

    //Load a graphic into the texture
    textureBackground.loadFromFile("graphics/background.png");

    //Creating a sprite for background;
    Sprite spriteBackground;

    // Attaching background sprite to its texture
    spriteBackground.setTexture(textureBackground);

    // Set the sprite background to cover the screen
    spriteBackground.setPosition(0, 0);

    // Main Game Loop
    while (window.isOpen()) {
        /*
        * *****Handle the players input*****
        */


        /*
        * *****Update the scene*****
        */

        /*
        * *****Draw the scene*****
        */

        //Clear everything from the last frame
        window.clear();

        //Draw our game scene here
        window.draw(spriteBackground);

        // Show everything we just drew
        window.display();


    }
    return 0;

}
