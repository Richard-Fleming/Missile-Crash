/// <summary>
/// Author Richard Fleming C0021212 6/12/2018
/// ---------------------------------------------------------
/// Missile Command project using vector maths for collision
/// ---------------------------------------------------------
/// Estimated Time: 8 hours		Actual Time: 7 hours 50 mins
/// Session One Start: 9:30		Session One End: 10:00
/// Session Two Start: 6:00AM (10/12/18)		Session Two End: 7:30AM (10/12/18)
/// Session Three Start: 5:30PM (10/12/18)		Session Three End: 8:50PM (10/12/18)
/// Session Four Start: 2:00AM		Session Four End: 4:30AM
/// Known Bugs: Unfinished
/// </summary>

#include "Game.h"
#include <iostream>


/// <summary>
/// default construcor
/// pass parameters fpr sfml window, setup m_exitGame
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Missile Crash" },
	m_exitGame{ false },		//when true game will exit

	m_ground{ sf::Vector2f{ 800 , 100 } },
	m_bunker{sf::Vector2f{70 , 50}},
	m_powerBar{sf::Vector2f{200 , 25} }


{
	setupShapes();		// load ground shape and bunker shape
	setupFontAndText();		// load font 
	setupSprite();		// load texture
	asteroid();		// draws the asteroid
	explosion();		// sets up the explosion
}

/// <summary>
/// default destructor for game, nothing to release
/// </summary>
Game::~Game()
{
}


/// <summary>
/// game loop running at 60fps
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);		// 60 fps
	while (m_window.isOpen())
	{
		processEvents();		// as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();		// at least 60 fps
			update(timePerFrame);		//60 fps
		}
		render();		// as many as possible
	}
}



/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		srand(time(NULL));
		asteroid();
		if (sf::Event::Closed == event.type)		// window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)		//user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
		if (sf::Event::MouseButtonPressed == event.type)		// Proccesses keypresses
		{
			processMouseEvents(event);
		}
		
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	srand(time(NULL));
	asteroidMove();
	if (m_startClick == true)
	{
		laserMove();
	}
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_gameOverText.setFont(m_ArialBlackfont);
	m_gameOverText.setString("GAME OVER");
	m_gameOverText.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_gameOverText.setPosition(125.0f, 150.0f);
	m_gameOverText.setCharacterSize(80);
	m_gameOverText.setOutlineColor(sf::Color::Red);
	m_gameOverText.setFillColor(sf::Color::Black);
	m_gameOverText.setOutlineThickness(3.0f);

}

void Game::setupShapes()		// setup the shapes for the ground, the bunker and the power bar
{
	m_ground.setFillColor(sf::Color::Green);
	m_ground.setPosition(0, 500);

	m_bunker.setFillColor(sf::Color::Yellow);
	m_bunker.setPosition(375, 450);

	m_powerBar.setFillColor(sf::Color::Red);
	m_powerBar.setPosition(25, 550);

	m_explosion.setFillColor(sf::Color::Blue);
	m_explosion.setOrigin(explosionOriginX, explosionOriginY);
	m_explosion.setPosition(-100, -100);
	
	
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{

}

void Game::processMouseEvents(sf::Event t_mouseEvent)		// when you click the mouse
{
	if (sf::Mouse::Left == t_mouseEvent.mouseButton.button)
	{	
		if (m_startClick == false)
		{
			// Sets the x and y co ordinates of the vector
			laserClick = sf::Vector2f{ static_cast<float>(t_mouseEvent.mouseButton.x),static_cast<float>(t_mouseEvent.mouseButton.y) };
			laserBase = sf::Vertex{ laserStart , sf::Color::Blue };		// Sets the color of the vector, and as a result half the laser
			m_laserCurrentPosition = laserStart;
			m_startClick = true;		// sets the first click to be true for future inputs
		}
	}
}

void Game::laserMove()
{
	if (m_laserCurrentPosition.y >= laserClick.y)
	{
		m_laser.append(laserBase);		// draws the laser
		m_laserIncrement = laserClick - laserStart;		// calculates the distance between
		m_laserVelocity = vectorUnitVector(m_laserIncrement) * laserSpeed;		// finds and assigns the velocity of the laser
		m_laserCurrentPosition += m_laserVelocity;		// updates the position of the laser every frame
		m_laser.append( sf::Vertex(m_laserCurrentPosition, sf::Color::White));		// draws the laser
	}
	else
	{
		
		m_laser.clear();		// clears the laser
		m_explosion.setPosition(m_laserCurrentPosition);
		explosion();
		m_startClick = false;
		m_window.clear();
	}
}

void Game::asteroid()
{
	if (falling == false)
	{
		asteroidBase = sf::Vertex{ asteroidStart, sf::Color::Red };		// sets half the color of the vector
		m_asteroidCurrentPosition = asteroidStart;		// sets the initial position of the asteroid
		falling = true;
	}
}

void Game::asteroidMove()
{
	if (m_asteroidCurrentPosition.y <= asteroidCrash.y)
	{
		m_asteroid.append(asteroidBase);		// draws the asteroid
		m_asteroidIncrement = asteroidCrash - asteroidStart;		// calculates the distance between
		m_asteroidVelocity = vectorUnitVector(m_asteroidIncrement) * asteroidSpeed;		// finds and assigns the velocity of the asteroid
		m_asteroidCurrentPosition += m_asteroidVelocity;		// updates the position of the asteroid every frame
		m_asteroid.append(sf::Vertex(m_asteroidCurrentPosition, sf::Color::Yellow));		// draws the asteroid
	}
	else
	{
		falling = false;
		m_asteroid.clear();		// clears the asteroid once it crashes
	}
}

void Game::explosion()
{
	for (int i = 120; i >= 0; i--)
	{
		explosionRadius++;
		explosionOriginX++;
		explosionOriginY++;
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	//m_window.draw(m_gameOverText);

	m_window.draw(m_ground);
	m_window.draw(m_bunker);
	m_window.draw(m_powerBar);
	if (m_startClick == true)
	{
		m_window.draw(m_laser);
	}
	else
	{
		m_window.draw(m_explosion);
	}
	m_window.draw(m_asteroid);
	m_window.display();
}