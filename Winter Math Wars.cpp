// include important libraries here

#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>

// Make code easier to type by using "using namespace"
using namespace sf;

// Snowball function declaration
void updateSnowballs(int seed); // Function Prototype

const int NUM_SNOWBALLS = 4;

Sprite snowballs[NUM_SNOWBALLS]; 

// Where is the Snowball?
// TOP, MIDDLE, BOTTOM or NONE

enum class side {TOP,MIDDLE,BOTTOM,NONE};
side snowballPositions[NUM_SNOWBALLS]; // we will have an array called snowballPositions with four values in it. Each of these values is of the side type and can be either TOP, MIDDLE, BOTTOM, or NONE.


int main()
{
    //Creating a video mode object
    VideoMode vm(960, 540);

    //Creating and opening a window for the game
    RenderWindow window(vm, "Winter Math Wars..!!!");
    View view(sf::FloatRect(0, 0, 1920, 1080));
    window.setView(view);

    // Tracking whether the game is running
    bool paused = true;

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
    * Player
    */

    //Create a texture to hold a graphic on the GPU
    Texture texturePlayer;

    //Load the zombie graphic into the texture
    texturePlayer.loadFromFile("graphics/Zombie_Villager.png");

    //Create a sprite for the zombie
    Sprite spritePlayer;

    //Attach the zombie sprite to the tree texture
    spritePlayer.setTexture(texturePlayer);


    // Set the scale of the zombie sprite to scale it down
    float scalePlayerX = 0.35f; 
    float scalePlayerY = 0.35f; 
    spritePlayer.setScale(scalePlayerX, scalePlayerX);

    // Set the scale to flip the zombie sprite horizontally
    //spriteZombie1.scale(-1.0f, 1.0f);

    //Set the position for the tree sprite
    spritePlayer.setPosition(100, 300);

    /*
   * Idle Snowman
   */
   
    Texture textureSnowman;

    //Load the zombie graphic into the texture
    textureSnowman.loadFromFile("graphics/snowman.png");

    // Create a Sprite for NPC
    Sprite spriteSnowman[2];

    for (int i = 0; i < 2; i++) {
        spriteSnowman[i].setTexture(textureSnowman);
    }

    // Set the scale of the NPC sprite to scale it down
    float scaleSnowmanX = 0.65f;
    float scaleSnowmanY = 0.65f;

    for (int i = 0; i < 2; i++) {
        spriteSnowman[i].setScale(scaleSnowmanX, scaleSnowmanY);
        //spriteSnowman[i].scale(-1.0f, 1.0f);
    }

    //Set the position for the tree sprite
    spriteSnowman[0].setPosition(100, 100);
    spriteSnowman[1].setPosition(100, 500);


    /*
    * NPC
    */

    // NPCs
    Texture textureNPC;

    //Load the zombie graphic into the texture
    textureNPC.loadFromFile("graphics/NPC.png");

    // Create a Sprite for NPC
    Sprite spriteNPCs[3];

    for (int i = 0; i < 3; i++) {
        spriteNPCs[i].setTexture(textureNPC);
    }

    // Set the scale of the NPC sprite to scale it down
    float scaleNPCX = 0.35f;
    float scaleNPCY = 0.35f;

    for (int i = 0; i < 3; i++) {
        spriteNPCs[i].setScale(scaleNPCX, scaleNPCY);
        spriteNPCs[i].scale(-1.0f, 1.0f);
    }

    //Set the position for the tree sprite
    spriteNPCs[0].setPosition(1800, 100);
    spriteNPCs[1].setPosition(1800, 300);
    spriteNPCs[2].setPosition(1800, 500);

    /*
    * Preparing Snowballs
    */

    Texture textureSnowball;

    textureSnowball.loadFromFile("graphics/snowball.png");

    // Setting up textures for each snowball
    for (int i = 0; i < NUM_SNOWBALLS; i++)
    {
        snowballs[i].setTexture(textureSnowball);
        snowballs[i].setPosition(-2000, 2000);
    }


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

        // Starting the game
        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            // Setup code for pause score and time later
            paused = false;

            //Making Snowballs

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

        // Draw the Player
        window.draw(spritePlayer);

        // Draw the Snowman
        for (int i = 0; i < 2; i++) {
            window.draw(spriteSnowman[i]);
        }

        // Draw the NPCs
        for (int i = 0; i < 3; i++) {
            window.draw(spriteNPCs[i]);
        }

        // Show everything we just drew
        window.display();


    }
    return 0;

}
