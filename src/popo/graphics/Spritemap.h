#ifndef POPO_SPRITEMAP_H
#define POPO_SPRITEMAP_H

#include <iostream>
#include <vector>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <popo/graphics/Drawable.h>


namespace popo{
	namespace graphics{
	    class Drawable;
	    class Spritemap;
	}
}

class popo::graphics::Spritemap: public Drawable {

private:

	int _tileWidth;
	int _tileHeight;

	std::vector<SDL_Rect> _frameClips;

public:

	Spritemap(
		const std::string& asset,
		int tileWidth,
		int tileHeight
	);

	virtual ~Spritemap();

    virtual void added(SDL_Renderer* renderer);
    virtual void render();


    int currentFrame = 0;
};


#endif // POPO_SPRITEMAP_H