
#ifndef EngineTesting_Component_h
#define EngineTesting_Component_h

#include <typeinfo>
#include <iostream>

class Transform;
class GameObject;
class System;

class Component
{
	friend class GameObject;
	friend class System;
	friend class Engine;
public:
    int priority;
	virtual void Create(){};
	virtual void Init(){};
	virtual void Update(){};
	virtual bool isEnabled() const;
	GameObject*const getGameObject() const;
	Transform*const getTransform() const;
protected:
	virtual ~Component()
	{
		std::cout << "~~~~~~~~~~~~~ Component: " << std::endl;
	};
	System* system;
private:
	GameObject* gameObject;
	Transform* transform;

friend std::ostream& operator << (std::ostream& stream, const Component& obj);
};

inline std::ostream& operator << (std::ostream& stream, const Component& obj)
{
	return stream << typeid(&obj).name() << " Component(" << obj.isEnabled() << ")" << std::endl;
}

inline bool Component::isEnabled() const
{ 
	return true; 
}

inline GameObject*const Component::getGameObject() const
{
	return gameObject;
}

inline Transform*const Component::getTransform() const
{
	return transform;
}

#endif