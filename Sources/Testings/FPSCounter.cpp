#ifndef FPSCOUNTER_CPP
#define FPSCOUNTER_CPP

#include "../CoreEngine/GameLogic.h"
#include "../Systems/GameTime.h"

#include <iostream>

class FPSCounter : public GameLogic
{
	GLfloat time = 0;
	int frames = 0;
public:
	void Update()
	{
		time += GameTime::DeltaTime();
		frames++;
		if (time >= 1)
		{
			std::cout << "FPS:" << frames << std::endl;
			frames = 0;
			time = 0;
		}
	}

	void OnEnable()
	{
		std::cout << "FPSCounter: OnEnable" << std::endl;
	}

	void OnDisable()
	{
		std::cout << "FPSCounter: OnDisable" << std::endl;
	}
};
#endif