//
// Created by Pablo on 2/12/2018.
//

#include <basics/Director>
#include "Game_Over_Scene.hpp"
#include "Menu_Scene.hpp"


namespace example
{


    void Game_Over_Scene::update_loading ()
    {
        Graphics_Context::Accessor context = director.lock_graphics_context ();

        if (context)
        {
            // Se carga la textura del logo:

            logo_texture = Texture_2D::create (0, context, "game-over.png");

            // Se comprueba si la textura se ha podido cargar correctamente:

            if (logo_texture)
            {
                context->add (logo_texture);

                timer.reset ();

                opacity = 0.f;
                state   = FADING_IN;
            }
            else
                state   = ERROR;
        }
    }

}
