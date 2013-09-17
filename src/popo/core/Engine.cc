#include <popo/core/Engine.h>

popo::core::Engine::Engine(
	const std::string& title,
	int width,
	int height
){

	_renderList = RenderList();
	input = InputManager();

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		logSDL("Init SDL");
		exit(1);
	}

	_window = SDL_CreateWindow("Hello World!", 0, 0, width, height, SDL_WINDOW_SHOWN);
	if(_window == nullptr){
		logSDL("Init window");
		exit(1);
	}

	_renderer = SDL_CreateRenderer(
		_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	if(_renderer == nullptr){
		logSDL("Init renderer");
		exit(1);
	}

};


popo::core::Engine::~Engine(){

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();

};


void popo::core::Engine::_handleEvents(){

	SDL_Event e;
	while(SDL_PollEvent(&e)){
		
		if(e.type == SDL_QUIT)
		{
			stop();
		}

		if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
		{
			input.handleKeypress(e);
			popo::graphics::Spritemap* spmp = dynamic_cast<popo::graphics::Spritemap*>(_renderList[0]);
			if(e.key.state == SDL_PRESSED)
			{
				std::cout << spmp->currentFrame << std::endl;
				if(e.key.keysym.sym == 45)
					spmp->currentFrame -= 1;
				if(e.key.keysym.sym == 61)
					spmp->currentFrame += 1;
				std::cout << spmp->currentFrame << std::endl;
			}
		}
	}

}

void popo::core::Engine::render(){

	SDL_RenderClear(_renderer);
	for(RenderList::iterator it = _renderList.begin(); it != _renderList.end(); ++it){
		(*it)->render();
	}
	SDL_RenderPresent(_renderer);

};

void popo::core::Engine::update(){

};

void popo::core::Engine::add(popo::graphics::Drawable* child){

	_renderList.push_back(child);
	child->added(_renderer);

};

void popo::core::Engine::start(){

	while(true){
		_handleEvents();
		update();
		render();
	}

};

void popo::core::Engine::stop(){

	exit(0);

};

void popo::core::Engine::log(const std::string& msg){

	_logger << msg << std::endl;

};

void popo::core::Engine::logSDL(const std::string& msg){

	log(msg);
	log(SDL_GetError());

}