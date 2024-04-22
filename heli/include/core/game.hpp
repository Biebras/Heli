#ifndef GAME_HPP
#define GAME_HPP

#include <graphics/camera.hpp>

class Game
{
    public:
        static Game& Get()
        {
            static Game instance;
            return instance;
        }
        ~Game(){}
        
        Camera* ActiveCamera;
    private:
        Game();
        void OnCameraActivate(Camera* camera);
};

#endif
