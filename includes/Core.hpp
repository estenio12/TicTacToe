// ###########################
// #
// # @ Author: Estenio Garcia
// #
// # @ License: MIT
// #
// ###########################

#pragma once

#include <iostream>
#include <cstdint>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Timer.hpp"

class Core{

public:
	bool playerturn = true;
	int win, lose, tie;
	char table[9];

	bool endMatch = false;

	char currentTurn;

	// # Graphics Assets

	// # Scene Assets
	sf::Sprite background;
	sf::Sprite grid;
	sf::Sprite screen;
	sf::Texture bg_tex[ 6 ];
	sf::Texture sc_tex[ 3 ];
	sf::Texture grid_tex;
	int BG_Section = 1;

	// HUD
	sf::Sprite HUD;
	sf::Texture hud_tex;
	sf::Font font;
	sf::Text h_win;
	sf::Text h_lose;
	sf::Text h_tie;
	sf::Text h_current_player;

	// # Sound
	sf::SoundBuffer library[5];
	sf::Sound play;

	// # AI Variables
	int buttonID = 0;
	bool chooseButton = true;
	size_t countSpace;

public:
	Core();

	void EventHandle(int );
	void RestartMatch();
	void Render(sf::RenderWindow& );

	void AIBrain();

	uint16_t CheckWins();
};