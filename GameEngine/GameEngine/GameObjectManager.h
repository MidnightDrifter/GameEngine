#pragma once
#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "GameObject.h"
#include <vector>


#define STARTING_OBJECT_NUMBER 0


class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	GameObject* createGameObject(std::vector<Component*>* c);
	GameObject* createGameObject(Component* c);

	//void deleteGameObject(int ID);

private:

	//static int objID;
	std::vector<GameObject*> * gameObjects;


};

#endif