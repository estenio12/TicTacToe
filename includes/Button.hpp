// ###########################
// #
// # @ Author: Estenio Garcia
// #
// # @ License: MIT
// #
// ###########################

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Timer.hpp"
#include "Core.hpp"

class Button{

public:
	sf::Sprite btnSpr;
	sf::Texture* btnTexs;
	
	int id = 0;
	bool locked = false;

	Core* core;


public:
	explicit Button(Core* );

	void SetSprite(sf::Texture* );
	void AddID(int ID);
	void SetLocation(sf::Vector2f);

	void Render(sf::RenderWindow& );
	void EventHandle(sf::RenderWindow& );

};