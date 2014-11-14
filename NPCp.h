#ifndef NPCP_H
#define NPCP_H

#include "Personaje.h"

class Personaje;

class NPCp : public Personaje
{
    public:
        NPCp(int x, int y,SDL_Renderer* renderer,
            list<Personaje*>*personajes);
        virtual ~NPCp();
        void logic(Uint8* teclas_presionadas);
    protected:
    private:
};

#endif // NPCP_H
