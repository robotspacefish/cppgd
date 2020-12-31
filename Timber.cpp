#include <sstream>
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

   // track whether the game is running
   bool paused = true;

   // draw some text 
   int score = 0;

   sf::Text messageText;
   sf::Text scoreText;

   // choose font 
   sf::Font font;
   font.loadFromFile("fonts/KOMIKAP_.ttf");

   // set font to our message 
   messageText.setFont(font);
   scoreText.setFont(font);

   // assign the actual message 
   messageText.setString("Press Enter to start!");
   scoreText.setString("Score = 0");

   // increase font size
   messageText.setCharacterSize(75);
   scoreText.setCharacterSize(100);

   // choose color 
   messageText.setFillColor(sf::Color::White);
   scoreText.setFillColor(sf::Color::White);

   // position the text
   sf::FloatRect textRect = messageText.getLocalBounds();

   messageText.setOrigin(
       textRect.left + textRect.width / 2.0f,
       textRect.top + textRect.height / 2.0f
   );

   messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

   scoreText.setPosition(20, 20);

   while (window.isOpen())
    {

        /** Handle Player Input */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        // start the game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            paused = false;

        if (!paused)
        {
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
            else
            {
                // move the bee
                spriteBee.setPosition(
                    spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                    spriteBee.getPosition().y
                );

                // has the bee reached the right hand edge of the screen?
                if (spriteBee.getPosition().x < -100)
                {
                    // set it up to be ready to be a whole new bee next frame 
                    beeActive = false;
                }
            }

            // manage the clouds 
            // cloud 1
            if (!cloud1Active)
            {
                // how fast is the cloud 
                srand((int)time(0) * 10);
                cloud1Speed = (rand() % 200);

                // how high is the cloud
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                spriteCloud1.setPosition(-200, height);
                cloud1Active = true;
            }
            else
            {
                spriteCloud1.setPosition(
                    spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
                    spriteCloud1.getPosition().y
                );

                // has the cloud reached the right hand edge of the screen?
                if (spriteCloud1.getPosition().x > 1920)
                {
                    // set it up ready to be a whole new cloud next frame 
                    cloud1Active = false;
                }
            }

            // cloud 2
            if (!cloud2Active)
            {
                // how fast is the cloud 
                srand((int)time(0) * 20);
                cloud2Speed = (rand() % 200);

                // how high is the cloud
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                spriteCloud2.setPosition(-200, height);
                cloud2Active = true;
            }
            else
            {
                spriteCloud2.setPosition(
                    spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()),
                    spriteCloud2.getPosition().y
                );

                // has the cloud reached the right hand edge of the screen?
                if (spriteCloud2.getPosition().x > 1920)
                {
                    // set it up ready to be a whole new cloud next frame 
                    cloud2Active = false;
                }
            }

            // cloud 3
            if (!cloud3Active)
            {
                // how fast is the cloud 
                srand((int)time(0) * 30);
                cloud3Speed = (rand() % 200);

                // how high is the cloud
                srand((int)time(0) * 30);
                float height = (rand() % 450) - 150;
                spriteCloud3.setPosition(-200, height);
                cloud3Active = true;
            }
            else
            {
                spriteCloud3.setPosition(
                    spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()),
                    spriteCloud3.getPosition().y
                );

                // has the cloud reached the right hand edge of the screen?
                if (spriteCloud3.getPosition().x > 1920)
                {
                    // set it up ready to be a whole new cloud next frame 
                    cloud3Active = false;
                }
            }

            // update the score text
            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());

        } // end if(!paused)

        

        /** Draw Scene */
        window.clear();

        // Draw
        window.draw(spriteBackground);

        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        window.draw(spriteTree);

        window.draw(spriteBee);

        window.draw(scoreText);

        if (paused)
            window.draw(messageText);

        // Show everything we just drew
        window.display();

    }

    return 0;
}