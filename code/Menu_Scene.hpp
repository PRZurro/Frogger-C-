/*
 * MENU SCENE
 * Copyright © 2018+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 */

#ifndef MENU_SCENE_HEADER
#define MENU_SCENE_HEADER


#include "Intro_Scene.hpp"
#include "Sprite.hpp"

using namespace basics;
using namespace std;

namespace example{

    class Menu_Scene : public Intro_Scene{

    private:
        typedef std::shared_ptr < Sprite     >     Sprite_Handle;
        typedef std::list< Sprite_Handle     >     Sprite_List;
        Sprite_List    sprites;

        Sprite_Handle buttonPlay;
        Sprite_Handle buttonExit;
        Sprite_Handle buttonOptions;
        bool mainGame = true;

        std::shared_ptr < Texture_2D > buttonPlay_texture;
        std::shared_ptr < Texture_2D > buttonExit_texture;


    public:
        void handle (basics::Event & event) override;
        void update_waiting() override;
        void update_fading_out () override;
        void update_loading() override;
        void Render_Textures(Canvas &canvas) override;
        void render_playfield(Canvas & canvas);
        void CreateSprite(Sprite_Handle & spriteP,  Texture_2D * texture2D, const Point2f & point);
    };

}


#endif
