#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


namespace popo{
	namespace graphics{
	    class Drawable;
	}
}


class popo::graphics::Drawable {

protected:
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    std::string _source;


public:
    Drawable(const std::string& asset);
    virtual ~Drawable();

    virtual void added(SDL_Renderer* renderer);
    virtual void render();
    void update();


    int x = 0;

    int y = 0;

};

#endif // DRAWABLE_H