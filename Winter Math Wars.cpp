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

    /*
    * Player Test
    */

    //Create a texture to hold a graphic on the GPU
    Texture textureZombie1;

    //Load the zombie graphic into the texture
    textureZombie1.loadFromFile("graphics/Zombie_Villager.png");

    //Create a sprite for the zombie
    Sprite spriteZombie1;

    //Attach the zombie sprite to the tree texture
    spriteZombie1.setTexture(textureZombie1);


    // Set the scale of the zombie sprite to scale it down
    float scaleX = 0.35f; 
    float scaleY = 0.35f; 
    spriteZombie1.setScale(scaleX, scaleY);

    // Set the scale to flip the zombie sprite horizontally
    //spriteZombie1.scale(-1.0f, 1.0f);

    //Set the position for the tree sprite
    spriteZombie1.setPosition(500, 300);

    // Main Game Loop
    while (window.isOpen()) {
        /*
        * *****Handle the players input*****
        */

        // If the player presses Escape - Window Close
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }


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

        // Draw the Zombie
        window.draw(spriteZombie1);

        // Show everything we just drew
        window.display();


    }
    return 0;

}
