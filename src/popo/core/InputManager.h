#ifndef POPO_INPUTMANAGER_H
#define POPO_INPUTMANAGER_H

#include <iostream>
#include <stdexcept>
#include <map>
#include <functional>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef std::function<void(SDL_Event*)> ActionFunc;
typedef std::map<std::string, ActionFunc> ActionNameMap;
typedef std::map<int, ActionFunc> EventCodeMap;
typedef std::map<int, EventCodeMap> EventTypeMap;

namespace popo{
	namespace core{
		class InputManager;
	}
}

class popo::core::InputManager{
private:

	EventTypeMap _eventTypeMap;
	ActionNameMap _actionNameMap;

public:

	InputManager();
	virtual ~InputManager();

	void addListener(int eventType, int code, std::string& action);
	void addListener(int eventType, int code, ActionFunc callback);

	void addAction(std::string& name, ActionFunc callback);

	void handleKeypress(SDL_Event& event);
};

#endif // POPO_INPUTMANAGER_H