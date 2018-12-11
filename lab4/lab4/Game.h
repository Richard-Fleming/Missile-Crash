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
	void laserMove();
	void asteroid();
	void asteroidMove();
	void explosion();

	sf::RenderWindow m_window;		// main SFML window
	sf::Font m_ArialBlackfont;		// font used by message
	sf::Text m_gameOverText;		// text used for message on screen
	
	bool falling = false;		// used to check if the asteroid is falling or not
	bool m_startClick = false;		// The bool used to check wether or not the asteroid is falling
	bool m_gameOver;		// control the game over screen
	bool m_exitGame;		// control exiting game
	
	sf::RectangleShape m_ground;		// ground at the botom of he screen
	sf::RectangleShape m_bunker;		// bunker on top of the ground that the laser fires from
	sf::RectangleShape m_powerBar;		// power bar that controls the altitude of the laser shot
	
	int explosionRadius = 20;		// radius of the explosion
	sf::CircleShape m_explosion{explosionRadius};		// explosion that is drawn at the end of the laser
	int explosionOriginX = 20;		// origin coordinates for the circle
	int explosionOriginY = 20;		// origin coordinates for the circle
	

	sf::VertexArray m_laser{ sf::Lines };		// line being drawn from the bunker
	sf::Vector2f m_laserIncrement{};		// the amount the laser increments by
	sf::Vector2f m_laserVelocity{};		// the velocity of the laser
	sf::Vector2f m_laserCurrentPosition{};		// the laser's current position
	sf::Vertex laserBase{};			// start point of laser at the bunker
	sf::Vector2f laserStart{ 410, 500 };		// Sets the x and y co ordinates of the vector to the bunker
	sf::Vector2f laserClick{};		// location of the mouse click and start of the laser
	float laserSpeed = 4.0f;		// speed of the laser
	
	sf::VertexArray m_asteroid{ sf::Lines };		// line being drawn from the sky
	sf::Vector2f m_asteroidIncrement{};		// the amount the asteroid increments by
	sf::Vector2f m_asteroidVelocity{};		// the velocity of the asteroid
	sf::Vector2f m_asteroidCurrentPosition{};		// the asteroid's current position
	sf::Vertex asteroidBase{};			// start point of asteroid in the sky
	sf::Vector2f asteroidStart{ rand() % 800, 0 };		// Sets the x and y co ordinates of the vector to a place in the sky
	sf::Vector2f asteroidCrash{rand() % 800 , 500};		// location of where the asteroid is going to crash
	float asteroidSpeed = 3.0f;		// seed of the asteroid

	

};

#endif // !GAME

