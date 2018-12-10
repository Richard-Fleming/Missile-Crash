/// <summary>
/// Author Richard Fleming C0021212 6/12/2018
/// ---------------------------------------------------------
/// Missile Command project using vector maths for collision
/// ---------------------------------------------------------
/// Estimated Time: 8 hours		Actual Time:
/// Session One Start: 9:30		Session One End: 11:00
/// Session Two Start: 1:30 (8/12/18)		Session Two End:   (8/12/18)
/// Known Bugs:
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

#include "game.h"



/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	Game game;
	game.run();
	return 0;
}