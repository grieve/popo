#ifndef POPO_ENGINE_H
#define POPO_ENGINE_H

#include <vector>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <popo/core/InputManager.h>
#include <popo/graphics/Drawable.h>
#include <popo/graphics/Spritemap.h>

typedef std::vector<popo::graphics::Drawable*> RenderList;

namespace popo {
	namespace core{
		class Engine;
	}
};

class popo::core::Engine {

private:
	void _handleEvents();
	void _bindInputs();

	RenderList _renderList;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	std::ostream& _logger = std::cout;

public:
	
	Engine(
		const std::string& title = "POPO Game Engine",
		int width = 640,
		int height = 480
	);

	virtual ~Engine();

	void render();
	void update();

	void start();
	void stop();

	void add(popo::graphics::Drawable* child);

	void log(const std::string& msg);
	void logSDL(const std::string& msg);

	InputManager input;
};

#endif // POPO_ENGINE_H