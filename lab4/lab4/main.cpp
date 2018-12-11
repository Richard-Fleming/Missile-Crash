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