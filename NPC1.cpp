#include "NPC1.h"
int adelante = 0;
int atras = 0;

NPC1::NPC1(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
   this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc2/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/down2.png"));

    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/up1.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/up2.png"));

    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/left1.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/left2.png"));

    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/right1.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc2/right2.png"));

    textura_actual=texturas_down.begin();

    orientacion="down";
}

NPC1::~NPC1()
{
    //dtor
}

void NPC1::logic(Uint8* teclas_presionadas)
{
    SDL_Rect temp = this->rectangulo;

//cout<<rectangulo.x<<" "<<rectangulo.y<<endl;

  if(rectangulo.x>=100 && rectangulo.x<350 && adelante==0){
    rectangulo.x++;
     if(orientacion!="right")
            textura_actual=texturas_right.begin();
        orientacion="right";
}else if(atras==0){
adelante=1;
rectangulo.x--;
if(rectangulo.x==100){
adelante = 0;
}
     if(orientacion!="left")
            textura_actual=texturas_left.begin();
        orientacion="left";
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
