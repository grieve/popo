#ifndef POPO_INPUTMANAGER_H
#define POPO_INPUTMANAGER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace popo{
	namespace core{
		class InputManager;
	}
}

class popo::core::InputManager{
private:

public:

	InputManager();
	virtual ~InputManager();

	void handleKeypress(SDL_Event& event);
};

#endif // POPO_INPUTMANAGER_H