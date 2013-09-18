#include <popo/core/InputManager.h>

popo::core::InputManager::InputManager(){
	_eventTypeMap = EventTypeMap();
	_actionNameMap = ActionNameMap();
};

popo::core::InputManager::~InputManager(){
	
};

void popo::core::InputManager::addListener(int eventType, int code, std::string& action){

	if(_actionNameMap[action]){
		addListener(eventType, code, _actionNameMap[action]);
	}

};

void popo::core::InputManager::addListener(int eventType, int code, ActionFunc callback){

	try{
		_eventTypeMap.at(eventType);
	} catch(const std::out_of_range& err){
		_eventTypeMap[eventType] = EventCodeMap();
	};

	_eventTypeMap[eventType][code] = callback;

};

void popo::core::InputManager::addAction(std::string& name, ActionFunc callback){

	_actionNameMap[name] = callback;

}

void popo::core::InputManager::handleKeypress(SDL_Event& event){

	int code;

	if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{
		code = event.key.keysym.sym;
		std::cout << "SYM: " << code << std::endl;
	}

	try {

		_eventTypeMap.at(event.type).at(code)(&event);

	} catch(const std::out_of_range& err){

		return;

	}

};