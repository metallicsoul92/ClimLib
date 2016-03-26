#pragma once

#include <iostream>

#include <vector>



namespace clim
{
	namespace core
	{

		class Component;
		class ComponentMessageHandler;

		/*! \brief clim::core::Entity
		Class Entity is the objects in the game, this could act as
		an NPC, a Player, Monster, or even warps, scripts,etc.
		If parent is equal to null, Then it will be the scene object.
		Each entity will be attached to it.
		They have a name, id, list of components and messageHandler 
		
		TODO: IMPLEMENT COMPONENTMESSAGEHANDLER


		!*/

		class Entity
		{
			/*!
			Type defines:
			Component list and entity list and the iterators to them
			!*/
			typedef std::vector<Component*> component_List;
			typedef component_List::iterator component_Itr;
			typedef component_List::const_iterator component_Const_Itr;

			typedef std::vector<Entity*> entity_List;
			typedef entity_List::iterator entity_Itr;
			typedef entity_List::const_iterator entity_Const_Itr;

		protected:
			int m_id;
			std::string m_Name;
			component_List listOfComponents;

			entity_List m_children;
			Entity* m_parent;
			/*when you have the ability via boost, add a serialization file or object to send to a file*/


		public:
			/*! 
				Getter and setter method for name
			*/
			void setName(std::string name);
			std::string getName();

			/*!
				addComponent function will take a component and attach it to the current object.

			*/
			void addComponent(Component* component);

			std::vector<Component*> getComponentList();

			Component* getComponent(std::string name);

			/*!
				Clears the object of all components in the list;
			*/
			void clear();
			/*!
				Since each id of a component will be similar to each object, i can use an integer to find a component in an entity.
				This function searches the component list and looks for the id of the integer passed in and returns true if found.
			*/
			bool hasComponent(int id);

			/*! 
				Entities can be constructed by default, or through multiple parameters, you can even create a component list, and then attach it during construction.
			*/
			Entity();
			/*!
				This constructor creates a new entity, with the name "Default" and passes the id to the objects id variable;
			*/
			Entity(int id);

			/*!
			I guess with this i will have to call parent, if parent is equal to null, i set the object as a scene-object, and create the m_id of 0
			It will then use the name to be passed into the name of the object, and given a null list of components.
			*/
			Entity(std::string name);
			/*!
			This constructor adds a null list of components to be add in later.
			*/
			Entity(int id, std::string name);
			/*!
			You can add an id, name, and component list through this constructor.
			*/
			Entity(int id, std::string name, component_List* cmplst);


			virtual ~Entity();

			/*!
			I was honestly just messing around with dynamic casting with this function, This is kinda similar to Unity's game-object handling system.
				searches the component list for the t component ( since all components are derived from the class Component, the Component list handles all extended classes)
				returns the type , if not returns null
			*/
			template <typename T>
			T* findComponentType()
			{
                for(unsigned int x = 0; x < listOfComponents.size();x++){
					//for (component_Itr itr = listOfComponents.begin(); itr != listOfComponents.end(), ++itr){
                    if (T* type = dynamic_cast<T*>(listOfComponents.at(x)))
					{
						return type;
					}

				}
					return nullptr;
			}

			/*! 
			Adds a child entity, and assigns the child's parent to this class.
			*/
			void addChild(Entity* child);

			/*! 
			Returns the pointer to the entity you are trying to find in the child list
			*/
			Entity* findChildByName(std::string name);

			/*!
			Returns a vector of pointers to entities with the same name in the child list;
			*/
			std::vector<Entity*> findAllChildrenByName(std::string name);
		};
	}
}
