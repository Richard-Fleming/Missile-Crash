// author Peter Lowe
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

	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window;		// main SFML window
	sf::Font m_ArialBlackfont;		// font used by message
	sf::Text m_gameOverText;		// text used for message on screen
	bool m_gameOver;		// control the game over screen
	bool m_exitGame;		// control exiting game

};

#endif // !GAME

