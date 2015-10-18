#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL.h>
 
class Graph {
 
	private:
		SDL_Window   *window;
		SDL_Renderer *renderer;
		SDL_Surface  *surface;
        SDL_Texture  *texture;
        SDL_Event     event;
        
        int posX;
		
    public:
        Graph();
        bool Init();
        bool ShowWindow();
        void Render();
        void Close();

};
 
#endif
