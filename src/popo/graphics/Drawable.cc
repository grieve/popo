#include <popo/graphics/Drawable.h>

popo::graphics::Drawable::Drawable(
	const std::string& asset
){
	_source = asset;
};

popo::graphics::Drawable::~Drawable(){

};

void popo::graphics::Drawable::added(SDL_Renderer* renderer){

	_renderer = renderer;
	_texture = IMG_LoadTexture(_renderer, _source.c_str());

}

void popo::graphics::Drawable::render(){
	SDL_Rect destination;
	destination.x = x;
	destination.y = y;

	SDL_QueryTexture(_texture, NULL, NULL, &destination.w, &destination.h);
	SDL_RenderCopy(_renderer, _texture, NULL, &destination);
};

void popo::graphics::Drawable::update(){

};