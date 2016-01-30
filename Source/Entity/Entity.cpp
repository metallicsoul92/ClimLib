#include "..\Include\Entity.h"
#include "..\Include\Component.h"
#include "..\Include\Logger.h"

#include <iostream>


namespace clim{
	namespace core{

		void Entity::setName(std::string name){
			m_Name = name;
		}
		std::string Entity::getName(){

			return m_Name;
		}



		void Entity::addComponent(Component *component){
			
			listOfComponents.push_back(component);
		}
	
		std::vector<Component*> Entity::getComponentList(){
		return listOfComponents;
	}
	Component* Entity::getComponent(std::string name){
		for each (Component *c in listOfComponents)
		{
			if (c->getName() == name){
				return c;
			}
		}
		
				return nullptr;

			
		}
	void Entity::clear(){
		if (this->listOfComponents.size() != NULL){
			listOfComponents.clear();
		}
	}
	bool Entity::hasComponent(int id){
		for each (Component *c in listOfComponents){
			if (c->getId() == id){
				return true;
			}

		}
		return false;
	}


	Entity::Entity()
		{
			//////
			//TODO: FIX THIS
			//////
			m_id = 0;
			m_parent = nullptr;

		}
	Entity::Entity(int id) : m_id(id) {

		m_parent = nullptr;
	}
	Entity::Entity(std::string name) : m_Name(name), m_parent(nullptr) {
		
		//////
		//TODO: FIX THIS
		//////
		m_id = 0;
		}
	Entity::Entity(int id, std::string name) : m_id(id), m_Name(name), m_parent(nullptr){  }
	Entity::Entity(int id, std::string name, component_List *cmplst) : m_id(id), m_Name(name), listOfComponents(*cmplst), m_parent(nullptr){  };

	Entity::~Entity()
	{
	
	}

	void Entity::addChild(Entity* child){
		if (child != nullptr){
			this->m_children.push_back(child);
		}
		else{
			std::string childName;
			childName = child->getName();
			system::logger.writeToGELog("Entity is equal to null pointer. Name: " + childName );
		}
	}

	Entity* Entity::findChildByName(std::string name){

		for each(Entity* e in m_children){
			if (e->getName() == name){
				return e;
			}
		}
		return nullptr;
	}

	std::vector<Entity*> Entity::findAllChildrenByName(std::string name){

		std::vector<Entity*> temp;

		for each(Entity* e in m_children){
			if (e->getName() == name){
				temp.push_back(e);
			}
		}
			return temp;
	}

	}
}