/// <summary>
/// Author Richard Fleming C0021212 6/12/2018
/// ---------------------------------------------------------
/// Missile Command project using vector maths for collision
/// ---------------------------------------------------------
/// Estimated Time: 5 hours		Actual Time:
/// Session One Start:		Session One End:
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
	m_bunker{sf::Vector2f{50 , 50}}

{
	setupShapes();		// load ground shape and bunker shape
	setupFontAndText();		// load font 
	setupSprite();		// load texture
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
	m_window.draw(m_ground);
	m_window.draw(m_bunker);
	m_window.draw(m_gameOverText);
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

void Game::setupShapes()		// setup the shapes for the ground and the bunker
{
	m_ground.setFillColor(sf::Color::Green);
	m_ground.setPosition(0, 500);

	m_bunker.setFillColor(sf::Color::Yellow);
	m_bunker.setPosition(375, 450);
}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{

}
