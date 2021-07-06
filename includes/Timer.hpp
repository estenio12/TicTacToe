// ###########################
// #
// # @ Author: Estenio Garcia
// #
// # @ License: MIT
// #
// ###########################

#pragma once

#include <iostream>
#include <chrono>

namespace Timer{

	// Variables
	static std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	static std::chrono::high_resolution_clock::time_point end;
	static float timer_runner = 0;
	static float deltaTime = 0;

	// # Functions
	bool Delay(float duration);
}