#include "NPC2.h"
int a = 0;
int d = 0;
NPC2::NPC2(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
     this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc3/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc3/down2.png"));

    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc3/up1.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc3/up2.png"));
//
//    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/left1.png"));
//    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/left2.png"));
//
//    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/right1.png"));
//    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/right2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";
}

NPC2::~NPC2()
{
    //dtor
}

void NPC2::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

//cout<<rectangulo.x<<" "<<rectangulo.y<<endl;

if(rectangulo.y>=0 && rectangulo.y<200 && a==0){
rectangulo.y++;
if(orientacion!="down")
            textura_actual=texturas_down.begin();
        orientacion="down";

}else if(d==0){
a=1;
rectangulo.y--;
if(rectangulo.y==0){
a = 0;
}
     if(orientacion!="up")
            textura_actual=texturas_up.begin();
        orientacion="up";

}
    for(list<Personaje*>::iterator i = personajes->begin();
            i!=personajes->end();
            i++)
    {
        if(this==(*i))
            continue;
        if(colision(this->rectangulo, (*i)->rectangulo))
            rectangulo=temp;
    }

}
