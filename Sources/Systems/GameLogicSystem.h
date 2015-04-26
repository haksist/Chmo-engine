
#ifndef EngineTesting_GameLogicSystem_h
#define EngineTesting_GameLogicSystem_h

#include <vector>
#include "../CoreEngine/GameLogic.h"
#include "../CoreEngine/System.h"

class GameLogicSystem:public System
{
private:
	std::vector<GameLogic*> components;
public:
    ~GameLogicSystem();
    void Init();
    void Update();
    void addComponent(Component &c);
	void removeComponent(Component &c);
	bool isSystemComponent(Component &c);
};

#endif
