#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // create a video mode object
    sf::VideoMode vm(1920, 1080);

    // create and open a window for the game 
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);

    // create a texture to hold a graphic on the GPU
    sf::Texture textureBackground;

    // load a graphic into the texture 
    textureBackground.loadFromFile("graphics/background.png");

    // create a sprite 
    sf::Sprite spriteBackground;

    // attach the texture to the sprite 
    spriteBackground.setTexture(textureBackground);

    // set the spriteBackground to cover the screen
    spriteBackground.setPosition(0, 0);

    // make a tree sprite
   sf::Texture textureTree;
   textureTree.loadFromFile("graphics/tree.png");
   sf::Sprite spriteTree;
   spriteTree.setTexture(textureTree);
   spriteTree.setPosition(810, 0);

   // prepare a bee sprite
   sf::Texture textureBee;
   textureBee.loadFromFile("graphics/bee.png");
   sf::Sprite spriteBee;
   spriteBee.setTexture(textureBee);
   spriteBee.setPosition(0, 800);

   // is bee currently moving?
   bool beeActive = false;

   // how fast can the bee fly
   float beeSpeed = 0.0f;
 
   // make 3 cloud sprites from 1 texture
   sf::Texture textureCloud;

   // load 1 new texture 
   textureCloud.loadFromFile("graphics/cloud.png");

   // 3 new sprites with the same texture 
   sf::Sprite spriteCloud1;
   sf::Sprite spriteCloud2;
   sf::Sprite spriteCloud3;
   spriteCloud1.setTexture(textureCloud);
   spriteCloud2.setTexture(textureCloud);
   spriteCloud3.setTexture(textureCloud);


   // position the clouds off screen 
   spriteCloud1.setPosition(0, 0);
   spriteCloud2.setPosition(0, 250);
   spriteCloud3.setPosition(0, 500);

   // are the clouds currently on screen?
   bool cloud1Active = false;
   bool cloud2Active = false;
   bool cloud3Active = false;
    
   // how fast is each cloud?
   float cloud1Speed = 0.0f;
   float cloud2Speed = 0.0f;
   float cloud3Speed = 0.0f;

    // variables to control time itself
   sf::Clock clock;

   while (window.isOpen())
    {
        /** Handle Player Input */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        /** Update Scene */
        sf::Time dt = clock.restart();

        // setup the bee
        if (!beeActive)
        {
            // how fast is the bee 
            srand((int)time(0));

            // generate random number between 199 and 399
            beeSpeed = (rand() % 200) + 200;

            // how high is the bee
            srand((int)time(0) * 10);

            // generate random number between 499 and 999
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(2000, height);
            beeActive = true;
        }

        /** Draw Scene */
        window.clear();

        // Draw
        window.draw(spriteBackground);

        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        window.draw(spriteTree);

        window.draw(spriteBee);

        // Show everything we just drew
        window.display();

    }

    return 0;
}