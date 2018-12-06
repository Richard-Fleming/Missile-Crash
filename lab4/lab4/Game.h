/// <summary>
/// Author Richard Fleming C0021212 6/12/2018
/// ---------------------------------------------------------
/// Missile Command project using vector maths for collision
/// ---------------------------------------------------------
/// Estimated Time: 5 hours		Actual Time:
/// Session One Start:		Session One End:
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

	sf::RenderWindow m_window;		// main SFML window
	sf::Font m_ArialBlackfont;		// font used by message
	sf::Text m_gameOverText;		// text used for message on screen
	bool m_gameOver;		// control the game over screen
	bool m_exitGame;		// control exiting game
	sf::RectangleShape m_ground;		// ground at the botom of he screen
	sf::RectangleShape m_bunker;		// bunker on top of the ground that the laser fires from
	sf::Vertex m_laser;		// laser being fired from the bunker

};

#endif // !GAME

