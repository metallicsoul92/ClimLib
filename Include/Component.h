#pragma once
#include <iostream>




namespace clim{
	namespace core{

		class Entity;

		/*!
		The Component class is the base class of all Components, it serves as a general purpose base class.
		*/
		class Component 
		{

        protected:
			int m_id;
			std::string m_name;
            Entity *m_parent;
            bool m_active;


		public:



			/*!
				Returns whether the component is enabled or not
			*/

			bool isEnabled()
			{
                return m_active;
			}

			/*!
				Enables the current component
			*/

			void Enable();
			
			/*!
				Sets the id of the current component
			*/

            void setID(int id);
			
			/*!
				Returns component id
			*/

			int getId();
			
			/*!
				Returns the name of the component
			*/

			std::string getName();
			
			/*!
				Sets the name of the component
			*/
			
			void setName(std::string name);
			
			/*!
				Sets the parent of the component
			*/
			
            void SetParent(Entity &parent);
			
			/*!
				Returns a pointer to the parent of the object
			*/
			
			Entity *getParent();

			/*!
				Default constructor, finds the parent of the object, sets the m_id to the current count plus one, and sets the name to Default.
			*/
		

			Component();
			
			/*!
				Creates a component with a name, and finds the count of the current amount of objects, and adds one, and sets id to that.
			*/
			
			Component(std::string name);
			
			/**
				Creates a component with an id, and sets name to "Default Component"
			*/
			
			Component(int id);
		
			/*
				Sets the name and the id of the component.
			*/
			
			Component(std::string name, int id);
			
			/*! 
				Finds the count of the parent, sets the id to that, attaches the component to the parent, and sets the name to "Default"
			*/
			
            Component(Entity *parent);
			
			/*!
				Finds the count of the parent, sets the id to that, attaches the component to the parent, and sets the name
			*/
			
            Component(std::string name, Entity *parent);
			
			/*!
				Sets the id and attaches the component to a parent.
			*/
			
            Component(int id, Entity *parent);
			
			/*!
				Sets the name, id, and attaches the component to the parent.
			*/
			
            Component(int id, std::string name, Entity *parent);

			
			/*!
			VIRTUAL:
				Set enabled to true, and do initializing functions.
			*/
			
			virtual void Awake();
			
			/*!
			VIRTUAL:
				Frees memory, and safetly deletes the component, and sets the pointer from the parent to null.
				
			*/
			
			virtual void Destroy();
			
			/*!
			VIRTUAL:
				start Awake() and then begin the function's beginning functions.
			*/
			
			virtual void Start();
			
			/*!
			VIRTUAL:
				Will use once i start tweaking with optimization
			*/
			
			virtual void FixUpdate();
			
			/*!
			VIRTUAL
				Update All Components to be used accordingly
			*/
			
			virtual void Update();
			
			/*!
			VIRTUAL
				Will use once i start tweaking with optimization
			*/
			
			virtual void LateUpdate();


			virtual ~Component();
		};

	}
}
