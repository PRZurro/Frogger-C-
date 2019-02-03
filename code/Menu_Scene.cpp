//
// Created by ThePa on 1/29/2018.
//

/*
 * MENU SCENE
 * Copyright © 2018+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#include "Game_Scene.hpp"
#include "Menu_Scene.hpp"

#include <basics/Canvas>
#include <basics/Director>

#include <basics/Log>
#include <basics/Scaling>
#include <basics/Rotation>
#include <basics/Translation>


using namespace basics;
using namespace std;



namespace example{

    void Menu_Scene::update_fading_out ()
    {
        if (state == FADING_OUT){
            state = FINISHED;

            if(mainGame){
                director.run_scene (shared_ptr< Scene >(new Game_Scene));
            }
        }
    }

    void Menu_Scene::handle(Event & event)
    {
       /* // Se esperan dos segundos sin hacer nada:

        if (timer.get_elapsed_seconds () > 2.f)
        {
            timer.reset ();

            state = FADING_OUT;
        }*/
        switch (event.id)
        {
            case ID(touch-started):
            case ID(touch-moved):
            case ID(touch-ended):
            {
                x = *event[ID(x)].as< var::Float > ();
                y = *event[ID(y)].as< var::Float > ();
                break;
            }
        }
    }

    void Menu_Scene::update_waiting() {

        if(buttonPlay.get()->contains({x,y})){
            mainGame=true;
            state=FADING_OUT;
        }

        if(buttonExit.get()->contains({x,y})){
            mainGame=false;
            director.stop();
        }
    }

    void Menu_Scene::update_loading ()
    {
        Graphics_Context::Accessor context = director.lock_graphics_context ();

        if (context)
        {
            // Se carga la textura del logo:

            buttonPlay_texture = Texture_2D::create (0, context, "game-scene/button_play.png");
            buttonExit_texture = Texture_2D::create (1, context, "game-scene/button_exit.png");

            // Se comprueba si la textura se ha podido cargar correctamente:

            if (buttonPlay_texture && buttonExit_texture)
            {
                context->add (buttonPlay_texture);
                context->add (buttonExit_texture);

                timer.reset ();

                opacity = 0.f;
                CreateSprite(buttonPlay, buttonPlay_texture.get(),{ canvas_width * .5f , canvas_height * .5f + 150.f });
                CreateSprite(buttonExit, buttonExit_texture.get(),{ canvas_width * .5f , canvas_height * .5f - 150.f });
                state   = FADING_IN;
            }
            else
                state   = ERROR;
        }
    }

    void Menu_Scene::render_playfield (Canvas & canvas)
    {
        for (auto & sprite : sprites)
        {
            sprite->render (canvas);
        }
    }

    void Menu_Scene::Render_Textures(Canvas &canvas) {
        render_playfield(canvas);

    }

    void Menu_Scene::CreateSprite(Sprite_Handle& spriteP,  Texture_2D * texture2D, const Point2f & point){
        if (texture2D)
        {
            Sprite_Handle buttonTemp(new Sprite(texture2D));

            spriteP =  buttonTemp;
            spriteP.get()->set_position( point );

            sprites.push_back(spriteP);

        }
    }

    }

