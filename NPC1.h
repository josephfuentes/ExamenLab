#ifndef NPC1_H
#define NPC1_H

#include "Personaje.h"

class Personaje;

class NPC1 : public Personaje
{
    public:
        NPC1(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPC1();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPC1_H
