#include <popo/core/InputManager.h>

popo::core::InputManager::InputManager(){
	
};

popo::core::InputManager::~InputManager(){
	
};

void popo::core::InputManager::handleKeypress(SDL_Event& event){
	if(event.key.state == SDL_PRESSED){
		std::cout << "PRESSED ";
	}
	if(event.key.state == SDL_RELEASED){
		std::cout << "RELEASED ";
	}

	std::cout << "SCAN: " << event.key.keysym.scancode << " ";
	std::cout << "SYM: " << event.key.keysym.sym << " ";
	std::cout << "MOD: " << event.key.keysym.mod << std::endl;
};