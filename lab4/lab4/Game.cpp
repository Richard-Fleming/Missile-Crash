/// <summary>
/// Author Richard Fleming C0021212 6/12/2018
/// ---------------------------------------------------------
/// Missile Command project using vector maths for collision
/// ---------------------------------------------------------
/// Estimated Time: 8 hours		Actual Time:
/// Session One Start: 9:30		Session One End: 11:00
/// Session Two Start: 6:00AM (10/12/18)		Session Two End: 7:30AM (10/12/18)
/// Session Three Start: 5:30PM (10/12/18)
/// Known Bugs:
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
	if (m_exitGame)
	{
		m_window.close();
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
	m_window.draw(m_laser);
	m_window.draw(m_asteroid);
	m_window.display();
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
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{

}

void Game::processMouseEvents(sf::Event t_mouseEvent)		// draws the laser being fired
{
	sf::Vertex laserBase{};			// start point of laser at the bunker
	sf::Vertex laserEnd{};		// end point of laser
	sf::Vector2f laserStart{};		// location of the base of the laser
	sf::Vector2f laserClick{};		// location of the mouse click and start of the laser

	if (sf::Mouse::Left == t_mouseEvent.mouseButton.button)
	{
		if (m_startClick == true)
		{
			m_laser.clear();			// reset the laser clear out the vertex array
			m_startClick = false;		// Resets the bool for the click so that it's ready to be used again
		}

		else if (m_startClick == false )		// The Click
		{
			laserClick = sf::Vector2f{ static_cast<float>(t_mouseEvent.mouseButton.x),static_cast<float>(t_mouseEvent.mouseButton.y) };// Sets the x and y co ordinates of the vector
			laserEnd = sf::Vertex{ sf::Vector2f{ laserClick } , sf::Color::White };		// Sets the color of the vector, and as a result half the laser
			m_laser.append(laserEnd);		// draws the laser

			laserStart = sf::Vector2f{ 410, 500 };		// Sets the x and y co ordinates of the vector to the bunker
			laserBase = sf::Vertex{ laserStart , sf::Color::Blue };		// Sets the color of the vector, and as a result half the laser
			m_laser.append(laserBase);		// draws the laser

			m_startClick = true;		// sets the first click to be true for future inputs
		}
	}
}

void Game::asteroid()
{
	sf::Vertex asteroidSpawn{};		// start point of the asteroid
	sf::Vertex asteroidEnd{};		// end point of the asteroid
	sf::Vector2f asteroidStart{};		// location of the asteroid's start point
	sf::Vector2f asteroidCrash{};		// location of where the asteroid lands
	int count = 0;		// the time between when the asteroid's start falling
	if (count == 0)
	{
		asteroidStart = sf::Vector2f{ 0,0 };		// sets the coordinates of the asteroid's start point
		asteroidSpawn = sf::Vertex{ asteroidStart, sf::Color::Red };		// sets the colour of half of the line drawn by the asteroid
		m_asteroid.append(asteroidStart);		// draws the asteroid

		asteroidCrash = sf::Vector2f{ 800, 400 };		// Sets the end coordinates of the asteroid
		asteroidEnd = sf::Vertex{ asteroidCrash , sf::Color::Yellow };		// sets the color of the other half of the line
		m_asteroid.append(asteroidEnd);		// draws the asteroid
		
	}
}