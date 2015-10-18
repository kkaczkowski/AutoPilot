#include "Graph.h"
 
Graph::Graph() {
	posX = 0;
}

bool Graph::Init() {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    } 
    return true;
}

bool Graph::ShowWindow() {
  /*   window = SDL_CreateWindow(
        "Artificial horizon",                  
        SDL_WINDOWPOS_UNDEFINED,          
        SDL_WINDOWPOS_UNDEFINED,          
        640,                               
        480,                               
        SDL_WINDOW_SHOWN  | SDL_WINDOW_INPUT_FOCUS                 
    );*/
    
     if (SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return false;
    }
	return true;
}

void Graph::Render() {

    // clear screen with red color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    // draw green line across screen
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, 0, 0, 640, 480 - posX);
    SDL_RenderPresent(renderer);
    posX++;

}

void Graph::Close() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}
 
int main(int argc, char* argv[]) {
    Graph theApp;
 
    theApp.Init();
    theApp.ShowWindow();

	while(1)
	{
		theApp.Render();
		
		SDL_Delay(10); 
	}
    
    theApp.Close();
    
    return 0;
}
