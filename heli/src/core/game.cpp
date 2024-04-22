#include "core/event.hpp"
#include <core/game.hpp>

#include <core/event_manager.h>

Game::Game()
{
    cameraEvents.OnActivate.Subscribe(MethodSubscriber(OnCameraActivate));
}

void Game::OnCameraActivate(Camera* camera)
{
    ActiveCamera = camera;
}
