//
// Created by Pablo on 2/12/2018.
//

#ifndef ANDROID_STUDIO_3_GAME_OVER_SCENE_H
#define ANDROID_STUDIO_3_GAME_OVER_SCENE_H


#include <basics/Graphics_Context>
#include <basics/internal/Texture_2D.hpp>
#include <basics/Canvas>
#include <basics/internal/Timer.hpp>
#include "Intro_Scene.hpp"

namespace example
{

    using basics::Timer;
    using basics::Canvas;
    using basics::Texture_2D;
    using basics::Graphics_Context;

    class Game_Over_Scene : public Intro_Scene
    {
    protected:

         void update_loading    () override ;
    };

}



#endif //ANDROID_STUDIO_3_GAME_OVER_SCENE_H
