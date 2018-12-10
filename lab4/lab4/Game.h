/// <summary>
/// Author Richard Fleming C0021212 6/12/2018
/// ---------------------------------------------------------
/// Missile Command project using vector maths for collision
/// ---------------------------------------------------------
/// Estimated Time: 5 hours		Actual Time:
/// Session One Start: 9:30		Session One End: 11:00
/// Session Two Start: 1:30 (8/12/18)		Session Two End:   (8/12/18)
/// Known Bugs:
/// </summary>
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "MyVector2.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	void setupShapes();
	void setupFontAndText();
	void setupSprite();
	void processMouseEvents(sf::Event t_mouseEvent);
	void asteroid();
	void laserMove();

	sf::RenderWindow m_window;		// main SFML window
	sf::Font m_ArialBlackfont;		// font used by message
	sf::Text m_gameOverText;		// text used for message on screen
	
	bool m_startClick = false;		// The bools used to differentiate the clicks
	bool m_gameOver;		// control the game over screen
	bool m_exitGame;		// control exiting game
	
	sf::RectangleShape m_ground;		// ground at the botom of he screen
	sf::RectangleShape m_bunker;		// bunker on top of the ground that the laser fires from
	sf::RectangleShape m_powerBar;		// power bar that controls the altitude of the laser shot
	
	sf::VertexArray m_laser{ sf::Lines };		// line being drawn from the bunker
	sf::Vector2f m_laserIncrement{};		// the amount the laser increments by
	sf::Vector2f m_laserVelocity{};		// the velocity of the laser
	sf::Vector2f m_laserCurrentPosition{};		// the laser's current position
	sf::Vertex laserBase{};			// start point of laser at the bunker
	sf::Vector2f laserStart{ 410, 500 };		// Sets the x and y co ordinates of the vector to the bunker
	sf::Vector2f laserClick{};		// location of the mouse click and start of the laser
	float laserSpeed = 4.0f;
	
	sf::VertexArray m_asteroid{ sf::Lines };		// line being drawn from the sky
	sf::Vector2f m_asteroidIncrement{};		// the amount the asteroid increments by
	sf::Vector2f m_asteroidVelocity{};		// the velocity of the laser
	sf::Vector2f m_asteroidCurrentPosition{};		// the laser's current position
	sf::Vertex asteroidBase{};			// start point of laser at the bunker
	sf::Vector2f asteroidStart{ 410, 500 };		// Sets the x and y co ordinates of the vector to the bunker
	sf::Vector2f asteroidClick{};		// location of the mouse click and start of the laser
	float asteroidSpeed = 3.0f;

	

};

#endif // !GAME

