#include "GameObjectManager.h"



GameObjectManager::GameObjectManager()
{
	//(this->objID) = 0;
	gameObjects = (new std::vector<GameObject*>);
}


GameObjectManager::~GameObjectManager()
{
	for (int i = 0; i < gameObjects->capacity(); i++)
	{
		if (gameObjects->at(i) != NULL)
		{
			delete gameObjects->at(i);
		}
	}
	delete gameObjects;
}


GameObject* GameObjectManager::createGameObject(std::vector<Component*>* c)
{
	GameObject* temp = new GameObject(c, 0); //(this->objID));
	//(this->objID)++;

	gameObjects->push_back(temp);
	return temp;
}


GameObject* GameObjectManager::createGameObject(Component* c)
{
	GameObject* temp = new GameObject(c, 0);//(this->objID));
	//(this->objID)++;

	gameObjects->push_back(temp);
	return temp;

}