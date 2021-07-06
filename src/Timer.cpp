#include "../includes/Timer.hpp"

bool Timer::Delay(float duration){

	end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> bruteDelta = end - start;

	deltaTime = bruteDelta.count();

	if( timer_runner >= duration ){

		timer_runner = 0;
		deltaTime = 0;
		return true;
	}

	start = end;
	timer_runner += deltaTime;

	return false;

}