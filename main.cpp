
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<list>
#include "PersonajeJugador.h"
#include "NPC.h"
#include "NPC1.h"
#include "NPC2.h"
#include "NPCp.h"
#include <stdlib.h>     /* srand, rand */
#include <SDL2/SDL_mixer.h>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character, *menu,*menuJugar, *menuSalir,*gameover_background;
SDL_Rect rect_background,rect_character;
Mix_Chunk *seleccion;
void loopMenu();
void loop_Gameover()
{

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(Event.type == SDL_KEYDOWN)
            {


        }




        SDL_RenderCopy(renderer, gameover_background, NULL, &rect_background);
        SDL_RenderPresent(renderer);
    }
}
}

void loopJuego()
{
list<Personaje*>personajes;
    personajes.push_back(new PersonajeJugador (0,0,renderer,&personajes));
    personajes.push_back(new NPCp(50,222,renderer,&personajes));
    personajes.push_back(new NPCp(100,20,renderer,&personajes));
    personajes.push_back(new NPCp(180,20,renderer,&personajes));
    personajes.push_back(new NPCp(200,145,renderer,&personajes));
    personajes.push_back(new NPCp(270,20,renderer,&personajes));
    personajes.push_back(new NPCp(300,145,renderer,&personajes));

    personajes.push_back(new NPCp(481,70,renderer,&personajes));
    personajes.push_back(new NPCp(520,80,renderer,&personajes));
    personajes.push_back(new NPCp(410,90,renderer,&personajes));
//    personajes.push_back(new NPCp(50,0,renderer,&personajes));
//    personajes.push_back(new NPCp(70,0,renderer,&personajes));
//    personajes.push_back(new NPCp(90,0,renderer,&personajes));
//    personajes.push_back(new NPCp(110,0,renderer,&personajes));
//    personajes.push_back(new NPCp(270,216,renderer,&personajes));
//    personajes.push_back(new NPCp(22,113,renderer,&personajes));
//
//    personajes.push_back(new NPCp(481,84,renderer,&personajes));
//    personajes.push_back(new NPCp(520,84,renderer,&personajes));
//    personajes.push_back(new NPCp(410,116,renderer,&personajes));
    personajes.push_back(new NPC1(100,100,renderer,&personajes));
    personajes.push_back(new NPC (50,50,renderer,&personajes));
    personajes.push_back(new NPC2(230,0,renderer,&personajes));




    //Main Loop
    int frame=0;
    while(true)
    {
//        frame++;
//        if(frame%100==0)
//            personajes.push_back(new NPC (100,rand() % 100,renderer,&personajes));
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                 exit(0);
            }
        }

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->logic((Uint8*)SDL_GetKeyboardState( NULL ));

        SDL_RenderCopy(renderer, background, NULL, &rect_background);

        for(list<Personaje*>::iterator i = personajes.begin();
                i!=personajes.end();
                i++)
            (*i)->render(renderer);

        SDL_RenderPresent(renderer);

        SDL_Delay(16.66);

        if(personajes.size()==10){
        loopMenu();
        }

    }
}

void loopMenu()
{

    SDL_RenderCopy(renderer, menu, NULL, &rect_background);

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                exit(0);
            }
            if(Event.type == SDL_MOUSEMOTION)
            {
                int x, y;
                SDL_GetMouseState( &x, &y );
                cout<<x<<","<<y<<endl;
                if(x>182 && x<307 && y>89 && y<111)
                {
                SDL_RenderCopy(renderer, menuJugar, NULL, &rect_background);
                }else if(x>183 && x<294 && y>153 && y<175){
                SDL_RenderCopy(renderer, menuSalir, NULL, &rect_background);
                }else{
                SDL_RenderCopy(renderer, menu, NULL, &rect_background);
                }
            }

             if(Event.type == SDL_MOUSEBUTTONDOWN)
            {

                int click_x, click_y;
                SDL_GetMouseState( &click_x, &click_y );
                cout<<click_x<<","<<click_y<<endl;
                if(click_x>182 && click_x<307 && click_y>89 && click_y<111)
                {
                Mix_PlayChannel( -1, seleccion, 0 );
                loopJuego();
                }
                if(click_x>183 && click_x<294 && click_y>153 && click_y<175)
                {
                Mix_PlayChannel( -1, seleccion, 0 );
                    exit(0);
                }
            }
        }


        SDL_RenderPresent(renderer);
    }
}
int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    menu = IMG_LoadTexture(renderer,"assets/menu.png");
    menuJugar = IMG_LoadTexture(renderer,"assets/menuJugar.png");
    menuSalir = IMG_LoadTexture(renderer,"assets/menuSalir.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0; rect_background.y = 0; rect_background.w = w; rect_background.h = h;

    character = IMG_LoadTexture(renderer, "assets/personaje/down.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;
    gameover_background = IMG_LoadTexture(renderer,"assets/game_over.png");

     Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
seleccion = Mix_LoadWAV("button.wav");

loopMenu();
	return 0;
}
