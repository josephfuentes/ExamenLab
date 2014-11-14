#include "NPCp.h"
void loop_Gameover();

int f=0;
int g=0;
NPCp::NPCp(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
   this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/llamas/01.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);
//
//    texturas_down.push_back(textura);
//    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/down2.png"));
//
//    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/up1.png"));
//    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/up2.png"));
//
//    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/left1.png"));
//    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/left2.png"));
//
//    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/right1.png"));
//    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/right2.png"));

     texturas_poder.push_back(IMG_LoadTexture(renderer, "assets/llamas/02.png"));
      texturas_poder.push_back(IMG_LoadTexture(renderer, "assets/llamas/03.png"));
       texturas_poder.push_back(IMG_LoadTexture(renderer, "assets/llamas/04.png"));

    textura_actual=texturas_poder.begin();


}


NPCp::~NPCp()
{
}
void NPCp::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;




            orientacion="poder";



    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo))
           loop_Gameover();
    }
}
