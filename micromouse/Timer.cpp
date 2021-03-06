#include "Timer.h"

#ifdef __MK20DX256__ // Teensy Compile
	#include "Arduino.h"
#endif

namespace Micromouse
{
	Timer::Timer()
	{
		start();
	}



	void Timer::start()
	{
		lastMicros = micros();
	}



	float Timer::getDeltaTime()
	{
		long currentTime = micros();
		float deltaTime = (currentTime - lastMicros) / 1000000.0f;
		lastMicros = currentTime;

		return deltaTime;
	}



#ifdef __MK20DX256__ // Teensy Compile
#else // PC compile
	long Timer::micros()
	{
		using namespace std::chrono;

		return duration_cast<microseconds>(high_resolution_clock::now() - initialTime).count();
	}
#endif
}