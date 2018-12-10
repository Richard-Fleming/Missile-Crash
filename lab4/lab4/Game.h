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

	sf::RenderWindow m_window;		// main SFML window
	sf::Font m_ArialBlackfont;		// font used by message
	sf::Text m_gameOverText;		// text used for message on screen
	
	bool m_startClick{ false };		// The bools used to differentiate the clicks
	bool m_endClick{ false };		// The bools used to differentiate the clicks
	bool m_gameOver;		// control the game over screen
	bool m_exitGame;		// control exiting game
	
	sf::RectangleShape m_ground;		// ground at the botom of he screen
	sf::RectangleShape m_bunker;		// bunker on top of the ground that the laser fires from

	sf::RectangleShape m_powerBar;		// power bar that controls the altitude of the laser shot
	
	sf::Vector2i m_mouseClick{ 0,0 };		// location of the mouse click and end point of the laser 
	sf::Vector2i m_baseShot{ 375,450 };		// location of the start point of the laser
	sf::VertexArray m_laser{ sf::Lines };		// line being drawn from the bunker
	
	sf::Vector2i m_asteroidEntry{ 0,0 };		// location of the start point of the asteroid
	sf::Vector2i m_asteroidCrash{ 800, 400 };		// location of the end point of the asteroid
	sf::VertexArray m_asteroid{ sf::Lines };		// the line being from the top of the screen(the asteroid)

};

#endif // !GAME

