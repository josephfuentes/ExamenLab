#include "NPC.h"

NPC::NPC(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes)
{
    this->rectangulo.x = x;
    this->rectangulo.y = y;
    this->personajes=personajes;
    SDL_Texture *textura = IMG_LoadTexture(renderer, "assets/npcs/npc1/down1.png");
    SDL_QueryTexture(textura, NULL, NULL, &this->rectangulo.w, &this->rectangulo.h);

    texturas_down.push_back(textura);
    texturas_down.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/down2.png"));


    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/up1.png"));
    texturas_up.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/up2.png"));

    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/left1.png"));
    texturas_left.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/left2.png"));

    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/right1.png"));
    texturas_right.push_back(IMG_LoadTexture(renderer, "assets/npcs/npc1/right2.png"));



    textura_actual=texturas_down.begin();

    orientacion="down";
}

NPC::~NPC()
{
    //dtor
}

void NPC::logic(Uint8* teclas_presionadas)
{

    SDL_Rect temp = this->rectangulo;
   // cout<<rectangulo.x<<" "<<rectangulo.y<<endl;
        if(rectangulo.x>=50 && rectangulo.x<433 && rectangulo.y==50){
    rectangulo.x++;
     if(orientacion!="right")
            textura_actual=texturas_right.begin();
        orientacion="right";
}

 if(rectangulo.y>=50 && rectangulo.y<170 && rectangulo.x==433){
    rectangulo.y++;
     if(orientacion!="down")
            textura_actual=texturas_down.begin();
        orientacion="down";
}

   if(rectangulo.x>50 && rectangulo.x<=433 && rectangulo.y==170){
    rectangulo.x--;
     if(orientacion!="left")
            textura_actual=texturas_left.begin();
        orientacion="left";
}
 if(rectangulo.y>50 && rectangulo.y<=170 && rectangulo.x==50){
    rectangulo.y--;
     if(orientacion!="up")
            textura_actual=texturas_up.begin();
        orientacion="up";
}




//    if(rectangulo.x<433 && rectangulo.y==50){
//    rectangulo.x++;
//     if(orientacion!="right")
//            textura_actual=texturas_right.begin();
//        orientacion="right";
//}else if(rectangulo.x==433 && rectangulo.y>=50){
//rectangulo.y++;
//     if(orientacion!="down")
//            textura_actual=texturas_down.begin();
//        orientacion="down";
//}
//
//if(rectangulo.x>50 && rectangulo.x<=433 && rectangulo.y==170){
//rectangulo.x--;
//     if(orientacion!="left")
//            textura_actual=texturas_left.begin();
//        orientacion="left";
//}
//
//if(rectangulo.x>50 && rectangulo.y>=170 && rectangulo.y<=50){
//rectangulo.y--;
//     if(orientacion!="up")
//            textura_actual=texturas_up.begin();
//        orientacion="up";
//
//}


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

