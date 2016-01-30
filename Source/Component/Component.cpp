#include "..\Include\Component.h"
#include "..\Include\Entity.h"

namespace clim{
	namespace core{
		void Component::Enable()
		{
			this->active = true;
		}

		void Component::setID(int id){
			m_id = id;
		}
		
		int Component::getId(){
			return m_id;
		}
		
		std::string Component::getName(){
			return m_name;
		}
		
		void Component::setName(std::string name){
			m_name = name;
		}
		
		void Component::SetParent(Entity parent){
			this->parent = &parent;
		}
		
		Entity* Component::getParent(){
			return parent;
		}



		Component::Component(){
			this->m_id = 0;
			this->m_name = "Default Component " + m_id;
			this->parent = nullptr;
			this->active = true;
		
		
		}
		
		Component::Component(std::string name) : m_name(name){
			this->m_id = 0;
			this->parent = nullptr;
			this->active = true;
		
		}
		
		Component::Component(int id) : m_id(id){
			this->m_name = "Default Component " + m_id;
			this->parent = nullptr;
			this->active = true;
		
		}
		
		Component::Component(std::string name, int id) : m_id(id), m_name(name){
			
			this->active = true;
		    this->parent = nullptr;
		}
		
		Component::Component(Entity *parent) : parent(parent){
			this->m_name = "Default Component";
			this->m_id = 0;
			parent->addComponent(this);
			this->active = true;
		
		}
		
		Component::Component(std::string name, Entity *parent) : m_name(name), parent(parent){
			this->m_id = 0;
			parent->addComponent(this);
			this->active = true;
		
		}
		
		Component::Component(int id, Entity *parent): m_id(id), parent(parent){
			this->m_name = "Default Component";
			parent->addComponent(this);
			this->active = true;
		
		}
		
		Component::Component(int id, std::string name, Entity *parent): m_id(id),m_name(name),parent(parent){
			parent->addComponent(this);
			this->active = true;
	
		}

		Component::~Component(){

		}


		void Component::Awake(){
		
		}
		void Component::Destroy(){
		
		}
		void Component::Start(){
		
		}
		void Component::FixUpdate(){
		
		}
		void Component::Update(){
		
		}
		void Component::LateUpdate(){
		
		}




	}
}