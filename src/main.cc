#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <popo/core/Engine.h>
#include <popo/graphics/Spritemap.h>

int main(int argc, char **argv){

	popo::core::Engine* engine = new popo::core::Engine("Title", 640, 480);
	popo::graphics::Spritemap* sprite = new popo::graphics::Spritemap("assets/gfx/tiles_fg_cave.bmp", 32, 32);

	engine->add(sprite);
	engine->start();
}