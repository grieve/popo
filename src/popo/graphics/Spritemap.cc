#include <popo/graphics/Spritemap.h>

popo::graphics::Spritemap::Spritemap(
	const std::string& asset,
	int tileWidth,
	int tileHeight
)
	: popo::graphics::Drawable(asset)
{
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
	_frameClips = std::vector<SDL_Rect>();
}

popo::graphics::Spritemap::~Spritemap(){

};


void popo::graphics::Spritemap::added(SDL_Renderer* renderer){
	popo::graphics::Drawable::added(renderer);
	int tilesetWidth;
	int tilesetHeight;

	SDL_QueryTexture(_texture, NULL, NULL, &tilesetWidth, &tilesetHeight);

	int idx = 0;

	for(int dY = 0; dY < tilesetHeight; dY += _tileHeight){
		for(int dX = 0; dX < tilesetWidth; dX += _tileWidth){
			_frameClips.push_back(SDL_Rect());
			_frameClips[idx].x = dX;
			_frameClips[idx].y = dY;
			_frameClips[idx].w = _tileWidth;
			_frameClips[idx].h = _tileHeight;
			idx++;
		}
	}
};


void popo::graphics::Spritemap::render(){
	SDL_Rect destination;
	destination.x = x;
	destination.y = y;
	destination.w = _tileWidth;
	destination.h = _tileHeight;

	SDL_RenderCopy(_renderer, _texture, &_frameClips[currentFrame], &destination);

};